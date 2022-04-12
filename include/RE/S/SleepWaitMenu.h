#pragma once

#include "RE/G/GFxValue.h"
#include "RE/I/IMenu.h"

namespace RE
{
	// menuDepth = 4
	// flags = kPausesGame | kRequiresUpdate | kAllowSaving | kApplicationMenu
	// kUsesCursor if gamepad disabled
	// context = kMenuMode
	class SleepWaitMenu : public IMenu
	{
	public:
		inline static auto                RTTI = RTTI_SleepWaitMenu;
		constexpr static std::string_view MENU_NAME = "Sleep/Wait Menu";

		struct RUNTIME_DATA
		{
			std::uint32_t unk30;  // 00
			std::uint32_t pad34;  // 04
			GFxValue      root;   // 08 - "SleepWaitMenu_mc"
			std::uint8_t  unk50;  // 20
			std::uint8_t  unk51;  // 21
			std::uint16_t pad52;  // 22
			std::uint32_t pad54;  // 24
		};
		static_assert(sizeof(RUNTIME_DATA) == 0x28);

		~SleepWaitMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

		[[nodiscard]] inline RUNTIME_DATA& GetRuntimeData() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x30, 0x40);
		}

		[[nodiscard]] inline const RUNTIME_DATA& GetRuntimeData() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA>(this, 0x30, 0x40);
		}

		// members
#if !defined(ENABLE_SKYRIM_VR) || (!defined(ENABLE_SKYRIM_AE) && !defined(ENABLE_SKYRIM_SE))
		RUNTIME_DATA runtimeData; // 30, 40
#endif
	};
#ifndef ENABLE_SKYRIM_VR
	static_assert(sizeof(SleepWaitMenu) == 0x58);
#elif !defined(ENABLE_SKYRIM_AE) && !defined(ENABLE_SKYRIM_SE)
	static_assert(sizeof(SleepWaitMenu) == 0x68);
#endif
}
