#pragma once

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

		virtual ~QuickSaveLoadHandler() = default;                  // 00

		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessKinect(KinectEvent* a_event) override;          // 02
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
		bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
		bool ProcessButton(ButtonEvent* a_event) override;          // 05

	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(QuickSaveLoadHandler) == 0x10);
}
