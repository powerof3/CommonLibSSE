#pragma once

#include "RE/I/IMessageBoxCallback.h"

namespace RE
{
	class MapMenu;

	class FastTravelConfirmCallback : public IMessageBoxCallback
	{
	public:
		inline static constexpr auto RTTI = RTTI___FastTravelConfirmCallback;
		inline static constexpr auto VTABLE = VTABLE___FastTravelConfirmCallback;

		~FastTravelConfirmCallback() override;  // 00

		// override (IMessageBoxCallback)
		void Run(std::uint8_t a_button) override;  //01

		// members
		MapMenu*     mapMenu;     // 10
		std::int32_t cursorPosX;  // 18
		std::int32_t cursorPosY;  // 1C
	};
	static_assert(sizeof(FastTravelConfirmCallback) == 0x20);
}
