#pragma once

#include "RE/B/BSShadowLight.h"

namespace RE
{
	class BSShadowFrustumLight : public BSShadowLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSShadowFrustumLight;
		inline static constexpr auto VTABLE = VTABLE_BSShadowFrustumLight;

		~BSShadowFrustumLight() override;  // 00

		// override (BSShadowLight)
		void Unk_04() override;                                                                                                                       // 04
		bool GetIsFrustumLight() override;                                                                                                            // 05
		void Accumulate(std::uint32_t& a_globalShadowLightCount, std::uint32_t& a_shadowMaskChannel, NiPointer<NiAVObject> a_cullingScene) override;  // 09
		void Render() override;                                                                                                                       // 0A
		bool UpdateCamera(const NiCamera* a_viewCamera) override;                                                                                     // 10

		// members
		float xFOV;          // 560
		float yFOV;          // 564
		float falloff;       // 568
		float nearDistance;  // 56C
		float farDistance;   // 570
	};
	static_assert(sizeof(BSShadowFrustumLight) == 0x578);
}
