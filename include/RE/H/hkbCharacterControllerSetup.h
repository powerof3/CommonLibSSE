#pragma once

#include "RE/H/hkbRigidBodySetup.h"

namespace RE
{
	class hkReferencedObject;

	struct hkbCharacterControllerSetup
	{
		// members
		hkbRigidBodySetup   rigidBodySetup;   // 00
		hkReferencedObject* controllerCInfo;  // 20
	};
	static_assert(sizeof(hkbCharacterControllerSetup) == 0x28);
}
