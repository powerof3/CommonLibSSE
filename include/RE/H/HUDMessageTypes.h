#pragma once

namespace RE
{
	enum class HUD_MESSAGE_TYPE
	{
		kNone = 0,
		kNotification = 1,
		kSetCrosshairTarget = 2,
		kSetCrosshairTargetTextOnly = 3,
		kSetLoadDoorInfo = 4,
		kShowSubtitle = 5,
		kHideSubtitle = 6,
		kShowArrowCount = 7,
		kUnk08 = 8,
		kUnk09 = 9,
		kSetBlinking = 11,
		kSetFadeOut = 12,
		kSetPct = 13,
		kQuestStarted = 14,
		kQuestComplete = 15,
		kQuestFailed = 16,
		kObjectiveStarted = 17,
		kObjectiveComplete = 18,
		kObjectiveFailed = 19,
		kSkillIncrease = 20,
		kWordOfPowerLearned = 21,
		kDragonSoulAbsorbed = 22,
		kSetMode = 23,
		kCrosshairSneak = 24,
		kUnk25 = 25,
		kLocationDiscovery = 26,
		kFavor = 27,
		kValidateCrosshair = 28,
		kShowLocationName = 29,
		kShowHintText = 30,
		kSetCrosshairEnabled = 31,
		kSetDisplayInfo = 32,
		kRefreshActivateButtonArt = 33,
		kRefreshAll = 34,
		kSurvival = 35,
	};
}
