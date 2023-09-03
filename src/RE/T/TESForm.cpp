#include "RE/T/TESForm.h"

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/F/FormTraits.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/I/InventoryEntryData.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/V/VirtualMachine.h"

namespace RE
{
	std::int32_t TESForm::GetGoldValue() const
	{
		const auto obj = As<TESBoundObject>();
		if (obj) {
			const InventoryEntryData entry{ const_cast<TESBoundObject*>(obj), 1 };
			return entry.GetValue();
		} else {
			return -1;
		}
	}

	const char* TESForm::GetName() const
	{
		const auto fullName = As<TESFullName>();
		if (fullName) {
			const auto str = fullName->GetFullName();
			return str ? str : "";
		} else {
			return "";
		}
	}

	float TESForm::GetWeight() const
	{
		const auto survival = []() {
			const auto dobj = BGSDefaultObjectManager::GetSingleton();
			const auto survival = dobj ? dobj->GetObject<TESGlobal>(DEFAULT_OBJECT::kSurvivalModeEnabled) : nullptr;
			return survival ? survival->value == 1.0F : false;
		};

		const auto ref = As<TESObjectREFR>();
		const auto baseObj = ref ? ref->GetBaseObject() : nullptr;
		const auto form = baseObj ? baseObj : this;
		if (!survival() && (form->IsAmmo() || form->IsLockpick())) {
			return 0.0F;
		} else if (const auto weightForm = form->As<TESWeightForm>(); weightForm) {
			return weightForm->weight;
		} else if (form->Is(FormType::NPC)) {
			const auto npc = static_cast<const TESNPC*>(form);
			return npc->weight;
		} else {
			return -1.0F;
		}
	}

	bool TESForm::HasAnyKeywordByEditorID(const std::vector<std::string>& editorIDs) const
	{
		// Try to cast to a keyword form interface
		const auto keywordForm = As<BGSKeywordForm>();
		if (!keywordForm) {
			return false;
		}

		// Iterate through the keywords
		for (std::uint32_t i = 0; i < keywordForm->GetNumKeywords(); ++i) {
			auto keywordOpt = keywordForm->GetKeywordAt(i);
			if (keywordOpt) {
				auto keyword = *keywordOpt;
				if (keyword) {
					const char* keywordEditorID = keyword->GetFormEditorID();
					if (keywordEditorID) {
						// Check if the keywordEditorID is in the given editorIDs vector
						if (std::find(editorIDs.begin(), editorIDs.end(), keywordEditorID) != editorIDs.end()) {
							return true;
						}
					}
				}
			}
		}

		return false;
	}

	bool TESForm::HasKeywordInArray(const std::vector<BGSKeyword*>& a_keywords, bool a_matchAll) const
	{
		const auto keywordForm = As<BGSKeywordForm>();
		if (!keywordForm) {
			return false;
		}

		bool hasKeyword = false;

		for (const auto& keyword : a_keywords) {
			hasKeyword = keyword && keywordForm->HasKeyword(keyword);
			if (a_matchAll && !hasKeyword || hasKeyword) {
				break;
			}
		}

		return hasKeyword;
	}

	bool TESForm::HasKeywordInList(BGSListForm* a_keywordList, bool a_matchAll) const
	{
		if (!a_keywordList) {
			return false;
		}

		const auto keywordForm = As<BGSKeywordForm>();
		if (!keywordForm) {
			return false;
		}

		bool hasKeyword = false;

		a_keywordList->ForEachForm([&](const TESForm& a_form) {
			const auto keyword = a_form.As<BGSKeyword>();
			hasKeyword = keyword && keywordForm->HasKeyword(keyword);
			if (a_matchAll && !hasKeyword || hasKeyword) {
				return BSContainer::ForEachResult::kStop;
			}
			return BSContainer::ForEachResult::kContinue;
		});

		return hasKeyword;
	}

	bool TESForm::HasVMAD() const
	{
		const auto vm = RE::BSScript::Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return false;
		}

		const auto policy = vm->GetObjectHandlePolicy();
		if (!policy) {
			return false;
		}

		const auto handle = policy->GetHandleForObject(GetFormType(), this);
		return handle != policy->EmptyHandle();
	}

	bool TESForm::HasWorldModel() const noexcept
	{
		return As<TESModel>() != nullptr;
	}

	bool TESForm::IsInventoryObject() const
	{
		switch (GetFormType()) {
		case FormType::Scroll:
		case FormType::Armor:
		case FormType::Book:
		case FormType::Ingredient:
		case FormType::Light:
		case FormType::Misc:
		case FormType::Apparatus:
		case FormType::Weapon:
		case FormType::Ammo:
		case FormType::KeyMaster:
		case FormType::AlchemyItem:
		case FormType::Note:
		case FormType::ConstructibleObject:
		case FormType::SoulGem:
		case FormType::LeveledItem:
			return true;
		default:
			return false;
		}
	}
}
