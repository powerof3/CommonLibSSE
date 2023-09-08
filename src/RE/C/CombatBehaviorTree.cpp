#include "RE/C/CombatBehaviorTree.h"

namespace RE
{
	CombatBehaviorTree::TreeBuilder::TreeBuilder()
	{
		using func_t = CombatBehaviorTree::TreeBuilder*(CombatBehaviorTree::TreeBuilder*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46266, 0) };  // I do not know for AE
		func(this);
	}

	CombatBehaviorTreeNode* CombatBehaviorTree::TreeBuilder::GetNode()
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::GetNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(46257, 0) };  // I do not know for AE
		return func(this);
	}

	CombatBehaviorTree::TreeBuilder& CombatBehaviorTree::TreeBuilder::operator[](const CombatBehaviorTree::TreeBuilder& other)
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::operator[]);
		REL::Relocation<func_t> func{ RELOCATION_ID(46256, 0) };  // I do not know for AE
		return func(this, other);
	}

	CombatBehaviorTree::TreeBuilder& CombatBehaviorTree::TreeBuilder::operator,(const CombatBehaviorTree::TreeBuilder& other)
	{
		using func_t = decltype(&CombatBehaviorTree::TreeBuilder::operator[]);
		REL::Relocation<func_t> func{ RELOCATION_ID(46255, 0) };  // I do not know for AE
		return func(this, other);
	}

	CombatBehaviorTree::TreeBuilder CombatBehaviorTree::AddNode(char* name, CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorTree::AddNode);
		REL::Relocation<func_t> func{ RELOCATION_ID(46261, 0) };  // I do not know for AE
		return func(name, node);
	}

	void CombatBehaviorTree::CreateTree(CombatBehaviorTreeNode* node)
	{
		using func_t = decltype(&CombatBehaviorTree::CreateTree);
		REL::Relocation<func_t> func{ RELOCATION_ID(46263, 0) };  // I do not know for AE
		return func(this, node);
	}
}
