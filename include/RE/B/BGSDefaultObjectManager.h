#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct DEFAULT_OBJECTS
	{
		enum DEFAULT_OBJECT
		{
			kWerewolfSpell = 0,
			kSittingAngleLimit = 1,
			kAllowPlayerShout = 2,
			kGold = 3,
			kLockpick = 4,
			kSkeletonKey = 5,
			kPlayerFaction = 6,
			kGuardFaction = 7,
			kDefaultMusic = 8,
			kBattleMusic = 9,
			kDeathMusic = 10,
			kSuccessMusic = 11,
			kLevelUpMusic = 12,
			kDungeonClearedMusic = 13,
			kPlayerVoiceMale = 14,
			kPlayerVoiceMaleChild = 15,
			kPlayerVoiceFemale = 16,
			kPlayerVoiceFemaleChild = 17,
			kEatPackageDefaultFood = 18,
			kLeftHandEquip = 19,
			kRightHandEquip = 20,
			kEitherHandEquip = 21,
			kVoiceEquip = 22,
			kPotionEquip = 23,
			kEveryActorAbility = 24,
			kCommandedActorAbility = 25,
			kDrugWearsOffImageSpace = 26,
			kFootstepSet = 27,
			kLandscapeMaterial = 28,
			kDragonLandZoneMarker = 29,
			kDragonCrashZoneMarker = 30,
			kCombatStyle = 31,
			kDefaultPackList = 32,
			kWaitForDialoguePackage = 33,
			kLocRefTypeBoss = 34,
			kVirtualLocation = 35,
			kPersistAllLocation = 36,
			kInventoryPlayer = 37,
			kPathingTestNPC = 38,
			kFavorCostSmall = 39,
			kFavorCostMedium = 40,
			kFavorCostLarge = 41,
			kFavorGiftsPerDay = 42,
			kActionSwimStateChange = 43,
			kActionLook = 44,
			kActionLeftAttack = 45,
			kActionLeftReady = 46,
			kActionLeftRelease = 47,
			kActionLeftInterrupt = 48,
			kActionRightAttack = 49,
			kActionRightReady = 50,
			kActionRightRelease = 51,
			kActionRightInterrupt = 52,
			kActionDualAttack = 53,
			kActionDualRelease = 54,
			kActionActivate = 55,
			kActionJump = 56,
			kActionFall = 57,
			kActionLand = 58,
			kActionSneak = 59,
			kActionVoice = 60,
			kActionVoiceReady = 61,
			kActionVoiceRelease = 62,
			kActionVoiceInterrupt = 63,
			kActionIdle = 64,
			kActionSprintStart = 65,
			kActionSprintStop = 66,
			kActionDraw = 67,
			kActionSheath = 68,
			kActionLeftPowerAttack = 69,
			kActionRightPowerAttack = 70,
			kActionDualPowerAttack = 71,
			kActionStaggerStart = 72,
			kActionBlockHit = 73,
			kActionBlockAnticipate = 74,
			kActionRecoil = 75,
			kActionLargeRecoil = 76,
			kActionBleedoutStart = 77,
			kActionBleedoutStop = 78,
			kActionIdleStop = 79,
			kActionWardHit = 80,
			kActionForceEquip = 81,
			kActionShieldChange = 82,
			kActionPathStart = 83,
			kActionPathEnd = 84,
			kActionLargeMovementDelta = 85,
			kActionFlyStart = 86,
			kActionFlyStop = 87,
			kActionHoverStart = 88,
			kActionHoverStop = 89,
			kActionBumpedInto = 90,
			kActionSummonedStart = 91,
			kActionTalkingIdle = 92,
			kActionListenIdle = 93,
			kActionDeath = 94,
			kActionDeathWait = 95,
			kActionIdleWarn = 96,
			kActionMoveStart = 97,
			kActionMoveStop = 98,
			kActionTurnRight = 99,
			kActionTurnLeft = 100,
			kActionTurnStop = 101,
			kActionMoveForward = 102,
			kActionMoveBackward = 103,
			kActionMoveLeft = 104,
			kActionMoveRight = 105,
			kActionResetAnimationGraph = 106,
			kActionKnockdown = 107,
			kActionGetUp = 108,
			kActionIdleStopInstant = 109,
			kActionRagdollInstant = 110,
			kActionWaterwalkStart = 111,
			kActionReload = 112,
			kPickupSoundGeneric = 113,
			kPutdownSoundGeneric = 114,
			kPickupSoundWeapon = 115,
			kPutdownSoundWeapon = 116,
			kPickupSoundArmor = 117,
			kPutdownSoundArmor = 118,
			kPickupSoundBook = 119,
			kPutdownSoundBook = 120,
			kPickupSoundIngredient = 121,
			kPutdownSoundIngredient = 122,
			kHarvestSound = 123,
			kHarvestFailedSound = 124,
			kWardBreakSound = 125,
			kWardAbsorbSound = 126,
			kWardDeflectSound = 127,
			kMagicFailSound = 128,
			kShoutFailSound = 129,
			kHeartbeatSoundFast = 130,
			kHeartbeatSoundSlow = 131,
			kImagespaceLowHealth = 132,
			kSoulCapturedSound = 133,
			kNoActivationSound = 134,
			kMapMenuLoopingSound = 135,
			kDialogueVoiceCategory = 136,
			kNonDialogueVoiceCategory = 137,
			kSFXToFadeInDialogueCategory = 138,
			kPauseDuringMenuCategoryFade = 139,
			kPauseDuringMenuCategoryImmediate = 140,
			kPauseDuringLoadingMenuCategory = 141,
			kMusicSoundCategory = 142,
			kStatsMuteCategory = 143,
			kStatsMusic = 144,
			kMasterSoundCategory = 145,
			kTimeSensitiveSoundCategory = 146,
			kDialogueOutputModel3D = 147,
			kDialogueOutputModel2D = 148,
			kPlayersOutputModel1stPerson = 149,
			kPlayersOutputModel3rdPerson = 150,
			kInterfaceOutputModel = 151,
			kReverbType = 152,
			kUnderwaterLoopSound = 153,
			kUnderwaterReverbType = 154,
			kKeywordHorse = 155,
			kKeywordUndead = 156,
			kKeywordNPC = 157,
			kKeywordBeastRace = 158,
			kKeywordDummyObject = 159,
			kKeywordUseGeometryEmitter = 160,
			kKeywordMustStop = 161,
			kKeywordUpdateDuringArchery = 162,
			kKeywordSkipOutfitItems = 163,
			kMaleFaceTextureSetHead = 164,
			kMaleFaceTextureSetMouth = 165,
			kMaleFaceTextureSetEyes = 166,
			kFemaleFaceTextureSetHead = 167,
			kFemaleFaceTextureSetMouth = 168,
			kFemaleFaceTextureSetEyes = 169,
			kImageSpaceModifierforinventorymenu = 170,
			kPackagetemplate = 171,
			kMainMenuCell = 172,
			kDefaultMovementTypeWalk = 173,
			kDefaultMovementTypeRun = 174,
			kDefaultMovementTypeSwim = 175,
			kDefaultMovementTypeFly = 176,
			kDefaultMovementTypeSneak = 177,
			kDefaultMovementTypeSprint = 178,
			kKeywordSpecialFurniture = 179,
			kKeywordFurnitureForces1stPerson = 180,
			kKeywordFurnitureForces3rdPerson = 181,
			kKeywordActivatorFurnitureNoPlayer = 182,
			kTelekinesisGrabSound = 183,
			kTelekinesisThrowSound = 184,
			kWorldMapWeather = 185,
			kHelpManualPC = 186,
			kHelpManualXBox = 187,
#ifdef SKYRIM_SUPPORT_AE
			kHelpManualNX,
#endif
			kKeywordTypeAmmo,
			kKeywordTypeArmor,
			kKeywordTypeBook,
			kKeywordTypeIngredient,
			kKeywordTypeKey,
			kKeywordTypeMisc,
			kKeywordTypeSoulGem,
			kKeywordTypeWeapon,
			kKeywordTypePotion,
			kBaseWeaponEnchantment,
			kBaseArmorEnchantment,
			kBasePotion,
			kBasePoison,
			kKeywordDragon,
			kKeywordMovable,
			kArtObjectAbsorbEffect,
			kWeaponMaterialList,
			kArmorMaterialList,
			kKeywordDisallowEnchanting,
			kFavortravelmarkerlocation,
			kKeywordHoldLocation,
			kKeywordCivilWarOwner,
			kKeywordCivilWarNeutral,
			kLocRefTypeCivilWarSoldier,
			kKeywordClearableLocation,
			kLocRefTypeResourceDestructible,
			kFormListHairColorList,
			kComplexSceneObject,
			kKeywordReusableSoulGem,
			kKeywordAnimal,
			kKeywordDaedra,
			kKeywordRobot,
			kKeywordNirnroot,
			kFightersGuildFaction,
			kMagesGuildFaction,
			kThievesGuildFaction,
			kDarkBrotherhoodFaction,
			kJarlFaction,
			kBunnyFaction,
			kPlayerIsVampireVariable,
			kPlayerIsWerewolfVariable,
			kRoadMarker,
			kKeywordScaleActorTo10,
			kKeywordVampire,
			kKeywordForge,
			kKeywordCookingPot,
			kKeywordSmelter,
			kKeywordTanningRack,
			kHelpBasicLockpickingPC,
			kHelpBasicLockpickingConsole,
			kHelpBasicForging,
			kHelpBasicCooking,
			kHelpBasicSmelting,
			kHelpBasicTanning,
			kHelpBasicObjectCreation,
			kHelpBasicEnchanting,
			kHelpBasicSmithingWeapon,
			kHelpBasicSmithingArmor,
			kHelpBasicAlchemy,
			kHelpBarter,
			kHelpLevelingup,
			kHelpSkillsMenu,
			kHelpMapMenu,
			kHelpJournal,
			kHelpLowHealth,
			kHelpLowMagicka,
			kHelpLowStamina,
			kHelpJail,
			kHelpTeamateFavor,
			kHelpWeaponCharge,
			kHelpFavorites,
			kKinectHelpFormList,
			kHelpFlyingMount,
			kHelpTargetLock,
			kHelpAttackTarget,
#ifdef SKYRIM_SUPPORT_AE
			kHelpMotionAttackBlock,
			kHelpMotionBowAiming,
			kHelpMotionMagicAiming,
			kHelpMotionLockpicking,
			kHelpAmiibo,
#endif
			kImagespaceLoadscreen,
			kKeywordWeaponMaterialDaedric,
			kKeywordWeaponMaterialDraugr,
			kKeywordWeaponMaterialDraugrHoned,
			kKeywordWeaponMaterialDwarven,
			kKeywordWeaponMaterialEbony,
			kKeywordWeaponMaterialElven,
			kKeywordWeaponMaterialFalmer,
			kKeywordWeaponMaterialFalmerHoned,
			kKeywordWeaponMaterialGlass,
			kKeywordWeaponMaterialImperial,
			kKeywordWeaponMaterialIron,
			kKeywordWeaponMaterialOrcish,
			kKeywordWeaponMaterialSteel,
			kKeywordWeaponMaterialWood,
			kKeywordWeaponTypeBoundArrow,
			kKeywordArmorMaterialDaedric,
			kKeywordArmorMaterialDragonplate,
			kKeywordArmorMaterialDragonscale,
			kKeywordArmorMaterialDragonbone,
			kKeywordArmorMaterialDwarven,
			kKeywordArmorMaterialEbony,
			kKeywordArmorMaterialElven,
			kKeywordArmorMaterialElvenSplinted,
			kKeywordArmorMaterialFullLeather,
			kKeywordArmorMaterialGlass,
			kKeywordArmorMaterialHide,
			kKeywordArmorMaterialImperial,
			kKeywordArmorMaterialImperialHeavy,
			kKeywordArmorMaterialImperialReinforced,
			kKeywordArmorMaterialIron,
			kKeywordArmorMaterialIronBanded,
			kKeywordArmorMaterialOrcish,
			kKeywordArmorMaterialScaled,
			kKeywordArmorMaterialSteel,
			kKeywordArmorMaterialSteelPlate,
			kKeywordArmorMaterialStormcloak,
			kKeywordArmorMaterialStudded,
			kKeywordGenericCraftableKeyword01,
			kKeywordGenericCraftableKeyword02,
			kKeywordGenericCraftableKeyword03,
			kKeywordGenericCraftableKeyword04,
			kKeywordGenericCraftableKeyword05,
			kKeywordGenericCraftableKeyword06,
			kKeywordGenericCraftableKeyword07,
			kKeywordGenericCraftableKeyword08,
			kKeywordGenericCraftableKeyword09,
			kKeywordGenericCraftableKeyword10,
			kKeywordJewelry,
			kKeywordCuirass,
			kLocalMapHidePlane,
			kSnowLODMaterial,
			kSnowLODMaterialHD,
			kAshLODMaterial,
			kAshLODMaterialHD,
			kDialogueFollowerQuest,
			kPotentialFollowerFaction,
			kWerewolfAvailablePerks,
			kVampireAvailablePerks,
			kSurvivalModeToggle,
			kSurvivalModeEnabled,
			kSurvivalModeShowOption,
			kSurvivalTemperature,
			kSurvivalColdPenalty,
			kSurvivalHungerPenalty,
			kSurvivalSleepPenalty,
			kSurvivalKeywordCold,
			kSurvivalKeywordWarm,
			kSurvivalKeywordArmorHands,
			kSurvivalKeywordClothingHands,
			kSurvivalKeywordArmorFeet,
			kSurvivalKeywordClothingFeet,
			kSurvivalKeywordArmorBody,
			kSurvivalKeywordClothingBody,
			kSurvivalKeywordArmorHead,
			kSurvivalKeywordClothingHead,
			kWerewolfRace,
			kVampireRace,
			kVampireSpells,
			kDragonMountNoLandList,
			kPlayerCanMountDragonHereList,
			kFlyingMountAllowedSpells,
			kFlyingMountDisallowedSpells,
			kKeywordMount,
			kVerletCape,
			kFurnitureTestNPC,
			kKeywordConditionalExplosion,
			kVampireFeedNoCrimeFaction,
			kSkyrimWorldspace,
			kKeywordArmorMaterialLightBonemold,
			kKeywordArmorMaterialLightChitin,
			kKeywordArmorMaterialLightNordic,
			kKeywordArmorMaterialLightStalhrim,
			kFlyingMountFlyFastWorldspaces,
			kKeywordArmorMaterialHeavyBonemold,
			kKeywordArmorMaterialHeavyChitin,
			kKeywordArmorMaterialHeavyNordic,
			kKeywordArmorMaterialHeavyStalhrim,
			kKeywordWeaponMaterialNordic,
			kKeywordWeaponMaterialStalhrim,
#ifndef SKYRIM_SUPPORT_AE
			kModsHelpFormList,
			kTotal
#else
			kHelpManualInstalledContent,
			kHelpManualInstalledContentAE,
			kModsHelpFormList,
			kTotal
#endif
		};
	};
	using DEFAULT_OBJECT = DEFAULT_OBJECTS::DEFAULT_OBJECT;
#ifndef SKYRIM_SUPPORT_AE
	static_assert(DEFAULT_OBJECTS::kKeywordTypeAmmo == 188);
	static_assert(DEFAULT_OBJECTS::kImagespaceLoadscreen == 263);
	static_assert(DEFAULT_OBJECTS::kModsHelpFormList == 363);
#else
	static_assert(DEFAULT_OBJECTS::kHelpManualNX == 188);
	static_assert(DEFAULT_OBJECTS::kKeywordTypeAmmo == 189);
	static_assert(DEFAULT_OBJECTS::kHelpMotionAttackBlock == 264);
	static_assert(DEFAULT_OBJECTS::kHelpAmiibo == 268);
	static_assert(DEFAULT_OBJECTS::kImagespaceLoadscreen == 269);
	static_assert(DEFAULT_OBJECTS::kModsHelpFormList == 371);
#endif

	enum class DEFAULT_OBJECT_TYPE
	{
		kMisc = 0,
		kFaceGen = 1,
		kMovement = 2,
		kActions = 3,
		kItems = 4,
		kSounds = 5,
		kKeywords = 6
	};

	struct DEFAULT_OBJECT_DATA
	{
	public:
		// members
		const char*                                       name;         // 00
		REX::TEnumSet<FormType, std::uint8_t>             type;         // 08
		std::uint8_t                                      pad09;        // 09
		std::uint16_t                                     pad0A;        // 0A
		char                                              uniqueID[4];  // 0C
		REX::TEnumSet<DEFAULT_OBJECT_TYPE, std::uint32_t> doType;       // 10
		std::uint32_t                                     pad14;        // 14
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x18);

	class BGSDefaultObjectManager :
		public TESForm,                                       // 000
		public BSTSingletonImplicit<BGSDefaultObjectManager>  // 020
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSDefaultObjectManager;
		inline static constexpr auto VTABLE = VTABLE_BGSDefaultObjectManager;

		using DefaultObject = DEFAULT_OBJECT;
		inline static constexpr auto FORMTYPE = FormType::DefaultObject;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BGSDefaultObjectManager() override;  // 00

		// override (TESForm)
		bool Load(TESFile* a_mod) override;  // 06
		void InitItemImpl() override;        // 13

		[[nodiscard]] static BGSDefaultObjectManager* GetSingleton()
		{
			using func_t = decltype(&BGSDefaultObjectManager::GetSingleton);
			static REL::Relocation<func_t> func{ RELOCATION_ID(10878, 13894) };
			return func();
		}

		[[nodiscard]] TESForm* GetObject(DefaultObject a_object) const noexcept { return GetObject(std::to_underlying(a_object)); }

		template <class T>
		[[nodiscard]] T* GetObject(DefaultObject a_object) const noexcept
		{
			return GetObject<T>(std::to_underlying(a_object));
		}

		[[nodiscard]] TESForm* GetObject(std::size_t a_idx) const noexcept
		{
			assert(a_idx < std::to_underlying(DefaultObject::kTotal));
			return objectInit[a_idx] ? objects[a_idx] : nullptr;
		}

		template <class T>
		[[nodiscard]] T* GetObject(std::size_t a_idx) const noexcept
		{
			const auto obj = GetObject(a_idx);
			return obj ? obj->As<T>() : nullptr;
		}

		// members
#ifndef SKYRIM_SUPPORT_AE
		TESForm*      objects[DEFAULT_OBJECTS::kTotal];     // 020 - DNAM
		bool          objectInit[DEFAULT_OBJECTS::kTotal];  // B80
		std::uint32_t padCEC;                               // CEC
#else
		TESForm*      objects[DEFAULT_OBJECTS::kTotal];     // 020 - DNAM
		bool          objectInit[DEFAULT_OBJECTS::kTotal];  // BC0
		std::uint32_t padD34;                               // D34
#endif
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(DEFAULT_OBJECTS::kTotal == 364);
	static_assert(sizeof(BGSDefaultObjectManager) == 0xCF0);
#else
	static_assert(DEFAULT_OBJECTS::kTotal == 372);
	static_assert(sizeof(BGSDefaultObjectManager) == 0xD38);
#endif
}
