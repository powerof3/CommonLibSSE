#pragma once

#include "RE/I/IDEvent.h"

namespace RE
{
#ifdef SKYRIM_SUPPORT_AE
	class SixaxisEvent : public IDEvent
	{
	public:
		inline static constexpr auto RTTI = RTTI_SixaxisEvent;
		inline static constexpr auto VTABLE = VTABLE_SixaxisEvent;

		~SixaxisEvent() override;  // 00

		// members
		std::uint8_t data[0x68];  // 28
	};
	static_assert(sizeof(SixaxisEvent) == 0x90);
#endif
}
