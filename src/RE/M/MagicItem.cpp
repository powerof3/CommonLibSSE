#include "RE/M/MagicItem.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	float MagicItem::CalculateMagickaCost(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}

	float MagicItem::CalculateTotalGoldValue(Actor* a_caster) const
	{
		return CalculateCost(a_caster);
	}

	MagicItemDataCollector MagicItem::CollectData() const
	{
		MagicItemDataCollector ans(this);
		Traverse(ans);
		return ans;
	}

	EffectSetting* MagicItem::GetAVEffect() const
	{
		using func_t = decltype(&MagicItem::GetAVEffect);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11194, 11302) };
		return func(this);
	}

	Effect* MagicItem::GetCostliestEffectItem(MagicSystem::Delivery a_delivery, bool a_positiveArea) const
	{
		using func_t = decltype(&MagicItem::GetCostliestEffectItem);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11216, 11335) };
		return func(this, a_delivery, a_positiveArea);
	}

	float MagicItem::CalculateCost(Actor* a_caster) const
	{
		using func_t = decltype(&MagicItem::CalculateTotalGoldValue);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11213, 11321) };
		return func(this, a_caster);
	}

	auto MagicItem::GetData()
		-> Data*
	{
		return GetData2();
	}

	auto MagicItem::GetData() const
		-> const Data*
	{
		return GetData1();
	}

	std::int32_t MagicItem::GetLargestArea() const
	{
		using func_t = decltype(&MagicItem::GetLargestArea);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11219, 11338) };
		return func(this);
	}

	std::uint32_t MagicItem::GetLongestDuration() const
	{
		using func_t = decltype(&MagicItem::GetLongestDuration);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11218, 11337) };
		return func(this);
	}

	bool MagicItem::HasEffect(EffectArchetype a_archetype)
	{
		using func_t = decltype(&MagicItem::HasEffect);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11207, 11315) };
		return func(this, a_archetype);
	}

	bool MagicItem::IsHostile() const
	{
		return hostileCount > 0;
	}

	bool MagicItem::IsPermanent() const
	{
		using func_t = decltype(&MagicItem::IsPermanent);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11183, 11290) };
		return func(this);
	}

	void MagicItem::Traverse(MagicItemTraversalFunctor& a_visitor) const
	{
		using func_t = decltype(&MagicItem::Traverse);
		static REL::Relocation<func_t> func{ RELOCATION_ID(11222, 11341) };
		return func(this, a_visitor);
	}
	[[nodiscard]] bool MagicItem::IsSpellPlayable() const 
	{
		using st = MagicSystem::SpellType;
		const auto type = GetSpellType();
		const auto skill = GetAssociatedSkill();

		switch (type){
			case st::kStaffEnchantment:
			case st::kScroll:
			case st::kSpell:
			case st::kLeveledSpell:
			case st::kVoicePower:
			case st::kLesserPower:
			case st::kPower:
			break;
			default:
			return false;
		}

		switch (skill){
			case ActorValue::kAlteration:
			case ActorValue::kConjuration:
			case ActorValue::kDestruction:
			case ActorValue::kIllusion:
			case ActorValue::kRestoration:
			return true;
			default: 
			return false;
		}
	}

	[[nodiscard]] bool MagicItem::IsSelfTargeted() const 
	{
		return GetDelivery() == MagicSystem::Delivery::kSelf;
	}
}
