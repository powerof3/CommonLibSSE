#pragma once

#include "RE/T/TESCameraState.h"

namespace RE
{
	class FurnitureCameraState : public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_FurnitureCameraState;
		inline static constexpr auto VTABLE = VTABLE_FurnitureCameraState;

		~FurnitureCameraState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05

		std::uint32_t unk20;  // 20
		NiPoint3      unk24;  // 24
		std::uint64_t unk30;  // 30
		std::uint32_t unk38;  // 38
		std::uint16_t unk3C;  // 3C
		std::uint16_t unk3E;  // 3E
	};
	static_assert(sizeof(FurnitureCameraState) == 0x40);
}
