#include "RE/T/TESWorldSpace.h"

namespace RE
{
	void TESWorldSpace::AddPersistentRef(RE::TESObjectREFR* a_ref)
	{
		using func_t = decltype(&TESWorldSpace::AddPersistentRef);
		static REL::Relocation<func_t> func{ RELOCATION_ID(20077, 20520) };
		func(this, a_ref);
	}

	bool TESWorldSpace::HasMaxHeightData() const
	{
		return maxHeightData != nullptr;
	}

	bool TESWorldSpace::GetMaxHeightAt(const NiPoint3& a_xy, float& a_outHeight)
	{
		using func_t = decltype(&TESWorldSpace::GetMaxHeightAt);
		static REL::Relocation<func_t> func{ RELOCATION_ID(20103, 20551) };
		return func(this, a_xy, a_outHeight);
	}

	TESObjectCELL* TESWorldSpace::GetSkyCell()
	{
		using func_t = decltype(&TESWorldSpace::GetSkyCell);
		static REL::Relocation<func_t> func{ RELOCATION_ID(20095, 20543) };
		return func(this);
	}

	float TESWorldSpace::GetDefaultWaterHeight() const
	{
		auto world = this;
		while (world->parentWorld && world->parentUseFlags.any(ParentUseFlag::kUseLandData)) {
			world = world->parentWorld;
		}
		return world->defaultWaterHeight;
	}

	TESObjectCELL* TESWorldSpace::LoadCell(std::int16_t a_x, std::int16_t a_y)
	{
		using func_t = decltype(&TESWorldSpace::LoadCell);
		static REL::Relocation<func_t> func{ RELOCATION_ID(20026, 20460) };
		return func(this, a_x, a_y);
	}

	void TESWorldSpace::RemovePersistentRef(RE::TESObjectREFR* a_ref)
	{
		using func_t = decltype(&TESWorldSpace::RemovePersistentRef);
		static REL::Relocation<func_t> func{ RELOCATION_ID(20078, 20521) };
		func(this, a_ref);
	}
}
