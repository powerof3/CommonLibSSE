#pragma once

#include "RE/B/BSTriShape.h"

namespace RE
{
	struct SegmentData
	{
		std::uint32_t index;        // 00
		std::uint32_t unkTriCount;  // 04
		std::uint8_t  unkFlags;     // 08
		std::uint32_t numTris;      // 0C
		std::uint8_t  flags;        // 10
	};

	class BSSubIndexTriShape : public BSTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSubIndexTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSSubIndexTriShape;
		inline static constexpr auto VTABLE = VTABLE_BSSubIndexTriShape;

		~BSSubIndexTriShape() override;  // 00

		// override (BSTriShape)
		const NiRTTI* GetRTTI() const override;                                                         // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;                                // 17
		void          LoadBinary(NiStream& a_stream) override;                                          // 18
		void          LinkObject(NiStream& a_stream) override;                                          // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                                 // 1A
		void          SaveBinary(NiStream& a_stream) override;                                          // 1B
		bool          IsEqual(NiObject* a_object) override;                                             // 1C
		void          OnVisible(NiCullingProcess& a_process, std::int32_t a_alphaGroupIndex) override;  // 34

		// members
		SegmentData*  segmentData;   // 160
		std::uint32_t numSegments;   // 168
		std::uint32_t unkSegCount;   // 16C
		bool          unk170;        // 170
		bool          nonSegmented;  // 171
	};
	static_assert(sizeof(BSSubIndexTriShape) == 0x178);
}
