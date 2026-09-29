#pragma once

#include "RE/I/IOTask.h"

namespace RE
{
	class ExteriorCellLoader;
	class TESObjectCELL;
	class TESWorldSpace;

	class CellLoaderTask : public IOTask
	{
	public:
		inline static constexpr auto RTTI = RTTI_CellLoaderTask;
		inline static constexpr auto VTABLE = VTABLE_CellLoaderTask;

		~CellLoaderTask() override;  // 00

		// override (BSTask)
		void Run() override;                                                   // 01
		void Finish() override;                                                // 02
		void Cancel(std::uint32_t a_previousState, void* a_unk) override;      // 03
		bool GetDescription(char* a_dest, std::uint32_t a_maxCount) override;  // 04

		// override (IOTask)
		void PostProcess() override;  // 06

		// members
		ExteriorCellLoader* loader;  // 18
		TESWorldSpace*      world;   // 20
		TESObjectCELL*      cell;    // 28
		std::int32_t        x;       // 30
		std::int32_t        y;       // 34
		std::uint32_t       state;   // 38 - modified with InterlockedCompareExchange
		std::uint32_t       unk3C;   // 3C
	};
	static_assert(sizeof(CellLoaderTask) == 0x40);
}
