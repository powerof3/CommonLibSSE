#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESObjectCELL;
	class TESObjectREFR;
	class TESWorldSpace;

	struct TeleportPath
	{
	public:
		struct Unk00Data
		{
		public:
			// members
			bool           unk00;         // 00 - Determines whether to use worldspace or cell?
			char           pad01[7];      // 01
			TESWorldSpace* worldspace;    // 08
			TESObjectCELL* interiorCell;  // 10
		};
		static_assert(sizeof(Unk00Data) == 0x18);

		struct Unk18Data
		{
		public:
			// members
			TESObjectREFR* ref;    // 00
			std::uint64_t  unk08;  // 08
			std::uint64_t  unk10;  // 10
		};
		static_assert(sizeof(Unk18Data) == 0x18);

		// members
		BSTArray<Unk00Data> pathCells;  // 00 - each cell in sequence between the current cell and the target cell
		BSTArray<Unk18Data> pathRefs;   // 18 - each teleport ref in sequence between the current cell and the target cell
		std::uint64_t       unk30;      // 30
		std::uint64_t       unk38;      // 38
		std::uint64_t       unk40;      // 40
	};
	static_assert(sizeof(TeleportPath) == 0x48);
}
