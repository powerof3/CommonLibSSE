#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class TESObjectCell;

	class LoadedAreaBound : public NiRefObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_LoadedAreaBound;
		inline static constexpr auto VTABLE = VTABLE_LoadedAreaBound;

		~LoadedAreaBound() override;  // 00

		void*          unk10;        // 10 - smart ptr
		std::uint64_t  unk18;        // 18
		std::uint64_t  unk20;        // 20
		std::uint64_t  unk28;        // 28
		std::uint64_t  unk30;        // 30
		std::uint64_t  unk38;        // 38
		TESObjectCell* currentCell;  // 40
		std::uint64_t  unk48;        // 48
		std::uint64_t  unk50;        // 50
		std::uint64_t  unk58;        // 58
		std::uint64_t  unk60;        // 60
		std::uint64_t  unk68;        // 68
		std::uint64_t  unk70;        // 70
		NiPoint3       unk78;        // 78
		NiPoint3       unk84;        // 84
		std::uint64_t  unk90;        // 90
		std::uint64_t  unk98;        // 98
	};
	static_assert(sizeof(LoadedAreaBound) == 0xA0);
}
