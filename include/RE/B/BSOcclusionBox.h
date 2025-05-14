#pragma once

#include "RE/B/BSCompoundFrustum.h"
#include "RE/B/BSOcclusionShape.h"
#include "RE/N/NiPoint2.h"

namespace RE
{
	class BSOcclusionBox : public BSOcclusionShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSOcclusionBox;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSOcclusionBox;
		inline static constexpr auto VTABLE = VTABLE_BSOcclusionBox;

		~BSOcclusionBox() override;  // 00

		// override (BSOcclusionShape)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		bool          IsOcclusionPlane() const override;                  // 25
		bool          IsOcclusionBox() const override;                    // 25

		// members
		NiPoint3        size;              // 048
		NiFrustumPlanes frustumPlanes[2];  // 054
		uint64_t        unk138;            // 138
		uint64_t        unk140;            // 140
		uint64_t        unk148;            // 148
		uint64_t        unk150;            // 150
		uint64_t        unk158;            // 158
		uint64_t        unk160;            // 160
		uint64_t        unk168;            // 168
		uint64_t        unk170;            // 170
		uint64_t        unk178;            // 178
		uint64_t        unk180;            // 180
		uint64_t        unk188;            // 188
		uint64_t        unk190;            // 190
		uint64_t        unk198;            // 198
		uint64_t        unk1A0;            // 1A0
		uint64_t        unk1A8;            // 1A8
		uint64_t        unk1B0;            // 1B0
		uint64_t        unk1B8;            // 1B8
		uint64_t        unk1C0;            // 1C0
		uint64_t        unk1C8;            // 1C8
		uint64_t        unk1D0;            // 1D0
		uint64_t        unk1D8;            // 1D8
		uint64_t        unk1E0;            // 1E0
	};
	static_assert(sizeof(BSOcclusionBox) == 0x1E8);
}
