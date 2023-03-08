#include "RE/E/EnchantConstructMenu.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		void EnchantConstructMenu::RenameItem(const char* a_name)
		{
			if (craftItemPreview) {
				customName = a_name;
				RenameItem_Impl(craftItemPreview, nullptr, a_name);
			}
		}

		void EnchantConstructMenu::RenameItem_Impl(InventoryEntryData* a_entryData, ExtraDataList* a_extraList, const char* a_name)
		{
			using func_t = decltype(&EnchantConstructMenu::RenameItem_Impl);
			REL::Relocation<func_t> func{ Offset::CraftingSubMenus::EnchantConstructMenu::RenameItem };
			return func(this, a_entryData, a_extraList, a_name);
		}

		void EnchantConstructMenu::UpdateInterface()
		{
			using func_t = decltype(&EnchantConstructMenu::UpdateInterface);
			REL::Relocation<func_t> func{ Offset::CraftingSubMenus::EnchantConstructMenu::UpdateInterface };
			return func(this);
		}
	}
}
