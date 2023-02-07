#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class BGSLocation;
	class TESLoadScreen;

	// menuDepth = 9
	// flags = kPausesGame | kAlwaysOpen | kAllowSaving | kApplicationMenu
	// context = kNone
	class LoadingMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_LoadingMenu;
		inline static constexpr auto      VTABLE = VTABLE_LoadingMenu;
		constexpr static std::string_view MENU_NAME = "Loading Menu";

		~LoadingMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

		// members
		GFxValue                 root;             // 30 - "Menu_mc"
		BGSLocation*             currentLocation;  // 48
		bool                     unk50;            // 50
		bool                     unk51;            // 51
		std::uint16_t            pad52;            // 52
		std::uint32_t            pad54;            // 54
		BSTArray<TESLoadScreen*> loadScreens;      // 58
		std::uint32_t            unk70;            // 70
		std::uint32_t            pad74;            // 74
		std::uint64_t            unk78;            // 78
	};
	static_assert(sizeof(LoadingMenu) == 0x80);
}
