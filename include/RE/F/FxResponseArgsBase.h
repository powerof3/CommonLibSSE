#pragma once

namespace RE
{
	class GFxValue;

	class FxResponseArgsBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_FxResponseArgsBase;
		inline static constexpr auto VTABLE = VTABLE_FxResponseArgsBase;

		FxResponseArgsBase() = default;
		FxResponseArgsBase(const FxResponseArgsBase&) = default;
		FxResponseArgsBase(FxResponseArgsBase&&) = default;

		virtual ~FxResponseArgsBase() = default;  // 00

		FxResponseArgsBase& operator=(const FxResponseArgsBase&) = default;
		FxResponseArgsBase& operator=(FxResponseArgsBase&&) = default;

		// add
		virtual std::uint32_t GetValues(GFxValue** a_params) = 0;  // 01
	};
	static_assert(sizeof(FxResponseArgsBase) == 0x8);
}
