#pragma once

namespace RE
{
	enum class WARNING_TYPES : std::int32_t
	{
		kDefault = 0,
		kCombat = 1,
		kAnimation = 2,
		kAI = 3,
		kScripts = 4,
		kSaveLoad = 5,
		kDialogue = 6,
		kQuests = 7,
		kPackages = 8,
		kEditor = 9,
		kModels = 10,
		kTextures = 11,
		kPlugins = 12,
		kMasterFile = 13,
		kForms = 14,
		kMagic = 15,
		kShaders = 16,
		kRendering = 17,
		kPathfinding = 18,
		kMenus = 19,
		kAudio = 20,
		kCells = 21,
		kHavok = 22,
		kFaceGen = 23,
		kWater = 24,
		kInGameMessage = 25,
		kMemory = 26,
		kPerformance = 27,
		kJobs = 28,
		kSystem = 29,
#ifdef SKYRIM_SUPPORT_AE
		kBNet = 30,
#endif
	};
}
