#pragma once

#include "RE/N/NiBound.h"
#include "RE/N/NiObject.h"

namespace RE
{
	class NiParticlesData : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiParticlesData;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiParticlesData;
		inline static constexpr auto VTABLE = VTABLE_NiParticlesData;

		~NiParticlesData() override;  // 00

		// override (NiObject)
		const NiRTTI* GetRTTI() const override;                          // 02
		void          LoadBinary(NiStream& a_stream) override;           // 18
		void          LinkObject(NiStream& a_stream) override;           // 19
		bool          RegisterStreamables(NiStream& a_stream) override;  // 1A
		void          SaveBinary(NiStream& a_stream) override;           // 1B
		bool          IsEqual(NiObject* a_object) override;              // 1C - { return false; }

		// add
		virtual void          SetActiveVertexCount(std::uint16_t a_vertexCount);  // 25
		virtual std::uint16_t GetActiveVertexCount();                             // 26
		virtual void          RemoveParticle(std::uint16_t a_particleCount);      // 28
		virtual void          CalculateNormals();                                 // 29 - { return; }

		// members
		bool          hasRotations;            // 10
		std::uint8_t  unk11;                   // 11
		std::uint16_t maxNumVertices;          // 12
		NiBound       bound;                   // 14
		std::uint32_t pad24;                   // 24
		NiQuaternion* rotations;               // 28
		NiPoint3*     positions;               // 30
		NiColorA*     color;                   // 38
		float*        radii;                   // 40
		float*        sizes;                   // 48
		float*        rotationAngles;          // 50
		NiPoint3*     rotationAxes;            // 58
		NiColorA*     subtextureOffsets;       // 60
		std::uint32_t subTextureOffsetsCount;  // 68 - max 256
		float         aspectRatio;             // 6C
		float         speedToAspectAspect2;    // 70
		float         speedToAspectAspect1;    // 74
		float         speedToAspectSpeed2;     // 78
		std::uint16_t numVertices;             // 7C
		std::uint16_t pad7E;                   // 7E
		std::uint8_t* textureIndices;          // 80
		std::uint8_t  unk88;                   // 88 - aspect flags?
		std::uint8_t  unk89;                   // 89
		std::uint16_t pad8A;                   // 8A
		std::uint32_t pad8C;                   // 8C
	};
	static_assert(sizeof(NiParticlesData) == 0x90);
}
