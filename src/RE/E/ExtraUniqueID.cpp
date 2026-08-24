#include "RE/E/ExtraUniqueID.h"

namespace RE
{
	ExtraUniqueID::ExtraUniqueID() :
		ExtraUniqueID(0, 0)
	{}

	ExtraUniqueID::ExtraUniqueID(FormID a_baseID, std::uint16_t a_uniqueID) :
		BSExtraData(),
		baseID(a_baseID),
		uniqueID(a_uniqueID),
		pad16(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraUniqueID::GetType() const
	{
		return ExtraDataType::kUniqueID;
	}

	bool ExtraUniqueID::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraUniqueID*>(a_rhs);
		return uniqueID != rhs->uniqueID || baseID != rhs->baseID;
	}
}
