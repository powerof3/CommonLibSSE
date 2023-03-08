#include "SKSE/InputMap.h"

#include <Windows.h>

#include <Xinput.h>

namespace SKSE
{
	std::uint32_t InputMap::GamepadMaskToKeycode(std::uint32_t keyMask)
	{
		switch (keyMask) {
		case XINPUT_GAMEPAD_DPAD_UP:
			return kGamepadButtonOffset_DPAD_UP;
		case XINPUT_GAMEPAD_DPAD_DOWN:
			return kGamepadButtonOffset_DPAD_DOWN;
		case XINPUT_GAMEPAD_DPAD_LEFT:
			return kGamepadButtonOffset_DPAD_LEFT;
		case XINPUT_GAMEPAD_DPAD_RIGHT:
			return kGamepadButtonOffset_DPAD_RIGHT;
		case XINPUT_GAMEPAD_START:
			return kGamepadButtonOffset_START;
		case XINPUT_GAMEPAD_BACK:
			return kGamepadButtonOffset_BACK;
		case XINPUT_GAMEPAD_LEFT_THUMB:
			return kGamepadButtonOffset_LEFT_THUMB;
		case XINPUT_GAMEPAD_RIGHT_THUMB:
			return kGamepadButtonOffset_RIGHT_THUMB;
		case XINPUT_GAMEPAD_LEFT_SHOULDER:
			return kGamepadButtonOffset_LEFT_SHOULDER;
		case XINPUT_GAMEPAD_RIGHT_SHOULDER:
			return kGamepadButtonOffset_RIGHT_SHOULDER;
		case XINPUT_GAMEPAD_A:
			return kGamepadButtonOffset_A;
		case XINPUT_GAMEPAD_B:
			return kGamepadButtonOffset_B;
		case XINPUT_GAMEPAD_X:
			return kGamepadButtonOffset_X;
		case XINPUT_GAMEPAD_Y:
			return kGamepadButtonOffset_Y;
		case 0x9:
			return kGamepadButtonOffset_LT;
		case 0xA:
			return kGamepadButtonOffset_RT;
		default:
			return kMaxMacros;  // Invalid
		}
	}

	std::uint32_t InputMap::GamepadKeycodeToMask(std::uint32_t keyCode)
	{
		switch (keyCode) {
		case kGamepadButtonOffset_DPAD_UP:
			return XINPUT_GAMEPAD_DPAD_UP;
		case kGamepadButtonOffset_DPAD_DOWN:
			return XINPUT_GAMEPAD_DPAD_DOWN;
		case kGamepadButtonOffset_DPAD_LEFT:
			return XINPUT_GAMEPAD_DPAD_LEFT;
		case kGamepadButtonOffset_DPAD_RIGHT:
			return XINPUT_GAMEPAD_DPAD_RIGHT;
		case kGamepadButtonOffset_START:
			return XINPUT_GAMEPAD_START;
		case kGamepadButtonOffset_BACK:
			return XINPUT_GAMEPAD_BACK;
		case kGamepadButtonOffset_LEFT_THUMB:
			return XINPUT_GAMEPAD_LEFT_THUMB;
		case kGamepadButtonOffset_RIGHT_THUMB:
			return XINPUT_GAMEPAD_RIGHT_THUMB;
		case kGamepadButtonOffset_LEFT_SHOULDER:
			return XINPUT_GAMEPAD_LEFT_SHOULDER;
		case kGamepadButtonOffset_RIGHT_SHOULDER:
			return XINPUT_GAMEPAD_RIGHT_SHOULDER;
		case kGamepadButtonOffset_A:
			return XINPUT_GAMEPAD_A;
		case kGamepadButtonOffset_B:
			return XINPUT_GAMEPAD_B;
		case kGamepadButtonOffset_X:
			return XINPUT_GAMEPAD_X;
		case kGamepadButtonOffset_Y:
			return XINPUT_GAMEPAD_Y;
		case kGamepadButtonOffset_LT:
			return 0x9;
		case kGamepadButtonOffset_RT:
			return 0xA;
		default:
			return 0xFF;  // Invalid
		}
	}

	std::string InputMap::GetKeyName(std::uint32_t a_keyCode)
	{
		if (a_keyCode >= kMacro_MouseButtonOffset && a_keyCode < kMacro_GamepadOffset) {
			return GetMouseButtonName(a_keyCode);
		} else if (a_keyCode >= kMacro_GamepadOffset && a_keyCode < kMaxMacros) {
			return GetGamepadButtonName(a_keyCode);
		} else {
			return GetKeyboardKeyName(a_keyCode);
		}
	}

	std::string InputMap::GetKeyboardKeyName(std::uint32_t a_keyCode)
	{
		std::uint32_t scancode = a_keyCode & 0xFF;

		switch (scancode) {
		case 0x9C:  // Numpad Enter
			scancode = 0x11C;
			break;
		case 0x9D:  // Right Control
			scancode = 0x11D;
			break;
		case 0xB5:  // Numpad /
			scancode = 0x135;
			break;
		case 0xB8:  // Right Alt
			scancode = 0x138;
			break;
		case 0xC7:  // Home
			scancode = 0x147;
			break;
		case 0xC8:  // Up Arrow
			scancode = 0x148;
			break;
		case 0xC9:  // Page Up
			scancode = 0x149;
			break;
		case 0xCB:  // Left Arrow
			scancode = 0x14B;
			break;
		case 0xCD:  // Right Arrow
			scancode = 0x14D;
			break;
		case 0xCF:  // End
			scancode = 0x14F;
			break;
		case 0xD0:  // Down Arrow
			scancode = 0x150;
			break;
		case 0xD1:  // Page Down
			scancode = 0x151;
			break;
		case 0xD2:  // Insert
			scancode = 0x152;
			break;
		case 0xD3:  // Delete
			scancode = 0x153;
			break;
		}

		std::uint32_t lParam = scancode << 16;

		if (scancode == 0x45) {
			lParam |= (0x1 << 24);
		}

		wchar_t      buffer[MAX_PATH];
		auto         length = ::GetKeyNameTextW(lParam, buffer, MAX_PATH);
		std::wstring keyNameW{ buffer, static_cast<std::size_t>(length) };

		return stl::utf16_to_utf8(keyNameW).value_or(""s);
	}

	std::string InputMap::GetMouseButtonName(std::uint32_t a_keyCode)
	{
		switch (a_keyCode) {
		case 256:
			return "Left Mouse Button"s;
		case 257:
			return "Right Mouse Button"s;
		case 258:
			return "Middle Mouse Button"s;
		case 259:
			return "Mouse Button 3"s;
		case 260:
			return "Mouse Button 4"s;
		case 261:
			return "Mouse Button 5"s;
		case 262:
			return "Mouse Button 6"s;
		case 263:
			return "Mouse Button 7"s;
		case 264:
			return "Mouse Wheel Up"s;
		case 265:
			return "Mouse Wheel Down"s;
		default:
			return ""s;
		}
	}

	std::string InputMap::GetGamepadButtonName(std::uint32_t a_keyCode)
	{
		switch (a_keyCode) {
		case kGamepadButtonOffset_DPAD_UP:
			return "Gamepad DPad Up"s;
		case kGamepadButtonOffset_DPAD_DOWN:
			return "Gamepad DPad Down"s;
		case kGamepadButtonOffset_DPAD_LEFT:
			return "Gamepad DPad Left"s;
		case kGamepadButtonOffset_DPAD_RIGHT:
			return "Gamepad DPad Right"s;
		case kGamepadButtonOffset_START:
			return "Gamepad Start"s;
		case kGamepadButtonOffset_BACK:
			return "Gamepad Back"s;
		case kGamepadButtonOffset_LEFT_THUMB:
			return "Gamepad Left Thumb"s;
		case kGamepadButtonOffset_RIGHT_THUMB:
			return "Gamepad Right Thumb"s;
		case kGamepadButtonOffset_LEFT_SHOULDER:
			return "Gamepad Left Shoulder"s;
		case kGamepadButtonOffset_RIGHT_SHOULDER:
			return "Gamepad Right Shoulder"s;
		case kGamepadButtonOffset_A:
			return "Gamepad A"s;
		case kGamepadButtonOffset_B:
			return "Gamepad B"s;
		case kGamepadButtonOffset_X:
			return "Gamepad X"s;
		case kGamepadButtonOffset_Y:
			return "Gamepad Y"s;
		case kGamepadButtonOffset_LT:
			return "Gamepad LT"s;
		case kGamepadButtonOffset_RT:
			return "Gamepad RT"s;
		default:
			return ""s;
		}
	}
}
