#pragma once

namespace RE
{
	class hkpCollidable;
	class NiAVObject;
	class TESObjectREFR;

	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpCollidable& a_linkedCollidable);
		NiAVObject*    FindCollidableObject(const hkpCollidable& a_linkedCollidable);
		float          GetDamageForImpact(float a_mass, float a_speed);
	}
}
