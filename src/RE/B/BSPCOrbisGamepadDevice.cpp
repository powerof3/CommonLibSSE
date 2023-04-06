#include "RE/B/BSPCOrbisGamepadDevice.h"

namespace RE
{
	BSPCOrbisGamepadDevice::BSPCOrbisGamepadDevice() :
		BSPCGamepadDeviceDelegate(),
		previousPadState(),
		previousLT(0.0f),
		previousRT(0.0f),
		previousLX(0.0f),
		previousLY(0.0f),
		previousRX(0.0f),
		previousRY(0.0f),
		currentPadState(),
		currentLT(0.0f),
		currentRT(0.0f),
		currentLX(0.0f),
		currentLY(0.0f),
		currentRX(0.0f),
		currentRY(0.0f)
	{
	}
}
