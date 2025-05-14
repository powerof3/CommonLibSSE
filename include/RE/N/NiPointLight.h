#pragma once

#include "RE/N/NiLight.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	class NiPointLight : public NiLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiPointLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiPointLight;
		inline static constexpr auto VTABLE = VTABLE_NiPointLight;

		~NiPointLight() override;  // 00

		// override (NiLight)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiPointLight* Create()
		{
			auto light = malloc<NiPointLight>();
			std::memset((void*)light, 0, sizeof(NiPointLight));
			if (light) {
				light->Ctor();
			}
			return light;
		}

		void SetLightAttenuation(float a_radius)
		{
			using func_t = decltype(&NiPointLight::SetLightAttenuation);
			static REL::Relocation<func_t> func{ RELOCATION_ID(17224, 17626) };
			return func(this, a_radius);
		}

		// members
		float constAttenuation;      // 140
		float linearAttenuation;     // 144
		float quadraticAttenuation;  // 148

	private:
		NiPointLight* Ctor()
		{
			using func_t = decltype(&NiPointLight::Ctor);
			static REL::Relocation<func_t> func{ RELOCATION_ID(69583, 70967) };
			return func(this);
		}
	};
	static_assert(sizeof(NiPointLight) == 0x150);
}
