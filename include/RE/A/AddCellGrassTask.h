#pragma once

#include "RE/Q/QueuedFile.h"

namespace RE
{
	class TESObjectCELL;

	class AddCellGrassTask : public QueuedFile
	{
	public:
		inline static constexpr auto RTTI = RTTI_AddCellGrassTask;
		inline static constexpr auto VTABLE = VTABLE_AddCellGrassTask;

		~AddCellGrassTask() override;  // 00

		// override (BSTask)
		void Run() override;  // 01

		static void CreateGrassLoadTaskForCell(TESObjectCELL* a_cell)
		{
			using func_t = decltype(&AddCellGrassTask::CreateGrassLoadTaskForCell);
			static REL::Relocation<func_t> func{ RELOCATION_ID(13137, 13277) };
			func(a_cell);
		}

		// members
		TESObjectCELL* cell;      // 38
		std::int32_t   x;         // 40
		std::int32_t   y;         // 44
		bool           cancel;    // 48
		std::uint8_t   pad49[7];  // 49
	};
	static_assert(sizeof(AddCellGrassTask) == 0x50);
}
