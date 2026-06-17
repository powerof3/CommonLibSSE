#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSTerrainNode;
	class NiNode;

	class BGSDistantObjectBlock
	{
	public:
		// members
		BGSTerrainNode*   terrainNode;  // 00 - todo: check
		NiPointer<NiNode> node;         // 08 - todo: check
		bool              doneLoading;  // 10
		bool              attached;     // 11
		bool              prepared;     // 12
		std::uint8_t      pad13[5];     // 13
	};
	static_assert(sizeof(BGSDistantObjectBlock) == 0x18);
}
