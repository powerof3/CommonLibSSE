#pragma once

#include "RE/B/BSShaderRenderTargets.h"
#include "RE/N/NiTexture.h"
#include "RE/R/RenderTargetData.h"
#include "RE/T/TextureFileFormat.h"

struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain;
struct ID3D11RenderTargetView1;
struct ID3D11ShaderResourceView1;

namespace RE
{
	namespace BSGraphics
	{
		struct RendererWindow
		{
		public:
			// members
			SKSE::WinAPI::HWND         hWnd;                   // 00
			std::int32_t               windowX;                // 08
			std::int32_t               windowY;                // 0C
			std::int32_t               windowWidth;            // 10
			std::int32_t               windowHeight;           // 14
			IDXGISwapChain*            swapChain;              // 18
			RENDER_TARGET              swapChainRenderTarget;  // 20
			std::uint32_t              unk24;                  // 24
			std::uint64_t              unk28;                  // 28
			ID3D11RenderTargetView1*   renderView;             // 30
			ID3D11ShaderResourceView1* resourceView;           // 38
			std::uint64_t              unk40;                  // 40
			std::uint64_t              unk48;                  // 48
		};
		static_assert(sizeof(RendererWindow) == 0x50);

		struct RendererData
		{
		public:
			// members
			std::uint32_t                  uiAdapter;                                            // 0000
			std::uint32_t                  unk04;                                                // 0004 - refreshRate?
			std::uint32_t                  unk08;                                                // 0008
			std::uint32_t                  unk0C;                                                // 000C
			std::uint32_t                  unk10;                                                // 0010
			std::uint32_t                  unk14;                                                // 0014
			std::uint32_t                  unk18;                                                // 0018
			std::uint32_t                  unk1C;                                                // 001C
			bool                           fullScreen;                                           // 0020
			bool                           borderlessDisplay;                                    // 0021
			bool                           readOnlyDepth;                                        // 0022
			std::uint8_t                   unk23;                                                // 0023
			std::uint8_t                   unk24;                                                // 0024
			std::uint32_t                  unk28;                                                // 0028
			std::uint32_t                  unk30;                                                // 0030
			std::uint32_t                  presentInterval;                                      // 0034
			ID3D11Device*                  forwarder;                                            // 0038
			ID3D11DeviceContext*           context;                                              // 0040
			RendererWindow                 renderWindows[32];                                    // 0048
			RenderTargetData               renderTargets[RENDER_TARGET::kTOTAL];                 // 0A48
			DepthStencilData               depthStencils[RENDER_TARGET_DEPTHSTENCIL::kTOTAL];    // 1FA8
			CubemapRenderTargetData        cubemapRenderTargets[RENDER_TARGET_CUBEMAP::kTOTAL];  // 26C8
			Texture3DTargetData            texture3DRenderTargets[RENDER_TARGET_3D::kTOTAL];     // 2708
			float                          clearColor[4];                                        // 2768
			std::uint8_t                   clearStencil;                                         // 2778
			SKSE::WinAPI::CRITICAL_SECTION lock;                                                 // 2780
			const char*                    className;                                            // 27A8
			SKSE::WinAPI::HINSTANCE        hInstance;                                            // 27B0
		};
		static_assert(offsetof(RendererData, lock) == 0x2780);

		class Renderer
		{
		public:
			[[nodiscard]] static Renderer* GetSingleton() noexcept;

			[[nodiscard]] NiTexture::RendererData* CreateRenderTexture(std::uint32_t a_width, std::uint32_t a_height);
			void                                   SaveRenderTargetToFile(RENDER_TARGET a_renderTarget, const char* a_filePath, TextureFileFormat a_textureFileFormat);

			// members
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
			RendererData  data;   // 10
		};
	}
}
