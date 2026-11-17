#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkRefVariant.h"
#include "RE/H/hkVector4.h"

namespace RE
{
	union hkbVariableValue
	{
		bool         b;
		std::int32_t i;
		float        f;
	};
	static_assert(sizeof(hkbVariableValue) == 0x4);

	class hkbVariableValueSet : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbVariableValueSet;
		inline static constexpr auto VTABLE = VTABLE_hkbVariableValueSet;

		~hkbVariableValueSet() override;  // 00

		// members
		hkArray<hkbVariableValue> wordVariableValues;     // 10
		hkArray<hkVector4>        quadVariableValues;     // 20
		hkArray<hkRefVariant>     variantVariableValues;  // 30
	};
	static_assert(sizeof(hkbVariableValueSet) == 0x40);
}
