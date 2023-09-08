#pragma once

namespace RE
{
	class CombatBehaviorResource;
	class CombatBehaviorThread;
	class CombatController;

	class CombatBehaviorController
	{
	public:
		// members
		CombatBehaviorThread*                              thread;          // 00
		BSTArray<CombatBehaviorThread*>                    active_threads;  // 08
		CombatController*                                  combat_control;  // 20
		BSTHashMap<BSFixedString, CombatBehaviorResource*> resources;       // 28
		BSTArray<CombatBehaviorThread*>                    queued;          // 58
		uint32_t                                           threads;         // 70
		uint32_t                                           pad_74;          // 74
	};
	static_assert(sizeof(CombatBehaviorController) == 0x78);
}
