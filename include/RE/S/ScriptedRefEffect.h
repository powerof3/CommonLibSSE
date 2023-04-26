#pragma once

#include "RE/S/ScriptEffect.h"

namespace RE
{
	class ScriptedRefEffect :
		public ScriptEffect  // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_ScriptedRefEffect;
		inline static constexpr auto VTABLE = VTABLE_ScriptedRefEffect;

		// override (ActiveEffect)
		virtual ~ScriptedRefEffect();  // 13
	};
	static_assert(sizeof(ScriptedRefEffect) == 0xA0);
}
