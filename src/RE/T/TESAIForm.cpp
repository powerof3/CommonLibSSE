#include "RE/T/TESAIForm.h"

namespace RE
{
	bool TESAIForm::AggroRadiusBehaviourIsEnabled() const
	{
		return aiData.aggroRadiusBehaviour;
	}

	ACTOR_AGGRESSION TESAIForm::GetAggressionLevel() const
	{
		return REX::BITS_TO_VALUE<ACTOR_AGGRESSION>(aiData.aggression1, aiData.aggression2);
	}

	ACTOR_ASSISTANCE TESAIForm::GetAssistanceLevel() const
	{
		return REX::BITS_TO_VALUE<ACTOR_ASSISTANCE>(aiData.assistance1, aiData.assistance2);
	}

	ACTOR_CONFIDENCE TESAIForm::GetConfidenceLevel() const
	{
		return REX::BITS_TO_VALUE<ACTOR_CONFIDENCE>(aiData.confidence1, aiData.confidence2, aiData.confidence3);
	}

	std::uint8_t TESAIForm::GetEnergyLevel() const
	{
		return REX::BITS_TO_VALUE<std::uint8_t>(aiData.energyLevel1, aiData.energyLevel2, aiData.energyLevel3, aiData.energyLevel4, aiData.energyLevel5, aiData.energyLevel6, aiData.energyLevel7, aiData.energyLevel8);
	}

	ACTOR_MOOD TESAIForm::GetMoodLevel() const
	{
		return REX::BITS_TO_VALUE<ACTOR_MOOD>(aiData.mood1, aiData.mood2, aiData.mood3);
	}

	ACTOR_MORALITY TESAIForm::GetMoralityLevel() const
	{
		return REX::BITS_TO_VALUE<ACTOR_MORALITY>(aiData.morality1, aiData.morality1);
	}

	bool TESAIForm::NoSlowApproach() const
	{
		return aiData.noSlowApproach;
	}

	void TESAIForm::SetAggressionLevel(ACTOR_AGGRESSION a_level)
	{
		const auto level = std::to_underlying(a_level);
		aiData.aggression1 = (level & 1) != 0;
		aiData.aggression2 = (level & 2) != 0;
	}

	void TESAIForm::SetAssistanceLevel(ACTOR_ASSISTANCE a_level)
	{
		const auto level = std::to_underlying(a_level);
		aiData.assistance1 = (level & 1) != 0;
		aiData.assistance2 = (level & 2) != 0;
	}

	void TESAIForm::SetConfidenceLevel(ACTOR_CONFIDENCE a_level)
	{
		const auto level = std::to_underlying(a_level);
		aiData.confidence1 = (level & 1) != 0;
		aiData.confidence2 = (level & 2) != 0;
		aiData.confidence3 = (level & 4) != 0;
	}
}
