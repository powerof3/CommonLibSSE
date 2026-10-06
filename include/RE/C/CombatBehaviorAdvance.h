#pragma once

#include "RE/C/CombatBehaviorAction.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatAimController;
	class CombatPath;
	class CombatTargetLocationSearch;
	class CombatTargetLocationSearchResult;

	class CombatBehaviorAdvance : public CombatBehaviorAction
	{
	public:
		// members
		NiPointer<CombatPath>                       path;            // 00
		NiPointer<CombatAimController>              aimController;   // 08
		NiPointer<CombatTargetLocationSearch>       locationSearch;  // 10
		NiPointer<CombatTargetLocationSearchResult> searchResult;    // 18
	};
	static_assert(sizeof(CombatBehaviorAdvance) == 0x20);
}
