#include "RE/E/ExtraRank.h"

namespace RE
{
	ExtraRank::ExtraRank() :
		ExtraRank(0)
	{}

	ExtraRank::ExtraRank(std::int32_t a_rank) :
		BSExtraData(),
		rank(a_rank),
		pad14(0)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraDataType ExtraRank::GetType() const
	{
		return ExtraDataType::kRank;
	}

	bool ExtraRank::IsNotEqual(const BSExtraData* a_rhs) const
	{
		auto rhs = static_cast<const ExtraRank*>(a_rhs);
		return rank != rhs->rank;
	}
}
