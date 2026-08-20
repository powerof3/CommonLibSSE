#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"

namespace RE
{
	class Actor;
	class CombatBehaviorResource;
	class CombatBehaviorThread;
	class CombatController;
	class CombatGroup;
	class CombatInventory;
	class CombatState;

	class CombatBehaviorController
	{
	public:
		static Actor*            GetCurrentAttacker();
		static CombatController* GetCurrentCombatController();
		static CombatGroup*      GetCurrentCombatGroup();
		static CombatInventory*  GetCurrentCombatInventory();
		static CombatState*      GetCurrentCombatState();

		// members
		CombatBehaviorThread*                              defaultThread;     // 00
		BSTArray<CombatBehaviorThread*>                    activeThreads;     // 08
		CombatController*                                  combatController;  // 20
		BSTHashMap<BSFixedString, CombatBehaviorResource*> resources;         // 28
		BSTArray<CombatBehaviorThread*>                    queued;            // 58
		std::uint32_t                                      nextThreadID;      // 70
		std::uint32_t                                      pad74;             // 74
	};
	static_assert(sizeof(CombatBehaviorController) == 0x78);
}
