#include "RE/E/ExtraEncounterZone.h"

namespace RE
{
	ExtraEncounterZone::ExtraEncounterZone() :
		ExtraEncounterZone(nullptr)
	{}

	ExtraEncounterZone::ExtraEncounterZone(BGSEncounterZone* a_zone) :
		BSExtraData(),
		zone(a_zone)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraEncounterZone::GetType() const
	{
		return ExtraDataType::kEncounterZone;
	}

	bool ExtraEncounterZone::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraEncounterZone*>(a_rhs);
		return zone != rhs->zone;
	}
}
