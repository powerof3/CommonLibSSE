#include "RE/A/AnimationFileManagerSingleton.h"

namespace RE
{
	std::uint64_t AnimationFileManagerSingleton::Load(const hkbContext& a_context, hkbClipGenerator* a_clipGenerator, std::uint64_t a_arg4)
	{
		using func_t = decltype(&AnimationFileManagerSingleton::Load);
		REL::Relocation<func_t> func{ RELOCATION_ID(63070, 63982) };
		return func(this, a_context, a_clipGenerator, a_arg4);
	}
}
