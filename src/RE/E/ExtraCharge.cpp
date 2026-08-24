#include "RE/E/ExtraCharge.h"

namespace RE
{
	ExtraCharge::ExtraCharge() :
		BSExtraData(),
		charge(0.0F),
		pad14(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraCharge::GetType() const
	{
		return ExtraDataType::kCharge;
	}

	bool ExtraCharge::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraCharge*>(a_rhs);
		return charge != rhs->charge;
	}
}
