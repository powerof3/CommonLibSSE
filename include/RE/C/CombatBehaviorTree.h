#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatBehaviorContextMelee.h"
#include "RE/C/CombatBehaviorEquipContext.h"
#include "RE/C/CombatBehaviorThread.h"
#include "RE/C/CombatBehaviorTreeCreateContextNode.h"
#include "RE/C/CombatBehaviorTreeNode.h"

#define TES_COMBAT_CREATE_CONTEXT(T, SE, AE)                   \
	template <>                                                \
	CombatBehaviorTreeNode* CreateContext<T>()                 \
	{                                                          \
		using func_t = CombatBehaviorTreeNode*();              \
		REL::Relocation<func_t> func{ RELOCATION_ID(SE, AE) }; \
		return func();                                         \
	}

namespace RE
{
	class CombatBehaviorContextAcquireWeapon;
	class CombatBehaviorContextBlock;
	class CombatBehaviorContextCloseMovement;
	class CombatBehaviorContextCover;
	class CombatBehaviorContextDodgeThreat;
	class CombatBehaviorContextFindAttackLocation;
	class CombatBehaviorContextFlankingMovement;
	class CombatBehaviorContextFlee;
	class CombatBehaviorContextHide;
	class CombatBehaviorContextMagic;
	class CombatBehaviorContextRanged;
	class CombatBehaviorContextRangedMovement;
	class CombatBehaviorContextSearch;
	class CombatBehaviorContextShout;
	class CombatBehaviorContextUsePotion;

	class CombatBehaviorTree
	{
	public:
		class TreeBuilder
		{
		public:
			explicit TreeBuilder();
			CombatBehaviorTreeNode* GetNode();
			TreeBuilder&            operator[](const TreeBuilder& a_other);
			TreeBuilder&            operator,(const TreeBuilder& a_other);

			// members
			RE::BSTArray<CombatBehaviorTreeNode*> data;
		};
		static_assert(sizeof(TreeBuilder) == 0x18);

		static TreeBuilder AddNode(char* name, CombatBehaviorTreeNode* node);
		void               CreateTree(CombatBehaviorTreeNode* node);

		template <typename Context>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext()
		{
			return new CombatBehaviorTreeCreateContextNode<Context>();
		}

		template <typename Context>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext(auto arg);

		template <typename Context>
		[[nodiscard]] static CombatBehaviorTreeNode* CreateContext(auto arg1, auto arg2);

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextAcquireWeapon>()
		{
			return CreateContextNoInlined<46373, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextDodgeThreat>()
		{
			return CreateContextNoInlined<46599, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextCloseMovement>()
		{
			return CreateContextNoInlined<46753, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextFindAttackLocation>()
		{
			return CreateContextNoInlined<46985, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextFlankingMovement>()
		{
			return CreateContextNoInlined<47164, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextFlee>()
		{
			return CreateContextNoInlined<47449, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextHide>()
		{
			return CreateContextNoInlined<47450, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextRangedMovement>()
		{
			return CreateContextNoInlined<48484, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextSearch>()
		{
			return CreateContextNoInlined<48572, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextCover>()
		{
			return CreateContextNoInlined<48865, 0>();  // I do not know for AE
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextRanged>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg)
		{
			return CreateContextInlined<CombatBehaviorContextRanged, 0x30, RE::VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextRanged_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____>(arg);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorEquipContext>(decltype(&CombatBehaviorThread::GetChildIndex) arg)
		{
			return CreateContextInlined<CombatBehaviorEquipContext, 0x30, RE::VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorEquipContext_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorThread_unsignedint_CombatBehaviorThread____void____>(arg);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextBlock>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg1, RE::CombatBehaviorContextMelee::ATTACK_TYPE arg2)
		{
			return CreateContextInlined<CombatBehaviorContextBlock, 0x38, RE::VTABLE_CombatBehaviorTreeCreateContextNode2_CombatBehaviorContextBlock_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____CombatBehaviorContextMelee__ATTACK_TYPE_>(arg1, arg2);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextMagic>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg)
		{
			return CreateContextInlined<CombatBehaviorContextMagic, 0x30, RE::VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextMagic_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____>(arg);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextMelee>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg1, RE::CombatBehaviorContextMelee::ATTACK_TYPE arg2)
		{
			return CreateContextInlined<CombatBehaviorContextMelee, 0x38, RE::VTABLE_CombatBehaviorTreeCreateContextNode2_CombatBehaviorContextMelee_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____CombatBehaviorContextMelee__ATTACK_TYPE_>(arg1, arg2);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextShout>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg)
		{
			return CreateContextInlined<CombatBehaviorContextShout, 0x30, RE::VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextShout_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____>(arg);
		}

		template <>
		CombatBehaviorTreeNode* CreateContext<CombatBehaviorContextUsePotion>(decltype(&CombatBehaviorEquipContext::GetCombatItem) arg)
		{
			return CreateContextInlined<CombatBehaviorContextUsePotion, 0x30, RE::VTABLE_CombatBehaviorTreeCreateContextNode1_CombatBehaviorContextUsePotion_CombatBehaviorExpression_CombatBehaviorMemberFunc_CombatBehaviorEquipContext_NiPointer_CombatInventoryItem_const_CombatBehaviorEquipContext____void____>(arg);
		}

		virtual void Initialize();

		// members
		BSFixedString           name;  // 08
		CombatBehaviorTreeNode* root;  // 10

	private:
		template <uint64_t SE, uint64_t AE>
		static CombatBehaviorTreeNode* CreateContextNoInlined()
		{
			REL::Relocation<CombatBehaviorTreeNode*()> func{ RELOCATION_ID(SE, AE) };
			return func();
		}

		template <const std::array<REL::ID, 1>& vftableID>
		static void CreateContextInlinedInit(CombatBehaviorTreeNode* node)
		{
			node->Ctor();
			node->SetVftable(vftableID[0]);
		}

		template <typename Context, size_t size, const std::array<REL::ID, 1>& vftableID>
		static CombatBehaviorTreeNode* CreateContextInlined(auto arg)
		{
			using Node = CombatBehaviorTreeCreateContextNode1<Context, decltype(arg)>;
			static_assert(sizeof(Node) == size);

			auto node = RE::malloc<Node>();
			CreateContextInlinedInit<vftableID>(node);
			node->field = arg;
			return node;
		}

		template <typename Context, size_t size, const std::array<REL::ID, 1>& vftableID>
		static CombatBehaviorTreeNode* CreateContextInlined(auto arg1, auto arg2)
		{
			using Node = CombatBehaviorTreeCreateContextNode2<Context, decltype(arg1), decltype(arg2)>;
			static_assert(sizeof(Node) == size);

			auto node = RE::malloc<Node>();
			CreateContextInlinedInit<vftableID>(node);
			node->field1 = arg1;
			node->field2 = arg2;
			return node;
		}
	};
	static_assert(sizeof(CombatBehaviorTree) == 0x18);
}
