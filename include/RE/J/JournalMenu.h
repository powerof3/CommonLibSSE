#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/I/IMenu.h"
#include "RE/J/Journal_QuestsTab.h"
#include "RE/J/Journal_StatsTab.h"
#include "RE/J/Journal_SystemTab.h"
#include "RE/M/MenuEventHandler.h"

namespace RE
{
	class BSSystemEvent;

	// menuDepth = 5
	// flags = kPausesGame | kUsesMenuContext | kFreezeFrameBackground | kRequiresUpdate | kTopmostRenderedMenu | kUpdateUsesCursor | kAllowSaving
	// kDisablePauseMenu if game load prevented
	// context = kJournal
	class JournalMenu :
		public IMenu,                       // 00
		public MenuEventHandler,            // 30
		public BSTEventSink<BSSystemEvent>  // 40
	{
	public:
		inline static constexpr auto      RTTI = RTTI_JournalMenu;
		inline static constexpr auto      VTABLE = VTABLE_JournalMenu;
		constexpr static std::string_view MENU_NAME = "Journal Menu";

		~JournalMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               PostDisplay() override;                                                // 06

		// override (MenuEventHandler)
		bool CanProcess(InputEvent* a_event) override;              // 01
		bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03

		// override (BSTEventSink<BSSystemEvent>)
		BSEventNotifyControl ProcessEvent(const BSSystemEvent* a_event, BSTEventSource<BSSystemEvent>* a_eventSource) override;  // 01

		// members
		Journal_QuestsTab questsTab;  // 48
		Journal_StatsTab  statsTab;   // 80
		Journal_SystemTab systemTab;  // 98
		std::uint64_t     unkD0;      // D0
		std::uint64_t     unkD8;      // D8
		bool              unkE0;      // E0
#ifdef SKYRIMVR
		std::uint64_t unkF8;   // F8
		std::uint64_t unk100;  // 100
#endif
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(JournalMenu) == 0xE8);
#else
	static_assert(sizeof(JournalMenu) == 0x108);
#endif
}
