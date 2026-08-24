#include "RE/E/ExtraContainerChanges.h"

#include "RE/I/InventoryChanges.h"

namespace RE
{
	ExtraContainerChanges::ExtraContainerChanges() :
		ExtraContainerChanges(nullptr)
	{}

	ExtraContainerChanges::ExtraContainerChanges(InventoryChanges* a_changes) :
		BSExtraData(),
		changes(a_changes)
	{
		REX::EMPLACE_VTABLE(this);
	}

	ExtraContainerChanges::~ExtraContainerChanges()
	{
		delete changes;
	}

	ExtraDataType ExtraContainerChanges::GetType() const
	{
		return ExtraDataType::kContainerChanges;
	}
}
