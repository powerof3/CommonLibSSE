#pragma once

#include "RE/B/BSTaskManager.h"

namespace RE
{
	class IOManager : public BSTaskManager
	{
	public:
		inline static constexpr auto RTTI = RTTI_IOManager;
		inline static constexpr auto VTABLE = VTABLE_IOManager;

		static IOManager* GetSingleton()
		{
			static REL::Relocation<IOManager**> singleton{ RELOCATION_ID(524542, 411121) };
			return *singleton;
		}

		~IOManager() override;  // 00

		// override (SynchronizedMap<std::int64_t, NiPointer<BSTask>>)
		std::uint32_t GetBucketForKey(std::int64_t a_key) override;  // 08

		// override (BSTaskManager)
		bool AddTask(BSTask* a_task) override;                  // 11
		void CancelAllTasks() override;                         // 14
		void DoOnPreRunTask(BSTaskThread* a_thread) override;   // 15
		void DoOnThreadPause(BSTaskThread* a_thread) override;  // 16

		// add
		void DoOnThreadResumed(BSTaskThread* a_thread);  // 18

		// members
		std::uint64_t unk0C0;  // 0C0
		std::uint64_t unk0C8;  // 0C8
		std::uint64_t unk0D0;  // 0D0
		std::uint64_t unk0D8;  // 0D8
		std::uint64_t unk0E0;  // 0E0
		std::uint64_t unk0E8;  // 0E8
		std::uint64_t unk0F0;  // 0F0
		std::uint64_t unk0F8;  // 0F8
		std::uint64_t unk100;  // 100
		std::uint64_t unk108;  // 108
		std::uint64_t unk110;  // 110
		std::uint64_t unk118;  // 118
		std::uint64_t unk120;  // 120
	};
	static_assert(sizeof(IOManager) == 0x128);
}
