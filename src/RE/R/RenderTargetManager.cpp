#include "RE/R/RenderTargetManager.h"

namespace RE
{
	namespace BSGraphics
	{
		void RenderTargetManager::SetCurrentCubeMapRenderTarget(RENDER_TARGET_CUBEMAP a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_faceIndex, bool a_updateViewport)
		{
			using func_t = decltype(&RenderTargetManager::SetCurrentCubeMapRenderTarget);
			static REL::Relocation<func_t> func{ RELOCATION_ID(77455, 77455) };
			return func(this, a_renderTarget, a_mode, a_faceIndex, a_updateViewport);
		}

		void RenderTargetManager::SetCurrentDepthStencilTarget(RENDER_TARGET_DEPTHSTENCIL a_renderTarget, SetRenderTargetMode a_mode, std::uint32_t a_slice)
		{
			using func_t = decltype(&RenderTargetManager::SetCurrentDepthStencilTarget);
			static REL::Relocation<func_t> func{ RELOCATION_ID(77454, 77454) };
			return func(this, a_renderTarget, a_mode, a_slice);
		}
	}
}
