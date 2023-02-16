#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectCELL;

	struct TESCellAttachDetachEvent
	{
		NiPointer<TESObjectREFR> reference;  // 00
		bool                     attached;   // 08
	};
	static_assert(sizeof(TESCellAttachDetachEvent) == 0x10);
}
