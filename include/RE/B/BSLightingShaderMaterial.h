#pragma once

#include "RE/B/BSLightingShaderMaterialBase.h"

namespace RE
{
	class BSLightingShaderMaterial : public BSLightingShaderMaterialBase
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSLightingShaderMaterial;
		inline static constexpr auto VTABLE = VTABLE_BSLightingShaderMaterial;
		inline static constexpr auto FEATURE = Feature::kDefault;

		virtual ~BSLightingShaderMaterial();  // 00

		// override (BSLightingShaderMaterialBase)
		virtual BSShaderMaterial* Create() override;            // 01
		virtual Feature           GetFeature() const override;  // 06 - { return Feature::kDefault; }

	protected:
		BSLightingShaderMaterial* ctor()
		{
			using func_t = decltype(&BSLightingShaderMaterial::ctor);
			REL::Relocation<func_t> func{ REL::ID(254404) };
			return func(this);
		}
		friend class BSLightingShaderMaterialBase;
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xA0);
}
