#pragma once

#include "RE/B/BSGamepadDevice.h"

namespace RE
{
	class BSPCGamepadDeviceHandler;

	class BSPCGamepadDeviceDelegate : public BSGamepadDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPCGamepadDeviceDelegate;
		inline static constexpr auto VTABLE = VTABLE_BSPCGamepadDeviceDelegate;

		~BSPCGamepadDeviceDelegate() override;  // 00

		// override (BSGamepadDevice)
		void Initialize() override;                                          // 01 - { return; }
		void Poll(float a_timeDelta) override;                               // 02 - { return; }
		void Shutdown() override;                                            // 03 - { return; }
		void ClearInputState() override;                                     // 08 - { return; }
		void SetVibration(float a_largeMotor, float a_smallMotor) override;  // 09 - { return; }

		// members
		BSPCGamepadDeviceHandler* gamepadDeviceHandler;  // D0

	protected:
		friend class BSGamepadDeviceHandler;
		BSPCGamepadDeviceDelegate();
	};
	static_assert(sizeof(BSPCGamepadDeviceDelegate) == 0xD8);
}
