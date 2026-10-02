#pragma once

namespace RE
{
	struct INPUT_DEVICES
	{
		enum INPUT_DEVICE
		{
			kNone = static_cast<std::underlying_type_t<INPUT_DEVICE>>(-1),
			kKeyboard = 0,
			kMouse,
			kGamepad,
#ifdef SKYRIM_SUPPORT_AE
			kUnk3,
			kUnk4,
#endif
			kVirtualKeyboard,

			kTotal
		};
	};
	using INPUT_DEVICE = INPUT_DEVICES::INPUT_DEVICE;
}
