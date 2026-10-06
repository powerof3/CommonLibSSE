#pragma once

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	template <class T>
	class CombatBehaviorTreeNodeObjectBase : public CombatBehaviorTreeNode
	{
	public:
		~CombatBehaviorTreeNodeObjectBase() override = default;  // 00

		// override (CombatBehaviorTreeNode)
		void                 Exit(CombatBehaviorThread* a_thread) override;                                           // 03
		void                 Update(CombatBehaviorThread* a_thread) override;                                         // 04
		void                 Abort(CombatBehaviorThread* a_thread) override;                                          // 05
		void                 SaveGame(CombatBehaviorThread* a_thread, BGSSaveFormBuffer* a_saveGameBuffer) override;  // 06
		void                 LoadGame(CombatBehaviorThread* a_thread, BGSLoadFormBuffer* a_loadGameBuffer) override;  // 07
		bool                 Validate(const CombatBehaviorTreeNode* a_node) override;                                 // 08
		const BSFixedString& GetType() override;                                                                      // 09
	};
}
