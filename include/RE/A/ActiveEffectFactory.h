#pragma once

#include "RE/E/Effect.h"
#include "RE/M/MagicCaster.h"
#include "RE/M/MagicItem.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	namespace ActiveEffectFactory
	{
		bool CheckCast(MagicCaster* a_caster, MagicItem* a_spell, Effect* a_effect, MagicSystem::CannotCastReason& a_reason);
	}
}
