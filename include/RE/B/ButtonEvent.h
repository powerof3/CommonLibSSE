#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IDEvent.h"
#include "RE/I/InputEvent.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class ButtonEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_ButtonEvent;
		inline static constexpr auto VTABLE = VTABLE_ButtonEvent;

		~ButtonEvent() override;  // 00

		void Init(INPUT_DEVICE a_device, std::int32_t a_id, float a_value, float a_duration)
		{
			Init(a_device, a_id, a_value, a_duration, ""sv);
		}

		void Init(INPUT_DEVICE a_device, std::int32_t a_id, float a_value, float a_duration, const BSFixedString& a_userEvent)
		{
			value = a_value;
			heldDownSecs = a_duration;
			device = a_device;
			idCode = a_id;
			userEvent = a_userEvent;
#ifdef SKYRIMVR
			unkVR28 = -1;
#endif
		}

#ifdef SKYRIMVR
		void Init(INPUT_DEVICE a_device, std::int32_t a_arg2, std::int32_t a_id, float a_value, float a_duration)
		{
			Init(a_device, a_arg2, a_id, a_value, a_duration, ""sv);
		}

		void Init(INPUT_DEVICE a_device, std::int32_t a_arg2, std::int32_t a_id, float a_value, float a_duration, const BSFixedString& a_userEvent)
		{
			value = a_value;
			heldDownSecs = a_duration;
			device = a_device;
			idCode = a_id;
			userEvent = a_userEvent;
			unkVR28 = a_arg2;
		}
#endif

		[[nodiscard]] constexpr float Value() const noexcept { return value; }
		[[nodiscard]] constexpr float HeldDuration() const noexcept { return heldDownSecs; }
		[[nodiscard]] constexpr bool  IsPressed() const noexcept { return Value() > 0.0F; }
		[[nodiscard]] constexpr bool  IsRepeating() const noexcept { return HeldDuration() > 0.0F; }
		[[nodiscard]] constexpr bool  IsDown() const noexcept { return IsPressed() && (HeldDuration() == 0.0F); }
		[[nodiscard]] constexpr bool  IsHeld() const noexcept { return IsPressed() && IsRepeating(); }
		[[nodiscard]] constexpr bool  IsUp() const noexcept { return (Value() == 0.0F) && IsRepeating(); }

		// members
		float value;         // 28
		float heldDownSecs;  // 2C

		static ButtonEvent* Create(INPUT_DEVICE a_inputDevice, const BSFixedString& a_userEvent, uint32_t a_idCode, float a_value, float a_heldDownSecs)
		{
			auto buttonEvent = malloc<ButtonEvent>(sizeof(ButtonEvent));
			std::memset((void*)buttonEvent, 0, sizeof(ButtonEvent));
			if (buttonEvent) {
				stl::emplace_vtable<ButtonEvent>(buttonEvent);
				buttonEvent->device = a_inputDevice;
				buttonEvent->eventType = INPUT_EVENT_TYPE::kButton;
				buttonEvent->next = nullptr;
				buttonEvent->userEvent = a_userEvent;
				buttonEvent->idCode = a_idCode;
				buttonEvent->value = a_value;
				buttonEvent->heldDownSecs = a_heldDownSecs;
			}
			return buttonEvent;
		}
	};
	static_assert(sizeof(ButtonEvent) == 0x30);
}
