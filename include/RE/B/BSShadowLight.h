#pragma once

#include "RE/B/BSLight.h"
#include "RE/N/NiFrustumPlanes.h"
#include "RE/N/NiRect.h"

namespace RE
{
	class BSShadowLight : public BSLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowLight;
		inline static constexpr auto VTABLE = VTABLE_BSShadowLight;

		struct ShadowMapData
		{
			REX::W32::XMFLOAT4X4           projection;         // 00
			NiPointer<NiCamera>            camera;             // 40
			NiPointer<BSShaderAccumulator> shaderAccumulator;  // 48
			std::uint32_t                  unk50;              // 50
			RENDER_TARGET_DEPTHSTENCIL     renderTarget;       // 54
			std::uint32_t                  shadowMapIndex;     // 58
			NiFrustumPlanes                clipPlanes;         // 5C
			std::uint32_t                  unitsPerTexel;      // CC
			NiRect<std::uint32_t>          shadowMapRect;      // D0
			BSCullingProcess*              cullingProcess;     // E0
			bool                           clearRenderTarget;  // E8
		};
		static_assert(sizeof(ShadowMapData) == 0xF0);

		~BSShadowLight() override;  // 00

		// add
		virtual void Unk_04();                                                                                                                           // 04
		virtual bool GetIsFrustumLight();                                                                                                                // 05
		virtual void GetIsDirectionalLight();                                                                                                            // 06
		virtual bool GetIsParabolicLight();                                                                                                              // 07
		virtual bool GetIsOmniLight();                                                                                                                   // 08
		virtual void Accumulate(std::uint32_t& a_globalShadowLightCount, std::uint32_t& a_shadowMaskChannel, NiPointer<NiAVObject> a_cullingScene) = 0;  // 09
		virtual void Render() = 0;                                                                                                                       // 0A
		virtual void SetShadowMapCount(std::uint32_t a_count);                                                                                           // 0B
		virtual void ClearShadowMapData();                                                                                                               // 0C
		virtual void Unk_0D();                                                                                                                           // 0D
		virtual void Unk_0E();                                                                                                                           // 0E
		virtual void Unk_0F();                                                                                                                           // 0F
		virtual bool UpdateCamera(const NiCamera* a_viewCamera) = 0;                                                                                     // 10

		// members
		std::uint32_t                   shadowMapIndex;        // 140
		std::uint32_t                   unk144;                // 144
		BSTArray<ShadowMapData>         shadowMapDataList;     // 148
		ShadowMapData                   shadowMapData[4];      // 161
		std::uint32_t                   maskIndex;             // 520
		std::uint32_t                   accumulatedIndex;      // 524
		BSTArray<NiPointer<NiAVObject>> sceneAccumArray;       // 528
		float                           shadowBiasScale;       // 540
		NiRect<std::uint32_t>           projectedBoundingBox;  // 544
		std::uint32_t                   sceneGraphIndex;       // 554
		std::uint8_t                    unk558;                // 558
		std::uint8_t                    pad559;                // 559
		std::uint8_t                    pad55A;                // 55A
		std::uint32_t                   pad55B;                // 55B
	};
	static_assert(sizeof(BSShadowLight) == 0x560);
}
