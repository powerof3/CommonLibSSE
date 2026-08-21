#include "RE/B/BSShaderAccumulator.h"

namespace RE
{
	BSShaderAccumulator* BSShaderAccumulator::GetCurrentAccumulator()
	{
		using func_t = decltype(&BSShaderAccumulator::GetCurrentAccumulator);
		static REL::Relocation<func_t> func{ RELOCATION_ID(98997, 105651) };
		return func();
	}

	void BSShaderAccumulator::SetCurrentAccumulator(BSShaderAccumulator* a_accumulator)
	{
		using func_t = decltype(&BSShaderAccumulator::SetCurrentAccumulator);
		static REL::Relocation<func_t> func{ RELOCATION_ID(98998, 105652) };
		return func(a_accumulator);
	}
}
