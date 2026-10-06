#pragma once

#include "RE/B/BSWin32TaskletData.h"

namespace RE
{
	class BSProceduralLightningTasklet : public BSWin32TaskletData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSProceduralLightningTasklet;
		inline static constexpr auto VTABLE = VTABLE_BSProceduralLightningTasklet;

		~BSProceduralLightningTasklet() override;  // 00

		// override (BSTaskletData)
		void Process() override;     // 02
		void OnComplete() override;  // 03

		// members
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
		std::uint64_t unk68;  // 68
		std::uint64_t unk70;  // 70
		std::uint64_t unk78;  // 78
		std::uint64_t unk80;  // 80
		std::uint64_t unk88;  // 88
		std::uint64_t unk90;  // 90
		std::uint64_t unk98;  // 98
		std::uint64_t unkA0;  // A0
		std::uint64_t unkA8;  // A8
	};
	static_assert(sizeof(BSProceduralLightningTasklet) == 0xB0);
}
