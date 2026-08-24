#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	class CombatBehaviorController;
	class CombatBehaviorTreeNode;

	class CombatBehaviorThread
	{
	public:
		enum class Status
		{
			kNormal = 0,
			kAdditiveDeprecated = 1,
			kAdditive = 2
		};

		enum class State
		{
			kAscending = 0,
			kUpdating = 1,
			kDescending = 2,
			kRestarting = 3
		};

		enum class Flag
		{
			kPaused = 1 << 0,
			kSuspended = 1 << 1,
			kUnk2 = 1 << 2,
			kIsWorking_mb = 1 << 3
		};

		template <typename T>
		T* GetCurrentObject()
		{
			return currentContextPtr.GetObject<T>();
		}

		template <typename T>
		const T* GetCurrentObject() const
		{
			return currentContextPtr.GetObject<T>();
		}

		// members
		CombatBehaviorStack                                                       stack;              // 000
		BSTSmallArray<BSTTuple<const CombatBehaviorTreeNode*, std::uint32_t>, 16> stackFrame;         // 010
		std::uint32_t                                                             stackPos;           // 120
		std::uint32_t                                                             pad124;             // 124
		CombatBehaviorStack::ObjectPtr                                            currentContextPtr;  // 128
		const CombatBehaviorTreeNode*                                             currentNode;        // 138
		const CombatBehaviorTreeNode*                                             previousNode;       // 140
		REX::TEnumSet<Status, std::int32_t>                                       status;             // 148
		REX::TEnumSet<State, std::int32_t>                                        state;              // 14C
		REX::TEnumSet<Flag, std::int32_t>                                         flags;              // 150
		std::uint32_t                                                             threadID;           // 154
		CombatBehaviorController*                                                 controller;         // 158
		CombatBehaviorThread*                                                     parent;             // 160
		BSTSmallArray<CombatBehaviorThread*, 4>                                   children;           // 168
	};
	static_assert(sizeof(CombatBehaviorThread) == 0x198);
}
