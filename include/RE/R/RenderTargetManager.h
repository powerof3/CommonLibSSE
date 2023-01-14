#pragma once

#include "RE/B/BSShaderRenderTargets.h"
#include "RE/R/RenderTargetProperties.h"

namespace RE
{
	namespace BSGraphics
	{
		class RenderTargetManager
		{
		public:
			[[nodiscard]] static RenderTargetManager* GetSingleton()
			{
				REL::Relocation<RenderTargetManager**> singleton{ RELOCATION_ID(524970, 411451) };
				return *singleton;
			}

			// members
			RenderTargetProperties        renderTargetData[RENDER_TARGET::kTOTAL];                      // 0x000
			DepthStencilTargetProperties  depthStencilTargetData[RENDER_TARGETS_DEPTHSTENCIL::kTOTAL];  // 0xC78
			CubeMapRenderTargetProperties cubeMapRenderTargetData[RENDER_TARGETS_CUBEMAP::kTOTAL];      // 0xD38
		};
		static_assert(sizeof(RenderTargetManager) == 0xD44);
	}
}
