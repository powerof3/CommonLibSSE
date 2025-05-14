#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTPointerList.h"

namespace RE
{
	class BSMultiBoundRoom;
	class BSOcclusionShape;
	class BSPortal;
	class BSPortalSharedNode;
	class NiAVObject;
	class NiNode;

	class BSPortalGraph : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPortalGraph;
		inline static constexpr auto VTABLE = VTABLE_BSPortalGraph;

		~BSPortalGraph() override;  // 00

		// members
		NiTPointerList<BSOcclusionShape>      occlusionShapes;   // 10
		NiTPointerList<BSPortal>              portals;           // 28
		BSTArray<NiPointer<BSMultiBoundRoom>> rooms;             // 40
		BSTArray<NiPointer<NiAVObject>>       unk58;             // 58
		NiPointer<BSPortalSharedNode>         portalSharedNode;  // 70
		BSTArray<NiPointer<NiAVObject>>       unk78;             // 78
		BSTArray<NiPointer<NiAVObject>>       unk90;             // 90
		BSTArray<void*>                       unkA8;             // A8
		FormID                                cellID;            // C0
		std::uint32_t                         padC4;             // C4
	};
	static_assert(sizeof(BSPortalGraph) == 0xC8);
}
