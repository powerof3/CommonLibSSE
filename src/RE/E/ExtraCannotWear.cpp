#include "RE/E/ExtraCannotWear.h"

namespace RE
{
	ExtraCannotWear::ExtraCannotWear() :
		BSExtraData()
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraCannotWear::GetType() const
	{
		return ExtraDataType::kCannotWear;
	}
}
