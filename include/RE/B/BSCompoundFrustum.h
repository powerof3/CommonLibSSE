#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiFrustumPlanes.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiCamera;

	class BSCompoundFrustum
	{
	public:
		// members
		BSTArray<void*> unk00;          // 00
		BSTArray<void*> unk18;          // 18
		NiFrustumPlanes frustumPlanes;  // 30
		NiPoint3        unkA0;          // A0
		NiCamera*       camera;         // B0
		uint32_t        unkB8;          // B8
		uint32_t        unkBC;          // BC
		uint32_t        unkC0;          // C0
		uint16_t        unkC4;          // C4
	};
	static_assert(sizeof(BSCompoundFrustum) == 0xC8);
}
