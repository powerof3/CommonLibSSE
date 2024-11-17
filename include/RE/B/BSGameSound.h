#pragma once

#include "RE/B/BSAudioMonitor.h"
#include "RE/B/BSTArray.h"
#include "RE/I/ID.h"
#include "RE/M/MemoryManager.h"
#include "RE/N/NiPoint3.h"
#include "RE/S/SoundMessageList.h"

namespace RE
{
	class BSGameSound
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSGameSound;
		inline static constexpr auto VTABLE = VTABLE_BSGameSound;

		// add
		virtual void Unk_00(void);  // 00 - { return; }

		virtual ~BSGameSound();  // 01

		virtual void          Unk_02(void);                                   // 02 - { return (unk5C >> 4) & 1; }
		virtual void          Unk_03(bool a_arg1);                            // 03
		virtual std::uint32_t GetCurrentPlaybackPosition() const = 0;         // 04
		virtual void          Unk_05(void);                                   // 05
		virtual void          Unk_06(void) = 0;                               // 06
		virtual void          Unk_07(void) = 0;                               // 07
		virtual void          Unk_08(void) = 0;                               // 08
		virtual void          Unk_09(void) = 0;                               // 09
		virtual void          Unk_0A(void) = 0;                               // 0A
		virtual bool          Prepare();                                      // 0B - { unk5C |= 0x800; }
		virtual void          Unk_0C(void);                                   // 0C
		virtual void          Unk_0D(void) = 0;                               // 0D
		virtual void          Unk_0E(void);                                   // 0E
		virtual void          Unk_0F(void) = 0;                               // 0F
		virtual void          Unk_10(void) = 0;                               // 10
		virtual void          Unk_11(void) = 0;                               // 11
		virtual void          Copy(BSGameSound* a_other, bool a_update) = 0;  // 12
		virtual void          DoApplyFrequency();                             // 13 - { return; }
		virtual void          Unk_14(void) = 0;                               // 14
		virtual void          Unk_15(void) = 0;                               // 15
		virtual void          Unk_16(void) = 0;                               // 16
		virtual void          Unk_17() = 0;                                   // 17
		virtual void          SetVolumeImpl() = 0;                            // 18

		TES_HEAP_REDEFINE_NEW();

		[[nodiscard]] constexpr float GetFrequency() const noexcept { return frequency * 0.01f; }

		// members
		BSTSmallArray<BSAudioMonitor::Request, 2> requests;              // 08
		NiPoint3                                  beamEnd;               // 20
		std::byte                                 pad2C[4];              // 2C
		SoundMessageList                          soundMessageList;      // 30
		BSResource::ID                            resourceID;            // 40
		std::uint32_t                             unk4C;                 // 4C
		std::uint64_t                             unk50;                 // 50
		std::uint32_t                             unk58;                 // 58
		std::uint32_t                             flags;                 // 5C
		std::uint32_t                             durationMilliseconds;  // 60
		std::uint16_t                             staticAttenuation;     // 64
		std::uint16_t                             unk66;                 // 66
		std::uint16_t                             systemAttenuation;     // 68
		std::uint16_t                             unk6A;                 // 6A
		std::uint16_t                             unk6C;                 // 6C
		std::byte                                 pad6E[2];              // 6E
		float                                     volume;                // 70
		std::uint32_t                             unk74;                 // 74
		std::uint64_t                             unk78;                 // 78
		std::uint64_t                             unk80;                 // 80
		std::uint64_t                             unk88;                 // 88
		std::uint64_t                             unk90;                 // 90
		std::uint64_t                             unk98;                 // 98
		std::uint64_t                             unkA0;                 // A0
		std::uint64_t                             unkA8;                 // A8
		std::uint64_t                             unkB0;                 // B0
		std::uint64_t                             unkB8;                 // B8
		std::int8_t                               frequency;             // C0
		std::uint8_t                              unkC1;                 // C1
		std::uint16_t                             unkC2;                 // C2
		std::uint32_t                             unkC4;                 // C4
	};
	static_assert(sizeof(BSGameSound) == 0xC8);
}
