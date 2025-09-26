#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/B/ButtonEvent.h"
#include "RE/C/CharEvent.h"
#include "RE/D/DeviceConnectEvent.h"
#include "RE/K/KinectEvent.h"
#include "RE/M/MouseMoveEvent.h"
#include "RE/T/ThumbstickEvent.h"

namespace RE
{
	class BSInputEventQueue : public BSTSingletonSDM<BSInputEventQueue>
	{
	public:
		inline static constexpr std::uint8_t MAX_BUTTON_EVENTS = 10;
		inline static constexpr std::uint8_t MAX_CHAR_EVENTS = 5;
		inline static constexpr std::uint8_t MAX_MOUSE_EVENTS = 1;
		inline static constexpr std::uint8_t MAX_THUMBSTICK_EVENTS = 2;
		inline static constexpr std::uint8_t MAX_CONNECT_EVENTS = 1;
		inline static constexpr std::uint8_t MAX_KINECT_EVENTS = 1;

		static BSInputEventQueue* GetSingleton();

		template <class... Args>
		void AddButtonEvent(Args&&... args)
		{
			if (buttonEventCount < MAX_BUTTON_EVENTS) {
				auto& cachedEvent = buttonEvents[buttonEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				PushOntoInputQueue(&cachedEvent);
				++buttonEventCount;
			}
		}

		template <class... Args>
		void AddCharEvent(Args&&... args)
		{
			if (charEventCount < MAX_CHAR_EVENTS) {
				auto& cachedEvent = charEvents[charEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				++charEventCount;
			}
		}

		template <class... Args>
		void AddMouseMoveEvent(Args&&... args)
		{
			if (mouseEventCount < MAX_MOUSE_EVENTS) {
				auto& cachedEvent = mouseEvents[mouseEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				PushOntoInputQueue(&cachedEvent);
				++mouseEventCount;
			}
		}

		template <class... Args>
		void AddThumbstickEvent(Args&&... args)
		{
			if (thumbstickEventCount < MAX_THUMBSTICK_EVENTS) {
				auto& cachedEvent = thumbstickEvents[thumbstickEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				PushOntoInputQueue(&cachedEvent);
				++thumbstickEventCount;
			}
		}

		template <class... Args>
		void AddConnectEvent(Args&&... args)
		{
			if (connectEventCount < MAX_CONNECT_EVENTS) {
				auto& cachedEvent = connectEvents[connectEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				PushOntoInputQueue(&cachedEvent);
				++connectEventCount;
			}
		}

		template <class... Args>
		void AddKinectEvent(Args&&... args)
		{
			if (kinectEventCount < MAX_KINECT_EVENTS) {
				auto& cachedEvent = kinectEvents[kinectEventCount];
				cachedEvent.Init(std::forward<Args>(args)...);
				PushOntoInputQueue(&cachedEvent);
				++kinectEventCount;
			}
		}
		void PushOntoInputQueue(InputEvent* a_event);
		void ClearInputQueue();

		// members
		std::uint8_t       pad001;                                   // 001
		std::uint16_t      pad002;                                   // 002
		std::uint32_t      buttonEventCount;                         // 004
		std::uint32_t      charEventCount;                           // 008
		std::uint32_t      mouseEventCount;                          // 00C
		std::uint32_t      thumbstickEventCount;                     // 010
		std::uint32_t      connectEventCount;                        // 014
		std::uint32_t      kinectEventCount;                         // 018
		std::uint32_t      pad01C;                                   // 01C
		ButtonEvent        buttonEvents[MAX_BUTTON_EVENTS];          // 020
		CharEvent          charEvents[MAX_CHAR_EVENTS];              // 200
		MouseMoveEvent     mouseEvents[MAX_MOUSE_EVENTS];            // 2A0
		ThumbstickEvent    thumbstickEvents[MAX_THUMBSTICK_EVENTS];  // 2D0
		DeviceConnectEvent connectEvents[MAX_CONNECT_EVENTS];        // 330
		KinectEvent        kinectEvents[MAX_KINECT_EVENTS];          // 350
		InputEvent*        queueHead;                                // 380
		InputEvent*        queueTail;                                // 388
	};
	static_assert(sizeof(BSInputEventQueue) == 0x390);
}
