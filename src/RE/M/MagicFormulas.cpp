#include "RE/M/MagicFormulas.h"

#include "RE/G/GameSettingCollection.h"

namespace RE
{
	namespace MagicFormulas
	{
		float CalcDualCastCost(float a_spellCost)
		{
			if (auto GameSettingCollection = GameSettingCollection::GetSingleton()) {
				auto fMagicDualCastingCostBase = GameSettingCollection->GetSetting("fMagicDualCastingCostBase");
				auto fMagicDualCastingCostMult = GameSettingCollection->GetSetting("fMagicDualCastingCostMult");
				if (fMagicDualCastingCostBase && fMagicDualCastingCostMult) {
					a_spellCost = fMagicDualCastingCostBase->GetFloat() + (fMagicDualCastingCostMult->GetFloat() * a_spellCost);
				}
			}

			return a_spellCost;
		}

		float GetWortcraftEffectStrength(float a_alchemySkill)
		{
			if (auto GameSettingCollection = GameSettingCollection::GetSingleton()) {
				auto fWortAlchMult = GameSettingCollection->GetSetting("fWortAlchMult");
				auto fWortStrMult = GameSettingCollection->GetSetting("fWortStrMult");
				if (fWortAlchMult && fWortStrMult) {
					a_alchemySkill = fWortStrMult->GetFloat() * (fWortAlchMult->GetFloat() * a_alchemySkill);
				}
			}

			return a_alchemySkill;
		}
	}
}
