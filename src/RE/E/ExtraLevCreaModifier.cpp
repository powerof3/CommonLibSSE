#include "RE/E/ExtraLevCreaModifier.h"

namespace RE
{
	ExtraLevCreaModifier::ExtraLevCreaModifier() :
		ExtraLevCreaModifier(LEV_CREA_MODIFIER::kNone)
	{}

	ExtraLevCreaModifier::ExtraLevCreaModifier(LEV_CREA_MODIFIER a_modifier) :
		BSExtraData(),
		modifier(a_modifier),
		pad14(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraLevCreaModifier::GetType() const
	{
		return ExtraDataType::kLevCreaModifier;
	}

	bool ExtraLevCreaModifier::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraLevCreaModifier*>(a_rhs);
		return modifier != rhs->modifier;
	}
}
