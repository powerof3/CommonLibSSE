#pragma once

#include <cstddef>
#include <cstdint>

#include "RE/B/BSShaderRenderTargets.h"
#include "RE/R/RenderTargetProperties.h"
#include "RE/R/RendererShadowState.h"

namespace RE
{
	namespace BSGraphics
	{
		class RenderTargetManager
		{
		public:
			[[nodiscard]] static RenderTargetManager* GetSingleton()
			{
				static REL::Relocation<RenderTargetManager**> singleton{ RELOCATION_ID(524970, 411451) };
				return *singleton;
			}

			void CreateCubeMapRenderTarget(RENDER_TARGET_CUBEMAP a_renderTarget, const CubeMapRenderTargetProperties& a_properties);
			void CreateDepthStencilTarget(RENDER_TARGET_DEPTHSTENCIL a_renderTarget, const DepthStencilTargetProperties& a_properties);
			void SetCurrentCubeMapRenderTarget(RENDER_TARGET_CUBEMAP a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_faceIndex, bool a_updateViewport);
			void SetCurrentDepthStencilTarget(RENDER_TARGET_DEPTHSTENCIL a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_slice);

			// members
			RenderTargetProperties renderTargetData[RENDER_TARGET::kTOTAL];  // 000
#ifdef SKYRIM_SUPPORT_AE
			std::byte padC78[0x38];  // C78
#endif
			DepthStencilTargetProperties  depthStencilTargetData[RENDER_TARGETS_DEPTHSTENCIL::kTOTAL];  // C78, CB0
			CubeMapRenderTargetProperties cubeMapRenderTargetData[RENDER_TARGETS_CUBEMAP::kTOTAL];      // D38, D70
		};

#ifdef SKYRIM_SUPPORT_AE
		static_assert(sizeof(RenderTargetManager) == 0xD7C);
#else
		static_assert(sizeof(RenderTargetManager) == 0xD44);
#endif
	}
}
