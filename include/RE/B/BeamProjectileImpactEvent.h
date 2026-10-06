#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class Projectile;

	struct BeamProjectileImpactEvent
	{
	public:
		// members
		Projectile*   projectile;  // 00
		NiPoint3      contactPos;  // 08
		std::uint32_t pad14;       // 14
	};
	static_assert(sizeof(BeamProjectileImpactEvent) == 0x18);
}
