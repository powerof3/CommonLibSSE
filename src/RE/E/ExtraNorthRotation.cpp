#include "RE/E/ExtraNorthRotation.h"

namespace RE
{
	ExtraNorthRotation::ExtraNorthRotation() :
		BSExtraData(),
		northRot(0.0F),
		pad14(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraNorthRotation::GetType() const
	{
		return ExtraDataType::kNorthRotation;
	}
}
