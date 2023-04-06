#include "RE/B/BSWin32GamepadDevice.h"

namespace RE
{
	BSWin32GamepadDevice::BSWin32GamepadDevice() :
		BSPCGamepadDeviceDelegate(),
		previousState(),
		previousLT(0.0f),
		previousRT(0.0f),
		previousLX(0.0f),
		previousLY(0.0f),
		previousRX(0.0f),
		previousRY(0.0f),
		currentState(),
		currentLT(0.0f),
		currentRT(0.0f),
		currentLX(0.0f),
		currentLY(0.0f),
		currentRX(0.0f),
		currentRY(0.0f)
	{}
}
