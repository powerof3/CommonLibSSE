#pragma once

#include "RE/C/CombatBehavior.h"

namespace RE
{
	class CombatBehaviorAction : public CombatBehavior
	{
	public:
	};
	static_assert(std::is_empty_v<CombatBehaviorAction>);
}
