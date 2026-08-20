#include "RE/B/BSScaleformTranslator.h"

namespace RE
{
	void BSScaleformTranslator::GetCachedString(wchar_t** a_pOut, wchar_t* a_bufIn, std::uint32_t a_unused)
	{
		using func_t = decltype(&BSScaleformTranslator::GetCachedString);
		static REL::Relocation<func_t> func{ RELOCATION_ID(67844, 69188) };
		return func(a_pOut, a_bufIn, a_unused);
	}
}
