#include "RE/S/Sky.h"

#include "RE/T/TESWeather.h"

namespace RE
{
	Sky* Sky::GetSingleton()
	{
		using func_t = decltype(&Sky::GetSingleton);
		REL::Relocation<func_t> func{ Offset::Sky::GetSingleton };
		return func();
	}

	bool Sky::IsRaining() const
	{
		return currentWeather && currentWeather->data.flags.any(TESWeather::WeatherDataFlag::kRainy) && (currentWeather->data.precipitationBeginFadeIn * (1.0f / 255)) < currentWeatherPct ||
		       lastWeather && lastWeather->data.flags.any(TESWeather::WeatherDataFlag::kRainy) && ((lastWeather->data.precipitationEndFadeOut * (1.0f / 255)) + 0.001f) > currentWeatherPct;
	}

	bool Sky::IsSnowing() const
	{
		return currentWeather && currentWeather->data.flags.any(TESWeather::WeatherDataFlag::kSnow) && (currentWeather->data.precipitationBeginFadeIn * (1.0f / 255)) < currentWeatherPct ||
		       lastWeather && lastWeather->data.flags.any(TESWeather::WeatherDataFlag::kSnow) && ((lastWeather->data.precipitationEndFadeOut * (1.0f / 255)) + 0.001f) > currentWeatherPct;
	}

	void Sky::SetWeather(TESWeather* apWeather, bool abOverride, bool abAccelerate)
	{
		using func_t = decltype(&Sky::SetWeather);
		REL::Relocation<func_t> func{ Offset::Sky::SetWeather };
		func(this, apWeather, abOverride, abAccelerate);
	}

	void Sky::ForceWeather(TESWeather* apWeather, bool abOverride)
	{
		using func_t = decltype(&Sky::ForceWeather);
		REL::Relocation<func_t> func{ Offset::Sky::ForceWeather };
		func(this, apWeather, abOverride);
	}

	void Sky::ResetWeather()
	{
		using func_t = decltype(&Sky::ResetWeather);
		REL::Relocation<func_t> func{ Offset::Sky::ResetWeather };
		func(this);
	}
}
