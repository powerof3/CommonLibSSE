#pragma once

#include "RE/B/BSTriShape.h"

namespace RE
{
	class BSDynamicTriShape : public BSTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSDynamicTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSDynamicTriShape;
		inline static constexpr auto VTABLE = VTABLE_BSDynamicTriShape;

		~BSDynamicTriShape() override;  // 00

		// override (BSTriShape)
		const NiRTTI*      GetRTTI() const override;                           // 02
		BSDynamicTriShape* AsDynamicTriShape() override;                       // 0C
		NiObject*          CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void               LoadBinary(NiStream& a_stream) override;            // 18
		void               LinkObject(NiStream& a_stream) override;            // 19 - { BSTriShape::LinkObject(a_stream); }
		bool               RegisterStreamables(NiStream& a_stream) override;   // 1A - { return BSTriShape::RegisterStreamables(a_stream); }
		void               SaveBinary(NiStream& a_stream) override;            // 1B
		bool               IsEqual(NiObject* a_object) override;               // 1C

		// members
		void*              dynamicData;  // 160
		mutable BSSpinLock lock;         // 168
		std::uint32_t      dataSize;     // 170
		std::uint32_t      frameCount;   // 174
		std::uint32_t      unk178;       // 178
		std::uint32_t      unk17C;       // 17C
	};
	static_assert(sizeof(BSDynamicTriShape) == 0x180);
}
