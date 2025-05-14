#include "RE/B/BarterMenu.h"

namespace RE
{
	RefHandle BarterMenu::GetTargetRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(519283, 405823) };
		return *handle;
	}
}
