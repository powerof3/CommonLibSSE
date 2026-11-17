#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/A/AITimer.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSAttackData;
	class CombatMeleeAimController;

	class CombatBehaviorContextMelee
	{
	public:
		enum class ATTACK_TYPE : std::uint32_t
		{
			kWeaponRight,
			kShield,
			kWeaponLeft
		};

		struct CombatAttackData
		{
		public:
			BGSAttackData* attackData;         // 00
			NiPoint3       attackVector;       // 08
			NiPoint3       attackTranslation;  // 14
			float          attackDistance;     // 20
			float          attackTime;         // 24
			AITimer        recoveryTimer;      // 28
		};
		static_assert(sizeof(CombatAttackData) == 0x30);

		// members
		float                               reach;               // 00
		ATTACK_TYPE                         attackType;          // 04
		AITimeStamp                         finishedAttackTime;  // 08
		std::uint32_t                       unk0C;               // 0C
		std::uint64_t                       unk10;               // 10
		BSTArray<CombatAttackData>          attackData;          // 18
		float                               unk30;               // 30
		float                               speedMult;           // 34
		NiPointer<CombatMeleeAimController> aimController;       // 38
	};
	static_assert(sizeof(CombatBehaviorContextMelee) == 0x40);
}
