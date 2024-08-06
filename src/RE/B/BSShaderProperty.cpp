#include "RE/B/BSShaderProperty.h"

namespace RE
{
	void BSShaderProperty::SetEffectShaderData(const BSTSmartPointer<BSEffectShaderData>& a_data)
	{
		lastRenderPassState = std::numeric_limits<std::int32_t>::max();
		effectData = a_data;
	}

	void BSShaderProperty::SetMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::SetMaterial);
		static REL::Relocation<func_t> func{ RELOCATION_ID(98897, 105544) };
		return func(this, a_material, a_unk1);
	}

	void BSShaderProperty::SetFlags(EShaderPropertyFlag8 a_flag, bool a_set)
	{
		using func_t = decltype(&BSShaderProperty::SetFlags);
		static REL::Relocation<func_t> func{ RELOCATION_ID(98893, 105540) };
		return func(this, a_flag, a_set);
	}

	void BSShaderProperty::LinkMaterial(BSShaderMaterial* a_material, bool a_unk1)
	{
		using func_t = decltype(&BSShaderProperty::LinkMaterial);
		static REL::Relocation<func_t> func{ RELOCATION_ID(98897, 105544) };
		return func(this, a_material, a_unk1);
	}

	void BSShaderProperty::LoadBinary(NiStream& a_stream)
	{
		auto vtable = REL::Relocation<void***>(BSShaderProperty::VTABLE[0]);
		auto baseMethod = reinterpret_cast<void (*)(BSShaderProperty*, NiStream&)>((vtable.get()[0x18]));
		return baseMethod(this, a_stream);
	}
}
