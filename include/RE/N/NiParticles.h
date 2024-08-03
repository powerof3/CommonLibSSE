#pragma once

#include "RE/B/BSGeometry.h"

namespace RE
{
	class NiParticlesData;

	class NiParticles : public BSGeometry
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiParticles;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiParticles;
		inline static constexpr auto VTABLE = VTABLE_NiParticles;

		~NiParticles() override;  // 00

		// override (BSGeometry)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiParticles*  AsParticlesGeom() override;                         // 10
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          LinkObject(NiStream& a_stream) override;            // 19 - { BSGeometry::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;   // 1A - { return BSGeometry::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C - { return BSGeometry::IsEqual(); }

		// members
		NiPointer<NiParticlesData> particleData;  // 158
		std::uint64_t              unk160;        // 160
	};
	static_assert(sizeof(NiParticles) == 0x168);
}
