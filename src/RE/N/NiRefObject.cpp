#include "RE/N/NiRefObject.h"

namespace RE
{
	NiRefObject::NiRefObject()
	{
		REX::TAtomicRef objectCount{ *GetTotalObjectCount() };
		++objectCount;
	}

	NiRefObject::~NiRefObject()
	{
		REX::TAtomicRef objectCount{ *GetTotalObjectCount() };
		--objectCount;
	}

	void NiRefObject::DeleteThis()
	{
		delete this;
	}

	void NiRefObject::IncRefCount()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		++myRefCount;
	}

	void NiRefObject::DecRefCount()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		if (--myRefCount == 0) {
			DeleteThis();
		}
	}

	volatile std::uint32_t* NiRefObject::GetTotalObjectCount()
	{
		static REL::Relocation<volatile std::uint32_t*> totalObjectCount{ RELOCATION_ID(523912, 410493) };
		return totalObjectCount.get();
	}
}
