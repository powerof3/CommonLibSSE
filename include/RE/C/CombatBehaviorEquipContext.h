#pragma once

#include "RE/C/CombatInventoryItem.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatBehaviorEquipContext
	{
	public:
		bool                                  CheckEquipmentChanged();
		bool                                  EquipItem();
		NiPointer<CombatInventoryItem> const& GetCombatItem() const;

		// members
		uint32_t             slot;         // 00
		uint32_t             pad_4;        // 04
		CombatInventoryItem* combat_item;  // 08
		bool                 dirty;        // 10
		char                 pad_11[7];    // 11
	};
	static_assert(sizeof(CombatBehaviorEquipContext) == 0x18);
}
