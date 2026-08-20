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
			float                      unk044;                             // 044
			float                      unk048;                             // 048
			std::uint32_t              frameCount;                         // 04C
			bool                       unk50;                              // 050 - previously misnamed insideFrame
			bool                       letterbox;                          // 051
			bool                       unk052;                             // 052
			bool                       compiledShaderThisFrame;            // 053
			bool                       insideFrame;                        // 054 - previously misnamed useEarlyZ
			bool                       unk055;                             // 055
#ifdef SKYRIM_SUPPORT_AE
			bool unk56;                                       // 056
			bool doubleDynamicResolutionAdjustmentFrequency;  // 057
			bool unk58;                                       // 058
			bool unk59;                                       // 059
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
#else
		static_assert(sizeof(State) == 0x118);
#endif
	}
}
