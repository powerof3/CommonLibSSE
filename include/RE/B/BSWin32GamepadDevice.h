#pragma once

#include "RE/B/BSPCGamepadDeviceDelegate.h"

namespace RE
{
	// So we don't have to include XInput.h
	struct __XINPUT_GAMEPAD
	{
		std::uint16_t wButtons;
		std::byte     bLeftTrigger;
		std::byte     bRightTrigger;
		std::int16_t  sThumbLX;
		std::int16_t  sThumbLY;
		std::int16_t  sThumbRX;
		std::int16_t  sThumbRY;
	};
	struct __XINPUT_STATE
	{
		std::uint32_t    dwPacketNumber;
		__XINPUT_GAMEPAD Gamepad;
	};
	class BSWin32GamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32GamepadDevice;

		struct Keys
		{
			enum Key : std::uint32_t
			{
				// button masks for wButtons
				kUp = 0x0001,
				kDown = 0x0002,
				kLeft = 0x0004,
				kRight = 0x0008,
				kStart = 0x0010,
				kBack = 0x0020,
				kLeftThumb = 0x0040,
				kRightThumb = 0x0080,
				kLeftShoulder = 0x0100,
				kRightShoulder = 0x0200,

				kA = 0x1000,
				kB = 0x2000,
				kX = 0x4000,
				kY = 0x8000,

				// arbitrary values
				kLeftTrigger = 0x0009,
				kRightTrigger = 0x000A
			};
		};
		using Key = Keys::Key;

		struct ButtonState
		{
			bool up: 1;             // 0x0001
			bool down: 1;           // 0x0002
			bool left: 1;           // 0x0004
			bool right: 1;          // 0x0008
			bool start: 1;          // 0x0010
			bool back: 1;           // 0x0020
			bool leftThumb: 1;      // 0x0040
			bool rightThumb: 1;     // 0x0080
			bool leftShoulder: 1;   // 0x0100
			bool rightShoulder: 3;  // 0x0200, skip over 2 bits (XInput documentation says the state of these two bits are undefined)
			bool a: 1;              // 0x1000
			bool b: 1;              // 0x2000
			bool x: 1;              // 0x4000
			bool y: 1;              // 0x8000
		};

		~BSWin32GamepadDevice() override;  // 00

		// override (BSPCGamepadDeviceDelegate)
		void Initialize() override;           // 01
		void Process(float a_arg1) override;  // 02
		void Release() override;              // 03 - { return; }
		void Reset() override;                // 08 - { std::memset(&unk0D8, 0, 0x50); }
		void Unk_09(void) override;           // 09 - { return; }

		static constexpr uint32_t BUTTON_MASK = Key::kUp | Key::kDown | Key::kLeft | Key::kRight | Key::kStart | Key::kBack | Key::kLeftThumb | Key::kRightThumb | Key::kLeftShoulder | Key::kRightShoulder | Key::kA | Key::kB | Key::kX | Key::kY;
		// helper functions

		/**
		 * Returns the previous ButtonState of the gamepad
		 *
		 * @return ButtonState
		 */
		ButtonState GetPreviousButtonState()
		{
			return stl::unrestricted_cast<ButtonState>(PreviousState.Gamepad.wButtons & BUTTON_MASK);
		};

		/**
		 * Returns the current ButtonState of the gamepad
		 *
		 * @return ButtonState
		 */
		ButtonState GetCurrentButtonState()
		{
			return stl::unrestricted_cast<ButtonState>(CurrentState.Gamepad.wButtons & BUTTON_MASK);
		};

		// members
		__XINPUT_STATE PreviousState;  // 0D8
		float          PreviousLT;     // 0E8
		float          PreviousRT;     // 0EC
		float          PreviousLX;     // 0F0
		float          PreviousLY;     // 0F4
		float          PreviousRX;     // 0F8
		float          PreviousRY;     // 0FC
		__XINPUT_STATE CurrentState;   // 100
		float          CurrentLT;      // 110
		float          CurrentRT;      // 114
		float          CurrentLX;      // 118
		float          CurrentLY;      // 11C
		float          CurrentRX;      // 120
		float          CurrentRY;      // 124
	};
	static_assert(sizeof(BSWin32GamepadDevice) == 0x128);
}
