#pragma once

#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 4
	// flags = kPausesGame | kRequiresUpdate | kAllowSaving | kApplicationMenu
	// kUsesCursor if gamepad disabled
	// context = kMenuMode
	class SleepWaitMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_SleepWaitMenu;
		constexpr static std::string_view MENU_NAME = "Sleep/Wait Menu";

		~SleepWaitMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

		static void ToggleOpenSleepWaitMenu(bool a_sleeping)
		{
			using func_t = decltype(&SleepWaitMenu::ToggleOpenSleepWaitMenu);
			static REL::Relocation<func_t> func{ RELOCATION_ID(51618, 52490) };
			return func(a_sleeping);
		}

		// members
		std::uint32_t unk30;  // 30
		std::uint32_t pad34;  // 34
		GFxValue      root;   // 38 - "SleepWaitMenu_mc"
		std::uint8_t  unk50;  // 50
		std::uint8_t  unk51;  // 51
		std::uint16_t pad52;  // 52
		std::uint32_t pad54;  // 54
	};
	static_assert(sizeof(SleepWaitMenu) == 0x58);
}
