#pragma once

#include "RE/M/MagicTarget.h"

namespace RE
{
	class ActiveEffect;

	class FindMaxMagnitudeVisitor : public MagicTarget::ForEachActiveEffectVisitor
	{
	public:
		inline static constexpr auto RTTI = RTTI_FindMaxMagnitudeVisitor;
		inline static constexpr auto VTABLE = VTABLE_FindMaxMagnitudeVisitor;

		~FindMaxMagnitudeVisitor() override = default;  // 00

		// add
		virtual BSContainer::ForEachResult Accept(ActiveEffect* a_effect) override;  // 01

		// members
		ActiveEffect* activeEffect{ nullptr };  // 08
		float         maxMagnitude{ -1.0F };    // 10
	};
	static_assert(sizeof(FindMaxMagnitudeVisitor) == 0x18);

}
