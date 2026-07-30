#pragma once

#include "RE/B/BGSActorCellEvent.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSMusicType;

	class PlayerRegionState :
		public BSTEventSink<BGSActorCellEvent>,
		public BSTSingletonSDM<PlayerRegionState>
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerRegionState;
		inline static constexpr auto VTABLE = VTABLE_PlayerRegionState;

		~PlayerRegionState() override;

		// override (BSTEventSink<BGSActorCellEvent>)
		BSEventNotifyControl ProcessEvent(const BGSActorCellEvent* a_event, BSTEventSource<BGSActorCellEvent>* a_eventSource) override;  // 01

		static PlayerRegionState* GetSingleton()
		{
			static REL::Relocation<PlayerRegionState**> singleton{ RELOCATION_ID(514317, 400477) };
			return *singleton;
		}

		// members
		BSTArray<void*>                    unk10;                   // 10
		BSTArray<void*>                    unk28;                   // 28
		bool                               unk40;                   // 40
		bool                               unk41;                   // 41
		std::uint16_t                      pad42;                   // 42
		std::uint32_t                      pad44;                   // 44
		TESRegion*                         lastKnownWeatherRegion;  // 48
		BGSMusicType*                      unk50;                   // 50
		BSTEventSource<BGSActorCellEvent>* eventSource;             // 58
	};
	static_assert(sizeof(PlayerRegionState) == 0x60);
}
