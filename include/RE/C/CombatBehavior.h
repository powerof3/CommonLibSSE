#pragma once

#include "RE/C/CombatBehaviorAccessors.h"

namespace RE
{
	class CombatBehaviorThread;

	class CombatBehavior : public CombatBehaviorAccessors
	{
	public:
		bool CheckTargetChanged()
		{
			using func_t = decltype(&CombatBehavior::CheckTargetChanged);
			static REL::Relocation<func_t> func{ RELOCATION_ID(46089, 47353) };
			return func(this);
		}

		CombatBehaviorThread* CreateChildThread(std::uint32_t a_childIndex, bool a_addThread)
		{
			using func_t = decltype(&CombatBehavior::CreateChildThread);
			static REL::Relocation<func_t> func{ RELOCATION_ID(46090, 47354) };
			return func(this, a_childIndex, a_addThread);
		}

		void StartChildThread(CombatBehaviorThread* a_thread, std::uint32_t a_childIndex, bool a_addThread)
		{
			using func_t = decltype(&CombatBehavior::StartChildThread);
			static REL::Relocation<func_t> func{ RELOCATION_ID(46091, 47355) };
			func(this, a_thread, a_childIndex, a_addThread);
		}
	};
	static_assert(std::is_empty_v<CombatBehavior>);
}
