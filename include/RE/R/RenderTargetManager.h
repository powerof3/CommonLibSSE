#pragma once

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

			void SetCurrentCubeMapRenderTarget(RENDER_TARGET_CUBEMAP a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_faceIndex, bool a_updateViewport);
			void SetCurrentDepthStencilTarget(RENDER_TARGET_DEPTHSTENCIL a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_slice);

			// members
			RenderTargetProperties        renderTargetData[RENDER_TARGET::kTOTAL];                      // 0x000
			DepthStencilTargetProperties  depthStencilTargetData[RENDER_TARGETS_DEPTHSTENCIL::kTOTAL];  // 0xC78
			CubeMapRenderTargetProperties cubeMapRenderTargetData[RENDER_TARGETS_CUBEMAP::kTOTAL];      // 0xD38
		};
		static_assert(sizeof(RenderTargetManager) == 0xD44);
	}
}
