#pragma once

#include "RE/N/NiPoint2.h"
#include "RE/N/NiQuaternion.h"
#include "RE/T/TESCameraState.h"

namespace RE
{
	class TweenMenuCameraState : public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_TweenMenuCameraState;
		inline static constexpr auto VTABLE = VTABLE_TweenMenuCameraState;

		~TweenMenuCameraState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05

		// members
		NiQuaternion  intialRotation;   // 20
		float         initialFOV;       // 30
		NiPoint2      currentAddedRot;  // 34
		NiPoint2      targetAddedRot;   // 3C
		float         currentAddedFOV;  // 44
		float         targetAddedFOV;   // 48
		bool          endingState;      // 4C
		std::uint8_t  pad4D;            // 4D
		std::uint16_t pad4E;            // 4E
	};
	static_assert(sizeof(TweenMenuCameraState) == 0x50);
}
