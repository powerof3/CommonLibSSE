#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class BSShadowParabolicLight : public BSShadowLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowParabolicLight;
		inline static constexpr auto VTABLE = VTABLE_BSShadowParabolicLight;

		~BSShadowParabolicLight() override;  // 00

		// override (BSShadowLight)
		bool GetIsParabolicLight() override;                                                                                                          // 07
		bool GetIsOmniLight() override;                                                                                                               // 08
		void Accumulate(std::uint32_t& a_globalShadowLightCount, std::uint32_t& a_shadowMaskChannel, NiPointer<NiAVObject> a_cullingScene) override;  // 09
		void Render() override;                                                                                                                       // 0A
		void SetShadowMapCount(std::uint32_t a_count) override;                                                                                       // 0B
		void ClearShadowMapData() override;                                                                                                           // 0C
		void Unk_0D() override;                                                                                                                       // 0D
		void Unk_0E() override;                                                                                                                       // 0E
		bool UpdateCamera(const NiCamera* a_viewCamera) override;                                                                                     // 10
	};
	static_assert(sizeof(BSShadowParabolicLight) == 0x560);
}
