#include "RE/C/CombatBehaviorEquipContext.h"

namespace RE
{
	bool CombatBehaviorEquipContext::CheckEquipmentChanged()
	{
		using func_t = decltype(&CombatBehaviorEquipContext::CheckEquipmentChanged);
		REL::Relocation<func_t> func{ RELOCATION_ID(46951, 0) };  // I do not know for AE
		return func(this);
	}

	bool CombatBehaviorEquipContext::EquipItem()
	{
		using func_t = decltype(&CombatBehaviorEquipContext::EquipItem);
		REL::Relocation<func_t> func{ RELOCATION_ID(46952, 0) };  // I do not know for AE
		return func(this);
	}

	NiPointer<CombatInventoryItem> const& CombatBehaviorEquipContext::GetCombatItem() const
	{
		using func_t = decltype(&CombatBehaviorEquipContext::GetCombatItem);
		REL::Relocation<func_t> func{ RELOCATION_ID(32458, 0) };  // I do not know for AE
		return func(this);
	}
}
