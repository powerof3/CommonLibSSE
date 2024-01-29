#include "RE/M/MagicSystem.h"

namespace RE
{
	namespace MagicSystem
	{
		const char* GetCannotCastString(MagicSystem::CannotCastReason a_reason)
		{
			using func_t = decltype(&MagicSystem::GetCannotCastString);
			REL::Relocation<func_t> func{ RELOCATION_ID(11295, 11423) };
			return func(a_reason);
		}

		float GetMagicCasterTargetUpdateInterval()
		{
			using func_t = decltype(&MagicSystem::GetMagicCasterTargetUpdateInterval);
			REL::Relocation<func_t> func{ RELOCATION_ID(11294, 11422) };
			return func();
		}

		BGSSoundDescriptorForm* GetMagicFailureSound(MagicSystem::SpellType a_type)
		{
			using func_t = decltype(&MagicSystem::GetMagicFailureSound);
			REL::Relocation<func_t> func{ RELOCATION_ID(11286, 11411) };
			return func(a_type);
		}
	}
}
