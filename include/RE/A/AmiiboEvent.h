#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
#ifdef SKYRIM_SUPPORT_AE
	class AmiiboEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_AmiiboEvent;
		inline static constexpr auto VTABLE = VTABLE_AmiiboEvent;

		~AmiiboEvent() override;  // 00

		// members
		std::uint8_t data[0x18];  // 28
	};
	static_assert(sizeof(AmiiboEvent) == 0x40);
#endif
}
