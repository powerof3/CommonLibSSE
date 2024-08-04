#pragma once

#include "RE/N/NiParticlesData.h"

namespace RE
{
	class NiParticleInfo
	{
	public:
		// members
		NiPoint3      velocity;    // 00
		float         age;         // 0C
		float         lifespan;    // 10
		float         lastUpdate;  // 14
		std::uint16_t unk18;       // 18
		std::uint16_t unk1A;       // 1A
		std::uint32_t pad1C;       // 1C
	};
	static_assert(sizeof(NiParticleInfo) == 0x20);

	class NiPSysData : public NiParticlesData
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPSysData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPSysData;
		inline static constexpr auto VTABLE = VTABLE_NiPSysData;

		~NiPSysData() override;  // 00

		// override (NiParticlesData)
		const NiRTTI* GetRTTI() const override;                                // 02
		void          LoadBinary(NiStream& a_stream) override;                 // 18
		void          LinkObject(NiStream& a_stream) override;                 // 19
		bool          RegisterStreamables(NiStream& a_stream) override;        // 1A
		void          SaveBinary(NiStream& a_stream) override;                 // 1B
		bool          IsEqual(NiObject* a_object) override;                    // 1C - { return false; }
		void          RemoveParticle(std::uint16_t a_particleCount) override;  // 28

		// add
		virtual std::uint16_t AddParticle();            // 2A
		virtual void          ResolveAddedParticles();  // 2B

		// members
		NiParticleInfo* particleInfo;        // 90
		float*          rotationSpeeds;      // 98
		std::uint16_t   addedParticleCount;  // A0
		std::uint16_t   addedParticlesBase;  // A0
		std::uint32_t   padA4;               // A4
	};
	static_assert(sizeof(NiPSysData) == 0xA8);
}
