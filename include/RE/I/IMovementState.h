#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/H/hkpCharacterState.h"
#include "RE/I/IMovementInterface.h"

namespace RE
{
	class NiPoint3;
	class IMovementParameters;
	struct BSPathingLocation;
	namespace Movement
	{
		struct MaxSpeeds;
		struct IdleThresholds;
	}

	class IMovementState : public IMovementInterface
	{
	public:
		inline static constexpr auto RTTI = RTTI_IMovementState;
		inline static constexpr auto VTABLE = VTABLE_IMovementState;

		~IMovementState() override;  // 00

		// add
		virtual std::uint32_t              DoGetNumericID() = 0;                                                                     // 01
		virtual void                       DoGetPathingLocation(BSPathingLocation& a_retLocation) = 0;                               // 02
		virtual void                       DoGetLocation(NiPoint3& a_retLocation) = 0;                                               // 03
		virtual void                       DoGetEulerAngles(NiPoint3& a_retAngles) = 0;                                              // 04
		virtual float                      DoGetMovementSpeed() = 0;                                                                 // 05
		virtual float                      DoGetRotationSpeed() = 0;                                                                 // 06
		virtual float                      DoGetMovementRotation(NiPoint3& a_retMovementRotation) = 0;                               // 07
		virtual bool                       DoGetCurrentMaxSpeeds(Movement::MaxSpeeds& a_retMaxSpeeds) = 0;                           // 08
		virtual float                      DoGetMovementRadius() = 0;                                                                // 09
		virtual float                      DoGetMovementWidth() = 0;                                                                 // 0A
		virtual float                      DoGetMovementLength() = 0;                                                                // 0B
		virtual float                      DoGetMovementHeight() = 0;                                                                // 0C
		virtual float                      DoGetLookingHeight() = 0;                                                                 // 0D
		virtual bool                       DoMakeDefaultMovementParameters(BSTSmartPointer<IMovementParameters>& a_parameters) = 0;  // 0E
		virtual const IMovementParameters& DoGetDefaultMovementParameters() = 0;                                                     // 0F
		virtual bool                       DoGetIdleThresholds(Movement::IdleThresholds& a_unk) = 0;                                 // 10
		virtual hkpCharacterStateType      DoGetCharacterState() = 0;                                                                // 11
		virtual bool                       DoGetMountedByPlayer() = 0;                                                               // 12
		virtual bool                       DoGetUseVelocityObstacles() = 0;                                                          // 13
	};
	static_assert(sizeof(IMovementState) == 0x8);
}
