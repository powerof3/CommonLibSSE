#pragma once

#include "RE/A/AnimationSystemUtils.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESActionData.h"

namespace RE
{
	class CombatAnimation
	{
	public:
		enum ANIM : std::uint32_t
		{
			kActionRightAttack = 0,
			kActionRightRelease = 1,
			kActionRightPowerAttack = 2,
			kActionLeftAttack = 3,
			kActionLeftRelease = 4,
			kActionRightAttack2 = 5,
			kActionRightRelease2 = 6,
			kActionRightInterrupt = 7,
			kActionSneak = 8,
			kActionActivate = 9
		};

		enum class STATE
		{
			kNoChange = 0,
			kClearedDetailedPath = 1,
			kCreatedDetailedPath = 2,
			kUpdatedDetailedPath = 3,
			kFailed = -1,
		};

		CombatAnimation(Actor* a_actor, ANIM a_anim);
		CombatAnimation(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim);
		CombatAnimation(Actor* a_actor, BGSAction* a_action);
		~CombatAnimation() = default;

		bool Execute() { return actionData.Process(); }
		bool LoadClipData();

		static bool ConstructAndExecute(Actor* a_actor, ANIM a_anim);
		static bool ConstructAndExecute(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim);

		// members
		TESActionData                                     actionData;  // 00
		BSScrapArray<AnimationSystemUtils::UtilsClipData> clipData;    // 60
		REX::EnumSet<STATE, std::int32_t>                 state;       // 80
		std::uint32_t                                     pad84;       // 84

	private:
		CombatAnimation* Ctor0(Actor* a_actor, ANIM a_anim);
		CombatAnimation* Ctor1(Actor* a_actor, TESObjectREFR* a_target, ANIM a_anim);
		CombatAnimation* Ctor2(Actor* a_actor, BGSAction* a_action);
	};
	static_assert(sizeof(CombatAnimation) == 0x88);
}
