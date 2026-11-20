#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTaskletGroupData.h"

namespace RE
{
	class BSWin32TaskletGroupData : public BSTaskletGroupData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSWin32TaskletGroupData;
		inline static constexpr auto VTABLE = VTABLE_BSWin32TaskletGroupData;

		~BSWin32TaskletGroupData() override;  // 00

		// override (BSTaskletGroupData)
		void WaitForCompletion(bool a_poll) override;  // 01
		void Cancel() override;                        // 02
		void ForceProcess(float a_ms) override;        // 03

		// members
		BSSemaphore       completionSemaphore;  // 10
		BSCriticalSection lock;                 // 18
		bool              isAttached;           // 40
		bool              allowTaskAttach;      // 41
		bool              cancelled;            // 42
		std::uint8_t      pad43;                // 43
		std::uint32_t     priority;             // 44
		std::uint32_t     attached;             // 48
		std::uint32_t     completed;            // 4C
	};
	static_assert(sizeof(BSWin32TaskletGroupData) == 0x50);
}
