#pragma once

#include "RE/B/BSResourceHandle.h"

namespace RE
{
	class BGSTerrainManager;

	class BGSTerrainNode
	{
	public:
		enum class Flag
		{
			kUnk0 = 0x1,
			kUnk1 = 0x2,
			kUnk2 = 0x4,
			kTerrainIsSplit = 0x8,
			kUnk3 = 0x10,
			kUnk4 = 0x20,
			kUnk5 = 0x40,
			kUnk6 = 0x80,
			kUnk7 = 0x100,
			kUnk8 = 0x400,
			kUnk9 = 0x800,

			kNeedsUpdate = 0x1000,
			kNeedsTreeVisUpdate = 0x2000,
			kUnk10 = 0x4000,
			kUnk11 = 0x8000,

			kLODLevel4 = 0x800000,
			kLODLevel8 = 0x1000000,
			kLODLevel16 = 0x2000000,
			kLODLevel32 = 0x4000000,
			kLODLevel64 = 0x8000000,
			kLODLevel128 = 0x10000000,
			kLODLevel256 = 0x20000000,
			kLODLevel512 = 0x40000000
		};

		std::uint32_t GetLODLevel() const { return (nodeState.underlying() >> 21) & 0x3FC; }

		// members
		BGSTerrainManager*                manager;         // 00
		BGSBtrDBHandle                    chunkHandle;     // 08
		BGSBtoDBHandle                    blockHandle;     // 10
		BGSBttDBHandle                    treeHandle;      // 18
		BGSBtrDBHandle                    mapChunkHandle;  // 20
		BGSBtoDBHandle                    mapBlockHandle;  // 28
		BGSTerrainNode*                   children;        // 30
		BGSTerrainNode*                   parent;          // 38
		REX::TEnumSet<Flag, std::uint32_t> nodeState;       // 40
		std::uint32_t                     nodeNumber;      // 44
		std::int16_t                      baseCellX;       // 48
		std::int16_t                      baseCellY;       // 4A
		std::uint32_t                     pad4C;           // 4C
	};
	static_assert(sizeof(BGSTerrainNode) == 0x50);
}
