#pragma once

#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESObjectREFR;

	enum class ACTOR_LOS_LOCATION
	{
		kOrigin = 0,
		kEye = 1,
		kHead = 2,
		kTorso = 3,
		kFeet = 4
	};

	struct CombatUtilities
	{
		static RE::NiPoint3 GetAngleToProjectedTarget(RE::NiPoint3 a_origin, RE::TESObjectREFR* a_target, float a_speed, float a_gravity, RE::ACTOR_LOS_LOCATION a_location)
		{
			using func_t = decltype(&GetAngleToProjectedTarget);
			REL::Relocation<func_t> func{ Offset::CombatUtilities::GetAngleToProjectedTarget };
			return func(a_origin, a_target, a_speed, a_gravity, a_location);
		}
	};
}
