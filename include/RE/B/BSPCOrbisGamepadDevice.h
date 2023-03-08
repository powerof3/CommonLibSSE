#pragma once

#include "RE/B/BSPCGamepadDeviceDelegate.h"
namespace RE
{
	// PS3/PS4 controller used via RAW HID polling
	class BSPCOrbisGamepadDevice : public BSPCGamepadDeviceDelegate
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCOrbisGamepadDevice;

		struct Keys
		{
			enum Key : std::uint32_t
			{
				// Masks for buttonState
				// Key hardware value.  Matches SCE_PAD_BUTTON_* enum values on ORBIS
				KUp = 0x0010,
				kDown = 0x0040,
				kLeft = 0x0080,
				kRight = 0x0020,
				kPS3_Start = 0x0008,
				kPS3_Back = 0x00100000,
				kPS3_L3 = 0x0002,
				kPS3_R3 = 0x0004,
				kPS3_LB = 0x0400,
				kPS3_RB = 0x0800,
				kPS3_A = 0x4000,
				kPS3_B = 0x2000,
				kPS3_X = 0x8000,
				kPS3_Y = 0x1000,
				// arbitrary values
				kPS3_LT = 0x0009,
				kPS3_RT = 0x000a,
				kPS3_LS = 0x000b,
				kPS3_RS = 0x000c,
			};
		};
		using Key = Keys::Key;

		// unused values are kept here because they may contain other buttons, like the touchpad
		// Further investigation needed
		struct ButtonState
		{
			bool _unused00: 1;        // 0x0001
			bool L3: 1;               // 0x0002
			bool R3: 1;               // 0x0004
			bool PS3_Start: 1;        // 0x0008
			bool Up: 1;               // 0x0010
			bool Right: 1;            // 0x0020
			bool Down: 1;             // 0x0040
			bool Left: 1;             // 0x0080
			bool _unused100: 1;       // 0x0100
			bool _unused200: 1;       // 0x0200
			bool LB: 1;               // 0x0400
			bool RB: 1;               // 0x0800
			bool Y: 1;                // 0x1000 (Triangle)
			bool B: 1;                // 0x2000 (Circle)
			bool A: 1;                // 0x4000 (Cross)
			bool X: 1;                // 0x8000 (Square)
			bool _unused10000: 1;     // 0x00010000
			bool _unused20000: 1;     // 0x00020000
			bool _unused40000: 1;     // 0x00040000
			bool _unused80000: 1;     // 0x00080000
			bool Back: 1;             // 0x00100000
			bool _unused200000: 1;    // 0x00200000
			bool _unused400000: 1;    // 0x00400000
			bool _unused800000: 1;    // 0x00800000
			bool _unused1000000: 1;   // 0x01000000
			bool _unused2000000: 1;   // 0x02000000
			bool _unused4000000: 1;   // 0x04000000
			bool _unused8000000: 1;   // 0x08000000
			bool _unused10000000: 1;  // 0x10000000
			bool _unused20000000: 1;  // 0x20000000
			bool _unused40000000: 1;  // 0x40000000
			bool _unused80000000: 1;  // 0x80000000
		};
		static_assert(sizeof(ButtonState) == 0x4);

		// Note: This doesn't match the DS4 HID report data structure(s) known publicly.
		// May be massaged somewhere else in the code, or a previously unknown HID report structure.
		struct HIDState
		{
			std::uint32_t buttonState;         // 00 -- doesn't match publicly known HID data button fields, but works with button masks above
			std::byte     rawLeftStickX;       // 04
			std::byte     rawLeftStickY;       // 05
			std::byte     rawRightStickX;      // 06
			std::byte     rawRightStickY;      // 07
			std::byte     rawLeftTrigger;      // 08
			std::byte     rawRightTrigger;     // 09
			std::byte     unk_0A;              // 0A
			std::byte     unk_0B;              // 0B
			std::uint32_t unk_0C;              // 0C  -- this is really a 64-bit value, but structure size is off if I try to insert an unaligned uint64_t
			std::uint32_t unk_10;              // 10  -- part of the above 64-bit value
			std::uint32_t unk_14;              // 14
			std::uint32_t unk_18;              // 18
			std::uint32_t unk_1C;              // 1C
			std::uint64_t unk_20;              // 20
			std::uint64_t unk_28;              // 28
			std::uint32_t unk_30;              // 30
			std::byte     unk_34;              // 34
			std::byte     unk_35[23];          // 35
			bool          hidDeviceConnected;  // 4C
			std::byte     unk_4D[3];           // 4D
			std::uint64_t unk_50;              // 50
			std::byte     unk_58[16];          // 58
			std::byte     unk_68;              // 68
			std::byte     unk_69[15];          // 69
		};
		static_assert(sizeof(HIDState) == 0x78);

		~BSPCOrbisGamepadDevice() override;  // 00

		// override (BSPCGamepadDeviceDelegate)
		void Initialize() override;                                                                   // 01
		void Process(float a_arg1) override;                                                          // 02
		void Release() override;                                                                      // 03
		void Reset() override;                                                                        // 08 - { memset(this+0xD8, 0, 0x120); }
		void Unk_09(void) override;                                                                   // 09 - takes two floats, and then does some HID polling
		void Unk_0A(void) override;                                                                   // 0A - takes in a structure, and then does some HID polling
		void Unk_0B(void) override;                                                                   // 0B - no params, does HID polling
		void ProcessRawInput(int32_t a_rawX, int32_t a_rawY, float& a_outX, float& a_outY) override;  // 0D
		void Unk_0E(void) override;                                                                   // 0E - { return; }

		ButtonState GetPreviousButtonState()
		{
			return stl::unrestricted_cast<ButtonState>(previousHIDState.buttonState);
		};

		ButtonState GetCurrentButtonState()
		{
			return stl::unrestricted_cast<ButtonState>(currentHIDState.buttonState);
		};

		// members
		HIDState previousHIDState;  // D8
		float    previousLT;        // 150
		float    previousRT;        // 154
		float    previousLX;        // 158
		float    previousLY;        // 15C
		float    previousRX;        // 160
		float    previousRY;        // 164
		HIDState currentHIDState;   // 168
		float    currentLT;         // 1E0
		float    currentRT;         // 1E4
		float    currentLX;         // 1E8
		float    currentLY;         // 1EC
		float    currentRX;         // 1F0
		float    currentRY;         // 1F4
	};
	static_assert(sizeof(BSPCOrbisGamepadDevice) == 0x1F8);

}