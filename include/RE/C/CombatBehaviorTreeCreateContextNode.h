#pragma once

#include "RE/C/CombatBehaviorTreeNode.h"

namespace RE
{
	template <typename Context, typename T>
	class CombatBehaviorTreeCreateContextNode1 : public CombatBehaviorTreeNode
	{
	public:
		// members
		T field;  // 28
	};

	template <typename Context, typename T, typename U>
	class CombatBehaviorTreeCreateContextNode2 : public CombatBehaviorTreeNode
	{
	public:
		// members
		T field1;  // 28
		U field2;  // ??
	};

	template <typename Context>
	class __declspec(novtable) CombatBehaviorTreeCreateContextNode : public CombatBehaviorTreeNode
	{
	public:
		static constexpr auto VTABLE{ VTABLE_NiNode };

		void Enter(CombatBehaviorThread* a_thread) override
		{
			a_thread->cur_context_sptr = a_thread->stack.Allocate<Context>();
			a_thread->stack.StoreData(a_thread->cur_context_sptr);
			a_thread->Descend(uint32_t(0));
		}

		void Exit(CombatBehaviorThread* thread) override
		{
			thread->cur_context_sptr = thread->stack.RemoveData<CombatBehaviorStack::ObjectPtr>();
			thread->stack.Deallocate<Context>();
		}

		void SaveGame(CombatBehaviorThread* a_thread, BGSSaveFormBuffer* a_buf) override
		{
			//Context::SaveGame(a_thread->GetCurrentStackObject<Context>(), a_buf);
		}

		void LoadGame(CombatBehaviorThread* a_thread, BGSLoadFormBuffer* a_buf) override
		{

		}

		bool Validate(CombatBehaviorTreeNode* node) const override
		{
			return CombatBehaviorBranch::Validate(node);
		}

		const BSFixedString& GetType() const override
		{
			static BSFixedString ans("CombatBehaviorTreeCreateContextNode");
			return ans;
		}

		~CombatBehaviorTreeCreateContextNode() {}

		const BSFixedString& GetName() const {
			return name;
		}

		CombatBehaviorTreeCreateContextNode() {

		}
	};
}
