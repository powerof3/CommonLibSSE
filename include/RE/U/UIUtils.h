#pragma once

#include "RE/B/BGSSoundDescriptorForm.h"

namespace RE
{
	namespace UIUtils
	{
		inline void PlayMenuSound(const BGSSoundDescriptorForm* a_descriptor)
		{
			using func_t = decltype(&PlayMenuSound);
			static REL::Relocation<func_t> func{ Offset::UIUtils::PlayMenuSound };
			return func(a_descriptor);
		}
	}
}
