#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/C/CombatBehaviorThread.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;

	class CombatBehaviorTreeNode
	{
	public:
		virtual ~CombatBehaviorTreeNode();
		virtual const BSFixedString& GetName() const;
		virtual void                 Enter(CombatBehaviorThread* a_thread);
		virtual void                 Exit(CombatBehaviorThread* a_thread);
		virtual void                 Update(CombatBehaviorThread* a_thread);
		virtual void                 Abort(CombatBehaviorThread* a_thread);
		virtual void                 SaveGame(CombatBehaviorThread* a_thread, BGSSaveFormBuffer* a_buf);
		virtual void                 LoadGame(CombatBehaviorThread* a_thread, BGSLoadFormBuffer* a_buf);
		virtual bool                 Validate(CombatBehaviorTreeNode* a_other) const;
		virtual const BSFixedString& GetType() const;

		CombatBehaviorTreeNode* Ctor();
		CombatBehaviorTreeNode* GetRoot();
		void                    SetVftable(REL::ID id);

		// members
		BSFixedString                          name;      // 08
		CombatBehaviorTreeNode*                parent;    // 10
		BSStaticArray<CombatBehaviorTreeNode*> children;  // 18
	};
	static_assert(sizeof(CombatBehaviorTreeNode) == 0x28);

	class CombatBehaviorBranch
	{
	public:
		static bool Validate(CombatBehaviorTreeNode*);
	};

	// Inherit your custom nodes from it
	class CombatBehaviorTreeNodeCustom
	{
	public:
		virtual ~CombatBehaviorTreeNodeCustom() {}
		virtual const BSFixedString& GetName() const { return name; }
		virtual void                 Enter(CombatBehaviorThread*) {}
		virtual void                 Exit(CombatBehaviorThread*) {}
		virtual void                 Update(CombatBehaviorThread*) {}
		virtual void                 Abort(CombatBehaviorThread*) {}
		virtual void                 SaveGame(CombatBehaviorThread*, BGSSaveFormBuffer*) {}
		virtual void                 LoadGame(CombatBehaviorThread*, BGSLoadFormBuffer*) {}
		virtual bool                 Validate(CombatBehaviorTreeNode*) const { return true; }
		virtual const BSFixedString& GetType() const { return name; }

		CombatBehaviorTreeNode& asNodeRef() { return reinterpret_cast<CombatBehaviorTreeNode&>(*this); }
		CombatBehaviorTreeNode* asNode() { return reinterpret_cast<CombatBehaviorTreeNode*>(this); }

		// members
		BSFixedString                          name;      // 08
		CombatBehaviorTreeNode*                parent;    // 10
		BSStaticArray<CombatBehaviorTreeNode*> children;  // 18
	};
	static_assert(sizeof(CombatBehaviorTreeNode) == sizeof(CombatBehaviorTreeNode));
}
