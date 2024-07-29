#pragma once

#include "RE/N/NiAVObject.h"
#include "RE/N/NiGeometryData.h"
#include "RE/N/NiProperty.h"
#include "RE/N/NiSkinInstance.h"

namespace RE
{
	class NiGeometry : public NiAVObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiGeometry;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiGeometry;
		inline static constexpr auto VTABLE = VTABLE_NiGeometry;

		~NiGeometry() override;  // 00

		// override (NiAVObject)
		const NiRTTI* GetRTTI() const override;                                                                                    // 02
		void          LoadBinary(NiStream& a_stream) override;                                                                     // 18
		void          LinkObject(NiStream& a_stream) override;                                                                     // 19
		bool          RegisterStreamables(NiStream& a_stream) override;                                                            // 1A
		void          SaveBinary(NiStream& a_stream) override;                                                                     // 1B
		bool          IsEqual(NiObject* a_object) override;                                                                        // 1C
		void          ProcessClone(NiCloningProcess& a_cloning) override;                                                          // 1D
		void          AttachProperty(NiAlphaProperty* a_property) override;                                                        // 27
		void          SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid) override;  // 2B
		void          UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                                     // 2C
		void          UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                             // 2D
		void          UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;                                // 2E
		void          UpdateWorldBound() override;                                                                                 // 2F

		// override (NiObject)
		NiGeometry* AsNiGeometry() { return nullptr; }                             // 0D
		void        PostLinkObject([[maybe_unused]] NiStream& a_stream) override;  // 1E

		// add
		virtual void  Unk_35(void);                           // 35 - call controller vtbl+0xA0?
		virtual void  Unk_36(void);                           // 36 - ret 0
		virtual void  Unk_37(void);                           // 37 - same as Unk_33
		virtual void* Unk_38(void);                           // 38 - ret call spModelData vtbl+0x9C
		virtual void  SetGeometryData(NiGeometryData* unk1);  // 39 - set and AddRef geometry data
		virtual void* Unk_3A(void);                           // 3A - ret callspModelData vtbl+0x94

		// members
		NiPointer<NiProperty>     spPropertyState;  // 110
		NiPointer<NiProperty>     spEffectState;    // 118
		NiPointer<NiSkinInstance> spSkinInstance;   // 120
		NiPointer<NiGeometryData> spModelData;      // 128
		std::uint64_t             unk130;           // 130
	};
	static_assert(sizeof(NiGeometry) == 0x138);
}
