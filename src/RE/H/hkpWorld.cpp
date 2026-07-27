#include "RE/H/hkpWorld.h"

namespace RE
{
	hkpPhantom* hkpWorld::AddPhantom(hkpPhantom* a_phantom)
	{
		using func_t = decltype(&hkpWorld::AddPhantom);
		static REL::Relocation<func_t> func{ RELOCATION_ID(60502, 61314) };
		return func(this, a_phantom);
	}

	void hkpWorld::CastRay(const hkpWorldRayCastInput& a_input, hkpWorldRayCastOutput& a_output) const
	{
		using func_t = decltype(&hkpWorld::CastRay);
		static REL::Relocation<func_t> func{ RELOCATION_ID(60551, 61399) };
		func(this, a_input, a_output);
	}

	void hkpWorld::RemoveEntity(hkpEntity* a_entity)
	{
		using func_t = decltype(&hkpWorld::RemoveEntity);
		static REL::Relocation<func_t> func{ RELOCATION_ID(60493, 61305) };
		func(this, a_entity);
	}

	void hkpWorld::RemovePhantom(hkpPhantom* a_phantom)
	{
		using func_t = decltype(&hkpWorld::RemovePhantom);
		static REL::Relocation<func_t> func{ RELOCATION_ID(60504, 61316) };
		func(this, a_phantom);
	}

	void hkpWorld::LinearCast(const hkpCollidable* a_colA, const hkpLinearCastInput& a_input, hkpCdPointCollector& a_castCollector, hkpCdPointCollector* a_startCollector) const
	{
		using func_t = decltype(&hkpWorld::LinearCast);
		static REL::Relocation<func_t> func{ RELOCATION_ID(60554, 61402) };
		func(this, a_colA, a_input, a_castCollector, a_startCollector);
	}
}
