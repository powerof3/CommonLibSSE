#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class CombatBehaviorThread;

	class CombatBehaviorTreeNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatBehaviorTreeNode;
		inline static constexpr auto VTABLE = VTABLE_CombatBehaviorTreeNode;

		virtual ~CombatBehaviorTreeNode();  // 00

		virtual const BSFixedString& GetName();                                                                      // 01
		virtual void                 Enter(CombatBehaviorThread* a_thread);                                          // 02
		virtual void                 Exit(CombatBehaviorThread* a_thread);                                           // 03
		virtual void                 Update(CombatBehaviorThread* a_thread);                                         // 04
		virtual void                 Abort(CombatBehaviorThread* a_thread);                                          // 05
		virtual void                 SaveGame(CombatBehaviorThread* a_thread, BGSSaveFormBuffer* a_saveGameBuffer);  // 06
		virtual void                 LoadGame(CombatBehaviorThread* a_thread, BGSLoadFormBuffer* a_loadGameBuffer);  // 07
		virtual bool                 Validate(const CombatBehaviorTreeNode* a_node);                                 // 08
		virtual const BSFixedString& GetType();                                                                      // 09

		void AddChild(CombatBehaviorTreeNode* a_child);
		void AddChildren(const BSTArray<CombatBehaviorTreeNode*>& a_children);

		// members
		BSFixedString            name;        // 08
		CombatBehaviorTreeNode*  parent;      // 10
		CombatBehaviorTreeNode** children;    // 18
		std::uint32_t            childCount;  // 20
		std::uint32_t            pad24;       // 24
	};
	static_assert(sizeof(CombatBehaviorTreeNode) == 0x28);
}
