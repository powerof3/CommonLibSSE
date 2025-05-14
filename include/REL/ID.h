#pragma once

#include "REL/Module.h"

namespace REL
{
	namespace detail
	{
		class memory_map
		{
		public:
			memory_map() noexcept = default;
			memory_map(const memory_map&) = delete;

			memory_map(memory_map&& a_rhs) noexcept :
				_mapping(a_rhs._mapping),
				_view(a_rhs._view)
			{
				a_rhs._mapping = nullptr;
				a_rhs._view = nullptr;
			}

			~memory_map() { close(); }

			memory_map& operator=(const memory_map&) = delete;

			memory_map& operator=(memory_map&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_mapping = a_rhs._mapping;
					a_rhs._mapping = nullptr;

					_view = a_rhs._view;
					a_rhs._view = nullptr;
				}
				return *this;
			}

			[[nodiscard]] void* data() noexcept { return _view; }

			bool open(stl::zwstring a_name, std::size_t a_size);
			bool create(stl::zwstring a_name, std::size_t a_size);
			void close();

		private:
			void* _mapping{ nullptr };
			void* _view{ nullptr };
		};
	}

	class IDDatabase
	{
	private:
		struct mapping_t
		{
			std::uint64_t id;
			std::uint64_t offset;
		};

	public:
		class Offset2ID
		{
		public:
			using value_type = mapping_t;
			using container_type = std::vector<value_type>;
			using size_type = typename container_type::size_type;
			using const_iterator = typename container_type::const_iterator;
			using const_reverse_iterator = typename container_type::const_reverse_iterator;

			template <class ExecutionPolicy>
			explicit Offset2ID(ExecutionPolicy&& a_policy)  //
				requires(std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>)
			{
				const std::span<const mapping_t> id2offset = IDDatabase::get()._id2offset;
				_offset2id.reserve(id2offset.size());
				_offset2id.insert(_offset2id.begin(), id2offset.begin(), id2offset.end());
				std::sort(a_policy, _offset2id.begin(), _offset2id.end(), [](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.offset < a_rhs.offset;
				});
			}

			Offset2ID() :
				Offset2ID(std::execution::sequenced_policy{})
			{}

			[[nodiscard]] std::uint64_t operator()(std::size_t a_offset) const
			{
				const mapping_t elem{ 0, a_offset };
				const auto      it = std::lower_bound(
                    _offset2id.begin(),
                    _offset2id.end(),
                    elem,
                    [](auto&& a_lhs, auto&& a_rhs) {
                        return a_lhs.offset < a_rhs.offset;
                    });
				if (it == _offset2id.end()) {
					stl::report_and_fail(
						std::format(
							"Failed to find the offset within the database: 0x{:08X}"sv,
							a_offset));
				}

				return it->id;
			}

			[[nodiscard]] const_iterator begin() const noexcept { return _offset2id.begin(); }
			[[nodiscard]] const_iterator cbegin() const noexcept { return _offset2id.cbegin(); }

			[[nodiscard]] const_iterator end() const noexcept { return _offset2id.end(); }
			[[nodiscard]] const_iterator cend() const noexcept { return _offset2id.cend(); }

			[[nodiscard]] const_reverse_iterator rbegin() const noexcept { return _offset2id.rbegin(); }
			[[nodiscard]] const_reverse_iterator crbegin() const noexcept { return _offset2id.crbegin(); }

			[[nodiscard]] const_reverse_iterator rend() const noexcept { return _offset2id.rend(); }
			[[nodiscard]] const_reverse_iterator crend() const noexcept { return _offset2id.crend(); }

			[[nodiscard]] size_type size() const noexcept { return _offset2id.size(); }

		private:
			container_type _offset2id;
		};

		[[nodiscard]] static IDDatabase& get()
		{
			static IDDatabase singleton;
			return singleton;
		}

		[[nodiscard]] inline std::size_t id2offset(std::uint64_t a_id) const
		{
			mapping_t  elem{ a_id, 0 };
			const auto it = std::lower_bound(
				_id2offset.begin(),
				_id2offset.end(),
				elem,
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.id < a_rhs.id;
				});
			if (it == _id2offset.end()) {
				stl::report_and_fail(
					std::format(
						"Failed to find the id within the address library: {}\n"
						"This means this script extender plugin is incompatible with the address "
						"library for this version of the game, and thus does not support it."sv,
						a_id));
			}

			return static_cast<std::size_t>(it->offset);
		}

	private:
		friend Offset2ID;

		class header_t
		{
		public:
			void read(binary_io::file_istream& a_in)
			{
				const auto [format] = a_in.read<std::int32_t>();
#ifdef SKYRIM_SUPPORT_AE
				if (format != 2) {
#else
				if (format != 1) {
#endif
					stl::report_and_fail(
						std::format(
							"Unsupported address library format: {}\n"
							"This means this script extender plugin is incompatible with the address "
							"library available for this version of the game, and thus does not "
							"support it."sv,
							format));
				}

				const auto [major, minor, patch, revision] =
					a_in.read<std::int32_t, std::int32_t, std::int32_t, std::int32_t>();
				_version[0] = static_cast<std::uint16_t>(major);
				_version[1] = static_cast<std::uint16_t>(minor);
				_version[2] = static_cast<std::uint16_t>(patch);
				_version[3] = static_cast<std::uint16_t>(revision);

				const auto [nameLen] = a_in.read<std::int32_t>();
				a_in.seek_relative(nameLen);

				a_in.read(_pointerSize, _addressCount);
			}

			[[nodiscard]] std::size_t   address_count() const noexcept { return static_cast<std::size_t>(_addressCount); }
			[[nodiscard]] std::uint64_t pointer_size() const noexcept { return static_cast<std::uint64_t>(_pointerSize); }
			[[nodiscard]] Version       version() const noexcept { return _version; }

		private:
			Version      _version;
			std::int32_t _pointerSize{ 0 };
			std::int32_t _addressCount{ 0 };
		};

		IDDatabase() { load(); }

		IDDatabase(const IDDatabase&) = delete;
		IDDatabase(IDDatabase&&) = delete;

		~IDDatabase() = default;

		IDDatabase& operator=(const IDDatabase&) = delete;
		IDDatabase& operator=(IDDatabase&&) = delete;

		void load()
		{
			const auto version = Module::get().version();
			const auto filename =
				stl::utf8_to_utf16(
					std::format(
#ifdef SKYRIM_SUPPORT_AE
						"Data/SKSE/Plugins/versionlib-{}.bin"sv,
#else
						"Data/SKSE/Plugins/version-{}.bin"sv,
#endif
						version.string()))
					.value_or(L"<unknown filename>"s);
			load_file(filename, version);
		}

		void load_file(stl::zwstring a_filename, Version a_version)
		{
			try {
				binary_io::file_istream in(a_filename);
				header_t                header;
				header.read(in);
				if (header.version() != a_version) {
					stl::report_and_fail("version mismatch"sv);
				}

				auto mapname = L"CommonLibSSEOffsets-v2-"s;
				mapname += a_version.wstring();
				const auto byteSize = static_cast<std::size_t>(header.address_count()) * sizeof(mapping_t);
				if (_mmap.open(mapname, byteSize)) {
					_id2offset = { static_cast<mapping_t*>(_mmap.data()), header.address_count() };
				} else if (_mmap.create(mapname, byteSize)) {
					_id2offset = { static_cast<mapping_t*>(_mmap.data()), header.address_count() };
					unpack_file(in, header);
					std::sort(
						_id2offset.begin(),
						_id2offset.end(),
						[](auto&& a_lhs, auto&& a_rhs) {
							return a_lhs.id < a_rhs.id;
						});
				} else {
					stl::report_and_fail("failed to create shared mapping"sv);
				}
			} catch (const std::system_error&) {
				stl::report_and_fail(
					std::format(
						"Failed to locate an appropriate address library with the path: {}\n"
						"This means you are missing the address library for this specific version of "
						"the game. Please continue to the mod page for address library to download "
						"an appropriate version. If one is not available, then it is likely that "
						"address library has not yet added support for this version of the game."sv,
						stl::utf16_to_utf8(a_filename).value_or("<unknown filename>"s)));
			}
		}

		void unpack_file(binary_io::file_istream& a_in, header_t a_header)
		{
			std::uint8_t  type = 0;
			std::uint64_t id = 0;
			std::uint64_t offset = 0;
			std::uint64_t prevID = 0;
			std::uint64_t prevOffset = 0;
			for (auto& mapping : _id2offset) {
				a_in.read(type);
				const auto lo = static_cast<std::uint8_t>(type & 0xF);
				const auto hi = static_cast<std::uint8_t>(type >> 4);

				switch (lo) {
				case 0:
					a_in.read(id);
					break;
				case 1:
					id = prevID + 1;
					break;
				case 2:
					id = prevID + std::get<0>(a_in.read<std::uint8_t>());
					break;
				case 3:
					id = prevID - std::get<0>(a_in.read<std::uint8_t>());
					break;
				case 4:
					id = prevID + std::get<0>(a_in.read<std::uint16_t>());
					break;
				case 5:
					id = prevID - std::get<0>(a_in.read<std::uint16_t>());
					break;
				case 6:
					std::tie(id) = a_in.read<std::uint16_t>();
					break;
				case 7:
					std::tie(id) = a_in.read<std::uint32_t>();
					break;
				default:
					stl::report_and_fail("unhandled type"sv);
				}

				const std::uint64_t tmp = (hi & 8) != 0 ? (prevOffset / a_header.pointer_size()) : prevOffset;

				switch (hi & 7) {
				case 0:
					a_in.read(offset);
					break;
				case 1:
					offset = tmp + 1;
					break;
				case 2:
					offset = tmp + std::get<0>(a_in.read<std::uint8_t>());
					break;
				case 3:
					offset = tmp - std::get<0>(a_in.read<std::uint8_t>());
					break;
				case 4:
					offset = tmp + std::get<0>(a_in.read<std::uint16_t>());
					break;
				case 5:
					offset = tmp - std::get<0>(a_in.read<std::uint16_t>());
					break;
				case 6:
					std::tie(offset) = a_in.read<std::uint16_t>();
					break;
				case 7:
					std::tie(offset) = a_in.read<std::uint32_t>();
					break;
				default:
					stl::report_and_fail("unhandled type"sv);
				}

				if ((hi & 8) != 0) {
					offset *= a_header.pointer_size();
				}

				mapping = { id, offset };

				prevOffset = offset;
				prevID = id;
			}
		}

		detail::memory_map   _mmap;
		std::span<mapping_t> _id2offset;
	};

	class ID
	{
	public:
		constexpr ID() noexcept = default;

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(std::uint64_t a_id) noexcept
		{
			_id = a_id;
			return *this;
		}

		[[nodiscard]] std::uintptr_t          address() const { return base() + offset(); }
		[[nodiscard]] constexpr std::uint64_t id() const noexcept { return _id; }
		[[nodiscard]] std::size_t             offset() const { return IDDatabase::get().id2offset(_id); }

	private:
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }

		std::uint64_t _id{ 0 };
	};
}
