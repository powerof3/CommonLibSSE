#include "RE/I/INIPrefSettingCollection.h"

namespace RE
{
	INIPrefSettingCollection* INIPrefSettingCollection::GetSingleton()
	{
		static REL::Relocation<INIPrefSettingCollection**> singleton{ Offset::INIPrefSettingCollection::Singleton };
		return *singleton;
	}
}
