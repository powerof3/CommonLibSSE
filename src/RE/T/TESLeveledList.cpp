#include "RE/T/TESLeveledList.h"

#include "RE/F/FormTraits.h"

namespace RE
{
	void TESLeveledList::CalculateCurrentFormList(std::uint16_t a_level, std::int16_t a_count, BSScrapArray<CALCED_OBJECT>& a_calcedObjects, std::uint32_t a_arg5, bool a_usePlayerLevel)
	{
		using func_t = decltype(&TESLeveledList::CalculateCurrentFormList);
		static REL::Relocation<func_t> func{ RELOCATION_ID(14579, 14751) };
		return func(this, a_level, a_count, a_calcedObjects, a_arg5, a_usePlayerLevel);
	}

	std::vector<TESForm*> TESLeveledList::GetContainedForms() const
	{
		std::vector<TESForm*>      results;
		std::stack<const TESLeveledList*> queued;
		queued.push(this);
		do {
			std::vector<const TESLeveledList*> downstream{};
			auto iter = queued.top();
			downstream.push_back(iter);
			queued.pop();
			for (const auto& entry : iter->entries) {
				auto form = entry.form;
				if (form) {
					auto ll = form->As<TESLeveledList>();
					if (ll) {
						if (std::find(downstream.begin(), downstream.end(), ll) == downstream.end()) {
							queued.push(ll);
							downstream.push_back(ll);
						}
					} else {
						//We only care about contained forms and don't want to see multiples.
						if (std::find(results.begin(), results.end(), form) == results.end()) {
							results.push_back(form);
						}
					}
				}
			}
		} while (!queued.empty());
		return results;
	}
}
