#include "RE/B/BSInputEventQueue.h"

namespace RE
{
	BSInputEventQueue* BSInputEventQueue::GetSingleton()
	{
		REL::Relocation<BSInputEventQueue**> singleton{ RELOCATION_ID(520856, 407374) };
		return *singleton;
	}

	void BSInputEventQueue::AddButtonEvent(INPUT_DEVICE a_device, std::int32_t a_id, float a_value, float a_duration)
	{
		if (buttonEventCount < MAX_BUTTON_EVENTS) {
			auto& cachedEvent = buttonEvents[buttonEventCount];
			cachedEvent.value = a_value;
			cachedEvent.heldDownSecs = a_duration;
			cachedEvent.device = a_device;
			cachedEvent.idCode = a_id;
			cachedEvent.userEvent = {};

			PushOntoInputQueue(&cachedEvent);
			++buttonEventCount;
		}
	}

	void BSInputEventQueue::AddCharEvent(std::uint32_t a_keyCode)
	{
		if (charEventCount < MAX_CHAR_EVENTS) {
			auto& cachedEvent = charEvents[charEventCount];
			cachedEvent.keycode = a_keyCode;

			PushOntoInputQueue(&cachedEvent);
			++charEventCount;
		}
	}

	void BSInputEventQueue::AddMouseMoveEvent(std::int32_t a_mouseInputX, std::int32_t a_mouseInputY)
	{
		if (mouseEventCount < MAX_MOUSE_EVENTS) {
			auto& cachedEvent = mouseEvents[mouseEventCount];
			cachedEvent.mouseInputX = a_mouseInputX;
			cachedEvent.mouseInputY = a_mouseInputY;
			cachedEvent.userEvent = {};

			PushOntoInputQueue(&cachedEvent);
			++mouseEventCount;
		}
	}

	void BSInputEventQueue::AddThumbstickEvent(ThumbstickEvent::InputType a_id, float a_xValue, float a_yValue)
	{
		if (thumbstickEventCount < MAX_THUMBSTICK_EVENTS) {
			auto& cachedEvent = thumbstickEvents[thumbstickEventCount];
			cachedEvent.idCode = a_id;
			cachedEvent.xValue = a_xValue;
			cachedEvent.yValue = a_yValue;
			cachedEvent.userEvent = {};

			PushOntoInputQueue(&cachedEvent);
			++thumbstickEventCount;
		}
	}

	void BSInputEventQueue::AddConnectEvent(INPUT_DEVICE a_device, bool a_connected)
	{
		if (connectEventCount < MAX_CONNECT_EVENTS) {
			auto& cachedEvent = connectEvents[connectEventCount];
			cachedEvent.device = a_device;
			cachedEvent.connected = a_connected;

			PushOntoInputQueue(&cachedEvent);
			++connectEventCount;
		}
	}

	void BSInputEventQueue::AddKinectEvent(const BSFixedString& a_userEvent, const BSFixedString& a_heard)
	{
		if (kinectEventCount < MAX_KINECT_EVENTS) {
			auto& cachedEvent = kinectEvents[kinectEventCount];
			cachedEvent.userEvent = a_userEvent;
			cachedEvent.heard = a_heard;

			PushOntoInputQueue(&cachedEvent);
			++kinectEventCount;
		}
	}

	void BSInputEventQueue::PushOntoInputQueue(InputEvent* a_event)
	{
		if (!queueHead) {
			queueHead = a_event;
		}

		if (queueTail) {
			queueTail->next = a_event;
		}

		queueTail = a_event;
		queueTail->next = nullptr;
	}

	void BSInputEventQueue::ClearInputQueue()
	{
		kinectEventCount = 0;
		connectEventCount = 0;
		thumbstickEventCount = 0;
		mouseEventCount = 0;
		charEventCount = 0;
		buttonEventCount = 0;
		queueTail = nullptr;
		queueHead = nullptr;
	}
}
