#include "RE/L/LockpickingMenu.h"

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* LockpickingMenu::GetTargetReference()
	{
		static REL::Relocation<TESObjectREFRPtr*> refptr{ RELOCATION_ID(519716, 406271) };
		return refptr->get();
	}
}
