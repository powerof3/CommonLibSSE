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

namespace RE
{
	class BSAudioManager;
	class MapLookHandler;
	class MapMoveHandler;
	class MapZoomHandler;
	class MenuOpenCloseEvent;
	class TESWorldSpace;

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
		inline static constexpr auto      VTABLE = VTABLE_MapMenu;
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
			static REL::Relocation<func_t> func{ RELOCATION_ID(52226, 53113) };
			return func(this);
		}

		// members
		BSTSmartPointer<MapMoveHandler> moveHandler;           // 00040
		BSTSmartPointer<MapLookHandler> lookHandler;           // 00048
		BSTSmartPointer<MapZoomHandler> zoomHandler;           // 00050
		ObjectRefHandle                 mapMarker;             // 00058
		LocalMapMenu                    localMapMenu;          // 00060
		ObjectRefHandle                 cameraRootRef;         // 30460 - defaults to player ref
		NiPoint3                        playerMarkerPosition;  // 30464
		BSTArray<MapMenuMarker>         mapMarkers;            // 30470
		BSTArray<GFxValue>              markerData;            // 30488
		MapCamera                       camera;                // 304A0
		std::uint64_t                   unk30530;              // 30530
		TESWorldSpace*                  worldSpace;            // 30538
		GFxValue                        mapMovie;              // 30540
		std::int32_t                    selectedMarker;        // 30558
		NiPoint3                        cameraPickOrigin;      // 3055C
		NiPoint3                        cameraPickDirection;   // 30568
		BSSoundHandle                   unk30574;              // 30574
		std::uint64_t                   unk30580;              // 30580
		std::uint32_t                   unk30588;              // 30588
		bool                            controlsReady;         // 3058C
		std::uint8_t                    unk3058D;              // 3058D
		std::uint16_t                   unk3058E;              // 3058E
		std::uint64_t                   unk30590;              // 30590
	};
	static_assert(sizeof(MapMenu) == 0x30598);
}
