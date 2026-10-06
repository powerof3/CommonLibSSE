#pragma once

#include "RE/C/CombatBehaviorTreeNodeObjectBase.h"

namespace RE
{
	template <class T>
	struct CBTraits;

#define REGISTER_COMBAT_BEHAVIOR(Type)                                                       \
	template <>                                                                              \
	struct CBTraits<Type>                                                                    \
	{                                                                                        \
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeNodeObject_##Type##_;     \
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeNodeObject_##Type##_; \
	};

	class CombatBehaviorAdvance;
	class CombatBehaviorAttackFromCover;
	class CombatBehaviorAttackLow;
	class CombatBehaviorAttack;
	class CombatBehaviorBackoff;
	class CombatBehaviorBash;
	class CombatBehaviorBlockAttack;
	class CombatBehaviorBlock;
	class CombatBehaviorCastConcentrationSpell;
	class CombatBehaviorCastImmediateSpell;
	class CombatBehaviorCastShout;
	class CombatBehaviorChase;
	class CombatBehaviorCheckUnreachableTarget;
	class CombatBehaviorCircleDistant;
	class CombatBehaviorCircle;
	class CombatBehaviorDiveBomb;
	class CombatBehaviorDodgeThreat;
	class CombatBehaviorDrinkPotion;
	class CombatBehaviorDynamicConditionalNode;
	class CombatBehaviorEquipObject;
	class CombatBehaviorEquipRangedWeapon;
	class CombatBehaviorEquipShout;
	class CombatBehaviorEquipSpell;
	class CombatBehaviorExitWater;
	class CombatBehaviorFallbackToRanged;
	class CombatBehaviorFallback;
	class CombatBehaviorFindAllyAttackLocation;
	class CombatBehaviorFindAttackLocation;
	class CombatBehaviorFindCover;
	class CombatBehaviorFindLateralAttackLocation;
	class CombatBehaviorFindWeapon;
	class CombatBehaviorFlankDistant;
	class CombatBehaviorFlank;
	class CombatBehaviorFleeThroughDoor;
	class CombatBehaviorFleeToAlly;
	class CombatBehaviorFleeToCover;
	class CombatBehaviorFlee;
	class CombatBehaviorFlyingAttack;
	class CombatBehaviorForceFail;
	class CombatBehaviorForceSuccess;
	class CombatBehaviorGroundAttack;
	class CombatBehaviorHide;
	class CombatBehaviorHover;
	class CombatBehaviorLand;
	class CombatBehaviorMaintainOptimalRange;
	class CombatBehaviorOrbitDistant;
	class CombatBehaviorOrbit;
	class CombatBehaviorParallel;
	class CombatBehaviorPause;
	class CombatBehaviorPerchAttack;
	class CombatBehaviorPrepareDualCast;
	class CombatBehaviorPursueTarget;
	class CombatBehaviorRangedAttack;
	class CombatBehaviorRepeat;
	class CombatBehaviorReposition;
	class CombatBehaviorReturnToCombatArea;
	class CombatBehaviorSearchInvestigateDoor;
	class CombatBehaviorSequence;
	class CombatBehaviorSpecialAttack;
	class CombatBehaviorStalk;
	class CombatBehaviorStrafe;
	class CombatBehaviorSurround;
	class CombatBehaviorTakeoff;
	class CombatBehaviorTrackTarget;
	class CombatBehaviorWaitBehindCover;

	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorAdvance);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorAttackFromCover);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorAttackLow);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorBackoff);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorBash);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorBlockAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorBlock);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCastConcentrationSpell);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCastImmediateSpell);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCastShout);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorChase);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCheckUnreachableTarget);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCircleDistant);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorCircle);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorDiveBomb);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorDodgeThreat);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorDrinkPotion);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorDynamicConditionalNode);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorEquipObject);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorEquipRangedWeapon);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorEquipShout);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorEquipSpell);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorExitWater);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFallbackToRanged);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFallback);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFindAllyAttackLocation);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFindAttackLocation);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFindCover);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFindLateralAttackLocation);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFindWeapon);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFlankDistant);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFlank);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFleeThroughDoor);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFleeToAlly);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFleeToCover);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFlee);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorFlyingAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorForceFail);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorForceSuccess);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorGroundAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorHide);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorHover);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorLand);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorMaintainOptimalRange);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorOrbitDistant);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorOrbit);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorParallel);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorPause);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorPerchAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorPrepareDualCast);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorPursueTarget);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorRangedAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorRepeat);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorReposition);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorReturnToCombatArea);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorSearchInvestigateDoor);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorSequence);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorSpecialAttack);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorStalk);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorStrafe);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorSurround);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorTakeoff);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorTrackTarget);
	REGISTER_COMBAT_BEHAVIOR(CombatBehaviorWaitBehindCover);

	template <class T>
	class CombatBehaviorTreeNodeObject : public CombatBehaviorTreeNodeObjectBase<T>
	{
	public:
		inline static constexpr auto RTTI = CBTraits<T>::RTTI;
		inline static constexpr auto VTABLE = CBTraits<T>::VTABLE;

		~CombatBehaviorTreeNodeObject() override = default;  // 00

		// override (CombatBehaviorTreeNodeObjectBase<T>)
		void Enter(CombatBehaviorThread* a_thread) override;  // 02

		static CombatBehaviorTreeNodeObject<T>* CreateObject()
		{
			static_assert(sizeof(CombatBehaviorTreeNodeObject<T>) == 0x28);
			auto obj = malloc<CombatBehaviorTreeNodeObject<T>>();
			if (obj) {
				std::memset(obj, 0, sizeof(CombatBehaviorTreeNodeObject<T>));
				obj->Ctor();  // CombatBehaviorTreeNode::Ctor
				REX::EMPLACE_VTABLE(obj);
			}
			return obj;
		}
	};
}
