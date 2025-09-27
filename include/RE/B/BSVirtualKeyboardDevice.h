#pragma once

#include "RE/B/BSKeyboardDevice.h"

namespace RE
{
	class BSVirtualKeyboardDevice : public BSKeyboardDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSVirtualKeyboardDevice;
		inline static constexpr auto VTABLE = VTABLE_BSVirtualKeyboardDevice;

		~BSVirtualKeyboardDevice() override;  // 00

		// override (BSKeyboardDevice)
		void Unk_09(void) override;  // 09 - { return; }
		void Unk_0A(void) override;  // 0A - { return; }

		// add
		virtual void Start(const kbInfo* a_info) = 0;  // 0B
		virtual void Stop() = 0;                       // 0C
		virtual void UserCancelled() = 0;              // 0D

	protected:
		BSVirtualKeyboardDevice();  // The virtual keyboard device constructor does not set the device type to virtualKeyboard, it remains 'kKeyboard'
	};
	static_assert(sizeof(BSVirtualKeyboardDevice) == 0x70);
}
