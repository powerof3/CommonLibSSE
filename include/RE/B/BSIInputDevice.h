#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	class BSIInputDevice
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSIInputDevice;
		inline static constexpr auto VTABLE = VTABLE_BSIInputDevice;

		virtual ~BSIInputDevice();  // 00

		// add
		virtual void               Initialize() = 0;                                                         // 01
		virtual void               Poll(float a_timeDelta) = 0;                                              // 02
		virtual void               Shutdown() = 0;                                                           // 03
		virtual bool               GetButtonNameFromID(std::int32_t a_id, BSFixedString& a_buttonName) = 0;  // 04
		virtual std::uint32_t      GetMappingKey(BSFixedString a_mapping) = 0;                               // 05
		virtual bool               GetKeyCodeFromID(std::int32_t a_id, std::uint32_t& a_keyCode) = 0;        // 06
		[[nodiscard]] virtual bool IsEnabled() const = 0;                                                    // 07
		virtual void               ClearInputState() = 0;                                                    // 08
	};
	static_assert(sizeof(BSIInputDevice) == 0x8);
}
