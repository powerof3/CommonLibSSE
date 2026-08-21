#pragma once

namespace RE
{
	namespace BSGraphics
	{
		struct ViewData
		{
			// NOTE: To avoid pulling in DirectXMath. Probably not safe to use, but represents in IDA.
			// DirectX::XMVector
			struct Vector
			{
				float f[4];
			};

			// DirectX::XMMatrix
			struct Matrix
			{
				float m[4][4];
			};

			Vector        viewUp;                            // 00
			Vector        viewRight;                         // 10
			Vector        viewDir;                           // 20
			Matrix        viewMat;                           // 30
			Matrix        projMat;                           // 70
			Matrix        viewProjMat;                       // B0
			Matrix        unknownMatF0;                      // F0
			Matrix        viewProjMatrixUnjittered;          // 130
			Matrix        previousViewProjMatrixUnjittered;  // 170
			Matrix        projMatrixUnjittered;              // 1B0
			Matrix        unknownMat1F0;                     // 1F0
			NiRect<float> viewPort;                          // 230
			NiPoint2      viewDepthRange;                    // 240
			std::uint64_t pad248;                            // 248
		};
		static_assert(sizeof(ViewData) == 0x250);

		enum ShaderFlags : uint32_t
		{
			DIRTY_RENDERTARGET = 0x1,
			DIRTY_VIEWPORT = 0x2,
			DIRTY_DEPTH_MODE = 0x4,
			DIRTY_DEPTH_STENCILREF_MODE = 0x8,
			DIRTY_UNKNOWN1 = 0x10,
			DIRTY_RASTER_CULL_MODE = 0x20,
			DIRTY_RASTER_DEPTH_BIAS = 0x40,
			DIRTY_ALPHA_BLEND = 0x80,
			DIRTY_ALPHA_TEST_REF = 0x100,
			DIRTY_ALPHA_ENABLE_TEST = 0x200,
			DIRTY_VERTEX_DESC = 0x400,
			DIRTY_PRIMITIVE_TOPO = 0x800,
			DIRTY_UNKNOWN2 = 0x1000,
		};

		enum ClearDepthStencilTarget
		{
			CLEAR_DEPTH_STENCIL_TARGET_DEPTH = 1,
			CLEAR_DEPTH_STENCIL_TARGET_STENCIL = 2,
			CLEAR_DEPTH_STENCIL_TARGET_ALL = 3,
		};

		enum SetRenderTargetMode : uint32_t
		{
			SRTM_CLEAR = 0,
			SRTM_CLEAR_DEPTH = 1,
			SRTM_CLEAR_STENCIL = 2,
			SRTM_RESTORE = 3,
			SRTM_NO_CLEAR = 4,
			SRTM_FORCE_COPY_RESTORE = 5,
			SRTM_INIT = 6,
		};

		enum DepthStencilStencilMode
		{
			DEPTH_STENCIL_STENCIL_MODE_DISABLED = 0,

			DEPTH_STENCIL_STENCIL_MODE_DEFAULT = DEPTH_STENCIL_STENCIL_MODE_DISABLED,  // Used for BSShader::RestoreX
		};

		enum RasterStateCullMode
		{
			RASTER_STATE_CULL_MODE_BACK = 1,

			RASTER_STATE_CULL_MODE_DEFAULT = RASTER_STATE_CULL_MODE_BACK,  // Used for BSShader::RestoreX
		};

		class RendererShadowState
		{
		public:
			// members
			REX::TEnumSet<ShaderFlags, uint32_t>             stateUpdateFlags;                                                       // 00
			std::uint32_t                                   PSResourceModifiedBits;                                                 // 04
			std::uint32_t                                   PSSamplerModifiedBits;                                                  // 08
			std::uint32_t                                   CSResourceModifiedBits;                                                 // 0C
			std::uint32_t                                   CSSamplerModifiedBits;                                                  // 10
			std::uint32_t                                   CSUorderedAccessViewModifiedBits;                                       // 14
			RENDER_TARGET                                   renderTargets[REX::W32::D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];        // 18
			std::uint32_t                                   depthStencil;                                                           // 38
			std::uint32_t                                   depthStencilSlice;                                                      // 3C
			std::uint32_t                                   cubeMapRenderTarget;                                                    // 40
			std::uint32_t                                   cubeMapRenderTargetView;                                                // 44
			SetRenderTargetMode                             setRenderTargetMode[REX::W32::D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT];  // 48
			SetRenderTargetMode                             setDepthStencilMode;                                                    // 68
			SetRenderTargetMode                             setCubeMapRenderTargetMode;                                             // 6C
			REX::W32::D3D11_VIEWPORT                        viewPort;                                                               // 70
			DepthStencilDepthMode                           depthStencilDepthMode;                                                  // 88
			DepthStencilDepthMode                           depthStencilDepthModePrevious;                                          // 8C
			std::uint32_t                                   depthStencilStencilMode;                                                // 90
			std::uint32_t                                   stencilRef;                                                             // 94
			std::uint32_t                                   rasterStateFillMode;                                                    // 98
			std::uint32_t                                   rasterStateCullMode;                                                    // 9C
			std::uint32_t                                   rasterStateDepthBiasMode;                                               // A0
			std::uint32_t                                   rasterStateScissorMode;                                                 // A4
			std::uint32_t                                   alphaBlendMode;                                                         // A8
			std::uint32_t                                   alphaBlendAlphaToCoverage;                                              // AC
			std::uint32_t                                   alphaBlendWriteMode;                                                    // B0
			bool                                            alphaTestEnabled;                                                       // B4
			float                                           alphaTestRef;                                                           // B8
			REX::TEnumSet<TextureAddressMode, std::uint32_t> PSTextureAddressMode[16];                                               // BC
			REX::TEnumSet<TextureFilterMode, std::uint32_t>  PSTextureFilterMode[16];                                                // FC
			ID3D11ShaderResourceView*                       PSTexture[16];                                                          // 140
			REX::TEnumSet<TextureAddressMode, std::uint32_t> CSTextureAddressMode[16];                                               // 1C0
			REX::TEnumSet<TextureFilterMode, std::uint32_t>  CSTextureFilterMode[16];                                                // 200
			ID3D11ShaderResourceView*                       CSTexture[16];                                                          // 240
			std::uint32_t                                   CSTextureMinLodMode[16];                                                // 2C0
			ID3D11UnorderedAccessView*                      CSUnorderedAccessView[8];                                               // 300
			std::uint64_t                                   vertexDesc;                                                             // 340
			VertexShader*                                   currentVertexShader;                                                    // 348
			PixelShader*                                    currentPixelShader;                                                     // 350
			REX::W32::D3D11_PRIMITIVE_TOPOLOGY              topology;                                                               // 358
			NiPoint3                                        posAdjust;                                                              // 35C
			NiPoint3                                        previousPosAdjust;                                                      // 368
			std::byte                                       pad374[12];                                                             // 374
			ViewData                                        cameraData;                                                             // 380
			std::uint32_t                                   alphaBlendModeExtra;                                                    // 5D0
			float                                           viewNear;                                                               // 5D4
			float                                           viewFar;                                                                // 5D8
			std::uint32_t                                   unk5DC;                                                                 // 5D0
		};
		static_assert(sizeof(RendererShadowState) == 0x5E0);
	}
}
