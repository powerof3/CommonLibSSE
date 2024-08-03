#include "RE/B/BSShaderProperty.h"

#include "RE/B/BSRenderPass.h"

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

	BSRenderPass* BSShaderProperty::RenderPassArray::MakeRenderPass(BSShader* a_shader, BSShaderProperty* a_property, BSGeometry* a_geometry, uint32_t a_technique, uint8_t a_numLights, BSLight** a_lights)
	{
		using func_t = decltype(&BSShaderProperty::RenderPassArray::MakeRenderPass);
		static REL::Relocation<func_t> func{ RELOCATION_ID(100717, 107497) };
		return func(this, a_shader, a_property, a_geometry, a_technique, a_numLights, a_lights);
	}

	void BSShaderProperty::RenderPassArray::ClearRenderPass(BSRenderPass* a_pass)
	{
		using func_t = decltype(&RenderPassArray::ClearRenderPass);
		static REL::Relocation<func_t> func{ RELOCATION_ID(100718, 107498) };
		func(this, a_pass);
	}

	void BSShaderProperty::RenderPassArray::Clear()
	{
		while (head != nullptr) {
			BSRenderPass* next = head->next;
			ClearRenderPass(head);
			head = next;
		}
		head = nullptr;
	}

	BSRenderPass* BSShaderProperty::RenderPassArray::EmplacePass(BSShader* a_shader, BSShaderProperty* a_property, BSGeometry* a_geometry,
		uint32_t a_technique, uint8_t a_numLights, BSLight* a_light0, BSLight* a_light1, BSLight* a_light2, BSLight* a_light3)
	{
		BSLight* lights[4]{
			a_light0,
			a_light1,
			a_light2,
			a_light3
		};
		auto* newPass = MakeRenderPass(a_shader, a_property, a_geometry, a_technique, a_numLights, lights);
		if (head != nullptr) {
			RE::BSRenderPass* lastPass = head;
			while (lastPass->next != nullptr) {
				lastPass = lastPass->next;
			}
			lastPass->next = newPass;
		} else {
			head = newPass;
		}
		return newPass;
	}
}
