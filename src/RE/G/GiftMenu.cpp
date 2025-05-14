#include "RE/G/GiftMenu.h"

namespace RE
{
	RefHandle GiftMenu::GetTargetRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(519570, 406111) };
		return *handle;
	}
}
