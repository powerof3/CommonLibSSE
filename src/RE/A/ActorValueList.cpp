#include "RE/A/ActorValueList.h"

#include "RE/A/ActorValueInfo.h"

namespace RE
{
	ActorValueInfo* ActorValueList::GetActorValueInfo(ActorValue a_actorValue) const
	{
		using func_t = decltype(&ActorValueList::GetActorValueInfo);
		static REL::Relocation<func_t> func{ RELOCATION_ID(26569, 27202) };
		return func(this, a_actorValue);
	}

	ActorValue ActorValueList::LookupActorValueByName(const char* a_enumName) const
	{
		using func_t = decltype(&ActorValueList::LookupActorValueByName);
		static REL::Relocation<func_t> func{ RELOCATION_ID(26570, 27203) };
		return func(this, a_enumName);
	}

	std::string_view ActorValueToString(ActorValue a_actorValue) noexcept
	{
		auto info = RE::ActorValueList::GetSingleton()->GetActorValueInfo(a_actorValue);
		return info ? info->enumName : "None"sv;
	}
}
