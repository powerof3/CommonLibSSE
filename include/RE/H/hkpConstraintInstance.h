#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hkpConstraintData;
	class hkpConstraintOwner;
	struct hkpModifierConstraintAtom;

	class hkpConstraintInstance : public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpConstraintInstance;
		inline static constexpr auto VTABLE = VTABLE_hkpConstraintInstance;

		~hkpConstraintInstance() override;  // 00

		inline hkpRigidBody* GetRigidBodyA() const
		{
			return reinterpret_cast<hkpRigidBody*>(entities[0]);
		}

		inline hkpRigidBody* GetRigidBodyB() const
		{
			return reinterpret_cast<hkpRigidBody*>(entities[1]);
		}

		// members
		hkpConstraintOwner*        owner;                // 10
		hkpConstraintData*         data;                 // 18
		hkpModifierConstraintAtom* constraintModifiers;  // 20
		hkpEntity*                 entities[2];          // 28
	};
	static_assert(sizeof(hkpConstraintInstance) == 0x38);
}
