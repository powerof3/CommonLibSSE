#pragma once

namespace RE
{
	class hkbBehaviorGraphStringData : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbBehaviorGraphStringData;
		inline static constexpr auto VTABLE = VTABLE_hkbBehaviorGraphStringData;

		virtual ~hkbBehaviorGraphStringData() = default;  // 00

		// members
		hkArray<hkStringPtr> eventNames;              // 10
		hkArray<hkStringPtr> attributeNames;          // 20
		hkArray<hkStringPtr> variableNames;           // 30
		hkArray<hkStringPtr> characterPropertyNames;  // 40
	};
	static_assert(sizeof(hkbBehaviorGraphStringData) == 0x50);
}
