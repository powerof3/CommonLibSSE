#include "RE/T/TESHavokUtilities.h"

namespace RE
{
	namespace TESHavokUtilities
	{
		TESObjectREFR* FindCollidableRef(const hkpCollidable& a_linkedCollidable)
		{
			using func_t = decltype(&FindCollidableRef);
			REL::Relocation<func_t> func{ Offset::TESHavokUtilities::FindCollidableRef };
			return func(a_linkedCollidable);
		}

		NiAVObject* FindCollidableObject(const hkpCollidable& a_linkedCollidable)
		{
			using func_t = decltype(&FindCollidableObject);
			REL::Relocation<func_t> func{ RELOCATION_ID(15644, 15870) };
			return func(a_linkedCollidable);
		}

		float GetDamageForImpact(float a_mass, float a_speed)
		{
			using func_t = decltype(&GetDamageForImpact);
			REL::Relocation<func_t> func{ RELOCATION_ID(25478, 26018) };
			return func(a_mass, a_speed);
		}
	}
}
