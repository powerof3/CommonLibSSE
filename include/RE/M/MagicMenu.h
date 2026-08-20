#pragma once

#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	struct BottomBar;
	struct ItemCard;
	struct MagicItemList;

	// menuDepth = 0
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class MagicMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_MagicMenu;
		inline static constexpr auto      VTABLE = VTABLE_MagicMenu;
		constexpr static std::string_view MENU_NAME = "MagicMenu";

		~MagicMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04
		void               PostDisplay() override;                           // 06

		// members
		MagicItemList* itemList;         // 30
		ItemCard*      itemCard;         // 38
		BottomBar*     bottomBar;        // 40
		GFxValue       root;             // 48 - "Menu_mc"
		bool           pcControlsReady;  // 60
		std::uint8_t   pad61;            // 61
		std::uint16_t  pad62;            // 62
		std::uint32_t  pad64;            // 64
	};
	static_assert(sizeof(MagicMenu) == 0x68);
}
