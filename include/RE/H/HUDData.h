#pragma once

#include "RE/B/BSString.h"
#include "RE/H/HUDMessageTypes.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class TESQuest;
	class TESWordOfPower;

	class HUDData : public IUIMessageData
	{
	public:
		inline static constexpr auto RTTI = RTTI_HUDData;
		inline static constexpr auto VTABLE = VTABLE_HUDData;
		inline static constexpr std::string_view CLASS_NAME = "HUDData";

		enum class Type
		{
			kUnk0 = 0,
			kNotification = 1,
			kSetBlinking = 11,
			kSetFadeOut = 12,
			kSetPct = 13,
			kQuestStarted = 14,
			kQuestComplete = 15,
			kQuestFailed = 16,
			kSkillIncrease = 20,
			kWordOfPower1 = 21,
			kWordOfPower2 = 22,
			kSetMode = 23
		};

		enum class Discovery
		{
			kCity = 1,
			kTown = 2,
			kDungeon4 = 4,
			kDungeon7 = 7,
			kDungeon8 = 8,
			kDungeon12 = 12,
			kDungeon15 = 15
		};

		~HUDData() override;  // 00

		// members
		REX::EnumSet<HUD_MESSAGE_TYPE, std::uint32_t> type;          // 10
		std::uint32_t                                 pad14;         // 14
		BSString                                      text;          // 18
		ObjectRefHandle                               crosshairRef;  // 28
		std::uint32_t                                 pad2C;         // 2C
		TESQuest*                                     quest;         // 30
		TESWordOfPower*                               wordOfPower;   // 38
		bool                                          show;          // 40
		std::uint8_t                                  pad41;         // 41
		std::uint16_t                                 pad42;         // 42
		std::uint32_t                                 typeData;      // 44 - varies by type
	};
	static_assert(sizeof(HUDData) == 0x48);
}
