#pragma once

#include "RE/B/BSAtomic.h"

namespace RE
{
	class BSTaskletData;
	class BSTaskletGroup;
	class BSTaskletGroupData;

	class BSTaskletManager
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTaskletManager;
		inline static constexpr auto VTABLE = VTABLE_BSTaskletManager;

		virtual ~BSTaskletManager();  // 00

		// add
		virtual void SetTaskletThreadPriority(std::uint32_t a_unk1, std::int32_t a_unk2);                                  // 01 - { return; }
		virtual void ShutdownAllTasks() = 0;                                                                               // 02
		virtual bool IsTaskletThread(std::uint32_t a_threadID) = 0;                                                        // 03
		virtual bool CreateTaskGroupData(BSTaskletGroupData*& a_result) = 0;                                               // 04
		virtual bool OpenTaskGroupData(BSTaskletGroupData* a_taskGroupData) = 0;                                           // 05
		virtual bool AttachTaskData(BSTaskletGroupData* a_taskGroupData, BSTaskletData* a_taskData, bool a_lastTask) = 0;  // 06
		virtual bool CloseTaskGroupData(BSTaskletGroupData* a_taskGroupData) = 0;                                          // 07
		virtual void DestroyTaskGroupData(BSTaskletData* a_tasklet) = 0;                                                   // 08
		virtual void InstanceAvailable();                                                                                  // 09 - { return; }

		bool CreateTaskGroup(BSTaskletGroup& a_taskGroup)
		{
			using func_t = decltype(&BSTaskletManager::CreateTaskGroup);
			static REL::Relocation<func_t> func{ RELOCATION_ID(68207, 69558) };
			return func(this, a_taskGroup);
		}

		// members
		bool               available;          // 08
		bool               signaled;           // 09
		std::uint8_t       pad0A[6];           // 0A
		BSCountedSemaphore instanceSemaphore;  // 10
	};
	static_assert(sizeof(BSTaskletManager) == 0x20);
}
