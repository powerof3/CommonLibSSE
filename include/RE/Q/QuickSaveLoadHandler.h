#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class KinectEvent;
	class MouseMoveEvent;
	class ThumbstickEvent;

	class QuickSaveLoadHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_QuickSaveLoadHandler;
		inline static constexpr auto VTABLE = VTABLE_QuickSaveLoadHandler;

		~QuickSaveLoadHandler() override;  // 00

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessKinect(KinectEvent* a_event) override;          // 02
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05
	};
	static_assert(sizeof(QuickSaveLoadHandler) == 0x10);
}
