#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/C/CombatObject.h"

namespace RE
{
	class CombatPath : public CombatObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_CombatPath;
		inline static constexpr auto VTABLE = VTABLE_CombatPath;

		enum class SPEED : std::uint32_t
		{
			kUnk00,
			kUnk01,
			kUnk02,
			kUnk03,
			kUnk04
		};

		enum class STATE : std::uint32_t
		{
			kNone,
			kBuilding,
			kFollowing,
			kRetrying,
			kComplete,
			kFailed,
			kUnk06
		};

		~CombatPath() override;  // 00

		// override (CombatObject)
		void SaveGame(BGSSaveGameBuffer* a_buf) override;  // 03
		void LoadGame(BGSLoadGameBuffer* a_buf) override;  // 04

		// add
		virtual void Unk_05(void) = 0;  // 05
		virtual void Unk_06(void) = 0;  // 06
		virtual void Unk_07(void) = 0;  // 07
		virtual void Unk_08(void) = 0;  // 08
		virtual void Unk_09(void) = 0;  // 09
		virtual void Unk_0A(void) = 0;  // 0A
		virtual void Unk_0B(void) = 0;  // 0B
		virtual void Unk_0C(void) = 0;  // 0C

		void SetAccelerationDecelerationMult(float a_accelerationMult, float a_decelerationMult)
		{
			using func_t = decltype(&CombatPath::SetAccelerationDecelerationMult);
			static REL::Relocation<func_t> func{ RELOCATION_ID(49022, 49953) };
			func(this, a_accelerationMult, a_decelerationMult);
		}

		void Start()
		{
			using func_t = decltype(&CombatPath::Start);
			static REL::Relocation<func_t> func{ RELOCATION_ID(49013, 49944) };
			func(this);
		}

		void Update()
		{
			using func_t = decltype(&CombatPath::Start);
			static REL::Relocation<func_t> func{ RELOCATION_ID(49011, 47899) };
			func(this);
		}

		// members
		ActorHandle actor;       // 10
		STATE       state;       // 14
		STATE       lastState;   // 18
		SPEED       speed;       // 1C
		AITimer     retryTimer;  // 20
		AITimer     waitTimer;   // 28
		void*       unk30;       // 30 - smart ptr
	};
	static_assert(sizeof(CombatPath) == 0x38);
}
