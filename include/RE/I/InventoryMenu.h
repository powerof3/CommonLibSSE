#pragma once

#include "RE/B/BSTArray.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class GFxMovieView;
	class TESObjectREFR;
	struct BottomBar;
	struct ItemCard;
	struct ItemList;

	// menuDepth = 0
	// flags = kPausesGame | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kNone
	class InventoryMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_InventoryMenu;
		inline static constexpr auto      VTABLE = VTABLE_InventoryMenu;
		constexpr static std::string_view MENU_NAME = "InventoryMenu";

		~InventoryMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04
		void               PostDisplay() override;                           // 06

		// Rebuilds the Scaleform item list from the player's inventory and invalidates
		// the list data. Call only from the game/UI thread while this menu is open.
		void RefreshItemList()
		{
			using func_t = decltype(&InventoryMenu::RefreshItemList);
			static REL::Relocation<func_t> func{ RELOCATION_ID(50987, 51866) };
			return func(this);
		}

		// Updates the inventory menu's bottom-bar state and its Scaleform bindings.
		void RefreshBottomBar()
		{
			using func_t = decltype(&InventoryMenu::RefreshBottomBar);
			static REL::Relocation<func_t> func{ RELOCATION_ID(50986, 51865) };
			return func(this);
		}

		// members
		GFxValue        root;             // 30 - kDisplayObject - "_level0.Menu_mc"
		ItemList*       itemList;         // 48
		ItemCard*       itemCard;         // 50
		BottomBar*      bottomBar;        // 58
		BSTArray<void*> unk60;            // 60
		std::uint8_t    unk78;            // 78
		std::uint8_t    pad79;            // 79
		std::uint16_t   pad7A;            // 7A
		std::uint32_t   unk7C;            // 7C
		bool            pcControlsReady;  // 80
		std::uint8_t    unk81;            // 81
		std::uint16_t   pad82;            // 82
		std::uint32_t   pad84;            // 84
	};
	static_assert(sizeof(InventoryMenu) == 0x88);
}
