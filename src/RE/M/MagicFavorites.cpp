#include "RE/M/MagicFavorites.h"

namespace RE
{
	MagicFavorites* MagicFavorites::GetSingleton()
	{
		REL::Relocation<MagicFavorites**> singleton{ Offset::MagicFavorites::Singleton };
		return *singleton;
	}

	void MagicFavorites::RemoveFavorite(TESForm* a_form)
	{
		using func_t = decltype(&MagicFavorites::RemoveFavorite);
		REL::Relocation<func_t> func{ RELOCATION_ID(51122, 52005) };
		return func(this, a_form);
	}

	void MagicFavorites::SetFavorite(TESForm* a_form)
	{
		using func_t = decltype(&MagicFavorites::SetFavorite);
		REL::Relocation<func_t> func{ RELOCATION_ID(51121, 52004) };
		return func(this, a_form);
	}
}
