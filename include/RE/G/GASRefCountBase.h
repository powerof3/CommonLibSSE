#pragma once

#include "RE/G/GFxPlayerStats.h"
#include "RE/G/GRefCountBaseGC.h"

namespace RE
{
	template <typename T>
	class GASRefCountBase : public GRefCountBaseGC<GFxStatMovieViews::kGFxStatMV_ActionScript_Mem>
	{
	public:
	};
	// size == 0x20
}
