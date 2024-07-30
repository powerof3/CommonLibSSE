#include "RE/B/BSShaderTextureSet.h"

namespace RE
{
	BSShaderTextureSet* BSShaderTextureSet::Ctor()
	{
		using func_t = decltype(&BSShaderTextureSet::Ctor);
		static REL::Relocation<func_t> func{ REL::ID(99886) };
		return func(this);
	}

	BSShaderTextureSet* BSShaderTextureSet::Create()
	{
#ifdef SKYRIM_SUPPORT_AE
		using func_t = decltype(&BSShaderTextureSet::Create);
		static REL::Relocation<func_t> func{ REL::ID(107172) };
		return func();
#else
		auto textureset = malloc<BSShaderTextureSet>();
		std::memset(textureset, 0, sizeof(BSShaderTextureSet));
		if (textureset) {
			textureset->Ctor();
		}
		return textureset;
#endif
	}
}
