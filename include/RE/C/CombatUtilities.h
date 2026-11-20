#pragma once

#include "RE/A/ActorLOSLocation.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESObjectREFR;

	struct CombatUtilities
	{
		static NiPoint3 GetAngleToProjectedTarget(NiPoint3 a_origin, TESObjectREFR* a_target, float a_speed, float a_gravity, ACTOR_LOS_LOCATION a_location)
		{
			using func_t = decltype(&GetAngleToProjectedTarget);
			static REL::Relocation<func_t> func{ RELOCATION_ID(46022, 523983) };
			return func(a_origin, a_target, a_speed, a_gravity, a_location);
		}

		static bool CheckStraightPath(TESObjectREFR* a_ref, const NiPoint3& a_startPos, NiPoint3& a_endPos, float a_speed, float a_minDistance)
		{
			using func_t = decltype(&CheckStraightPath);
			static REL::Relocation<func_t> func{ RELOCATION_ID(46050, 47314) };
			return func(a_ref, a_startPos, a_endPos, a_speed, a_minDistance);
		}
	};
}
