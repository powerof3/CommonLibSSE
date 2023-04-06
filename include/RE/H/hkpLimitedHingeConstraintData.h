#pragma once

#include "RE/H/hkpConstraintAtom.h"
#include "RE/H/hkpConstraintData.h"

namespace RE
{
	class hkpLimitedHingeConstraintData : public hkpConstraintData
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpLimitedHingeConstraintData;
		inline static constexpr auto VTABLE = VTABLE_hkpLimitedHingeConstraintData;

		struct Atoms
		{
			struct hkpSetLocalTransformsConstraintAtom transforms;
			struct hkpSetupStabilizationAtom           setupStabilization;
			struct hkpAngMotorConstraintAtom           angMotor;
			struct hkpAngFrictionConstraintAtom        angFriction;
			struct hkpAngLimitConstraintAtom           angLimit;
			struct hkp2dAngConstraintAtom              twoDAng;
			struct hkpBallSocketConstraintAtom         ballSocket;
		};
		static_assert(sizeof(Atoms) == 0xF0);

		// members
		Atoms atoms;  // 18
	};
	static_assert(sizeof(hkpLimitedHingeConstraintData) == 0x110);
}
