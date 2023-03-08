#pragma once

#include "RE/B/BSInputDevice.h"

namespace RE
{
	class BSMouseDevice : public BSInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMouseDevice;

		~BSMouseDevice() override;  // 00

		// add
		virtual void Reinitialize(void);  // 09 - { return; }

		// members
		bool backgroundMouse;  // 70
	};
	static_assert(sizeof(BSMouseDevice) == 0x78);
}
