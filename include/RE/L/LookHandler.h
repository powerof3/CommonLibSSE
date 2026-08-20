#pragma once

#include "RE/P/PlayerInputHandler.h"
#ifdef SKYRIM_SUPPORT_AE
#	include "RE/S/SixaxisEvent.h"
#endif

namespace RE
{
	struct LookHandler : public PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_LookHandler;
		inline static constexpr auto VTABLE = VTABLE_LookHandler;

		~LookHandler() override;  // 00

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                          // 01
		void ProcessThumbstick(ThumbstickEvent* a_event, PlayerControlsData* a_data) override;  // 02
		void ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data) override;    // 03

#ifdef SKYRIM_SUPPORT_AE
		// members
		std::uint32_t unk10;         // 10
		std::uint32_t pad14;         // 14
		SixaxisEvent  sixaxisEvent;  // 18
		std::uint64_t unkA8;         // A8
		std::int32_t  unkB0;         // B0
		std::uint32_t unkB4;         // B4
#endif
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(LookHandler) == 0x10);
#else
	static_assert(sizeof(LookHandler) == 0xB8);
#endif
}
