#pragma once

#include "RE/T/TESCameraState.h"

namespace RE
{
	class AutoVanityState : public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_AutoVanityState;
		inline static constexpr auto VTABLE = VTABLE_AutoVanityState;

		~AutoVanityState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05

		// members
		float         autoVanityRot;  // 20
		std::uint32_t pad24;          // 24
	};
	static_assert(sizeof(AutoVanityState) == 0x28);
}
