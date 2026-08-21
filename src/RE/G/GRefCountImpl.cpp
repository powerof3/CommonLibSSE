#include "RE/G/GRefCountImpl.h"

namespace RE
{
	void GRefCountImpl::AddRef()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		++myRefCount;
	}

	void GRefCountImpl::Release()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		if (--myRefCount == 0) {
			delete this;
		}
	}
}
