#include "RE/C/CombatAnimation.h"

namespace RE
{
	CombatAnimation::CombatAnimation(Actor* a_actor, ANIM a_anim)
	{
		Ctor0(a_actor, a_anim);
	}

	CombatAnimation::CombatAnimation(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim)
	{
		Ctor1(a_actor, a_target, a_anim);
	}

	CombatAnimation::CombatAnimation(Actor* a_actor, BGSAction* a_action)
	{
		Ctor2(a_actor, a_action);
	}

	bool CombatAnimation::ConstructAndExecute(Actor* a_actor, ANIM a_anim)
	{
		using func_t = bool(Actor*, ANIM);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43245, 44446) };
		return func(a_actor, a_anim);
	}

	bool CombatAnimation::ConstructAndExecute(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim)
	{
		using func_t = bool(Actor*, TESObjectREFR*, ANIM);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43246, 44447) };
		return func(a_actor, a_target, a_anim);
	}

	bool CombatAnimation::LoadClipData()
	{
		using func_t = decltype(&CombatAnimation::LoadClipData);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43247, 44448) };
		return func(this);
	}

	CombatAnimation* CombatAnimation::Ctor0(Actor* a_actor, ANIM a_anim)
	{
		using func_t = decltype(&CombatAnimation::Ctor0);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43235, 44436) };
		return func(this, a_actor, a_anim);
	}

	CombatAnimation* CombatAnimation::Ctor1(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim)
	{
		using func_t = decltype(&CombatAnimation::Ctor1);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43236, 44437) };
		return func(this, a_actor, a_target, a_anim);
	}

	CombatAnimation* CombatAnimation::Ctor2(Actor* a_actor, BGSAction* a_action)
	{
		using func_t = decltype(&CombatAnimation::Ctor2);
		static REL::Relocation<func_t> func{ RELOCATION_ID(43237, 44438) };
		return func(this, a_actor, a_action);
	}
}
