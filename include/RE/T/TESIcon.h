#pragma once

#include "RE/T/TESTexture.h"

namespace RE
{
	class TESIcon : public TESTexture
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESIcon;
		inline static constexpr auto VTABLE = VTABLE_TESIcon;

		~TESIcon() override;  // 00

		// override (TESTexture)
		[[nodiscard]] const char* GetDefaultPath() const override;  // 06 - { return "Textures"; }
	};
	static_assert(sizeof(TESIcon) == 0x10);
}
