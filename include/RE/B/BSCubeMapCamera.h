#pragma once

#include "RE/N/NiCamera.h"
#include "RE/N/NiRTTI.h"

namespace RE
{
	class BSCubeMapCamera : public NiCamera
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSCubeMapCamera;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSCubeMapCamera;
		inline static constexpr auto VTABLE = VTABLE_BSCubeMapCamera;

		virtual ~BSCubeMapCamera() override { Dtor(); };  // 00

		// override (NiCamera)
		const NiRTTI* GetRTTI() const override;  // 02

	private:
		void Dtor();
	};
}
