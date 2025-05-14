#include "RE/B/BGSFootstepManager.h"

namespace RE
{
	BGSFootstepManager* BGSFootstepManager::GetSingleton()
	{
		static REL::Relocation<BGSFootstepManager**> singleton{ Offset::BGSFootstepManager::Singleton };
		return *singleton;
	}
}
