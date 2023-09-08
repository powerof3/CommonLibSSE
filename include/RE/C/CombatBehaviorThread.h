#pragma once

#include "RE/C/CombatBehaviorStack.h"
#include "RE/B/BSTTuple.h"

namespace RE
{
	class CombatBehaviorController;
	class CombatBehaviorTreeNode;

	class CombatBehaviorThread
	{
	public:
		enum class FailState : uint32_t
		{
			kOk,
			kFailed,
			kAborted
		};

		enum class State : uint32_t
		{
			kAscended,
			kProcessing,
			kDescended
		};

		enum class Flags : uint32_t
		{
			kPaused = 1 << 0,
			kSuspended = 1 << 1,
			kUnk2 = 1 << 2,
			kIsWorking_mb = 1 << 3
		};

		template<typename T>
		T& GetCurrentStackObject() {
			return stack.Access<T>(stack_for_cur_node);
		}

		void     Ascend();
		void     Descend(uint32_t ind);
		void     Descend(CombatBehaviorTreeNode* ind);
		uint32_t GetChildIndex() const;
		void     Pause();
		void     Suspend();
		void     Unpause();
		void     Unsuspend();

		// members
		CombatBehaviorStack                                            stack;               // 000
		BSTSmallArray<BSTTuple<CombatBehaviorTreeNode*, uint32_t>, 16> stack_layout;        // 010
		uint32_t                                                       stack_for_cur_node;  // 120
		uint32_t                                                       pad_124;             // 124
		CombatBehaviorStack::ObjectPtr                                 cur_context_sptr;    // 128
		CombatBehaviorTreeNode*                                        active_node;         // 138
		CombatBehaviorTreeNode*                                        prev_active_node;    // 140
		FailState                                                      fail_state;          // 148
		State                                                          state;               // 14C
		stl::enumeration<Flags, uint32_t>                              flags;               // 150
		uint32_t                                                       index_in_control;    // 154
		CombatBehaviorController*                                      control;             // 158
		CombatBehaviorThread*                                          parent;              // 160
		BSTSmallArray<CombatBehaviorThread*, 4>                        child_threads;       // 168
	};
	static_assert(sizeof(CombatBehaviorThread) == 0x198);
}
