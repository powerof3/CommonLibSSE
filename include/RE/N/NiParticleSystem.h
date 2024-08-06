#pragma once

#include "RE/N/NiParticles.h"
#include "RE/N/NiTPointerList.h"

namespace RE
{
	class NiPSysModifier;

	class NiParticleSystem : public NiParticles
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiParticleSystem;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiParticleSystem;
		inline static constexpr auto VTABLE = VTABLE_NiParticleSystem;

		~NiParticleSystem() override;  // 00

		// override (NiParticles)
		const NiRTTI* GetRTTI() const override;                                                                                    // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;                                                           // 17
		void          LoadBinary(NiStream& a_stream) override;                                                                     // 18
		void          LinkObject(NiStream& a_stream) override;                                                                     // 19 - { BSGeometry::LinkObject(a_stream); }
		bool          RegisterStreamables(NiStream& a_stream) override;                                                            // 1A - { return BSGeometry::RegisterStreamables(a_stream); }
		void          SaveBinary(NiStream& a_stream) override;                                                                     // 1B
		bool          IsEqual(NiObject* a_object) override;                                                                        // 1C - { return BSGeometry::IsEqual(); }
		void          ProcessClone(NiCloningProcess& a_cloning) override;                                                          // 1D
		void          SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
		void          UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                                     // 2C
		void          UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                             // 2D
		void          UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                                // 2E
		void          UpdateWorldData(NiUpdateData* a_data) override;                                                              // 30

		// add
		virtual void UpdateSystem(float a_time);     // 38 - { return NiParticleSystem::Do_UpdateSystem(a_time); }
		virtual void Do_UpdateSystem(float a_time);  // 39

		void AddModifier(NiPSysModifier* a_modifier)
		{
			using func_t = decltype(&NiParticleSystem::AddModifier);
			static REL::Relocation<func_t> func{ RELOCATION_ID(72799, 74499) };
			return func(this, a_modifier);
		}

		// members
		NiTPointerList<NiPointer<NiPSysModifier>> modifierList;   // 168
		float                                     unk180;         // 180
		float                                     unk184;         // 184
		float                                     unk188;         // 188
		float                                     lastUpdate;     // 18C
		bool                                      resetSystem;    // 190
		bool                                      dynamicBounds;  // 191
		bool                                      isWorldspace;   // 192
		std::uint8_t                              pad193;         // 192
		std::uint32_t                             pad194;         // 194
	};
	static_assert(sizeof(NiParticleSystem) == 0x198);
}
