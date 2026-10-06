#pragma once

#include "RE/b/bhkEntityListener.h"

namespace RE
{
	class BGSAcousticSpaceListener : public bhkEntityListener
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSAcousticSpaceListener;
		inline static constexpr auto VTABLE = VTABLE_BGSAcousticSpaceListener;

		~BGSAcousticSpaceListener() override;  // 00

		// override (bhkEntityListener)
		void EntityRemovedCallback(hkpEntity* a_entity) override;            // 02
		void Update(float a_delta) override;                                 // 06
		bool ContactPointAddedCallback(hkpRootCdPoint& a_point) override;    // 07
		bool ContactPointRemovedCallback(hkpRootCdPoint& a_point) override;  // 08

		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20 - BSTHashMap?
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
	};
	static_assert(sizeof(BGSAcousticSpaceListener) == 0x50);
}
