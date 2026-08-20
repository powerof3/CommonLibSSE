#include "RE/C/CombatBehaviorTree.h"

namespace RE
{
	CombatBehaviorTree::TreeBuilder* CombatBehaviorTree::TreeBuilder::AppendLastNode(const TreeBuilder& a_other)
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::AppendLastNode);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46255, 47510) };
		return func(this, a_other);
	}

	void CombatBehaviorTree::CreateTree(CombatBehaviorTreeNode* a_node)
	{
		using func_t = decltype(&CombatBehaviorTree::CreateTree);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46263, 47518) };
		func(this, a_node);
	}

	CombatBehaviorTree::TreeBuilder* CombatBehaviorTree::AddNode(TreeBuilder* a_out, const char* a_name, CombatBehaviorTreeNode* a_node)
	{
		using func_t = decltype(&CombatBehaviorTree::AddNode);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46261, 47516) };
		return func(a_out, a_name, a_node);
	}

	Actor* CombatBehaviorTree::GetAttacker()
	{
		using func_t = decltype(&CombatBehaviorTree::GetAttacker);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46264, 47519) };
		return func();
	}

	Actor* CombatBehaviorTree::GetTarget()
	{
		using func_t = decltype(&CombatBehaviorTree::GetTarget);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46265, 47520) };
		return func();
	}
}
