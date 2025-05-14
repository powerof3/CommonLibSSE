#pragma once

#include "RE/B/BSCompoundFrustum.h"
#include "RE/B/BSTHashMap.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiBoundRoom;
	class BSPortalGraph;
	class NiNode;

	class BSPortalGraphEntry : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPortalGraphEntry;
		inline static constexpr auto VTABLE = VTABLE_BSPortalGraphEntry;

		~BSPortalGraphEntry() override;  // 00

		// members
		BSPortalGraph*                          portalGraph;      // 10
		BSTArray<NiPointer<BSMultiBoundRoom>>   rooms;            // 18
		NiPointer<BSMultiBoundRoom>             room;             // 30
		BSTHashMap<NiNode*, BSCompoundFrustum*> nodes;            // 38
		BSCompoundFrustum                       compoundFrustum;  // 68
		uint64_t                                unk130;           // 130
		uint32_t                                cellId;           // 138
	};
	static_assert(sizeof(BSPortalGraphEntry) == 0x140);
}
