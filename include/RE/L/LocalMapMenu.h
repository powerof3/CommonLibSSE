#pragma once

#include "RE/B/BSCullingProcess.h"
#include "RE/B/BSScaleformExternalTexture.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/G/GFxValue.h"
#include "RE/I/ImageSpaceShaderParam.h"
#include "RE/L/LocalMapCamera.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSShaderAccumulator;
	class NiCamera;
	class NiNode;
	struct MapMenuMarker;

	struct LocalMapMenu
	{
	public:
		struct LocalMapCullingProcess  // actually: LocalMapRenderer
		{
		public:
			// members
			BSCullingProcess               cullingProcess;         // 00000
			BSCullingJob                   cullingJob;             // 301F8
			LocalMapCamera                 camera;                 // 30260
			NiPointer<BSShaderAccumulator> accumulator;            // 302C8
			ImageSpaceShaderParam          imageSpaceShaderParam;  // 302D0
			std::uint32_t                  renderTarget;           // 30350
			std::uint32_t                  renderMode;             // 30354
			NiPointer<NiNode>              unk30358;               // 30358
		};
		static_assert(sizeof(LocalMapCullingProcess) == 0x30360);

		class InputHandler : public MenuEventHandler
		{
		public:
			inline static constexpr auto RTTI = RTTI_LocalMapMenu__InputHandler;
			inline static constexpr auto VTABLE = VTABLE_LocalMapMenu__InputHandler;

			~InputHandler() override;  // 00

			// override (MenuEventHandler)
			bool CanProcess(InputEvent* a_event) override;              // 01
			bool ProcessThumbstick(ThumbstickEvent* a_event) override;  // 03
			bool ProcessMouseMove(MouseMoveEvent* a_event) override;    // 04
			bool ProcessButton(ButtonEvent* a_event) override;          // 05

			// members
			LocalMapMenu* localMapMenu;  // 10
		};
		static_assert(sizeof(InputHandler) == 0x18);

		// members
		BSTArray<MapMenuMarker>       mapMarkers;           // 00000
		GFxValue                      unk00018;             // 00018
		float                         unk00030;             // 00030
		float                         unk00034;             // 00034
		float                         unk00038;             // 00038
		float                         unk0003C;             // 0003C
		LocalMapCullingProcess        localCullingProcess;  // 00040
		BSScaleformExternalTexture    unk303A0;             // 303A0
		GFxValue                      localMapMovie;        // 303B8
		GFxValue                      mapMovie;             // 303D0
		GFxMovieView*                 parentMenuView;       // 303E8
		BSTSmartPointer<InputHandler> unk303F0;             // 303F0
		std::int32_t                  selectedMarker;       // 303F8
		bool                          showingMap;           // 303FC
		bool                          dragging;             // 303FD
		bool                          controlsReady;        // 303FE
		std::uint8_t                  unk303FF;             // 303FF
	};
	static_assert(sizeof(LocalMapMenu) == 0x30400);
}
