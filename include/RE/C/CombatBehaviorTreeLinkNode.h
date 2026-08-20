#pragma once

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	class CombatBehaviorTreeLinkNode : public CombatBehaviorTreeNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeLinkNode;
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeLinkNode;

		// override (CombatBehaviorTreeNode)
		void                 Enter(CombatBehaviorThread* a_thread) override;           // 02
		bool                 Validate(const CombatBehaviorTreeNode* a_node) override;  // 08
		const BSFixedString& GetType() override;                                       // 09

		// members
		BSFixedString linkName;  // 28
	};
	static_assert(sizeof(CombatBehaviorTreeLinkNode) == 0x30);
}
