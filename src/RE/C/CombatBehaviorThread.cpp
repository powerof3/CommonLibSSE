#include "RE/C/CombatBehaviorThread.h"

namespace RE
{
	void CombatBehaviorThread::Ascend()
	{
		using func_t = decltype(&CombatBehaviorThread::Suspend);
		REL::Relocation<func_t> func{ RELOCATION_ID(46229, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Descend(uint32_t ind)
	{
		using func_t = void(CombatBehaviorThread*, uint32_t);
		REL::Relocation<func_t> func{ RELOCATION_ID(46230, 0) };  // I do not know for AE
		return func(this, ind);
	}

	void CombatBehaviorThread::Descend(CombatBehaviorTreeNode* node)
	{
		using func_t = void(CombatBehaviorThread*, CombatBehaviorTreeNode*);
		REL::Relocation<func_t> func{ RELOCATION_ID(46231, 0) };  // I do not know for AE
		return func(this, node);
	}

	uint32_t CombatBehaviorThread::GetChildIndex() const
	{
		using func_t = decltype(&CombatBehaviorThread::GetChildIndex);
		REL::Relocation<func_t> func{ RELOCATION_ID(46531, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Pause()
	{
		flags.set(Flags::kPaused);
	}

	void CombatBehaviorThread::Unpause()
	{
		flags.reset(Flags::kPaused);
	}

	void CombatBehaviorThread::Suspend()
	{
		using func_t = decltype(&CombatBehaviorThread::Suspend);
		REL::Relocation<func_t> func{ RELOCATION_ID(46238, 0) };  // I do not know for AE
		return func(this);
	}

	void CombatBehaviorThread::Unsuspend()
	{
		using func_t = decltype(&CombatBehaviorThread::Unsuspend);
		REL::Relocation<func_t> func{ RELOCATION_ID(46239, 0) };  // I do not know for AE
		return func(this);
	}
}
