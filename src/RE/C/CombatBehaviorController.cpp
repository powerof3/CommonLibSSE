#include "RE/C/CombatBehaviorController.h"

namespace RE
{
	Actor* CombatBehaviorController::GetCurrentAttacker()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentAttacker);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46114, 47379) };
		return func();
	}

	CombatController* CombatBehaviorController::GetCurrentCombatController()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatController);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46113, 47378) };
		return func();
	}

	CombatGroup* CombatBehaviorController::GetCurrentCombatGroup()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatGroup);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46112, 47377) };
		return func();
	}

	CombatInventory* CombatBehaviorController::GetCurrentCombatInventory()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatInventory);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46111, 47376) };
		return func();
	}

	CombatState* CombatBehaviorController::GetCurrentCombatState()
	{
		using func_t = decltype(&CombatBehaviorController::GetCurrentCombatState);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46110, 47375) };
		return func();
	}
}
