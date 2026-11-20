#pragma once

#include "RE/C/CombatBehaviorTreeNodeObjectBase.h"

namespace RE
{
	template <class T>
	struct CBTNOTraits;

#define REGISTER_CBTNO(Type)                                                                 \
	class Type;                                                                              \
	template <>                                                                              \
	struct CBTNOTraits<Type>                                                                 \
	{                                                                                        \
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeNodeObject_##Type##_;     \
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeNodeObject_##Type##_; \
	};

	REGISTER_CBTNO(CombatBehaviorAdvance)
	REGISTER_CBTNO(CombatBehaviorAttackFromCover)
	REGISTER_CBTNO(CombatBehaviorAttackLow)
	REGISTER_CBTNO(CombatBehaviorAttack)
	REGISTER_CBTNO(CombatBehaviorBackoff)
	REGISTER_CBTNO(CombatBehaviorBash)
	REGISTER_CBTNO(CombatBehaviorBlockAttack)
	REGISTER_CBTNO(CombatBehaviorBlock)
	REGISTER_CBTNO(CombatBehaviorCastConcentrationSpell)
	REGISTER_CBTNO(CombatBehaviorCastImmediateSpell)
	REGISTER_CBTNO(CombatBehaviorCastShout)
	REGISTER_CBTNO(CombatBehaviorChase)
	REGISTER_CBTNO(CombatBehaviorCheckUnreachableTarget)
	REGISTER_CBTNO(CombatBehaviorCircleDistant)
	REGISTER_CBTNO(CombatBehaviorCircle)
	REGISTER_CBTNO(CombatBehaviorDiveBomb)
	REGISTER_CBTNO(CombatBehaviorDodgeThreat)
	REGISTER_CBTNO(CombatBehaviorDrinkPotion)
	REGISTER_CBTNO(CombatBehaviorDynamicConditionalNode)
	REGISTER_CBTNO(CombatBehaviorEquipObject)
	REGISTER_CBTNO(CombatBehaviorEquipRangedWeapon)
	REGISTER_CBTNO(CombatBehaviorEquipShout)
	REGISTER_CBTNO(CombatBehaviorEquipSpell)
	REGISTER_CBTNO(CombatBehaviorExitWater)
	REGISTER_CBTNO(CombatBehaviorFallbackToRanged)
	REGISTER_CBTNO(CombatBehaviorFallback)
	REGISTER_CBTNO(CombatBehaviorFindAllyAttackLocation)
	REGISTER_CBTNO(CombatBehaviorFindAttackLocation)
	REGISTER_CBTNO(CombatBehaviorFindCover)
	REGISTER_CBTNO(CombatBehaviorFindLateralAttackLocation)
	REGISTER_CBTNO(CombatBehaviorFindWeapon)
	REGISTER_CBTNO(CombatBehaviorFlankDistant)
	REGISTER_CBTNO(CombatBehaviorFlank)
	REGISTER_CBTNO(CombatBehaviorFleeThroughDoor)
	REGISTER_CBTNO(CombatBehaviorFleeToAlly)
	REGISTER_CBTNO(CombatBehaviorFleeToCover)
	REGISTER_CBTNO(CombatBehaviorFlee)
	REGISTER_CBTNO(CombatBehaviorFlyingAttack)
	REGISTER_CBTNO(CombatBehaviorForceFail)
	REGISTER_CBTNO(CombatBehaviorForceSuccess)
	REGISTER_CBTNO(CombatBehaviorGroundAttack)
	REGISTER_CBTNO(CombatBehaviorHide)
	REGISTER_CBTNO(CombatBehaviorHover)
	REGISTER_CBTNO(CombatBehaviorLand)
	REGISTER_CBTNO(CombatBehaviorMaintainOptimalRange)
	REGISTER_CBTNO(CombatBehaviorOrbitDistant)
	REGISTER_CBTNO(CombatBehaviorOrbit)
	REGISTER_CBTNO(CombatBehaviorParallel)
	REGISTER_CBTNO(CombatBehaviorPause)
	REGISTER_CBTNO(CombatBehaviorPerchAttack)
	REGISTER_CBTNO(CombatBehaviorPrepareDualCast)
	REGISTER_CBTNO(CombatBehaviorPursueTarget)
	REGISTER_CBTNO(CombatBehaviorRangedAttack)
	REGISTER_CBTNO(CombatBehaviorRepeat)
	REGISTER_CBTNO(CombatBehaviorReposition)
	REGISTER_CBTNO(CombatBehaviorReturnToCombatArea)
	REGISTER_CBTNO(CombatBehaviorSearchInvestigateDoor)
	REGISTER_CBTNO(CombatBehaviorSequence)
	REGISTER_CBTNO(CombatBehaviorSpecialAttack)
	REGISTER_CBTNO(CombatBehaviorStalk)
	REGISTER_CBTNO(CombatBehaviorStrafe)
	REGISTER_CBTNO(CombatBehaviorSurround)
	REGISTER_CBTNO(CombatBehaviorTakeoff)
	REGISTER_CBTNO(CombatBehaviorTrackTarget)
	REGISTER_CBTNO(CombatBehaviorWaitBehindCover)
#undef REGISTER_CBTNO

	template <class T>
	class CombatBehaviorTreeNodeObject : public CombatBehaviorTreeNodeObjectBase<T>
	{
	public:
		inline static constexpr auto RTTI = CBTNOTraits<T>::RTTI;
		inline static constexpr auto VTABLE = CBTNOTraits<T>::VTABLE;

		~CombatBehaviorTreeNodeObject() override = default;  // 00

		// override (CombatBehaviorTreeNode)
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
