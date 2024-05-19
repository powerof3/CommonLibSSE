#pragma once

#include "REL/Version.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	class Segment
	{
	public:
		enum Name : std::size_t
		{
			textx,
			idata,
			rdata,
			data,
			pdata,
			tls,
			textw,
			gfids,
			total
		};

		Segment() noexcept = default;

		Segment(std::uintptr_t a_proxyBase, std::uintptr_t a_address, std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase),
			_address(a_address),
			_size(a_size)
		{}

		[[nodiscard]] std::uintptr_t address() const noexcept { return _address; }
		[[nodiscard]] std::size_t    offset() const noexcept { return address() - _proxyBase; }
		[[nodiscard]] std::size_t    size() const noexcept { return _size; }

		[[nodiscard]] void* pointer() const noexcept { return reinterpret_cast<void*>(address()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		std::uintptr_t _proxyBase{ 0 };
		std::uintptr_t _address{ 0 };
		std::size_t    _size{ 0 };
	};

	class Module
	{
	public:
		[[nodiscard]] static Module& get()
		{
			static Module singleton;
			return singleton;
		}

		[[nodiscard]] std::uintptr_t base() const noexcept { return _base; }
		[[nodiscard]] stl::zwstring  filename() const noexcept { return _filename; }
		[[nodiscard]] Version        version() const noexcept { return _version; }

		[[nodiscard]] Segment segment(Segment::Name a_segment) const noexcept { return _segments[a_segment]; }

		[[nodiscard]] REX::W32::HMODULE pointer() const noexcept { return reinterpret_cast<REX::W32::HMODULE>(base()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		Module()
		{
			const auto getFilename = [&]() {
				return REX::W32::GetEnvironmentVariableW(
					ENVIRONMENT.data(),
					_filename.data(),
					static_cast<std::uint32_t>(_filename.size()));
			};

			_filename.resize(getFilename());
			if (const auto result = getFilename();
				result != _filename.size() - 1 ||
				result == 0) {
#ifndef SKYRIMVR
				_filename = L"SkyrimSE.exe"sv;
#else
				_filename = L"SkyrimVR.exe"sv;
#endif
			}

			load();
		}

		Module(const Module&) = delete;
		Module(Module&&) = delete;

		~Module() noexcept = default;

		Module& operator=(const Module&) = delete;
		Module& operator=(Module&&) = delete;

		void load()
		{
			auto handle = REX::W32::GetModuleHandleW(_filename.c_str());
			if (handle == nullptr) {
				stl::report_and_fail(
					std::format(
						"Failed to obtain module handle for: \"{0}\".\n"
						"You have likely renamed the executable to something unexpected. "
						"Renaming the executable back to \"{0}\" may resolve the issue."sv,
						stl::utf16_to_utf8(_filename).value_or("<unicode conversion error>"s)));
			}
			_base = reinterpret_cast<std::uintptr_t>(handle);

			load_version();
			load_segments();
		}

		void load_segments();

		void load_version()
		{
			const auto version = GetFileVersion(_filename);
			if (version) {
				_version = *version;
			} else {
				stl::report_and_fail(
					std::format(
						"Failed to obtain file version info for: {}\n"
						"Please contact the author of this script extender plugin for further assistance."sv,
						stl::utf16_to_utf8(_filename).value_or("<unicode conversion error>"s)));
			}
		}

		static constexpr std::array SEGMENTS{
			std::make_pair(".text"sv, REX::W32::IMAGE_SCN_MEM_EXECUTE),
			std::make_pair(".idata"sv, 0u),
			std::make_pair(".rdata"sv, 0u),
			std::make_pair(".data"sv, 0u),
			std::make_pair(".pdata"sv, 0u),
			std::make_pair(".tls"sv, 0u),
			std::make_pair(".text"sv, REX::W32::IMAGE_SCN_MEM_WRITE),
			std::make_pair(".gfids"sv, 0u)
		};

		static constexpr auto ENVIRONMENT = L"SKSE_RUNTIME"sv;

		std::wstring                        _filename;
		std::array<Segment, Segment::total> _segments;
		Version                             _version;
		std::uintptr_t                      _base{ 0 };
	};
}
