#include "RE/I/Inventory.h"

namespace RE
{
	BSTEventSource<Inventory::Event>* Inventory::GetEventSource()
	{
		using func_t = decltype(&Inventory::GetEventSource);
		static REL::Relocation<func_t> func{ Offset::Inventory::GetEventSource };
		return func();
	}
}
