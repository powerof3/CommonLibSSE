#pragma once

#include "RE/B/BSScaleformExternalTexture.h"
#include "RE/B/BSTEvent.h"
#include "RE/G/GFxFunctionHandler.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class BSSaveDataEvent;
	class BSSystemEvent;

	// menuDepth = 0
	// flags = kPausesGame | kDisablePauseMenu | kRequiresUpdate | kUpdateUsesCursor | kApplicationMenu
	// context = kMenuMode
	class MainMenu :
		public IMenu,                          // 00
		public BSTEventSink<BSSystemEvent>,    // 30
		public BSTEventSink<BSSaveDataEvent>,  // 38
#ifndef SKYRIMVR
		public GFxFunctionHandler  // 40
#else
		public BSTEventSink<BSGamerProfileEvent>,  // 50
		public MenuEventHandler                    // 58
#endif
	{
	public:
		inline static constexpr auto      RTTI = RTTI_MainMenu;
		constexpr static std::string_view MENU_NAME = "Main Menu";

		~MainMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05

		// override (BSTEventSink<BSSystemEvent>)
		BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;  // 01

		// override (BSTEventSink<BSSaveDataEvent>)
		BSEventNotifyControl ProcessEvent(const BSSaveDataEvent* a_event, BSTEventSource<BSSaveDataEvent>* a_eventSource) override;  // 01
#ifdef SKYRIMVR
		// override (BSTEventSink<BSSaveDataEvent>)
		BSEventNotifyControl ProcessEvent(const BSGamerProfileEvent* a_event, BSTEventSource<BSGamerProfileEvent>* a_eventSource) override;  // 01
#endif

#ifndef SKYRIMVR
		// override (GFxFunctionHandler)
		void Call(Params& a_params) override;  // 01
#endif

		// members
		BSScaleformExternalTexture gamerIconTexture;  // 50
		std::uint32_t              unk68;             // 68
		std::uint8_t               unk6C;             // 6C
		std::uint8_t               unk6D;             // 6D
		std::uint8_t               unk6E;             // 6E
		std::uint8_t               pad6F;             // 6F
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(MainMenu) == 0x70);
#else
	static_assert(sizeof(MainMenu) == 0x88);
#endif
}
