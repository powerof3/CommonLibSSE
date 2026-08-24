#include "RE/B/BSHandleRefObject.h"

namespace RE
{
	BSHandleRefObject::~BSHandleRefObject()
	{
		_refCount = _refCount & kRefCountMask;
		REX::TAtomicRef totalObjects{ *GetTotalObjectCount() };
		--totalObjects;
	}

	void BSHandleRefObject::DecRefCount()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		if (((--myRefCount) & kRefCountMask) == 0) {
			DeleteThis();
		}
	}

	void BSHandleRefObject::IncRefCount()
	{
		REX::TAtomicRef myRefCount{ _refCount };
		++myRefCount;
	}

	bool BSHandleRefObject::IsHandleValid() const
	{
		return static_cast<bool>(_refCount & kHandleValid);
	}

	std::uint32_t BSHandleRefObject::QRefCount() const
	{
		return _refCount & kRefCountMask;
	}
}
