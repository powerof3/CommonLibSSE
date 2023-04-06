#include "RE/B/BSWin32KeyboardDevice.h"

namespace RE
{
	bool BSWin32KeyboardDevice::IsPressed(std::uint32_t a_keyCode) const
	{
		return (a_keyCode < sizeof(curState)) && ((curState[a_keyCode] & 0x80) != 0);
	}

	BSKeyboardDevice::Key BSWin32KeyboardDevice::RemapNumpadKey(DirectInput8::DIKey a_key)
	{
		if (WinAPI::GetKeyState(WinAPI::VKEnum::VK_NUMLOCK) != 1) {
			return Key::kNone;
		}
		switch (a_key) {
		case DirectInput8::DIKey::DIK_NUMPAD7:
			return Key::kKP_Multiply;
		case DirectInput8::DIKey::DIK_NUMPAD8:
			return Key::kLeftAlt;
		case DirectInput8::DIKey::DIK_NUMPAD9:
			return Key::kSpacebar;
		case DirectInput8::DIKey::DIK_NUMPAD4:
			return Key::kPeriod;
		case DirectInput8::DIKey::DIK_NUMPAD5:
			return Key::kSlash;
		case DirectInput8::DIKey::DIK_NUMPAD6:
			return Key::kRightShift;
		case DirectInput8::DIKey::DIK_NUMPAD1:
			return Key::kN;
		case DirectInput8::DIKey::DIK_NUMPAD2:
			return Key::kM;
		case DirectInput8::DIKey::DIK_NUMPAD3:
			return Key::kComma;
		case DirectInput8::DIKey::DIK_NUMPAD0:
			return Key::kB;
		case DirectInput8::DIKey::DIK_DECIMAL:
			return Key::kC;
		case DirectInput8::DIKey::DIK_DIVIDE:
			return Key::kV;
		default:
			break;
		}
		return Key::kNone;
	}

	BSWin32KeyboardDevice::BSWin32KeyboardDevice() :
		BSKeyboardDevice(),
		dInputDevice(nullptr),
		diObjData(),
		prevState(),
		curState(),
		capsLockOn(false)
	{}
}
