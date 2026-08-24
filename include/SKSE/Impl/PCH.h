#pragma once

#include <REL/REL.h>
#include <REX/REX.h>

namespace RE
{
	using namespace std::literals;
}

namespace REL
{
	using namespace std::literals;
}

namespace SKSE
{
	using namespace std::literals;
}

#ifdef SKYRIM_SUPPORT_AE
#	define RELOCATION_ID(SE, AE) REL::ID(AE)
#else
#	define RELOCATION_ID(SE, AE) REL::ID(SE)
#endif

#include "RE/Offsets_NiRTTI.h"
#include "RE/Offsets_RTTI.h"
#include "RE/Offsets_VTABLE.h"

#include "RE/B/BSCoreTypes.h"
#include "RE/S/SFTypes.h"
