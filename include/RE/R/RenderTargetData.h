#pragma once

struct ID3D11DepthStencilView;
struct ID3D11RenderTargetView;
struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;
struct ID3D11UnorderedAccessView;

namespace RE
{
	namespace BSGraphics
	{
		struct RenderTargetData
		{
			ID3D11Texture2D*           texture;      // 00
			ID3D11Texture2D*           textureCopy;  // 08
			ID3D11RenderTargetView*    RTV;          // 10 - for "Texture"
			ID3D11ShaderResourceView*  SRV;          // 18 - for Texture"
			ID3D11ShaderResourceView*  SRVCopy;      // 20 - for "TextureCopy"
			ID3D11UnorderedAccessView* UAV;          // 28 - for "Texture"
		};
		static_assert(sizeof(RenderTargetData) == 0x30);

		struct DepthStencilData
		{
			ID3D11Texture2D*          texture;           // 00
			ID3D11DepthStencilView*   views[8];          // 08
			ID3D11DepthStencilView*   readOnlyViews[8];  // 48
			ID3D11ShaderResourceView* depthSRV;          // 88
			ID3D11ShaderResourceView* stencilSRV;        // 90
		};
		static_assert(sizeof(DepthStencilData) == 0x98);

		struct CubemapRenderTargetData
		{
			ID3D11Texture2D*          texture;         // 00
			ID3D11RenderTargetView*   cubeSideRTV[6];  // 08
			ID3D11ShaderResourceView* SRV;             // 38
		};
		static_assert(sizeof(CubemapRenderTargetData) == 0x40);

		struct Texture3DTargetData
		{
			std::uint64_t unk00;  // 00
			std::uint64_t unk08;  // 08
			std::uint64_t unk10;  // 10
			std::uint64_t unk18;  // 18
		};
		static_assert(sizeof(Texture3DTargetData) == 0x20);
	}
}
