#include "RE/T/TESWaterReflections.h"

namespace RE
{
	TESWaterReflections* TESWaterReflections::Create(const NiPlane& a_plane, BSWaterShaderMaterial* a_mat, std::uint16_t a_flags, const char* a_texture)
	{
		auto obj = malloc<TESWaterReflections>();
		if (obj) {
			std::memset(obj, 0, sizeof(TESWaterReflections));
			obj->Ctor(a_plane, a_mat, a_flags, a_texture);
		}
		return obj;
	}

	bool TESWaterReflections::Update()
	{
		using func_t = decltype(&TESWaterReflections::Update);
		static REL::Relocation<func_t> func{ RELOCATION_ID(31373, 32160) };
		return func(this);
	}

	TESWaterReflections* TESWaterReflections::Ctor(const NiPlane& a_plane, BSWaterShaderMaterial* a_mat, std::uint16_t a_flags, const char* a_texture)
	{
		using func_t = decltype(&TESWaterReflections::Ctor);
		static REL::Relocation<func_t> func{ RELOCATION_ID(31371, 32158) };
		return func(this, a_plane, a_mat, a_flags, a_texture);
	}
}
