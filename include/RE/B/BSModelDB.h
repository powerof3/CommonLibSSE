#pragma once

#include "RE/D/DBTraits.h"
#include "RE/E/ErrorCodes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;

	namespace BSModelDB
	{
		BSResource::ErrorCode Demand(const char* a_modelPath, NiPointer<NiNode>& a_modelOut, const DBTraits::ArgsType& a_args);
	}
}
