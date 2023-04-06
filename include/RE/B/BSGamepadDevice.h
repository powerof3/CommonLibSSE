#pragma once

#include "RE/B/BSInputDevice.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	struct BSGamepadEvent;

	class BSGamepadDevice :
		public BSInputDevice,                  // 00
		public BSTEventSource<BSGamepadEvent>  // 70
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGamepadDevice;
		inline static constexpr auto VTABLE = VTABLE_BSGamepadDevice;

		struct ColorParam
		{
			std::uint32_t r;
			std::uint32_t g;
			std::uint32_t b;
		};

		~BSGamepadDevice() override;  // 00

		// override (BSInputDevice)
		bool IsEnabled() const override;  // 07 - { return connected && userIndex != -1; }

		// add
		virtual void SetRumble(float a_lValue, float a_rValue) = 0;                                  // 09
		virtual void SetLEDColor(ColorParam* a_colorParam);                                          // 0A - { return; }
		virtual void ResetLEDColor();                                                                // 0B - { return; }
		virtual void Unk_0C(void);                                                                   // 0C - { return 0; }
		virtual void ProcessRawInput(int32_t a_rawX, int32_t a_rawY, float& a_outX, float& a_outY);  // 0D
		virtual void Unk_0E(void);                                                                   // 0E - { return; }

		// members
		std::int32_t  userIndex;          // C8
		bool          connected;          // CC
		bool          listeningForInput;  // CD
		std::uint16_t padCE;              // CE

	protected:
		BSGamepadDevice();
	};
	static_assert(sizeof(BSGamepadDevice) == 0xD0);
}
