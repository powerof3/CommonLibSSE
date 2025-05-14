#pragma once

#include "RE/N/NiLight.h"

#include "RE/M/MemoryManager.h"

namespace RE
{
	class NiDirectionalLight : public NiLight
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiDirectionalLight;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiDirectionalLight;
		inline static constexpr auto VTABLE = VTABLE_NiDirectionalLight;

		~NiDirectionalLight() override;  // 00

		// override (NiLight)
		const NiRTTI* GetRTTI() const override;                           // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;  // 17
		void          LoadBinary(NiStream& a_stream) override;            // 18
		void          SaveBinary(NiStream& a_stream) override;            // 1B
		bool          IsEqual(NiObject* a_object) override;               // 1C

		static NiDirectionalLight* Create()
		{
			auto light = malloc<NiDirectionalLight>();
			std::memset((void*)light, 0, sizeof(NiDirectionalLight));
			if (light) {
				light->Ctor();
			}
			return light;
		}

		// members
		NiPoint3 worldDir;     // 140
		NiColor  effectColor;  // 14C

	private:
		NiDirectionalLight* Ctor()
		{
			using func_t = decltype(&NiDirectionalLight::Ctor);
			static REL::Relocation<func_t> func{ RELOCATION_ID(69692, 71073) };
			return func(this);
		}
	};
	static_assert(sizeof(NiDirectionalLight) == 0x158);
}
