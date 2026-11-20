#pragma once

namespace RE
{
	struct GrassParam;
	class NiPoint3;
	class TESObjectLAND;

	class CreateGrassParams
	{
	public:
		// members
		std::int32_t   cellX;             // 00
		std::int32_t   cellY;             // 04
		std::int32_t   quad;              // 08
		char           pad0C[4];          // 0C
		TESObjectLAND* land;              // 10
		NiPoint3*      grassPatchStart;   // 18
		GrassParam*    grassParam;        // 20
		float*         grassDensityPcts;  // 28
#ifdef SKYRIM_SUPPORT_AE
		float densityMultiplier;  // 30
#endif
		float         distanceFromWaterLevel;  // 30
		std::uint32_t underwaterState;         // 34
		float         waterHeight;             // 38
		std::uint32_t minSlopeDegrees;         // 3C
		std::uint32_t maxSlopeDegrees;         // 40
#ifdef SKYRIM_SUPPORT_AE
		char pad44[0x8];  // 48
#else
		char pad44[0xC];  // 44
#endif
	};
	static_assert(sizeof(CreateGrassParams) == 0x50);
}
