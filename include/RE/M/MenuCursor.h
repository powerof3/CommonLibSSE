#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class MenuCursor : public BSTSingletonSDM<MenuCursor>
	{
	public:
		static MenuCursor* GetSingleton();

		void SetCursorVisibility(bool a_visible);

		// members
		std::uint8_t  pad01;              // 01
		std::uint16_t pad02;              // 02
		float         cursorPosX;         // 04
		float         cursorPosY;         // 08
		float         safeZoneX;          // 0C
		float         safeZoneY;          // 10
		float         screenWidthX;       // 14
		float         screenWidthY;       // 18
		float         cursorSensitivity;  // 1C
		float         unk20;              // 20
		float         unk24;              // 24
		float         defaultMouseSpeed;  // 28
		std::int32_t  showCursorCount;    // 2C
	};
	static_assert(sizeof(MenuCursor) == 0x30);
}
