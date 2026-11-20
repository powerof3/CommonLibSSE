#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTask.h"
#include "RE/B/BSTaskManagerWaitAction.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/SynchronizedMap.h"

namespace RE
{
	class BSTaskThread;
	class BSTaskManagerThread;

	class BSTaskManager :
		public SynchronizedMap<std::int64_t, NiPointer<BSTask>>,
		public BSTEventSource<BSTaskManagerWaitAction>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTaskManager;
		inline static constexpr auto VTABLE = VTABLE_BSTaskManager;

		~BSTaskManager() override;  // 00

		// add
		virtual bool AddTask(BSTask* a_task);                   // 11
		virtual void RunTask(BSTask* a_task);                   // 12
		virtual void FinishTask(BSTask* a_task);                // 13
		virtual void CancelAllTasks();                          // 14
		virtual void DoOnPreRunTask(BSTaskThread* a_thread);    // 15 - { return; }
		virtual void DoOnThreadPause(BSTaskThread* a_thread);   // 16 - { return; }
		virtual void DoOnThreadResume(BSTaskThread* a_thread);  // 17 - { return; }

		// members
		BSTaskManagerThread**   threads;           // 98
		volatile std::uint32_t  numPausedThreads;  // A0
		volatile std::uint32_t  pauseCount;        // A4
		std::uint32_t           numThreads;        // A8
		std::uint32_t           padAC;             // AC
		volatile std::uint32_t* bucketTaskCounts;  // B0
		volatile std::uint32_t  numQueuedTasks;    // B8
		std::uint32_t           padBC;             // BC
	};
	static_assert(sizeof(BSTaskManager) == 0xC0);
}
