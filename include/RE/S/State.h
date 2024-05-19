#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiSourceTexture.h"

namespace RE
{
	namespace BSGraphics
	{
		class State
		{
		public:
			[[nodiscard]] static State* GetSingleton()
			{
				REL::Relocation<State*> singleton{ RELOCATION_ID(524998, 411479) };
				return singleton.get();
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
			float                      unk044;                             // 044
			float                      unk048;                             // 048
			std::uint32_t              frameCount;                         // 04C
			bool                       insideFrame;                        // 050
			bool                       letterbox;                          // 051
			bool                       unk052;                             // 052
			bool                       compiledShaderThisFrame;            // 053
			bool                       useEarlyZ;                          // 054
			bool                       unk055;                             // 055
#ifdef SKYRIM_SUPPORT_AE
			bool unk56;                                       // 056
			bool doubleDynamicResolutionAdjustmentFrequency;  // 057
			bool unk58;                                       // 058
#endif
			std::uint32_t              unk058;                                // 058
			std::uint32_t              unk05C;                                // 05C
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
#ifndef SKYRIMVR
			std::uint8_t unk11E;  // 11E
			std::uint8_t pad11F;  // 11F
#else
			std::uint16_t padVR11E;  // 11E
			std::int32_t  unkVR120;  // 120
			std::uint32_t padVR124;  // 124
#endif
		};
		static_assert(offsetof(State, screenWidth) == 0x24);
		static_assert(offsetof(State, frameBufferViewport) == 0x2C);
		static_assert(offsetof(State, letterbox) == 0x51);
#ifndef SKYRIMVR
#	ifdef SKYRIM_SUPPORT_AE
		static_assert(sizeof(State) == 0x120);
#	else
		static_assert(sizeof(State) == 0x118);
#	endif
#endif
	}
}
