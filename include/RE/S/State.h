#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiSourceTexture.h"

namespace RE
{
	class NiCamera;

	namespace BSGraphics
	{
		class State
		{
		public:
			[[nodiscard]] static State* GetSingleton()
			{
				static REL::Relocation<State*> singleton{ RELOCATION_ID(524998, 411479) };
				return singleton.get();
			}

			void SetCameraData(const NiCamera* a_camera, std::uint32_t a_flags)
			{
				using func_t = decltype(&State::SetCameraData);
				static REL::Relocation<func_t> func{ RELOCATION_ID(75694, 77503) };
				return func(this, a_camera, a_flags);
			}

			// members
			NiPointer<NiSourceTexture> defaultTextureProjNoiseMap;         // 000
			NiPointer<NiSourceTexture> defaultTextureProjDiffuseMap;       // 008
			NiPointer<NiSourceTexture> defaultTextureProjNormalMap;        // 010
			NiPointer<NiSourceTexture> defaultTextureProjNormalDetailMap;  // 018
			std::uint32_t              unk020;                             // 020
			std::uint32_t              screenWidth;                        // 024
			std::uint32_t              screenHeight;                       // 028
			std::uint32_t              frameBufferViewport[2];             // 02C
			std::uint32_t              unk034;                             // 034
			std::uint32_t              unk038;                             // 038
			std::uint32_t              unk03C;                             // 03C
			std::uint32_t              unk040;                             // 040
			float                      projectionPosScaleX;                // 044
			float                      projectionPosScaleY;                // 048
			std::uint32_t              frameCount;                         // 04C
#ifdef SKYRIM_SUPPORT_AE
			std::uint32_t unk050;                   // 050
			bool          insideFrame;              // 054
			bool          letterbox;                // 055
			bool          unk056;                   // 056
			bool          unk057;                   // 057
			bool          compiledShaderThisFrame;  // 058
			bool          useEarlyZ;                // 059
#else
			bool insideFrame;              // 050
			bool letterbox;                // 051
			bool unk052;                   // 052
			bool unk053;                   // 053
			bool compiledShaderThisFrame;  // 054
			bool useEarlyZ;                // 055
#endif
			NiPointer<NiSourceTexture> defaultTextureBlack;                   // 060
			NiPointer<NiSourceTexture> defaultTextureWhite;                   // 068
			NiPointer<NiSourceTexture> defaultTextureGrey;                    // 070
			NiPointer<NiSourceTexture> defaultHeightMap;                      // 078
			NiPointer<NiSourceTexture> defaultReflectionCubeMap;              // 080
			NiPointer<NiSourceTexture> defaultFaceDetailMap;                  // 088
			NiPointer<NiSourceTexture> defaultTexEffectMap;                   // 090
			NiPointer<NiSourceTexture> defaultTextureNormalMap;               // 098
			NiPointer<NiSourceTexture> defaultTextureDitherNoiseMap;          // 0A0
			BSTArray<void*>            cameraDataCache;                       // 0A8
			std::uint32_t              unk0C0;                                // 0C0
			float                      haltonSequence[2][8];                  // 0C4
			float                      dynamicResolutionWidthRatio;           // 104
			float                      dynamicResolutionHeightRatio;          // 108
			float                      dynamicResolutionPreviousWidthRatio;   // 10C
			float                      dynamicResolutionPreviousHeightRatio;  // 110
			std::uint32_t              dynamicResolutionIncreaseFrameWaited;  // 114
			volatile std::int32_t      dynamicResolutionLock;                 // 118
			bool                       canIncreaseDynamicResolution;          // 11C
			bool                       canDecreaseDynamicResolution;          // 11D
			bool                       canChangeDynamicResolution;            // 11E
		};
#ifdef SKYRIM_SUPPORT_AE
		static_assert(sizeof(State) == 0x120);
		static_assert(offsetof(State, insideFrame) == 0x54);
		static_assert(offsetof(State, letterbox) == 0x55);
		static_assert(offsetof(State, compiledShaderThisFrame) == 0x58);
		static_assert(offsetof(State, useEarlyZ) == 0x59);
		static_assert(offsetof(State, defaultTextureBlack) == 0x60);
		static_assert(offsetof(State, defaultTextureWhite) == 0x68);
		static_assert(offsetof(State, cameraDataCache) == 0xA8);
		static_assert(offsetof(State, dynamicResolutionWidthRatio) == 0x104);
		static_assert(offsetof(State, dynamicResolutionLock) == 0x118);
#else
		static_assert(sizeof(State) == 0x118);
		static_assert(offsetof(State, insideFrame) == 0x50);
		static_assert(offsetof(State, letterbox) == 0x51);
		static_assert(offsetof(State, compiledShaderThisFrame) == 0x54);
		static_assert(offsetof(State, useEarlyZ) == 0x55);
		static_assert(offsetof(State, defaultTextureBlack) == 0x58);
		static_assert(offsetof(State, defaultTextureWhite) == 0x60);
		static_assert(offsetof(State, cameraDataCache) == 0xA0);
		static_assert(offsetof(State, dynamicResolutionWidthRatio) == 0xFC);
		static_assert(offsetof(State, dynamicResolutionLock) == 0x110);
#endif
	}
}
