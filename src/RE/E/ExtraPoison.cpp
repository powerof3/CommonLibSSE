#include "RE/E/ExtraPoison.h"

namespace RE
{
	ExtraPoison::ExtraPoison() :
		ExtraPoison(nullptr, 0)
	{}

	ExtraPoison::ExtraPoison(AlchemyItem* a_poison, std::int32_t a_count) :
		BSExtraData(),
		poison(a_poison),
		count(a_count),
		pad1C(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraPoison::GetType() const
	{
		return ExtraDataType::kPoison;
	}

	bool ExtraPoison::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraPoison*>(a_rhs);
		return poison != rhs->poison || count != rhs->count;
	}
}
