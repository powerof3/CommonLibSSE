#include "RE/C/CombatBehaviorStack.h"

namespace RE
{
	void CombatBehaviorStack::CheckBuffer(uint32_t a_size)
	{
		using func_t = decltype(&CombatBehaviorStack::CheckBuffer);
		REL::Relocation<func_t> func{ RELOCATION_ID(32426, 0) };  // I do not know for AE
		return func(this, a_size);
	}
}
