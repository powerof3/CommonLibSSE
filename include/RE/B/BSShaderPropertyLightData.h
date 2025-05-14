#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class BSLight;

	class BSShaderPropertyLightData
	{
	public:
		// members
		BSTArray<BSLight*> lights;            // 00
		std::int32_t       lightListFence;    // 18
		std::uint32_t      unk1C;             // 1C
		bool               lightListChanged;  // 20
	};
	static_assert(sizeof(BSShaderPropertyLightData) == 0x28);
}
