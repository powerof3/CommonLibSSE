#include "RE/C/ContainerMenu.h"

namespace RE
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		static REL::Relocation<ContainerMode*> mode{ RELOCATION_ID(519396, 405937) };
		return *mode;
	}

	RefHandle ContainerMenu::GetTargetRefHandle()
	{
		static REL::Relocation<RefHandle*> handle{ RELOCATION_ID(519421, 405962) };
		return *handle;
	}
}
