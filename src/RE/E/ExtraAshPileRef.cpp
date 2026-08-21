#include "RE/E/ExtraAshPileRef.h"

namespace RE
{
	ExtraAshPileRef::ExtraAshPileRef() :
		ExtraAshPileRef(ObjectRefHandle())
	{}

	ExtraAshPileRef::ExtraAshPileRef(ObjectRefHandle ashPileRef) :
		BSExtraData(),
		ashPileRef(ashPileRef),
		pad14(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraAshPileRef::GetType() const
	{
		return ExtraDataType::kAshPileRef;
	}
}
