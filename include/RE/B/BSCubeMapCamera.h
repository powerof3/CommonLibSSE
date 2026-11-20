#pragma once

#include <cstdint>

#include "RE/B/BSTArray.h"
#include "RE/N/NiCamera.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiRTTI.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSShaderAccumulator;

	class BSCubeMapCamera : public NiCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSCubeMapCamera;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSCubeMapCamera;
		inline static constexpr auto VTABLE = VTABLE_BSCubeMapCamera;

		enum class FaceEnableFlags : std::uint32_t
		{
			kEnablePosX = 1 << 0,
			kEnableNegX = 1 << 1,
			kEnablePosY = 1 << 2,
			kEnableNegY = 1 << 3,
			kEnablePosZ = 1 << 4,
			kEnableNegZ = 1 << 5,
			kEnableAll = 0x3F
		};

		enum class Face : std::uint32_t
		{
			kPosX = 0,
			kNegX = 1,
			kPosY = 2,
			kNegY = 3,
			kPosZ = 4,
			kNegZ = 5
		};

		~BSCubeMapCamera() override = default;  // 00

		// override (NiCamera)
		const NiRTTI* GetRTTI() const override;  // 02

		// add
		virtual void RenderCubemap(FaceEnableFlags a_faceMask, bool a_arg2, bool a_clearScenes, bool a_arg4);  // 35

		static BSCubeMapCamera* Create();

		void SetFace(Face a_face);

		// members
		BSTArray<NiPointer<NiAVObject>> scenes;                 // 188
		NiPointer<BSShaderAccumulator>  accumulator;            // 1A0
		NiPointer<BSShaderAccumulator>  accumulatorBackground;  // 1A8
		NiPointer<NiCamera>             cameraBackground;       // 1B0
		NiColorA                        silhouetteColor;        // 1B8

	protected:
		BSCubeMapCamera* Ctor();
	};
	static_assert(sizeof(BSCubeMapCamera) == 0x1C8);
}
