#pragma once

#include "RE/T/TESCameraState.h"

namespace RE
{
	class VATSCameraState : public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_VATSCameraState;
		inline static constexpr auto VTABLE = VTABLE_VATSCameraState;

		~VATSCameraState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05

		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
	};
	static_assert(sizeof(VATSCameraState) == 0x38);
}
