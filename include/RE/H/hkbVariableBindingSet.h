#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hkStringPtr.h"

namespace RE
{
	class hkbVariableBindingSet : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkbVariableBindingSet;
		inline static constexpr auto VTABLE = VTABLE_hkbVariableBindingSet;

		struct Binding
		{
		public:
			enum class BindingType
			{
				kVariable = 0,
				kCharacterProperty = 1
			};

			enum class InternalBindingFlag
			{
				kNone = 0,
				kOutput = 1 << 0
			};

			// members
			hkStringPtr                                     memberPath;             // 00
			const hkClass*                                  memberClass;            // 08
			std::int32_t                                    offsetInObjectPlusOne;  // 10
			std::int32_t                                    offsetInArrayPlusOne;   // 14
			std::int32_t                                    rootVariableIndex;      // 18
			std::int32_t                                    variableIndex;          // 1C
			std::int8_t                                     bitIndex;               // 20
			REX::TEnumSet<BindingType, std::int8_t>         bindingType;            // 21
			std::uint8_t                                    memberType;             // 22 - hkClassMember::Type
			std::int8_t                                     variableType;           // 23
			REX::TEnumSet<InternalBindingFlag, std::int8_t> flags;                  // 24
			std::uint8_t                                    pad25;                  // 25
			std::uint16_t                                   pad26;                  // 26
		};
		static_assert(sizeof(Binding) == 0x28);

		~hkbVariableBindingSet() override;  // 00

		// members
		hkArray<Binding> bindings;                // 10
		std::int32_t     indexOfBindingToEnable;  // 20
		bool             hasOutputBinding;        // 24
		std::uint8_t     pad25;                   // 25
		std::uint16_t    pad26;                   // 26
	};
	static_assert(sizeof(hkbVariableBindingSet) == 0x28);
}
