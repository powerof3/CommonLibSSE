#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IMenu.h"
#include "RE/W/WorldSpaceMenu.h"

namespace RE
{
	class MenuOpenCloseEvent;

	// menuDepth = 3
	// flags = kUpdateUsesCursor | kDontHideCursorWhenTopmost
	// context = kMenuMode
	class DialogueMenu :
#ifndef SKYRIMVR
		public IMenu,  // 00
#else
		public WorldSpaceMenu,
#endif
		public BSTEventSink<MenuOpenCloseEvent>  // 30
	{
	public:
		inline static constexpr auto      RTTI = RTTI_DialogueMenu;
		inline static constexpr auto      VTABLE = VTABLE_DialogueMenu;
		constexpr static std::string_view MENU_NAME = "Dialogue Menu";

		struct Data
		{
			void*         unk00;  // 00
			std::uint64_t unk08;  // 08
		};
		static_assert(sizeof(Data) == 0x10);

		~DialogueMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

#ifdef SKYRIMVR
		virtual void        SetupMenuNode() override;
		virtual RE::NiNode* GetMenuParentNode() override;  // 0C
		virtual void        SetTransform() override;       // 0D
#endif
		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

#ifdef SKYRIMVR
		// override (BSTEventSink<HudModeChangeEvent>)
		BSEventNotifyControl ProcessEvent(const HudModeChangeEvent* a_event, BSTEventSource<HudModeChangeEvent>* a_eventSource) override;  // 01
#endif
		// members
		BSTArray<Data> unk38;  // 38
#ifdef SKYRIMVR
		RE::NiNode* occlusionCheckNode;  // 78 - name is "Dialogue Menu Occlusion Check Node"
#endif
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(DialogueMenu) == 0x50);
#else
	static_assert(sizeof(DialogueMenu) == 0x80);
#endif
}
