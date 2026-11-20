#pragma once

#include "RE/B/BGSActionData.h"

namespace RE
{
	class TESActionData : public BGSActionData
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESActionData;
		inline static constexpr auto VTABLE = VTABLE_TESActionData;

		virtual ~TESActionData() override = default;  // 00

		// override (ActionInput)
		ActorState*            GetSourceActorState() const override;    // 01
		void                   Unk_02(void) override;                   // 02 - { return 0; }
		BGSAnimationSequencer* GetAnimationSequencer() const override;  // 03

		// override (BGSActionData)
		BGSActionData* Clone() const override;  // 04
		bool           Process() override;      // 05

		static TESActionData* Create()
		{
			auto tesActionData = malloc<TESActionData>();
			if (tesActionData) {
				std::memset(tesActionData, 0, sizeof(TESActionData));
				tesActionData->Ctor();
				REX::EMPLACE_VTABLE(tesActionData);
			}
			return tesActionData;
		}

	private:
		TESActionData* Ctor()
		{
			using func_t = decltype(&TESActionData::Ctor);
			static REL::Relocation<func_t> func{ RELOCATION_ID(15916, 41558) };
			return func(this);
		}
	};
	static_assert(sizeof(TESActionData) == 0x60);
}
