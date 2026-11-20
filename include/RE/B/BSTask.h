#pragma once

namespace RE
{
	class BSTask
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTask;
		inline static constexpr auto VTABLE = VTABLE_BSTask;

		virtual ~BSTask();  // 00

		// add
		virtual void Run() = 0;                                               // 01
		virtual void Finish() = 0;                                            // 02
		virtual void Cancel(std::uint32_t a_previousState, void* a_unk);      // 03 - { return; }
		virtual bool GetDescription(char* a_dest, std::uint32_t a_maxCount);  // 04 - { return false; }

		enum class BS_TASK_STATE : std::uint32_t
		{
			kPending = 0,
			kQueued,
			kMoving,
			kRunning,
			kFinished,
			kCompleted,
			kCanceled,
		};

		void DecRefCount()
		{
			REX::TAtomicRef myRefCount{ refCount };
			if (--myRefCount == 0) {
				delete this;
			}
		}

		void IncRefCount()
		{
			REX::TAtomicRef myRefCount{ refCount };
			++myRefCount;
		}

		// members
		volatile std::int32_t refCount;  // 08
		BS_TASK_STATE         state;     // 0C
		std::int64_t          mapKey;    // 10
	};
	static_assert(sizeof(BSTask) == 0x18);
}
