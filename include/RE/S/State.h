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
#ifdef SKYRIM_SUPPORT_AE
			float         projectionPosScaleXUI;    // 04C
			float         projectionPosScaleYUI;    // 050
			std::uint32_t frameCount;               // 054
			std::uint32_t gUpdateCounter;           // 058
			std::uint32_t unk05C;                   // 05C
			bool          insideFrame;              // 060
			bool          letterbox;                // 061
			bool          unk062;                   // 062
			bool          unk063;                   // 063
			bool          compiledShaderThisFrame;  // 064
			bool          useEarlyZ;                // 065
			std::uint16_t unk066;                   // 066
			bool          unk068;                   // 068
#else
			std::uint32_t frameCount;               // 04C
			bool          insideFrame;              // 050
			bool          letterbox;                // 051
			bool          unk052;                   // 052
			bool          unk053;                   // 053
			bool          compiledShaderThisFrame;  // 054
			bool          useEarlyZ;                // 055
#endif
			NiPointer<NiSourceTexture> defaultTextureBlack;                   // 070
			NiPointer<NiSourceTexture> defaultTextureWhite;                   // 078
			NiPointer<NiSourceTexture> defaultTextureGrey;                    // 080
			NiPointer<NiSourceTexture> defaultHeightMap;                      // 088
			NiPointer<NiSourceTexture> defaultReflectionCubeMap;              // 090
			NiPointer<NiSourceTexture> defaultFaceDetailMap;                  // 098
			NiPointer<NiSourceTexture> defaultTexEffectMap;                   // 0A0
			NiPointer<NiSourceTexture> defaultTextureNormalMap;               // 0A8
			NiPointer<NiSourceTexture> defaultTextureDitherNoiseMap;          // 0B0
			BSTArray<void*>            cameraDataCache;                       // 0B8
			std::uint32_t              unk0C0;                                // 0D0
			float                      haltonSequence[2][8];                  // 0D4
			float                      dynamicResolutionWidthRatio;           // 114
			float                      dynamicResolutionHeightRatio;          // 118
			float                      dynamicResolutionPreviousWidthRatio;   // 11C
			float                      dynamicResolutionPreviousHeightRatio;  // 120
			std::uint32_t              dynamicResolutionIncreaseFrameWaited;  // 124
			volatile std::int32_t      dynamicResolutionLock;                 // 128
			bool                       canIncreaseDynamicResolution;          // 12C
			bool                       canDecreaseDynamicResolution;          // 12D
			bool                       canChangeDynamicResolution;            // 12E
		};
#ifdef SKYRIM_SUPPORT_AE
		static_assert(sizeof(State) == 0x130);
		static_assert(offsetof(State, frameCount) == 0x54);
		static_assert(offsetof(State, insideFrame) == 0x60);
		static_assert(offsetof(State, letterbox) == 0x61);
		static_assert(offsetof(State, compiledShaderThisFrame) == 0x64);
		static_assert(offsetof(State, useEarlyZ) == 0x65);
		static_assert(offsetof(State, defaultTextureBlack) == 0x70);
		static_assert(offsetof(State, defaultTextureWhite) == 0x78);
		static_assert(offsetof(State, cameraDataCache) == 0xB8);
		static_assert(offsetof(State, dynamicResolutionWidthRatio) == 0x114);
		static_assert(offsetof(State, dynamicResolutionLock) == 0x128);
#else
		static_assert(sizeof(State) == 0x118);
		static_assert(offsetof(State, frameCount) == 0x4C);
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
