#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	CombatBehaviorTreeNode::CombatBehaviorTreeNode()
	{
		Ctor();
	}

	void CombatBehaviorTreeNode::AddChild(CombatBehaviorTreeNode* a_child)
	{
		using func_t = decltype(&CombatBehaviorTreeNode::AddChild);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46304, 47548) };
		func(this, a_child);
	}

	void CombatBehaviorTreeNode::AddChildren(const BSTArray<CombatBehaviorTreeNode*>& a_children)
	{
		using func_t = decltype(&CombatBehaviorTreeNode::AddChildren);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46305, 47549) };
		func(this, a_children);
	}

	CombatBehaviorTreeNode* CombatBehaviorTreeNode::Ctor()
	{
		using func_t = decltype(&CombatBehaviorTreeNode::Ctor);
		static REL::Relocation<func_t> func{ RELOCATION_ID(46301, 47545) };
		return func(this);
	}
}
