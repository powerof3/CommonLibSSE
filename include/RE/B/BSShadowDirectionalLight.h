#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{

	class BSShadowDirectionalLight : public BSShadowLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowDirectionalLight;
		inline static constexpr auto VTABLE = VTABLE_BSShadowDirectionalLight;

		~BSShadowDirectionalLight() override;  // 00

		// override (BSShadowLight)
		bool          GetIsFrustumOrDirectionalLight() override;                                                                                     // 04
		bool          GetIsDirectionalLight() override;                                                                                              // 06
		void          Accumulate(std::uint32_t& a_globalShadowLightCount, std::uint32_t& a_shadowMaskChannel, NiAVObject* a_cullingScene) override;  // 09
		void          Render(std::uint32_t& a_index) override;                                                                                       // 0A
		void          ReturnShadowmaps() override;                                                                                                   // 0C
		std::uint32_t GetPassExtraParam(std::uint32_t a_accumFlag) override;                                                                         // 0D
		bool          GetNeedsClipPlanes() override;                                                                                                 // 0E
		void          TransformClipSpacePlanes(REX::W32::D3DMATRIX* a_matrix1, REX::W32::D3DMATRIX* a_matrix2) override;                           // 0F
		bool          UpdateCamera(const NiCamera* a_viewCamera) override;                                                                           // 10

		// members
		NiPoint3                                sunVector;                       // 560
		NiPoint3                                lastSunVector;                   // 56C
		NiPointer<NiCamera>                     fullFrustumCamera;               // 578
		BSTArray<BSGeometryListCullingProcess*> fullFrustumCullingProcessArray;  // 580
		std::uint8_t                            unk598[24];                      // 598
		float                                   sunUpdate;                       // 5B0
		std::uint32_t                           sunUpdateMode;                   // 5B4
	};
	static_assert(sizeof(BSShadowDirectionalLight) == 0x5B8);
}
