#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatState.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatAimController;
	class CombatAreaStandard;
	class CombatBehaviorController;
	class CombatBlackboard;
	class CombatGroup;
	class CombatInventory;
	class CombatTargetSelectorStandard;
	class CombatState;
	class TESCombatStyle;

	class CombatController
	{
	public:
		[[nodiscard]] bool IsFleeing() const
		{
			return state->isFleeing;
		}

		// members
		CombatGroup*                   combatGroup;           // 00
		CombatState*                   state;                 // 08
		CombatInventory*               inventory;             // 10
		CombatBlackboard*              blackboard;            // 18
		CombatBehaviorController*      behaviorController;    // 20
		ActorHandle                    attackerHandle;        // 28
		ActorHandle                    targetHandle;          // 2C
		ActorHandle                    previousTargetHandle;  // 30
		std::uint8_t                   unk34;                 // 34
		bool                           startedCombat;         // 35
		std::uint8_t                   unk36;                 // 36
		std::uint8_t                   unk37;                 // 37
		TESCombatStyle*                combatStyle;           // 38
		bool                           stoppedCombat;         // 40
		bool                           unk41;                 // 41 - isbeingMeleeAttacked?
		bool                           ignoringCombat;        // 42
		bool                           inactive;              // 43
		AITimer                        unk44;                 // 44
		float                          lowMovementDelta;      // 4C
		BSTArray<CombatAimController*> aimControllers;        // 50
#ifdef SKYRIM_SUPPORT_AE
		mutable BSSpinLock aimControllerLock;  // 68
#endif
		CombatAimController*                    currentAimController;    // 68
		CombatAimController*                    previousAimController;   // 70
		BSTArray<CombatAreaStandard*>           areas;                   // 78
		CombatAreaStandard*                     currentArea;             // 90
		BSTArray<CombatTargetSelectorStandard*> targetSelectors;         // 98
		CombatTargetSelectorStandard*           currentTargetSelector;   // B0
		CombatTargetSelectorStandard*           previousTargetSelector;  // B8
		std::uint32_t                           handleCount;             // C0
		std::int32_t                            unkC4;                   // C4
		NiPointer<Actor>                        cachedAttacker;          // C8 - attackerHandle
		NiPointer<Actor>                        cachedTarget;            // D0 - targetHandle
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(CombatController) == 0xD8);
#else
	static_assert(sizeof(CombatController) == 0xE0);
#endif
}
