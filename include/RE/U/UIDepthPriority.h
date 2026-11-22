#pragma once

namespace RE
{
	enum class UI_DEPTH_PRIORITY : std::int32_t
	{
		k3DUnderHUD = 0,
		kBook = 1,
		kHUD = 2,
		kStandard = 3,
		kGameMessage = 4,
		kPauseMenu = 5,
		kUnk06 = 6,
		kUnk07 = 7,
		kLoading3DModel = 8,
		kLoadingMenu = 9,
		kMessage = 10,
		kDebug = 11,
		kConsole = 12,
		kCursor = 13
	};
}
