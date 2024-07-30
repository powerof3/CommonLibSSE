#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class CraftingSubMenu;
	}

	// menuDepth = 0
	// flags = kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kDontHideCursorWhenTopmost
	// context = kItemMenu
	class CraftingMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_CraftingMenu;
		inline static constexpr auto      VTABLE = VTABLE_CraftingMenu;
		constexpr static std::string_view MENU_NAME = "Crafting Menu";

		~CraftingMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               PostDisplay() override;                                                // 06

		static void QuitMenu()
		{
			using func_t = decltype(&CraftingMenu::QuitMenu);
			static REL::Relocation<func_t> func{ RELOCATION_ID(50447, 51352) };
			return func();
		}

		// members
		CraftingSubMenus::CraftingSubMenu* subMenu;  // 30
	};
	static_assert(sizeof(CraftingMenu) == 0x38);
}
