#include "RE/B/BSWin32MouseDevice.h"

namespace RE
{
	BSWin32MouseDevice::BSWin32MouseDevice() :
		BSMouseDevice(),
		dInputDevice(nullptr),
		dInputPrevState(),
		dInputNextState(),
		notInitialized(false),
		reinitializeLock()
	{}
}
