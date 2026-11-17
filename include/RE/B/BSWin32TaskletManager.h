#pragma once

#include "RE/B/BSTaskletManager.h"

namespace RE
{
	class BSWin32TaskletData;

	class BSWin32TaskletManager : public BSTaskletManager
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32TaskletManager;
		inline static constexpr auto VTABLE = VTABLE_BSWin32TaskletManager;

		[[nodiscard]] static BSWin32TaskletManager* GetSingleton()
		{
			using func_t = decltype(&BSWin32TaskletManager::GetSingleton);
			static REL::Relocation<func_t> func{ RELOCATION_ID(68203, 69554) };
			return func();
		}

		// override (BSTaskletManager)
		void ShutdownAllTasks() override;                                                                               // 02
		bool IsTaskletThread(std::uint32_t a_threadID) override;                                                        // 03
		bool CreateTaskGroupData(BSTaskletGroupData*& a_result) override;                                               // 04
		bool OpenTaskGroupData(BSTaskletGroupData* a_taskGroupData) override;                                           // 05
		bool AttachTaskData(BSTaskletGroupData* a_taskGroupData, BSTaskletData* a_taskData, bool a_lastTask) override;  // 06
		bool CloseTaskGroupData(BSTaskletGroupData* a_taskGroupData) override;                                          // 07
		void DestroyTaskGroupData(BSTaskletData* a_tasklet) override;                                                   // 08

		// members
		void*                initThreadHandle;    // 20
		std::uint32_t        numThreads;          // 28
		std::uint32_t        numThreadsCreated;   // 2C
		void*                threadHandles[6];    // 30
		std::uint32_t        threadIDs[6];        // 60
		bool                 terminated;          // 78
		std::uint8_t         pad79[7];            // 79
		BSCriticalSection    queueLock;           // 80
		BSWin32TaskletData*  queueHead[0x40];     // A8
		BSWin32TaskletData** queueTail[0x40];     // 2A8
		BSSemaphore          startSemaphore;      // 4A8
		char                 threadNames[0x600];  // 4B0
	};
	static_assert(sizeof(BSWin32TaskletManager) == 0xAB0);
}
