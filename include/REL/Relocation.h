#pragma once

#pragma warning(push)
#pragma warning(disable: 4996 4458 4267 4244)
#include <csv.h>
#pragma warning(pop)

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <                                                                                    \
		class R,                                                                                  \
		class Cls,                                                                                \
		class... Args>                                                                            \
	struct member_function_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args...) a_propQual;                                     \
	};                                                                                            \
                                                                                                  \
	template <                                                                                    \
		class R,                                                                                  \
		class Cls,                                                                                \
		class... Args>                                                                            \
	struct member_function_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args..., ...) a_propQual;                                \
	};

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <                                                                                        \
		class R,                                                                                      \
		class Cls,                                                                                    \
		class... Args>                                                                                \
	struct member_function_non_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args...)a_propQual;                                  \
	};                                                                                                \
                                                                                                      \
	template <                                                                                        \
		class R,                                                                                      \
		class Cls,                                                                                    \
		class... Args>                                                                                \
	struct member_function_non_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args..., ...)a_propQual;                             \
	};

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

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

		template <class>
		struct member_function_pod_type;

		REL_MAKE_MEMBER_FUNCTION_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const volatile);

		template <class F>
		using member_function_pod_type_t = typename member_function_pod_type<F>::type;

		template <class>
		struct member_function_non_pod_type;

		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const volatile);

		template <class F>
		using member_function_non_pod_type_t = typename member_function_non_pod_type<F>::type;

		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T>
		struct meets_length_req :
			std::disjunction<
				std::bool_constant<sizeof(T) == 1>,
				std::bool_constant<sizeof(T) == 2>,
				std::bool_constant<sizeof(T) == 4>,
				std::bool_constant<sizeof(T) == 8>>
		{};

		template <class T>
		struct meets_function_req :
			std::conjunction<
				std::is_trivially_constructible<T>,
				std::is_trivially_destructible<T>,
				std::is_trivially_copy_assignable<T>,
				std::negation<
					std::is_polymorphic<T>>>
		{};

		template <class T>
		struct meets_member_req :
			std::is_standard_layout<T>
		{};

		template <class T, class = void>
		struct is_x64_pod :
			std::true_type
		{};

		template <class T>
		struct is_x64_pod<
			T,
			std::enable_if_t<
				std::is_union_v<T>>> :
			std::false_type
		{};

		template <class T>
		struct is_x64_pod<
			T,
			std::enable_if_t<
				std::is_class_v<T>>> :
			std::conjunction<
				meets_length_req<T>,
				meets_function_req<T>,
				meets_member_req<T>>
		{};

		template <class T>
		inline constexpr bool is_x64_pod_v = is_x64_pod<T>::value;

		template <
			class F,
			class First,
			class... Rest>
		decltype(auto) invoke_member_function_non_pod(F&& a_func, First&& a_first, Rest&&... a_rest)  //
			noexcept(std::is_nothrow_invocable_v<F, First, Rest...>)
		{
			using result_t = std::invoke_result_t<F, First, Rest...>;
			std::aligned_storage_t<sizeof(result_t), alignof(result_t)> result;

			using func_t = member_function_non_pod_type_t<F>;
			auto func = stl::unrestricted_cast<func_t*>(std::forward<F>(a_func));

			return func(std::forward<First>(a_first), std::addressof(result), std::forward<Rest>(a_rest)...);
		}
	}

	inline constexpr std::uint8_t NOP = 0x90;
	inline constexpr std::uint8_t RET = 0xC3;
	inline constexpr std::uint8_t INT3 = 0xCC;

	template <class F, class... Args>
	std::invoke_result_t<F, Args...> invoke(F&& a_func, Args&&... a_args)  //
		noexcept(std::is_nothrow_invocable_v<F, Args...>)                  //
		requires(std::invocable<F, Args...>)
	{
		if constexpr (std::is_member_function_pointer_v<std::decay_t<F>>) {
			if constexpr (detail::is_x64_pod_v<std::invoke_result_t<F, Args...>>) {  // member functions == free functions in x64
				using func_t = detail::member_function_pod_type_t<std::decay_t<F>>;
				auto func = stl::unrestricted_cast<func_t*>(std::forward<F>(a_func));
				return func(std::forward<Args>(a_args)...);
			} else {  // shift args to insert result
				return detail::invoke_member_function_non_pod(std::forward<F>(a_func), std::forward<Args>(a_args)...);
			}
		} else {
			return std::forward<F>(a_func)(std::forward<Args>(a_args)...);
		}
	}

	inline void safe_write(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		auto          success =
			WinAPI::VirtualProtect(
				reinterpret_cast<void*>(a_dst),
				a_count,
				(WinAPI::PAGE_EXECUTE_READWRITE),
				std::addressof(old));
		if (success != 0) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success =
				WinAPI::VirtualProtect(
					reinterpret_cast<void*>(a_dst),
					a_count,
					old,
					std::addressof(old));
		}

		assert(success != 0);
	}

	template <std::integral T>
	void safe_write(std::uintptr_t a_dst, const T& a_data)
	{
		safe_write(a_dst, std::addressof(a_data), sizeof(T));
	}

	template <class T>
	void safe_write(std::uintptr_t a_dst, std::span<T> a_data)
	{
		safe_write(a_dst, a_data.data(), a_data.size_bytes());
	}

	inline void safe_fill(std::uintptr_t a_dst, std::uint8_t a_value, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		auto          success =
			WinAPI::VirtualProtect(
				reinterpret_cast<void*>(a_dst),
				a_count,
				(WinAPI::PAGE_EXECUTE_READWRITE),
				std::addressof(old));
		if (success != 0) {
			std::fill_n(reinterpret_cast<std::uint8_t*>(a_dst), a_count, a_value);
			success =
				WinAPI::VirtualProtect(
					reinterpret_cast<void*>(a_dst),
					a_count,
					old,
					std::addressof(old));
		}

		assert(success != 0);
	}

	class Version
	{
	public:
		using value_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;

		constexpr Version() noexcept = default;

		explicit constexpr Version(std::array<value_type, 4> a_version) noexcept :
			_impl(a_version)
		{}

		constexpr Version(value_type a_v1, value_type a_v2 = 0, value_type a_v3 = 0, value_type a_v4 = 0) noexcept :
			_impl{ a_v1, a_v2, a_v3, a_v4 }
		{}

		[[nodiscard]] constexpr reference       operator[](std::size_t a_idx) noexcept { return _impl[a_idx]; }
		[[nodiscard]] constexpr const_reference operator[](std::size_t a_idx) const noexcept { return _impl[a_idx]; }

		[[nodiscard]] constexpr decltype(auto) begin() const noexcept { return _impl.begin(); }
		[[nodiscard]] constexpr decltype(auto) cbegin() const noexcept { return _impl.cbegin(); }
		[[nodiscard]] constexpr decltype(auto) end() const noexcept { return _impl.end(); }
		[[nodiscard]] constexpr decltype(auto) cend() const noexcept { return _impl.cend(); }

		[[nodiscard]] std::strong_ordering constexpr compare(const Version& a_rhs) const noexcept
		{
			for (std::size_t i = 0; i < _impl.size(); ++i) {
				if ((*this)[i] != a_rhs[i]) {
					return (*this)[i] < a_rhs[i] ? std::strong_ordering::less : std::strong_ordering::greater;
				}
			}
			return std::strong_ordering::equal;
		}

		[[nodiscard]] constexpr std::uint32_t pack() const noexcept
		{
			return static_cast<std::uint32_t>(
				(_impl[0] & 0x0FF) << 24u |
				(_impl[1] & 0x0FF) << 16u |
				(_impl[2] & 0xFFF) << 4u |
				(_impl[3] & 0x00F) << 0u);
		}

		[[nodiscard]] std::string string() const
		{
			std::string result;
			for (auto&& ver : _impl) {
				result += std::to_string(ver);
				result += '-';
			}
			result.pop_back();
			return result;
		}

		[[nodiscard]] std::wstring wstring() const
		{
			std::wstring result;
			for (auto&& ver : _impl) {
				result += std::to_wstring(ver);
				result += L'-';
			}
			result.pop_back();
			return result;
		}

	private:
		std::array<value_type, 4> _impl{ 0, 0, 0, 0 };
	};

	[[nodiscard]] constexpr bool                 operator==(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) == 0; }
	[[nodiscard]] constexpr std::strong_ordering operator<=>(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs); }

	[[nodiscard]] inline std::optional<Version> get_file_version(stl::zwstring a_filename)
	{
		std::uint32_t     dummy;
		std::vector<char> buf(WinAPI::GetFileVersionInfoSize(a_filename.data(), std::addressof(dummy)));
		if (buf.empty()) {
			return std::nullopt;
		}

		if (!WinAPI::GetFileVersionInfo(a_filename.data(), 0, static_cast<std::uint32_t>(buf.size()), buf.data())) {
			return std::nullopt;
		}

		void*         verBuf{ nullptr };
		std::uint32_t verLen{ 0 };
		if (!WinAPI::VerQueryValue(buf.data(), L"\\StringFileInfo\\040904B0\\ProductVersion", std::addressof(verBuf), std::addressof(verLen))) {
			return std::nullopt;
		}

		Version             version;
		std::wistringstream ss(
			std::wstring(static_cast<const wchar_t*>(verBuf), verLen));
		std::wstring token;
		for (std::size_t i = 0; i < 4 && std::getline(ss, token, L'.'); ++i) {
			version[i] = static_cast<std::uint16_t>(std::stoi(token));
		}

		return version;
	}

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
		/**
		 * Identifies a Skyrim runtime.
		 */
		enum class Runtime : uint8_t {
			/**
			 * The Skyrim runtime is a post-Anniversary Edition Skyrim SE release (version 1.6.x and later).
			 */
			AE,

			/**
			 * The Skyrim runtime is a pre-Anniversary Edition Skyrim SE release (version 1.5.97 and prior).
			 */
			SE,

			/**
			 * The Skyrim runtime is Skyrim VR.
			 */
			VR
		};

		[[nodiscard]] static Module& get()
		{
			static Module singleton;
			return singleton;
		}

		[[nodiscard]] std::uintptr_t               base() const noexcept { return _base; }
		[[nodiscard]] stl::zwstring                filename() const noexcept { return _filename; }
		[[nodiscard]] Version                      version() const noexcept { return _version; }

		[[nodiscard]] Segment segment(Segment::Name a_segment) const noexcept { return _segments[a_segment]; }

		[[nodiscard]] void* pointer() const noexcept { return reinterpret_cast<void*>(base()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

		/**
		 * Get the type of runtime the currently-loaded Skyrim module is.
		 */
		[[nodiscard]] inline Runtime GetRuntime() const noexcept
		{
			return _runtime;
		}

		/**
		 * Returns whether the current Skyrim runtime is a post-Anniversary Edition Skyrim SE release.
		 */
		[[nodiscard]] inline bool IsAE() const noexcept
		{
			return GetRuntime() == Runtime::AE;
		}

		/**
		 * Returns whether the current Skyrim runtime is a pre-Anniversary Edition Skyrim SE release.
		 */
		[[nodiscard]] inline bool IsSE() const noexcept
		{
			return GetRuntime() == Runtime::SE;
		}

		/**
		 * Returns whether the current Skyrim runtime is a Skyrim VR release.
		 */
		[[nodiscard]] inline bool IsVR() const noexcept
		{
			return GetRuntime() == Runtime::VR;
		}

	private:
		Module()
		{
			const auto getFilename = [&]() {
				return WinAPI::GetEnvironmentVariable(
					ENVIRONMENT.data(),
					_filename.data(),
					static_cast<std::uint32_t>(_filename.size()));
			};

			void* moduleHandle = nullptr;
			_filename.resize(getFilename());
			if (const auto result = getFilename();
				result != _filename.size() - 1 ||
				result == 0) {
				for (auto runtime : RUNTIMES) {
					_filename = runtime;
					moduleHandle = WinAPI::GetModuleHandle(_filename.c_str());
					if (moduleHandle) {
						break;
					}
				}
			}
			if (moduleHandle) {
				load(moduleHandle);
			}
		}

		Module(const Module&) = delete;
		Module(Module&&) = delete;

		~Module() noexcept = default;

		Module& operator=(const Module&) = delete;
		Module& operator=(Module&&) = delete;

		void load(void* handle)
		{
			if (_filename == L"SkyrimVR.exe") {
				_runtime = Runtime::VR;
			}
			_base = reinterpret_cast<std::uintptr_t>(handle);
			load_version();
			load_segments();
		}

		void load_segments();

		void load_version()
		{
			const auto version = get_file_version(_filename);
			if (version) {
				_version = *version;
				if (_version[1] == 5) {
					_runtime = Runtime::SE;
				}
			} else {
				stl::report_and_fail(
					fmt::format(
						"Failed to obtain file version info for: {}\n"
						"Please contact the author of this script extender plugin for further assistance."sv,
						stl::utf16_to_utf8(_filename).value_or("<unicode conversion error>"s)));
			}
		}

		static constexpr std::array SEGMENTS{
			std::make_pair(".text"sv, WinAPI::IMAGE_SCN_MEM_EXECUTE),
			std::make_pair(".idata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".rdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".data"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".pdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".tls"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".text"sv, WinAPI::IMAGE_SCN_MEM_WRITE),
			std::make_pair(".gfids"sv, static_cast<std::uint32_t>(0))
		};

		static constexpr auto ENVIRONMENT = L"SKSE_RUNTIME"sv;
		static constexpr std::array<std::wstring_view, 2> RUNTIMES{ {
			L"SkyrimVR.exe",
			L"SkyrimSE.exe"
		} };

		std::wstring                        _filename;
		std::array<Segment, Segment::total> _segments;
		Version                             _version;
		std::uintptr_t                      _base{ 0 };
		Runtime                             _runtime{ Runtime::AE };
	};

#ifndef USING_AE
#	define USING_AE (REL::Module::get().version()[1] > 5)
#endif
#ifndef USING_VR
#	define USING_VR (REL::Module::get().version()[1] == 4)
#endif

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
				std::sort(
					a_policy,
					_offset2id.begin(),
					_offset2id.end(),
					[](auto&& a_lhs, auto&& a_rhs) {
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
						fmt::format(
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
					fmt::format(
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
				if (format != (USING_AE ? 2 : 1)) {
					stl::report_and_fail(
						fmt::format(
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
			if (USING_VR) {
				const auto filename =
					stl::utf8_to_utf16(
						fmt::format(
							"Data/SKSE/Plugins/version-{}.csv"sv,
							version.string()))
						.value_or(L"<unknown filename>"s);
				load_csv(filename, version);
			} else {
				const auto filename =
					stl::utf8_to_utf16(
						USING_AE ?
							fmt::format("Data/SKSE/Plugins/versionlib-{}.bin"sv,
								version.string()) :
                            fmt::format("Data/SKSE/Plugins/version-{}.bin"sv,
								version.string()))
						.value_or(L"<unknown filename>"s);
				load_file(filename, version);
			}
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
				if (!_mmap.open(mapname, byteSize) &&
					!_mmap.create(mapname, byteSize)) {
					stl::report_and_fail("failed to create shared mapping"sv);
				}

				_id2offset = { static_cast<mapping_t*>(_mmap.data()), header.address_count() };
				unpack_file(in, header);
				std::sort(
					_id2offset.begin(),
					_id2offset.end(),
					[](auto&& a_lhs, auto&& a_rhs) {
						return a_lhs.id < a_rhs.id;
					});
			} catch (const std::system_error&) {
				stl::report_and_fail(
					fmt::format(
						"Failed to locate an appropriate address library with the path: {}\n"
						"This means you are missing the address library for this specific version of "
						"the game. Please continue to the mod page for address library to download "
						"an appropriate version. If one is not available, then it is likely that "
						"address library has not yet added support for this version of the game."sv,
						stl::utf16_to_utf8(a_filename).value_or("<unknown filename>"s)));
			}
		}

		// Ported from alandtse's CommonLibVR branch with CSV support.
		bool load_csv(stl::zwstring a_filename, Version a_version)
		{
			// conversion code from https://docs.microsoft.com/en-us/cpp/text/how-to-convert-between-various-string-types?view=msvc-170
			const wchar_t*    orig = a_filename.data();
			std::size_t       origsize = wcslen(orig) + 1;
			std::size_t       convertedChars = 0;
			const std::size_t newsize = origsize * 2;
			char*             nstring = new char[newsize];
			wcstombs_s(&convertedChars, nstring, newsize, orig, _TRUNCATE);
			if (!std::filesystem::exists(nstring))
				stl::report_and_fail(fmt::format("Required VR Address Library file {} does not exist"sv, nstring));
			io::CSVReader<2, io::trim_chars<>, io::no_quote_escape<','>> in(nstring);
			in.read_header(io::ignore_missing_column, "id", "offset");
			std::size_t id, address_count;
			std::string version, offset;
			auto        mapname = L"CommonLibSSEOffsets-v2-"s;
			mapname += a_version.wstring();
			in.read_row(address_count, version);
			const auto byteSize = static_cast<std::size_t>(address_count * sizeof(mapping_t));
			if (!_mmap.open(mapname, byteSize) &&
				!_mmap.create(mapname, byteSize)) {
				stl::report_and_fail("failed to create shared mapping"sv);
			}
			_id2offset = { static_cast<mapping_t*>(_mmap.data()), static_cast<std::size_t>(address_count) };
			int index = 0;
			while (in.read_row(id, offset)) {
				if (index >= address_count)
					stl::report_and_fail(fmt::format("VR Address Library {} tried to exceed {} allocated entries."sv, version, address_count));
				_id2offset[index++] = { static_cast<std::uint64_t>(id),
					static_cast<std::uint64_t>(std::stoul(offset, nullptr, 16)) };
			}
			if (index != address_count)
				stl::report_and_fail(fmt::format("VR Address Library {} loaded only {} entries but expected {}. Please redownload."sv, version, index, address_count));
			std::sort(
				_id2offset.begin(),
				_id2offset.end(),
				[](auto&& a_lhs, auto&& a_rhs) {
					return a_lhs.id < a_rhs.id;
				});
			//			_natvis = _id2offset.data();
			return true;
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

	class Offset
	{
	public:
		constexpr Offset() noexcept = default;

		explicit constexpr Offset(std::size_t a_offset) noexcept :
			_offset(a_offset)
		{}

		constexpr Offset& operator=(std::size_t a_offset) noexcept
		{
			_offset = a_offset;
			return *this;
		}

		[[nodiscard]] std::uintptr_t        address() const { return base() + offset(); }
		[[nodiscard]] constexpr std::size_t offset() const noexcept { return _offset; }

	private:
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }

		std::size_t _offset{ 0 };
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

	template <class T>
	class Relocation
	{
	public:
		using value_type =
			std::conditional_t<
				std::is_member_pointer_v<T> || std::is_function_v<std::remove_pointer_t<T>>,
				std::decay_t<T>,
				T>;

		constexpr Relocation() noexcept = default;

		explicit constexpr Relocation(std::uintptr_t a_address) noexcept :
			_impl{ a_address }
		{}

		explicit Relocation(Offset a_offset) :
			_impl{ a_offset.address() }
		{}

		explicit Relocation(ID a_id) :
			_impl{ a_id.address() }
		{}

		explicit Relocation(ID a_id, std::ptrdiff_t a_offset) :
			_impl{ a_id.address() + a_offset }
		{}

		constexpr Relocation& operator=(std::uintptr_t a_address) noexcept
		{
			_impl = a_address;
			return *this;
		}

		Relocation& operator=(Offset a_offset)
		{
			_impl = a_offset.address();
			return *this;
		}

		Relocation& operator=(ID a_id)
		{
			_impl = a_id.address();
			return *this;
		}

		template <class U = value_type>
		[[nodiscard]] decltype(auto) operator*() const noexcept  //
			requires(std::is_pointer_v<U>)
		{
			return *get();
		}

		template <class U = value_type>
		[[nodiscard]] auto operator->() const noexcept  //
			requires(std::is_pointer_v<U>)
		{
			return get();
		}

		template <class... Args>
		std::invoke_result_t<const value_type&, Args...> operator()(Args&&... a_args) const  //
			noexcept(std::is_nothrow_invocable_v<const value_type&, Args...>)                //
			requires(std::invocable<const value_type&, Args...>)
		{
			return REL::invoke(get(), std::forward<Args>(a_args)...);
		}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _impl; }
		[[nodiscard]] std::size_t              offset() const { return _impl - base(); }

		[[nodiscard]] value_type get() const  //
			noexcept(std::is_nothrow_copy_constructible_v<value_type>)
		{
			assert(_impl != 0);
			return stl::unrestricted_cast<value_type>(_impl);
		}

		template <class U = value_type>
		std::uintptr_t write_vfunc(std::size_t a_idx, std::uintptr_t a_newFunc)  //
			requires(std::same_as<U, std::uintptr_t>)
		{
			const auto addr = address() + (sizeof(void*) * a_idx);
			const auto result = *reinterpret_cast<std::uintptr_t*>(addr);
			safe_write(addr, a_newFunc);
			return result;
		}

		template <class F>
		std::uintptr_t write_vfunc(std::size_t a_idx, F a_newFunc)  //
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return write_vfunc(a_idx, stl::unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

	private :
		// clang-format off
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }
		// clang-format on

		std::uintptr_t _impl{ 0 };
	};

	namespace detail
	{
		namespace characters
		{
			[[nodiscard]] constexpr bool hexadecimal(char a_ch) noexcept
			{
				return ('0' <= a_ch && a_ch <= '9') ||
				       ('A' <= a_ch && a_ch <= 'F') ||
				       ('a' <= a_ch && a_ch <= 'f');
			}

			[[nodiscard]] constexpr bool space(char a_ch) noexcept
			{
				return a_ch == ' ';
			}

			[[nodiscard]] constexpr bool wildcard(char a_ch) noexcept
			{
				return a_ch == '?';
			}
		}

		namespace rules
		{
			namespace detail
			{
				[[nodiscard]] consteval std::byte hexacharacters_to_hexadecimal(char a_hi, char a_lo) noexcept
				{
					constexpr auto lut = []() noexcept {
						std::array<std::uint8_t, std::numeric_limits<unsigned char>::max() + 1> a = {};

						const auto iterate = [&](std::uint8_t a_iFirst, unsigned char a_cFirst, unsigned char a_cLast) noexcept {
							for (; a_cFirst <= a_cLast; ++a_cFirst, ++a_iFirst) {
								a[a_cFirst] = a_iFirst;
							}
						};

						iterate(0, '0', '9');
						iterate(0xA, 'A', 'F');
						iterate(0xa, 'a', 'f');

						return a;
					}();

					return static_cast<std::byte>(
						lut[static_cast<unsigned char>(a_hi)] * 0x10u +
						lut[static_cast<unsigned char>(a_lo)]);
				}
			}

			template <char HI, char LO>
			class Hexadecimal
			{
			public:
				[[nodiscard]] static constexpr bool match(std::byte a_byte) noexcept
				{
					constexpr auto expected = detail::hexacharacters_to_hexadecimal(HI, LO);
					return a_byte == expected;
				}
			};

			static_assert(Hexadecimal<'5', '7'>::match(std::byte{ 0x57 }));
			static_assert(Hexadecimal<'6', '5'>::match(std::byte{ 0x65 }));
			static_assert(Hexadecimal<'B', 'D'>::match(std::byte{ 0xBD }));
			static_assert(Hexadecimal<'1', 'C'>::match(std::byte{ 0x1C }));
			static_assert(Hexadecimal<'F', '2'>::match(std::byte{ 0xF2 }));
			static_assert(Hexadecimal<'9', 'f'>::match(std::byte{ 0x9f }));

			static_assert(!Hexadecimal<'D', '4'>::match(std::byte{ 0xF8 }));
			static_assert(!Hexadecimal<'6', '7'>::match(std::byte{ 0xAA }));
			static_assert(!Hexadecimal<'7', '8'>::match(std::byte{ 0xE3 }));
			static_assert(!Hexadecimal<'6', 'E'>::match(std::byte{ 0x61 }));

			class Wildcard
			{
			public:
				[[nodiscard]] static constexpr bool match(std::byte) noexcept
				{
					return true;
				}
			};

			static_assert(Wildcard::match(std::byte{ 0xB9 }));
			static_assert(Wildcard::match(std::byte{ 0x96 }));
			static_assert(Wildcard::match(std::byte{ 0x35 }));
			static_assert(Wildcard::match(std::byte{ 0xE4 }));

			template <char, char>
			void rule_for() noexcept;

			template <char C1, char C2>
			Hexadecimal<C1, C2> rule_for() noexcept
				requires(characters::hexadecimal(C1) && characters::hexadecimal(C2));

			template <char C1, char C2>
			Wildcard rule_for() noexcept
				requires(characters::wildcard(C1) && characters::wildcard(C2));
		}

		template <class... Rules>
		class PatternMatcher
		{
		public:
			static_assert(sizeof...(Rules) >= 1, "must provide at least 1 rule for the pattern matcher");

			[[nodiscard]] constexpr bool match(std::span<const std::byte, sizeof...(Rules)> a_bytes) const noexcept
			{
				std::size_t i = 0;
				return (Rules::match(a_bytes[i++]) && ...);
			}

			[[nodiscard]] bool match(std::uintptr_t a_address) const noexcept
			{
				return this->match(*reinterpret_cast<const std::byte(*)[sizeof...(Rules)]>(a_address));
			}

			void match_or_fail(std::uintptr_t a_address, std::source_location a_loc = std::source_location::current()) const noexcept
			{
				if (!this->match(a_address)) {
					const auto version = Module::get().version();
					stl::report_and_fail(
						fmt::format(
							"A pattern has failed to match.\n"
							"This means the plugin is incompatible with the current version of the game ({}.{}.{}). "
							"Head to the mod page of this plugin to see if an update is available."sv,
							version[0],
							version[1],
							version[2]),
						a_loc);
				}
			}
		};

		void consteval_error(const char* a_error);

		template <stl::nttp::string S, class... Rules>
		[[nodiscard]] constexpr auto do_make_pattern() noexcept
		{
			if constexpr (S.length() == 0) {
				return PatternMatcher<Rules...>();
			} else if constexpr (S.length() == 1) {
				constexpr char c = S[0];
				if constexpr (characters::hexadecimal(c) || characters::wildcard(c)) {
					consteval_error("the given pattern has an unpaired rule (rules are required to be written in pairs of 2)");
				} else {
					consteval_error("the given pattern has trailing characters at the end (which is not allowed)");
				}
			} else {
				using rule_t = decltype(rules::rule_for<S[0], S[1]>());
				if constexpr (std::same_as<rule_t, void>) {
					consteval_error("the given pattern failed to match any known rules");
				} else {
					if constexpr (S.length() <= 3) {
						return do_make_pattern<S.template substr<2>(), Rules..., rule_t>();
					} else if constexpr (characters::space(S[2])) {
						return do_make_pattern<S.template substr<3>(), Rules..., rule_t>();
					} else {
						consteval_error("a space character is required to split byte patterns");
					}
				}
			}
		}

		template <class... Bytes>
		[[nodiscard]] consteval auto make_byte_array(Bytes... a_bytes) noexcept
			-> std::array<std::byte, sizeof...(Bytes)>
		{
			static_assert((std::integral<Bytes> && ...), "all bytes must be an integral type");
			return { static_cast<std::byte>(a_bytes)... };
		}
	}

	template <stl::nttp::string S>
	[[nodiscard]] constexpr auto make_pattern() noexcept
	{
		return detail::do_make_pattern<S>();
	}

	static_assert(make_pattern<"40 10 F2 ??">().match(
		detail::make_byte_array(0x40, 0x10, 0xF2, 0x41)));
	static_assert(make_pattern<"B8 D0 ?? ?? D4 6E">().match(
		detail::make_byte_array(0xB8, 0xD0, 0x35, 0x2A, 0xD4, 0x6E)));

	/**
	 * Selects a proper <code>REL::ID</code> based on the current Skyrim runtime.
	 *
	 * <p>
	 * Skyrim SE and Skyrim AE have different databases of address library IDs. Using this function
	 * allows both to be provided, letting the compiled code dynamically select at runtime which is
	 * correct to use. This lets a single SKSE plugin target multiple versions of Skyrim.
	 * </p>
	 *
	 * <p>
	 * The Address Library for Skyrim VR reuses the same IDs as SE, so usually no VR alternative is
	 * required. However, the SE ID must be manually mapped to a VR offset in the VR Adress Library
	 * database. To support VR, you must verify that the ID is already mapped or map it yourself and
	 * submit a PR upstream to add the changes.
	 * </p>
	 *
	 * @param seAndVR the ID to use for Skyrim SE and VR.
	 * @param ae the ID to sue for Skyrim AE.
	 * @return The correct ID based on the currently running Skyrim executable.
	 */
	[[nodiscard]] inline REL::ID RelocationID(uint64_t seAndVR, uint64_t ae) noexcept
	{
		return REL::ID(Module::get().IsAE() ? ae : seAndVR);
	}

	/**
	 * Selects a proper <code>REL::ID</code> based on the current Skyrim runtime.
	 *
	 * <p>
	 * Skyrim SE and Skyrim AE have different databases of address library IDs. Using this function
	 * allows both to be provided, letting the compiled code dynamically select at runtime which is
	 * correct to use. This lets a single SKSE plugin target multiple versions of Skyrim.
	 * </p>
	 *
	 * <p>
	 * The Address Library for Skyrim VR reuses the same IDs as SE, however sometimes VR can be fundamentally
	 * different and needs to hook a different function entirely. Hence this overload allows selecting a
	 * different VR ID.
	 * </p>
	 *
	 * @param se the ID to use for Skyrim SE.
	 * @param ae the ID to use for Skyrim AE.
	 * @param vr the ID To use for Skyrim VR.
	 * @return the correct ID for the current runtime of Skyrim.
	 */
	[[nodiscard]] inline REL::ID RelocationID(std::uint64_t se, std::uint64_t ae, std::uint64_t vr) noexcept
	{
		switch (Module::get().GetRuntime()) {
		case Module::Runtime::AE:
			return REL::ID(ae);
		case Module::Runtime::VR:
			return REL::ID(vr);
		default:
			return REL::ID(se);
		}
	}

	/**
	 * Return the correct value of two choices between SE/VR, and AE versions of Skyrim.
	 *
	 * <p>
	 * This is commonly used to select between relative offsets within a function, when hooking a call instruction.
	 * In such cases the function can be identified by its Address Library ID, but the offset within the function
	 * may vary between Skyrim versions. This selection is made at runtime, allowing the same compiled code to run
	 * in multiple versions of Skyrim.
	 * </p>
	 *
	 * @tparam T the type of value to return.
	 * @param seAndVR the value to use for SE and VR.
	 * @param ae the value to use for AE.
	 * @return Either <code>seAndVR</code> if the current runtime is Skyrim SE or VR, or <code>ae</code> if the runtime is AE.
	 */
	template <class T>
	[[nodiscard]] inline T Relocate(T&& seAndVR, T&& ae) noexcept
	{
		return Module::get().IsAE() ? ae : seAndVR;
	}

	/**
	 * Return the correct value of two choices between SE, AE, and VR versions of Skyrim.
	 *
	 * <p>
	 * This is commonly used to select between relative offsets within a function, when hooking a call instruction.
	 * In such cases the function can be identified by its Address Library ID, but the offset within the function
	 * may vary between Skyrim versions. This selection is made at runtime, allowing the same compiled code to run
	 * in multiple versions of Skyrim.
	 * </p>
	 *
	 * @tparam T the type of value to return.
	 * @param se the value to use for SE.
	 * @param ae the value to use for AE.
	 * @param vr the value to use for VR.
	 * @return Either <code>se</code> if the current runtime is Skyrim SE, or <code>ae</code> if the runtime is AE, or
	 * <code>vr</code> if running Skyrim VR.
	 */
	template <class T>
	[[nodiscard]] inline T Relocate(T se, T ae, T vr) noexcept
	{
		switch (Module::get().GetRuntime()) {
		case Module::Runtime::AE:
			return ae;
		case Module::Runtime::VR:
			return vr;
		default:
			return se;
		}
	}

	namespace detail
	{
		template <class T>
		struct RelocateVirtualHelper
		{
		};

		template <class Ret, class This>
		struct RelocateVirtualHelper<Ret(This*)>
		{
			using this_type = This;
			using return_type = Ret;
			using function_type = Ret(This*);
		};

		template <class Ret, class This, class... Args>
		struct RelocateVirtualHelper<Ret(This*, Args...)>
		{
			using this_type = This;
			using return_type = Ret;
			using function_type = Ret(This*, Args...);
		};

		template <class Ret, class This>
		struct RelocateVirtualHelper<Ret(This::*)()>
		{
			using this_type = This;
			using return_type = Ret;
			using function_type = Ret(This*);
		};

		template <class Ret, class This, class... Args>
		struct RelocateVirtualHelper<Ret(This::*)(Args...)>
		{
			using this_type = This;
			using return_type = Ret;
			using function_type = Ret(This*, Args...);
		};

		template <class Ret, class This>
		struct RelocateVirtualHelper<Ret(This::*)() const>
		{
			using this_type = const This;
			using return_type = Ret;
			using function_type = Ret(const This*);
		};

		template <class Ret, class This, class... Args>
		struct RelocateVirtualHelper<Ret(This::*)(Args...) const>
		{
			using this_type = const This;
			using return_type = Ret;
			using function_type = Ret(const This*, Args...);
		};
	}

	/**
	 * Invokes a virtual function in a cross-platform way where the vtable structure is variant across AE/SE and VR runtimes.
	 *
	 * <p>
	 * Some classes in Skyrim VR add new virtual functions in the middle of the vtable structure, which makes it ABI-incompatible with AE/SE.
	 * A naive virtual function call, therefore, cannot work across all runtimes without the plugin being recompiled specifically for VR.
	 * This call works with types which have variant vtables to allow a non-virtual function definition to be created in the virtual function's
	 * place, and to have that call dynamically lookup the correct function based on the vtable structure expected in the current runtime.
	 * </p>
	 *
	 * @tparam Fn the type of the function being called.
	 * @tparam Args the types of the arguments being passed.
	 * @param seAndAEVtableIndex the index of the function in the class' vtable in SE and AE.
	 * @param vrVtableIndex the index of the function in the class' vtable in VR.
	 * @param self the <code>this</code> argument for the call.
	 * @param args the remaining arguments for the call, if any.
	 * @return The result of the function call.
	 */
	template <class Fn, class... Args>
	[[nodiscard]] inline typename detail::RelocateVirtualHelper<Fn>::return_type RelocateVirtual(
		std::ptrdiff_t seAndAEVtableIndex, std::ptrdiff_t vrVtableIndex,
		typename detail::RelocateVirtualHelper<Fn>::this_type* self, Args&&... args)
	{
		return (*reinterpret_cast<typename detail::RelocateVirtualHelper<Fn>::function_type**>(
			*reinterpret_cast<const uintptr_t*>(self) + (Module::get().IsVR() ? vrVtableIndex : seAndAEVtableIndex) *
													  sizeof(uintptr_t)))(self, std::forward<Args>(args)...);
	}

	/**
	 * Gets a member variable in a cross-platform way, using runtime-specific memory offsets.
	 *
	 * <p>
	 * This function handles the variant memory structures used in Skyrim VR as compared to versions of SE.
	 * It allows a memory offset relative to the object's base address for SE (and AE) and a separate one for
	 * VR. This simplifies the process of creating functions to get member variables that are at different
	 * offsets in different runtimes from a single build.
	 * </p>
	 *
	 * @tparam T the type of the member being accessed.
	 * @tparam This the type of the target object that has the member.
	 * @param self the target object that has the member.
	 * @param seAndAE the memory offset of the member in Skyrim SE and AE.
	 * @param vr the memory offset of the member in Skyrim VR.
	 * @return A reference to the member.
	 */
	template <class T, class This>
	[[nodiscard]] inline T& RelocateMember(This* self, ptrdiff_t seAndAE, ptrdiff_t vr) {
		return *reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(self) + Relocate(seAndAE, seAndAE, vr));
	}
}

#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL

#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL
