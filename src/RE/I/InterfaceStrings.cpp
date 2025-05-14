#include "RE/I/InterfaceStrings.h"

namespace RE
{
	InterfaceStrings* InterfaceStrings::GetSingleton()
	{
		static REL::Relocation<InterfaceStrings**> singleton{ Offset::InterfaceStrings::Singleton };
		return *singleton;
	}
}
