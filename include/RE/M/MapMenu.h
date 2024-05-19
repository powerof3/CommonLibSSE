#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IMapCameraCallbacks.h"
#include "RE/I/IMenu.h"
#include "RE/L/LocalMapMenu.h"
#include "RE/M/MapCamera.h"
#ifdef SKYRIMVR
#	include "RE/W/WorldSpaceMenu.h"
#endif

namespace RE
{
	class BSAudioManager;
	class MapLookHandler;
	class MapMoveHandler;
	class MapZoomHandler;
	class MenuOpenCloseEvent;
	class TESWorldSpace;

#ifndef SKYRIMVR
	// menuDepth = 3
	// flags = kPausesGame | kUsesCursor | kRendersOffscreenTargets | kCustomRendering
	// context = kMap
	class MapMenu :
		public IMenu,                             // 00000
		public BSTEventSink<MenuOpenCloseEvent>,  // 00030
		public IMapCameraCallbacks                // 00038
	{
	public:
		inline static constexpr auto      RTTI = RTTI_MapMenu;
		constexpr static std::string_view MENU_NAME = "MapMenu";

		~MapMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               RefreshPlatform() override;                                            // 08

		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		void PlaceMarker()
		{
			using func_t = decltype(&MapMenu::PlaceMarker);
			REL::Relocation<func_t> func{ RELOCATION_ID(52226, 53113) };
			return func(this);
		}

		// members
		BSTSmartPointer<MapMoveHandler> moveHandler;           // 00040
		BSTSmartPointer<MapLookHandler> lookHandler;           // 00048
		BSTSmartPointer<MapZoomHandler> zoomHandler;           // 00050
		ObjectRefHandle                 mapMarker;             // 00058
		LocalMapMenu                    localMapMenu;          // 00060
		RefHandle                       unk30460;              // 30460
		NiPoint3                        playerMarkerPosition;  // 30464
		BSTArray<void*>                 unk30470;              // 30470
		BSTArray<void*>                 unk30488;              // 30488
		MapCamera                       camera;                // 304A0
		std::uint64_t                   unk30530;              // 30530
		TESWorldSpace*                  worldSpace;            // 30538
		GFxValue                        unk30540;              // 30540
		std::uint32_t                   unk30558;              // 30558
		NiPoint3                        cameraPickOrigin;      // 3055C
		NiPoint3                        cameraPickDirection;   // 30568
		BSSoundHandle                   unk30574;              // 30574
		std::uint64_t                   unk30580;              // 30580
		std::uint64_t                   unk30588;              // 30588
		std::uint64_t                   unk30590;              // 30590
	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(MapMenu) == 0x30598);
#else
	class MapClickHandler;
	class MapTouchpadHandler;

	class MapMenu :
		public WorldSpaceMenu,                   // 00
		public BSTEventSink<MenuOpenCloseEvent>  // 58
	{
	public:
		inline static constexpr auto      RTTI = RTTI_MapMenu;
		constexpr static std::string_view MENU_NAME = "MapMenu";

		~MapMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;                       // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               RefreshPlatform() override;                                            // 08

		// override (BSTEventSink<MenuOpenCloseEvent>)
		BSEventNotifyControl ProcessEvent(const MenuOpenCloseEvent* a_event, BSTEventSource<MenuOpenCloseEvent>* a_eventSource) override;  // 01

		void PlaceMarker()
		{
			using func_t = decltype(&MapMenu::PlaceMarker);
			REL::Relocation<func_t> func{ RELOCATION_ID(52226, 53113) };
			return func(this);
		}

		// members
		BSTSmartPointer<MapMoveHandler>     moveHandler;      // 00060
		BSTSmartPointer<MapLookHandler>     lookHandler;      // 00068
		BSTSmartPointer<MapZoomHandler>     zoomHandler;      // 00070
		BSTSmartPointer<MapClickHandler>    clickHandler;     // 00078
		BSTSmartPointer<MapTouchpadHandler> touchpadHandler;  // 00080
		BSTSmartPointer<void*>              unk00088;         // 00088
		BSTSmartPointer<void*>              unk00090;         // 00090
		BSTSmartPointer<void*>              unk00098;         // 00098
		BSTSmartPointer<void*>              unk000A0;         // 000A0
		ObjectRefHandle                     mapMarker;        // 000A8
		LocalMapMenu                        localMapMenu;     // 000B0
		RefHandle                           unk30530;         // 30530
		NiPoint3                            unk30534;         // 30534
		BSTArray<void*>                     unk30540;         // 30540
		BSTArray<void*>                     unk30558;         // 30558
		NiPoint3                            unk30570;         // 30570
		std::uint32_t                       unk3057C;         // 3057C
		std::uint64_t                       unk30580;         // 30580
		std::uint64_t                       unk30588;         // 30588
		TESWorldSpace*                      worldSpace;       // 30590
		GFxValue                            unk30598;         // 30598
		BSSoundHandle                       unk305B0;         // 305B0
		std::uint64_t                       unk305C0;         // 305C0
		std::uint64_t                       unk305C8;         // 305C8
		std::uint64_t                       unk305D0;         // 305D0
		std::uint64_t                       unk305D8;         // 305D0
		std::uint64_t                       unk305E0;         // 305E0
		std::uint64_t                       unk305E8;         // 305E8
	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(MapMenu) == 0x305F0);
#endif
}
