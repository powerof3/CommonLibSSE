#pragma once

#include "RE/A/ActorValues.h"
#include "RE/M/MagicItem.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	namespace MagicUtilities
	{
		ActorValue                    GetAssociatedResource(MagicItem* a_item, MagicSystem::CastingSource a_castingSource);
		MagicSystem::CannotCastReason GetAssociatedResourceReason(MagicItem* a_item, MagicSystem::CastingSource a_castingSource);
		bool                          UsesResourceOnRelease(MagicItem* a_item, MagicSystem::CastingSource a_castingSource);
		bool                          UsesResourceWhileCasting(MagicItem* a_item, MagicSystem::CastingSource a_castingSource);
		bool                          UsesResourceWhileCharging(MagicItem* a_item, MagicSystem::CastingSource a_castingSource);
	}
}
