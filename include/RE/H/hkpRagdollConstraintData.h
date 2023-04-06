#pragma once

#include "RE/H/hkpConstraintAtom.h"
#include "RE/H/hkpConstraintData.h"

namespace RE
{
	class hkpRagdollConstraintData : public hkpConstraintData
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpRagdollConstraintData;
		inline static constexpr auto VTABLE = VTABLE_hkpRagdollConstraintData;

		struct Atoms
		{
			struct hkpSetLocalTransformsConstraintAtom transforms;
			struct hkpSetupStabilizationAtom           setupStabilization;
			struct hkpRagdollMotorConstraintAtom       ragdollMotors;
			struct hkpAngFrictionConstraintAtom        angFriction;
			struct hkpTwistLimitConstraintAtom         twistLimit;
			struct hkpConeLimitConstraintAtom          coneLimit;
			struct hkpConeLimitConstraintAtom          planesLimit;
			struct hkpBallSocketConstraintAtom         ballSocket;
		};
		static_assert(sizeof(Atoms) == 0x160);

		// members
		Atoms atoms;  // 18
	};
	static_assert(sizeof(hkpRagdollConstraintData) == 0x180);
}
