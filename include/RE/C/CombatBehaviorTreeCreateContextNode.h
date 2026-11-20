#pragma once

#include "RE/C/CombatBehaviorTreeCreateContextNodeBase.h"

namespace RE
{
	template <class T>
	struct CBTCCNTraits;

#define REGISTER_CBTCCN(Type)                                                                       \
	class Type;                                                                                     \
	template <>                                                                                     \
	struct CBTCCNTraits<Type>                                                                       \
	{                                                                                               \
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeCreateContextNode_##Type##_;     \
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeCreateContextNode_##Type##_; \
	};

	REGISTER_CBTCCN(CombatBehaviorContextAcquireWeapon)
	REGISTER_CBTCCN(CombatBehaviorContextCloseMovement)
	REGISTER_CBTCCN(CombatBehaviorContextCover)
	REGISTER_CBTCCN(CombatBehaviorContextDodgeThreat)
	REGISTER_CBTCCN(CombatBehaviorContextFindAttackLocation)
	REGISTER_CBTCCN(CombatBehaviorContextFlankingMovement)
	REGISTER_CBTCCN(CombatBehaviorContextFlee)
	REGISTER_CBTCCN(CombatBehaviorContextHide)
	REGISTER_CBTCCN(CombatBehaviorContextRangedMovement)
	REGISTER_CBTCCN(CombatBehaviorContextSearch)
#undef REGISTER_CBTCCN

	template <class T>
	class CombatBehaviorTreeCreateContextNode : public CombatBehaviorTreeCreateContextNodeBase<T>
	{
	public:
		inline static constexpr auto RTTI = CBTCCNTraits<T>::RTTI;
		inline static constexpr auto VTABLE = CBTCCNTraits<T>::VTABLE;

		~CombatBehaviorTreeCreateContextNode() override = default;  // 00

		// override (CombatBehaviorTreeNode)
		void Enter(CombatBehaviorThread* a_thread) override;  // 02

		static CombatBehaviorTreeCreateContextNode<T>* CreateContext()
		{
			static_assert(sizeof(CombatBehaviorTreeCreateContextNode<T>) == 0x28);
			auto obj = malloc<CombatBehaviorTreeCreateContextNode<T>>();
			if (obj) {
				std::memset(obj, 0, sizeof(CombatBehaviorTreeCreateContextNode<T>));
				obj->Ctor();  // CombatBehaviorTreeNode::Ctor
				REX::EMPLACE_VTABLE(obj);
			}
			return obj;
		}
	};
}
