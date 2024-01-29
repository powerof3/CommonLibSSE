#pragma once

namespace RE
{
	struct EffectArchetypes
	{
		enum class ArchetypeID
		{
			kNone = static_cast<std::underlying_type_t<ArchetypeID>>(-1),
			kValueModifier = 0,
			kScript = 1,
			kDispel = 2,
			kCureDisease = 3,
			kAbsorb = 4,
			kDualValueModifier = 5,
			kCalm = 6,
			kDemoralize = 7,
			kFrenzy = 8,
			kDisarm = 9,
			kCommandSummoned = 10,
			kInvisibility = 11,
			kLight = 12,
			kDarkness = 13,
			kNightEye = 14,
			kLock = 15,
			kOpen = 16,
			kBoundWeapon = 17,
			kSummonCreature = 18,
			kDetectLife = 19,
			kTelekinesis = 20,
			kParalysis = 21,
			kReanimate = 22,
			kSoulTrap = 23,
			kTurnUndead = 24,
			kGuide = 25,
			kWerewolfFeed = 26,
			kCureParalysis = 27,
			kCureAddiction = 28,
			kCurePoison = 29,
			kConcussion = 30,
			kValueAndParts = 31,
			kAccumulateMagnitude = 32,
			kStagger = 33,
			kPeakValueModifier = 34,
			kCloak = 35,
			kWerewolf = 36,
			kSlowTime = 37,
			kRally = 38,
			kEnhanceWeapon = 39,
			kSpawnHazard = 40,
			kEtherealize = 41,
			kBanish = 42,
			kSpawnScriptedRef = 43,
			kDisguise = 44,
			kGrabActor = 45,
			kVampireLord = 46
		};
	};
	using EffectArchetype = EffectArchetypes::ArchetypeID;

	[[nodiscard]] std::string_view EffectArchetypeToString(EffectArchetype a_archetype) noexcept;
}

namespace std
{
	[[nodiscard]] inline std::string to_string(RE::EffectArchetype a_archetype)
	{
		return RE::EffectArchetypeToString(a_archetype).data();
	}
}

#ifdef FMT_VERSION
namespace fmt
{
	template <>
	struct formatter<RE::EffectArchetype>
	{
		template <class ParseContext>
		constexpr auto parse(ParseContext& a_ctx)
		{
			return a_ctx.begin();
		}

		template <class FormatContext>
		auto format(const RE::EffectArchetype& a_archetype, FormatContext& a_ctx)
		{
			return fmt::format_to(a_ctx.out(), "{}", RE::EffectArchetypeToString(a_archetype));
		}
	};
}
#endif

#ifdef __cpp_lib_format
namespace std
{
	template <class CharT>
	struct formatter<RE::EffectArchetype, CharT> : std::formatter<std::string_view, CharT>
	{
		template <class FormatContext>
		auto format(RE::EffectArchetype a_archetype, FormatContext& a_ctx)
		{
			return formatter<std::string_view, CharT>::format(RE::EffectArchetypeToString(a_archetype), a_ctx);
		}
	};
}
#endif
