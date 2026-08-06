#pragma once

#include "RE/F/FormTypes.h"

namespace RE
{
	template <class T, FormType>
	class ConcreteFormFactory;

	enum class OBJECT_TYPE
	{
		kActivator = 0,
		kArmor = 1,
		kBook = 2,
		kContainer = 3,
		kDoor = 4,
		kIngredient = 5,
		kLight = 6,
		kMiscItem = 7,
		kStatic = 8,
		kGrass = 9,
		kTree = 10,
		kWeapon = 12,
		kActor = 13,
		kLeveledCharacter = 14,
		kSpell = 15,
		kEnchantment = 16,
		kPotion = 17,
		kLeveledItem = 18,
		kKey = 19,
		kAmmo = 20,
		kFlora = 21,
		kFurniture = 22,
		kSoundMarker = 23,
		kLandTexture = 24,
		kCombatStyle = 25,
		kLoadScreen = 26,
		kLeveledSpell = 27,
		kAnimObject = 28,
		kWaterType = 29,
		kIdleMarker = 30,
		kEffectShader = 31,
		kProjectile = 32,
		kTalkingActivator = 33,
		kExplosion = 34,
		kTextureSet = 35,
		kDebris = 36,
		kMenuIcon = 37,
		kFormList = 38,
		kPerk = 39,
		kBodyPartData = 40,
		kAddOnNode = 41,
		kMovableStatic = 42,
		kCameraShot = 43,
		kImpactData = 44,
		kImpactDataSet = 45,
		kQuest = 46,
		kPackage = 47,
		kVoiceType = 48,
		kClass = 49,
		kRace = 50,
		kEyes = 51,
		kHeadPart = 52,
		kFaction = 53,
		kNote = 54,
		kWeather = 55,
		kClimate = 56,
		kArmorAddon = 57,
		kGlobal = 58,
		kImagespace = 59,
		kImagespaceModifier = 60,
		kEncounterZone = 61,
		kMessage = 62,
		kConstructibleObject = 63,
		kAcousticSpace = 64,
		kRagdoll = 65,
		kScript = 66,
		kMagicEffect = 67,
		kMusicType = 68,
		kStaticCollection = 69,
		kKeyword = 70,
		kLocation = 71,
		kLocationRefType = 72,
		kFootstep = 73,
		kFootstepSet = 74,
		kMaterialType = 75,
		kActorAction = 76,
		kMusicTrack = 77,
		kWordofPower = 78,
		kShout = 79,
		kRelationship = 80,
		kEquipSlot = 81,
		kAssociationType = 82,
		kOutfit = 83,
		kArtObject = 84,
		kMaterialObject = 85,
		kLightingTemplate = 87,
		kShaderParticleGeometry = 88,
		kVisualEffect = 89,
		kApparatus = 90,
		kMovementType = 91,
		kHazard = 92,
		kSMEventNode = 93,
		kSoundDescriptor = 94,
		kDualCastData = 95,
		kSoundCategory = 96,
		kSoulGem = 97,
		kSoundOutputModel = 98,
		kCollisionLayer = 99,
		kScroll = 100,
		kColorForm = 101,
		kReverbParameters = 102,
		kLensFlare = 103,
		kVolumetricLighting = 105,
		kNone = 106
	};

	enum class OBJECT_CATEGORY_TYPE
	{
	};

	class IFormFactory
	{
	public:
		inline static constexpr auto RTTI = RTTI_IFormFactory;
		inline static constexpr auto VTABLE = VTABLE_IFormFactory;

		virtual ~IFormFactory();  // 00

	protected:
		// add
		virtual TESForm* CreateImpl() = 0;  // 01

	public:
		[[nodiscard]] virtual const char*          GetFormName() const = 0;    // 02
		[[nodiscard]] virtual FormType             GetFormType() const = 0;    // 03
		[[nodiscard]] virtual const char*          GetObjectName() const;      // 04 - { return 0; }
		[[nodiscard]] virtual OBJECT_TYPE          GetObjectType() const;      // 05 - { return 106; }
		[[nodiscard]] virtual OBJECT_CATEGORY_TYPE GetObjectCategory() const;  // 06 - { return 9; }

		static std::pair<IFormFactory**, bool> GetFormFactories();
		static IFormFactory*                   GetFormFactoryByType(FormType a_formType);

		template <class T>
		static ConcreteFormFactory<T, T::FORMTYPE>* GetConcreteFormFactoryByType();

		TESForm* Create();
		template <class T>
		static T* Create();
	};
	static_assert(sizeof(IFormFactory) == 0x8);
}
