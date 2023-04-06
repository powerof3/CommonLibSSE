#pragma once

#include "RE/B/BGSDefaultObjectManager.h"

namespace RE
{
	class Actor;

	namespace SourceActionMap
	{
		[[nodiscard]] std::span<DEFAULT_OBJECT, 12> GetSingleton();
		bool                                        DoAction(Actor* a_actor, DEFAULT_OBJECT a_action);
	}
}
