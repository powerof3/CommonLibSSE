#pragma once

#include "RE/H/hkpContactListener.h"

namespace RE
{
	class bhkContactListener : public hkpContactListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_bhkContactListener;

		~bhkContactListener() override;  // 04
	};
	static_assert(sizeof(bhkContactListener) == 0x8);
}
