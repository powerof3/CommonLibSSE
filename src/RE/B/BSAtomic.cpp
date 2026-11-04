#include "RE/B/BSAtomic.h"

#include "REX/W32/KERNEL32.h"

namespace RE
{
	BSNonReentrantSpinLock::BSNonReentrantSpinLock() :
		lock(0)
	{}

	void BSNonReentrantSpinLock::Lock()
	{
		while (REX::W32::InterlockedCompareExchange(&lock, 1, 0)) {
			REX::W32::Sleep(0);
		}
		_mm_mfence();
	}

	void BSNonReentrantSpinLock::Unlock()
	{
		lock = 0;
		_mm_mfence();
	}

	BSSemaphoreBase::BSSemaphoreBase(std::int32_t a_initCount, std::int32_t a_maxCount) :
		semaphore(REX::W32::CreateSemaphoreA(nullptr, a_initCount, a_maxCount, nullptr))
	{}

	BSSemaphoreBase::~BSSemaphoreBase()
	{
		REX::W32::CloseHandle(semaphore);
	}

	bool BSSemaphoreBase::Signal()
	{
		//return REX::W32::ReleaseSemaphore(semaphore, 1, nullptr);
		// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		return false;
	}

	std::uint32_t BSSemaphoreBase::Wait()
	{
		return REX::W32::WaitForSingleObject(semaphore, 0xFFFFFFFF);
	}

	BSCountedSemaphore::BSCountedSemaphore(std::int32_t a_initCount, std::int32_t a_maxCount) :
		BSSemaphoreBase(a_initCount, a_maxCount),
		count(a_initCount),
		maxCount(a_maxCount)
	{}

	bool BSCountedSemaphore::Signal()
	{
		const auto result = BSSemaphoreBase::Signal();
		if (result) {
			IncCount();
		}
		return result;
	}

	std::uint32_t BSCountedSemaphore::Wait()
	{
		const auto result = BSSemaphoreBase::Wait();
		if (result == 0) {
			DecCount();
		}
		return result;
	}

	void BSCountedSemaphore::DecCount()
	{
		REX::TAtomicRef myCount{ count };
		--myCount;
	}

	void BSCountedSemaphore::IncCount()
	{
		REX::TAtomicRef myCount{ count };
		++myCount;
	}

	BSSemaphore::BSSemaphore() :
		BSSemaphoreBase(0, 1)
	{}

	BSSemaphore::BSSemaphore(std::int32_t a_initCount, std::int32_t a_maxCount) :
		BSSemaphoreBase(a_initCount, a_maxCount)
	{}

	BSSpinLock::BSSpinLock() :
		_owningThread(0),
		_lockCount(0)
	{}

	void BSSpinLock::Lock(std::uint32_t a_pauseAttempts)
	{
		std::uint32_t myThreadID = REX::W32::GetCurrentThreadId();

		_mm_lfence();
		if (_owningThread == myThreadID) {
			REX::W32::InterlockedIncrement(&_lockCount);
		} else {
			std::uint32_t attempts = 0;
			if (REX::W32::InterlockedCompareExchange(&_lockCount, 1, 0)) {
				do {
					++attempts;
					_mm_pause();
					if (attempts >= a_pauseAttempts) {
						std::uint32_t spinCount = 0;
						while (REX::W32::InterlockedCompareExchange(&_lockCount, 1, 0)) {
							REX::W32::Sleep(++spinCount < kFastSpinThreshold ? 0 : 1);
						}
						break;
					}
				} while (REX::W32::InterlockedCompareExchange(&_lockCount, 1, 0));
				_mm_lfence();
			}

			_owningThread = myThreadID;
			_mm_sfence();
		}
	}

	void BSSpinLock::Unlock()
	{
		std::uint32_t myThreadID = REX::W32::GetCurrentThreadId();

		_mm_lfence();
		if (_owningThread == myThreadID) {
			if (_lockCount == 1) {
				_owningThread = 0;
				_mm_mfence();
				REX::W32::InterlockedCompareExchange(&_lockCount, 0, 1);
			} else {
				REX::W32::InterlockedDecrement(&_lockCount);
			}
		}
	}

	BSReadWriteLock::BSReadWriteLock() :
		_writerThread(0),
		_lock(0)
	{}

	void BSReadWriteLock::LockForRead()
	{
		using func_t = decltype(&BSReadWriteLock::LockForRead);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66976, 68233) };
		func(this);
	}

	void BSReadWriteLock::UnlockForRead()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockForRead);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66982, 68239) };
		func(this);
	}

	void BSReadWriteLock::LockForWrite()
	{
		using func_t = decltype(&BSReadWriteLock::LockForWrite);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66977, 68234) };
		func(this);
	}

	void BSReadWriteLock::UnlockForWrite()
	{
		using func_t = decltype(&BSReadWriteLock::UnlockForWrite);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66983, 68240) };
		func(this);
	}

	BSSpinLockGuard::BSSpinLockGuard(BSSpinLock& a_lock) :
		_lock(a_lock)
	{
		_lock.Lock();
	}

	BSSpinLockGuard::~BSSpinLockGuard()
	{
		_lock.Unlock();
	}

	BSReadLockGuard::BSReadLockGuard(BSReadWriteLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForRead();
	}

	BSReadLockGuard::~BSReadLockGuard()
	{
		_lock.UnlockForRead();
	}

	BSWriteLockGuard::BSWriteLockGuard(BSReadWriteLock& a_lock) :
		_lock(a_lock)
	{
		_lock.LockForWrite();
	}

	BSWriteLockGuard::~BSWriteLockGuard()
	{
		_lock.UnlockForWrite();
	}
}
