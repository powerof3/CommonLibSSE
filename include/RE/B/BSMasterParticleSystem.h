#pragma once

#include "RE/N/NiNode.h"

namespace RE
{
	class NiParticles;

	class BSMasterParticleSystem : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMasterParticleSystem;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMasterParticleSystem;
		inline static constexpr auto VTABLE = VTABLE_BSMasterParticleSystem;

		~BSMasterParticleSystem() override;  // 00

		// override (NiNode)
		const NiRTTI* GetRTTI() const override;                                                         // 02
		void          LoadBinary(NiStream& a_stream) override;                                          // 18
		void          LinkObject(NiStream& a_stream) override;                                          // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                                 // 1A
		void          SaveBinary(NiStream& a_stream) override;                                          // 1B
		void          PostLinkObject(NiStream& a_stream) override;                                      // 1E
		bool          IsEqual(NiObject* a_object) override;                                             // 1C
		void          UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;          // 2C
		void          UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
		void          UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;     // 2E

		// members
		BSTArray<NiPointer<NiAVObject>> emitterObjs;           // 128
		BSTArray<NiParticles*>          particles;             // 140
		std::int32_t                    index;                 // 158
		std::uint32_t                   unk15C;                // 15C
		std::uint16_t                   unk160;                // 160
		std::uint16_t                   maxEmitterObj;         // 162
		std::uint16_t                   maxParticlesPerFrame;  // 164
		bool                            destroyWhenNotInUse;   // 166
		std::uint8_t                    pad167;                // 167
	};
	static_assert(sizeof(BSMasterParticleSystem) == 0x168);
}
