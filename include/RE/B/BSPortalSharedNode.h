#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiNode.h"

namespace RE
{
	class BSLight;
	class BSPortal;

	class BSPortalSharedNode : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPortalSharedNode;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSPortalSharedNode;
		inline static constexpr auto VTABLE = VTABLE_BSPortalSharedNode;

		~BSPortalSharedNode() override;  // 00

		// override (NiNode)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          OnVisible(NiCullingProcess& a_process) override;    // 34

		// members
		BSTArray<BSLight*> lights;  // 128
		BSPortal*          portal;  // 140
	};
	static_assert(sizeof(BSPortalSharedNode) == 0x148);
}
