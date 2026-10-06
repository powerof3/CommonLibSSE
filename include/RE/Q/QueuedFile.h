#pragma once

#include "RE/I/IOTask.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class QueuedFile : public IOTask
	{
	public:
		inline static constexpr auto RTTI = RTTI_QueuedFile;
		inline static constexpr auto VTABLE = VTABLE_QueuedFile;

		~QueuedFile() override;  // 00

		// override (BSTask)
		void Run() override;                                               // 01 - { return; }
		void Finish() override;                                            // 02
		void Cancel(std::uint32_t a_previousState, void* a_unk) override;  // 03

		// override (IOTask)
		void Requeue(std::uint32_t a_newPriority) override;  // 08

		// add
		virtual void DoOnQueueMe();           // 09 - { return; }
		virtual void DoOnChildrenFinished();  // 0A - { return; }
		virtual void DoOnTaskFinished();      // 0B - { return; }

		// members
		std::uint64_t         unk18;     // 18
		NiPointer<QueuedFile> parent;    // 20
		std::uint64_t         children;  // 28
		std::uint64_t         unk30;     // 30
	};
	static_assert(sizeof(QueuedFile) == 0x38);
}
