#include "RE/S/ShadowSceneNode.h"
#include "RE/B/BSLight.h"

namespace RE
{
	BSLight* ShadowSceneNode::AddLight(NiLight* a_light, const ShadowSceneNode::LIGHT_CREATE_PARAMS& a_params)
	{
		using func_t = decltype(&ShadowSceneNode::AddLight);
		static REL::Relocation<func_t> func{ RELOCATION_ID(99692, 106326) };
		return func(this, a_light, a_params);
	}

	BSLight* ShadowSceneNode::GetLight(NiLight* a_light)
	{
		auto light = GetPointLight(a_light);
		if (!light) {
			light = GetShadowLight(a_light);
		}
		return light;
	}

	BSLight* ShadowSceneNode::GetPointLight(NiLight* a_light)
	{
		for (auto& light : activeLights) {
			if (light && light->light.get() == a_light) {
				return light.get();
			}
		}
		return nullptr;
	}

	BSLight* ShadowSceneNode::GetShadowLight(NiLight* a_light)
	{
		for (auto& light : activeShadowLights) {
			if (light && light->light.get() == a_light) {
				return light.get();
			}
		}
		return nullptr;
	}

	void ShadowSceneNode::RemoveLight(NiLight* a_light)
	{
		using func_t = decltype(&ShadowSceneNode::RemoveLight);
		static REL::Relocation<func_t> func{ RELOCATION_ID(99697, 106331) };
		return func(this, a_light);
	}
}
