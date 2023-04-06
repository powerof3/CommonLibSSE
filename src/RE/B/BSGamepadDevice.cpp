#include "RE/B/BSGamepadDevice.h"

namespace RE
{
	BSGamepadDevice::BSGamepadDevice() :
		BSInputDevice(),
		userIndex(-1),
		connected(false),
		listeningForInput(false),
		padCE(0)
	{
		device = INPUT_DEVICE::kGamepad;
		const char* gamepadFile = *reinterpret_cast<const char**>(RELOCATION_ID(511903, 388468).address());
		LoadControlsDefinitionFile(gamepadFile);
	}
}
