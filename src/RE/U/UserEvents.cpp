#include "RE/U/UserEvents.h"

namespace RE
{
	UserEvents* UserEvents::GetSingleton()
	{
		static REL::Relocation<UserEvents**> singleton{ Offset::UserEvents::Singleton };
		return *singleton;
	}
}
