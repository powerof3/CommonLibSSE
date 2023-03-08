#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CraftingSubMenu.h"
#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	namespace CraftingSubMenus
	{
		class AlchemyMenu : public CraftingSubMenu
		{
		public:
			inline static constexpr auto RTTI = RTTI_CraftingSubMenus__AlchemyMenu;

			class QuitMenuCallback : public IMessageBoxCallback
			{
			public:
				inline static constexpr auto RTTI = RTTI_CraftingSubMenus__AlchemyMenu__QuitMenuCallback;

				virtual ~QuitMenuCallback();  // 00

				// override (IMessageBoxCallback)
				void Run(Message a_msg) override;  // 01

				// members
				AlchemyMenu* subMenu;  // 10
			};
			static_assert(sizeof(QuitMenuCallback) == 0x18);

			class UsableEffectMap
			{
			public:
				std::uint32_t ingredientIndex;               // 00
				std::uint32_t effectIndex;                   // 04
				std::uint32_t nextCompatibleEffectMapIndex;  // 08
			};
			static_assert(sizeof(UsableEffectMap) == 0xC);

			class MenuIngredientEntry
			{
			public:
				InventoryEntryData* ingredient;       // 00
				std::uint8_t        effect1FilterID;  // 09
				std::uint8_t        effect2FilterID;  // 0A
				std::uint8_t        effect3FilterID;  // 0B
				std::uint8_t        effect4FilterID;  // 0C
				std::uint8_t        isSelected;       // 0D
				std::uint8_t        isNotGreyed;      // 0E
				std::uint16_t       padE;             // 0F
			};
			static_assert(sizeof(MenuIngredientEntry) == 0x10);

			class PotionCreationData
			{
			public:
				BSTArray<UsableEffectMap>      usableEffectsMaps;  // 0
				BSTArray<MenuIngredientEntry>* ingredientEntries;  // 18
			};
			static_assert(sizeof(PotionCreationData) == 0x20);

			~AlchemyMenu() override;  // 00

			// override (CraftingSubMenu)
			void Accept(CallbackProcessor* a_cbReg) override;          // 01
			bool ProcessUserEvent(BSFixedString* a_control) override;  // 05

			// members
			BSTArray<MenuIngredientEntry> ingredientEntries;      // 100
			BSTArray<void*>               unk118;                 // 118
			std::uint64_t                 unk130;                 // 130
			PotionCreationData            potionCreationData;     // 138
			GFxValue                      unk158;                 // 158
			std::uint64_t                 unk170;                 // 170
			TESForm*                      unk178;                 // 178
			TESForm*                      unk180;                 // 180
			std::uint64_t                 unk188;                 // 188
			BSFixedString                 newRecipeFormatString;  // 190
			std::uint64_t                 playerHasPurityPerk;    // 198
		};
		static_assert(sizeof(AlchemyMenu) == 0x1A0);
	}
}
