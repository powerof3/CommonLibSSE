#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 3
	// flags = kAlwaysOpen | kAllowSaving | kCustomRendering
	// context = kNone
	class FaderMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_FaderMenu;
		inline static constexpr auto      VTABLE = VTABLE_FaderMenu;
		constexpr static std::string_view MENU_NAME = "Fader Menu";

		virtual ~FaderMenu();  // 00

		// override (IMenu)
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void                       AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// members
		void*         unk30;     // 30 - smart ptr
		bool          isActive;  // 38
		bool          unk39;     // 39
		std::uint16_t pad3A;     // 3A
		std::uint32_t pad3C;     // 3C
	};
	static_assert(sizeof(FaderMenu) == 0x40);
}
