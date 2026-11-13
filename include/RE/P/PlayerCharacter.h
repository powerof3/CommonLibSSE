#pragma once

#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/C/Character.h"
#include "RE/C/Crime.h"
#include "RE/F/FormTypes.h"
#include "RE/H/hkRefPtr.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTMap.h"
#include "RE/P/PositionPlayerEvent.h"
#include "RE/T/TESObjectWEAP.h"
#include "RE/T/TESQuest.h"

namespace RE
{
	enum class AQUIRE_TYPE;

	class Actor;
	class BGSInstancedQuestObjective;
	class BGSLocation;
	class bhkMouseSpringAction;
	class BipedAnim;
	class BSFadeNode;
	class BSLight;
	class CombatGroup;
	class ImageSpaceModifierInstanceDOF;
	class InventoryEntryData;
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class NiAVObject;
	class NiNode;
	class ObjectListItem;
	class TESObject;
	class TESObjectREFR;
	class TintMask;
	class UserEventEnabledEvent;
	struct BGSActorCellEvent;
	struct BGSActorDeathEvent;
#ifdef SKYRIM_SUPPORT_AE
	class BSSystemEvent;
#endif
	struct PerkRankData;
	struct PositionPlayerEvent;
	struct TESQuestStageItem;
	struct TESTrackedStatsEvent;
	struct TeleportPath;

	enum class PLAYER_ACTION
	{
		kNone = 0,
		kSwingMeleeWeapon,
		kCastProjectileSpell,
		kShootBow,
		kZKeyObject,
		kJumping,
		kKnockingOverObjects,
		kStandOnTableChair,
		kIronSights,
		kDestroyObject,
		kLockedObject,
		kPickpocket,
		kCastSelfSpell,
		kShout,
		kActorCollision,

		kTotal,
		kInvalidMarker
	};

	struct CrimeGoldStruct
	{
	public:
		// members
		float violentCur;        // 00
		float nonViolentCur;     // 04
		float nonViolentInfamy;  // 08
		float violentInfamy;     // 0C
	};
	static_assert(sizeof(CrimeGoldStruct) == 0x10);

	struct StolenItemValueStruct
	{
	public:
		// members
		std::int32_t unwitnessed;  // 0
		std::int32_t witnessed;    // 4
	};
	static_assert(sizeof(StolenItemValueStruct) == 0x8);

	struct FriendshipFactionsStruct
	{
	public:
		// members
		std::uint16_t friendCounts[4];  // 0
	};
	static_assert(sizeof(FriendshipFactionsStruct) == 0x8);

	class PLAYER_TARGET_LOC
	{
	public:
		using ArrivalFunc_t = void(std::int64_t);

		// members
		TESWorldSpace* world;             // 00
		TESObjectCELL* interior;          // 08
		NiPoint3       location;          // 10
		NiPoint3       angle;             // 1C
		ArrivalFunc_t* arrivalFunc;       // 28
		std::int64_t   arrivalFuncData;   // 30
		RefHandle      furnitureRef;      // 38
		RefHandle      fastTravelMarker;  // 3C
		bool           resetWeather;      // 40
		bool           allowAutoSave;     // 41
		bool           isValid;           // 42
		std::uint8_t   pad43;             // 43
		std::uint32_t  pad44;             // 44
	};
	static_assert(sizeof(PLAYER_TARGET_LOC) == 0x48);

	struct PlayerActionObject
	{
	public:
		// members
		float                                       timer;   // 0
		RefHandle                                   refObj;  // 4
		REX::TEnumSet<PLAYER_ACTION, std::uint32_t> next;    // 8
	};
	static_assert(sizeof(PlayerActionObject) == 0xC);

	class PlayerCharacter :
		public Character,                            // 000
		public BSTEventSource<BGSActorCellEvent>,    // 2D0
		public BSTEventSource<BGSActorDeathEvent>,   // 328
		public BSTEventSource<PositionPlayerEvent>,  // 380
		public BSTEventSink<MenuOpenCloseEvent>,     // 2B0
		public BSTEventSink<MenuModeChangeEvent>,    // 2B8
		public BSTEventSink<UserEventEnabledEvent>,  // 2C0
#ifndef SKYRIM_SUPPORT_AE
		public BSTEventSink<TESTrackedStatsEvent>  // 2C8
#else
		public BSTEventSink<TESTrackedStatsEvent>,  // 2D0
		public BSTEventSink<BSSystemEvent>          // 2D8
#endif
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCharacter;
		inline static constexpr auto VTABLE = VTABLE_PlayerCharacter;
		inline static constexpr auto FORMTYPE = FormType::ActorCharacter;

		enum class GrabbingType
		{
			kNone = 0,
			kNormal,
			kTelekinesis,
		};

		enum class ByCharGenFlag
		{
			kNone = 0,
			kDisableSaving = 1 << 0,
			kDisableWaiting = 1 << 1,
			kShowControlsDisabledMessage = 1 << 2
		};

		struct PlayerFlags
		{
			// members
			bool          travelUseDoor: 1;                  // 0:0 - Guess from FO4 given matching logic for Character::WarpFollowers
			bool          fastTraveling: 1;                  // 0:1 - Set and cleared in the same fast travel function
			bool          overAutoAimTarget: 1;              // 0:2 - Crosshair over hostile actor AND equipped WEAPON_TYPE bow, staff, or crossbow, must have weapon out to be accurate
			bool          showQuestItems: 1;                 // 0:3 - Not used by game, confirmed with console command `SetShowQuestItems`
			bool          unk0_4: 1;                         // 0:4 - Unused?
			bool          hasQueuedEquipAnim: 1;             // 0:5 - Set true in `OnItemEquipped` if a_playAnim && isPaused, false once out of menu
			bool          escaping: 1;                       // 0:6 - Is Escaping from jail
			bool          forceQuestTargetRepath: 1;         // 0:7 - Updates quest target in compass
			bool          unk1_0: 1;                         // 1:0
			bool          unk1_1: 1;                         // 1:1
			bool          sleeping: 1;                       // 1:2
			bool          unk1_3: 1;                         // 1:3
			bool          unk1_4: 1;                         // 1:4
			bool          unk1_5: 1;                         // 1:5
			bool          greetingPlayer: 1;                 // 1:6 - NPC greeting player
			bool          unk1_7: 1;                         // 1:7
			bool          unk2_0: 1;                         // 2:0
			bool          aiControlledToPos: 1;              // 2:1 - Guess from FO4, confirmed aiControlled related
			bool          aiControlledFromPos: 1;            // 2:2 - Guess from FO4, confirmed aiControlled related
			bool          aiControlledPackage: 1;            // 2:3 - Guess from FO4, confirmed aiControlled related
			bool          returnToLastKnownGoodPosition: 1;  // 2:4 - return to lastKnownGoodPosition on next Update
			bool          isBeingChased: 1;                  // 2:5 - unused along with chaseTimer
			bool          unk2_6: 1;                         // 2:6
			bool          unk2_7: 1;                         // 2:7
			bool          isInThirdPersonMode: 1;            // 3:0
			bool          unk3_1: 1;                         // 3:1
			bool          unk3_2: 1;                         // 3:2
			bool          unk3_3: 1;                         // 3:3
			bool          target3DDistant: 1;                // 3:4 - Distance from object in crosshair > 1000
			bool          isInCombat: 1;                     // 3:5
			bool          attemptedYieldInCurrentCombat: 1;  // 3:6 - Set when yielding to guard for arrest dialogue, prevents multiple arrest dialogues
			bool          unk3_7: 1;                         // 3:7
			bool          isLoading: 1;                      // 4:0 - Is player loading a new area
			bool          shouldUpdateCrosshair: 1;          // 4:1 - If forced off without letting Skyrim update this, crosshair UI won't update,
			bool          unk4_2: 1;                         // 4:2
			bool          healthTutorialShown: 1;            // 4:3
			bool          magickaTutorialShown: 1;           // 4:4
			bool          staminaTutorialShown: 1;           // 4:5
			bool          goToJailQueued: 1;                 // 4:6 - Briefly set
			bool          unk4_7: 1;                         // 4:7
			bool          isSprinting: 1;                    // 5:0
			bool          isSungazing: 1;                    // 5:1 - Is staring at the sun
			bool          dragonRideTargetLocked: 1;         // 5:2
			bool          everModded: 1;                     // 5:3
			bool          servingJailTime: 1;                // 5:4 - Briefly set
			bool          pad5_5: 3;                         // 5:5
			std::uint16_t pad6;                              // 6
		};
		static_assert(sizeof(PlayerFlags) == 0x8);

		struct QueuedWeapon
		{
		public:
			// members
			TESObjectWEAP* rightHandWeapon;  // 00
			TESObjectWEAP* leftHandWeapon;   // 08
		};
		static_assert(sizeof(QueuedWeapon) == 0x10);

		struct PreTransformationData
		{
		public:
			// members
			MagicItem*      storedSelectedSpells[4];    // 00
			TESRace*        storedRace;                 // 20
			TESForm*        storedSelectedPower;        // 28
			TESBoundObject* storedLastOneHandItems[2];  // 30
		};
		static_assert(sizeof(PreTransformationData) == 0x40);

		struct PlayerSkills
		{
		public:
			struct Data
			{
			public:
				struct Skills
				{
					enum Skill : std::uint32_t
					{
						kOneHanded = 0,
						kTwoHanded = 1,
						kArchery = 2,
						kBlock = 3,
						kSmithing = 4,
						kHeavyArmor = 5,
						kLightArmor = 6,
						kPickpocket = 7,
						kLockpicking = 8,
						kSneak = 9,
						kAlchemy = 10,
						kSpeech = 11,
						kAlteration = 12,
						kConjuration = 13,
						kDestruction = 14,
						kIllusion = 15,
						kRestoration = 16,
						kEnchanting = 17,
						kTotal
					};
				};
				using Skill = Skills::Skill;

				struct SkillData
				{
				public:
					// members
					float level;           // 0
					float xp;              // 4
					float levelThreshold;  // 8
				};
				static_assert(sizeof(SkillData) == 0xC);

				// members
				float         xp;                              // 000
				float         levelThreshold;                  // 004
				SkillData     skills[Skill::kTotal];           // 008
				std::uint32_t legendaryLevels[Skill::kTotal];  // 0E0
			};
			static_assert(sizeof(Data) == 0x128);

			bool CanLevelUp();
			void AdvanceLevel(bool a_addThreshold);

			// members
			Data* data;  // 0
		};
		static_assert(sizeof(PlayerSkills) == 0x8);

		~PlayerCharacter() override;  // 000

		// override (TESForm)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;        // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;        // 0F
		void InitLoadGame(BGSLoadFormBuffer* a_buf) override;    // 10
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;  // 11
		void Revert(BGSLoadFormBuffer* a_buf) override;          // 12

		// override (TESObjectREFR)
		bool                              QCanUpdateSync() const override;                                                               // 46 - { return true; }
		bool                              GetAllowPromoteToPersistent() const override;                                                  // 47 - { return true; }
		void                              UpdateRefLight() override;                                                                     // 55
		NiPoint3                          GetLookingAtLocation() const override;                                                         // 5B
		NiAVObject*                       Load3D(bool a_backgroundLoading) override;                                                     // 6A
		void                              Set3D(NiAVObject* a_object, bool a_queue3DTasks = true) override;                              // 6C
		NiAVObject*                       Get3D1(bool a_firstPerson) const override;                                                     // 6F - { return Get3D2(); }
		NiAVObject*                       Get3D2() const override;                                                                       // 70
		bool                              Is3rdPersonVisible() const override;                                                           // 71 - { return true; }
		bool                              PopulateGraphProjectsToLoad(void) const override;                                              // 72
		void                              ModifyAnimationUpdateData(BSAnimationUpdateData& a_data) override;                             // 79 - { return; }
		void                              UpdateAnimation(float a_delta) override;                                                       // 7D
		const BSTSmartPointer<BipedAnim>& GetBiped1(bool a_firstPerson) const override;                                                  // 7E - { return GetBiped2(); }
		const BSTSmartPointer<BipedAnim>& GetBiped2() const override;                                                                    // 7F
		const BSTSmartPointer<BipedAnim>& GetCurrentBiped() const override;                                                              // 80 - { return GetBiped2(); }
		void                              RemoveWeapon(BIPED_OBJECT equipIndex) override;                                                // 082
		void                              GetLinearVelocity(NiPoint3& a_velocity) const override;                                        // 86
		NiAVObject*                       GetCurrent3D() const override;                                                                 // 8D - { return Get3D2(); }
		void                              SetParentCell(TESObjectCELL* a_cell) override;                                                 // 98
		bool                              ProcessInWater(hkpCollidable* a_collidable, float a_waterHeight, float a_deltaTime) override;  // 9C
		bool                              Unk_A0(NiAVObject* a_node, float& a_angleX, float& a_angleZ, NiPoint3& a_pos) const override;  // A0

		// override (Actor)
		void                 Unk_A2(void) override;                                                                                                                                               // 0A2
		void                 PlayPickUpSound(TESBoundObject* a_object, bool a_pickup, bool a_use) override;                                                                                       // 0A3
		float                GetHeading(bool a_ignoreRaceSettings) const override;                                                                                                                // 0A4
		void                 DrawWeaponMagicHands(bool a_draw) override;                                                                                                                          // 0A6
		void                 Resurrect(bool a_resetInventory, bool a_attach3D) override;                                                                                                          // 0AB
		void                 Update(float a_delta) override;                                                                                                                                      // 0AD
		void                 OnItemEquipped(bool a_playAnim) override;                                                                                                                            // 0B2
		void                 Unk_B3(void) override;                                                                                                                                               // 0B3 - { return 1; }
		void                 Unk_B4(void) override;                                                                                                                                               // 0B4
		void                 SetCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::uint32_t a_amount) override;                                                                           // 0B5
		void                 ModCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::int32_t a_amount) override;                                                                            // 0B6
		void                 RemoveCrimeGoldValue(TESFaction* a_faction, bool a_violent, std::int32_t a_amount) override;                                                                         // 0B7
		std::uint32_t        GetCrimeGoldValue(const TESFaction* a_faction) const override;                                                                                                       // 0B8
		void                 GoToPrison(TESFaction* a_faction, bool a_removeInventory, bool a_realJail) override;                                                                                 // 0B9 - { return; }
		void                 ServePrisonTime() override;                                                                                                                                          // 0BA - { return; }
		void                 PayFine(TESFaction* a_faction, bool a_goToJail, bool a_removeStolenItems) override;                                                                                  // 0BB - { return; }
		bool                 GetCannibal() override;                                                                                                                                              // 0BC - { return false; }
		bool                 GetVampireFeed() override;                                                                                                                                           // 0BE - { return false; }
		void                 InitiateVampireFeedPackage(Actor* a_target, TESObjectREFR* a_furniture) override;                                                                                    // 0C0 - { return; }
		void                 InitiateCannibalPackage(Actor* a_target) override;                                                                                                                   // 0C1 - { return; }
		void                 GetEyeVector(NiPoint3& a_origin, NiPoint3& a_direction, bool a_includeCameraOffset) override;                                                                        // 0C2
		void                 SetRefraction(bool a_enable, float a_refraction) override;                                                                                                           // 0C3
		void                 Unk_C6(void) override;                                                                                                                                               // 0C6
		void                 Unk_C9(void) override;                                                                                                                                               // 0C9
		ObjectRefHandle      DropObject(const TESBoundObject* a_object, ExtraDataList* a_extraList, std::int32_t a_count, const NiPoint3* a_dropLoc = 0, const NiPoint3* a_rotate = 0) override;  // 0CB
		void                 PickUpObject(TESObjectREFR* a_object, std::int32_t a_count, bool a_arg3 = false, bool a_playSound = true) override;                                                  // 0CC
		void                 AttachArrow(const BSTSmartPointer<BipedAnim>& a_biped) override;                                                                                                     // 0CD
		void                 DetachArrow(const BSTSmartPointer<BipedAnim>& a_biped) override;                                                                                                     // 0CE
		bool                 AddShout(TESShout* a_shout) override;                                                                                                                                // 0CF
		void                 Unk_D1(void) override;                                                                                                                                               // 0D1
		std::uint32_t        UseAmmo(std::uint32_t a_shotCount) override;                                                                                                                         // 0D2
		CombatGroup*         GetCombatGroup() const override;                                                                                                                                     // 0D4
		void                 SetCombatGroup(CombatGroup* a_group) override;                                                                                                                       // 0D5
		bool                 CheckValidTarget(TESObjectREFR& a_target) override;                                                                                                                  // 0D6
		void                 InitiateDialogue(Actor* a_target, PackageLocation* a_loc1, PackageLocation* a_loc2) override;                                                                        // 0D8
		void                 InitiateGetUpPackage() override;                                                                                                                                     // 0DE
		void                 UpdateAlpha() override;                                                                                                                                              // 0E0
		bool                 IsInCombat() const override;                                                                                                                                         // 0E3
		void                 StopCombat() override;                                                                                                                                               // 0E5
		void                 WeaponSwingCallBack() override;                                                                                                                                      // 0EF
		bool                 HasBeenAttacked() const override;                                                                                                                                    // 0F5
		void                 SetBeenAttacked(bool a_set) override;                                                                                                                                // 0F6
		void                 UseSkill(ActorValue a_av, float a_points, TESForm* a_advanceObject = nullptr, SKILL_ACTION a_advanceAction = SKILL_ACTION::kNormalUse) override;                     // 0F7 - { return; }
		bool                 IsInFaction(const TESFaction* faction) const override;                                                                                                               // 0F9
		void                 ForEachPerk(PerkEntryVisitor& a_visitor) const override;                                                                                                             // 0FA
		void                 AddPerk(BGSPerk* a_perk, std::uint32_t a_rank = 0) override;                                                                                                         // 0FB - { return; }
		void                 RemovePerk(BGSPerk* a_perk) override;                                                                                                                                // 0FC - { return; }
		void                 ApplyTemporaryPerk(BGSPerk* a_perk) override;                                                                                                                        // 0FD - { return; }
		void                 RemoveTemporaryPerk(BGSPerk* a_perk) override;                                                                                                                       // 0FE - { return; }
		void                 ApplyPerksFromBase() override;                                                                                                                                       // 101
		void                 StartPowerAttackCoolDown() override;                                                                                                                                 // 102 - { return; }
		bool                 IsPowerAttackCoolingDown() const override;                                                                                                                           // 103 - { return false; }
		void                 Unk_105(void) override;                                                                                                                                              // 105
		void                 CreateMovementController() override;                                                                                                                                 // 109
		void                 KillImpl(Actor* a_attacker, float a_damage, bool a_sendEvent, bool a_ragdollInstant) override;                                                                       // 10E
		bool                 DrinkPotion(AlchemyItem* a_potion, ExtraDataList* a_extralist) override;                                                                                             // 10F
		bool                 CheckCast(MagicItem* a_spell, bool a_dualCast, MagicSystem::CannotCastReason* a_reason) override;                                                                    // 110
		std::int32_t         GetCurrentShoutLevel() override;                                                                                                                                     // 112 - return -1 on error
		void                 SetLastRiddenMount(ActorHandle a_mount) override;                                                                                                                    // 113 - { return; }
		ActorHandle          QLastRiddenMount() const override;                                                                                                                                   // 114 - { return {}; }
		void                 Unk_117(NiPoint3& a_origin) override;                                                                                                                                // 117 - { return; }
		void                 InitValues() override;                                                                                                                                               // 118
		const BSFixedString& GetResponseString() const override;                                                                                                                                  // 119 - { return "ActorResponse"; }
		void                 ModifyMovementData(float a_delta, NiPoint3& a_arg3, NiPoint3& a_arg4) override;                                                                                      // 11A
		bool                 ComputeMotionFeedbackSpeedAndDirection(const ActorMotionFeedbackData& a_data, float a_delta, ActorMotionFeedbackOutput& a_output) override;                          // 11D
		void                 UpdateActor3DPosition() override;                                                                                                                                    // 11F
		void                 WornArmorChanged(void) override;                                                                                                                                     // 121
		bool                 ShouldRespondToActorCollision(const MovementMessageActorCollision& a_msg, const ActorHandlePtr& a_target) override;                                                  // 126
		float                CheckClampDamageModifier(ActorValue a_av, float a_delta) override;                                                                                                   // 127

		// override (Character)
		void Unk_129(void) override;  // 129 - { return 1; }

		// add
		virtual void          Unk_12A(void);                                                   // 12A
		virtual std::uint32_t GetViolentCrimeGoldValue(const TESFaction* a_faction) const;     // 12B
		virtual std::uint32_t GetNonViolentCrimeGoldValue(const TESFaction* a_faction) const;  // 12C
		virtual void          ClearAllCrimeGold(TESFaction* a_faction);                        // 12D
		virtual void          Unk_12E(void);                                                   // 12E - { return 0; }

		static PlayerCharacter* GetSingleton();
		static bool             IsGodMode();

		void                     ActivatePickRef();
		void                     AddPlayerAddItemEvent(TESObject* a_object, TESForm* a_owner, TESObjectREFR* a_container, AQUIRE_TYPE a_type);
		bool                     AttemptPickpocket(TESObjectREFR* a_containerRef, InventoryEntryData* a_entry, std::int32_t a_number, bool a_fromContainer = true);
		bool                     CenterOnCell(const char* a_cellName);
		bool                     CenterOnCell(TESObjectCELL* a_cell);
		bool                     CheckCast(MagicItem* a_spell, Effect* a_effect, MagicSystem::CannotCastReason& a_reason);
		void                     CheckPoisonWeapon(AlchemyItem* a_poison);
		void                     DestroyMouseSprings();
		void                     EndGrabObject();
		NiPointer<Actor>         GetActorDoingPlayerCommand() const;
		float                    GetArmorValue(InventoryEntryData* a_form);
		float                    GetDamage(InventoryEntryData* a_form);
		float                    GetEquippedWeaponsDamage();
		NiPointer<TESObjectREFR> GetGrabbedRef();
		std::int32_t             GetItemCount(TESBoundObject* a_object);
		std::uint32_t            GetNumTints(std::uint32_t a_tintType);
		TintMask*                GetOverlayTintMask(TintMask* a_original);
		BSTArray<TintMask*>&     GetTintList();
		TintMask*                GetTintMask(std::uint32_t a_tintType, std::uint32_t a_index);
		bool                     HasActorDoingCommand() const;
		bool                     IsGrabbing() const;
		void                     PlayMagicFailureSound(MagicSystem::SpellType a_spellType);
		void                     SetAIDriven(bool a_enable);
		void                     SetEscaping(bool a_flag, bool a_escaped);
		void                     StartGrabObject();
		void                     UpdateCrosshairs();

		template <class T>
		inline BSTEventSource<T>* GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		template <class T>
		inline void AddEventSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->AddEventSink(a_sink);
		}

		// members
		mutable BSSpinLock                                      questTargetsLock;                             // 3D8
		BSTHashMap<const TESFaction*, CrimeGoldStruct>          crimeGoldMap;                                 // 3E0
		BSTHashMap<const TESFaction*, StolenItemValueStruct>    stolenItemValueMap;                           // 410
		ObjectRefHandle                                         commandWaitMarker;                            // 440
		std::uint32_t                                           pad444;                                       // 444
		BSTHashMap<const TESFaction*, FriendshipFactionsStruct> factionOwnerFriendsMap;                       // 448
		NiPoint3                                                lastKnownGoodPosition;                        // 478
		NiPoint3                                                bulletAutoAim;                                // 484
		NiPoint3                                                cachedVelocity;                               // 490
		std::uint32_t                                           pad49C;                                       // 49C
		BGSNote*                                                unusedNote;                                   // 4A0 - Used for unimplemented formtype BGSNote
		BGSNote*                                                unusedNote2;                                  // 4A8 - Used for unimplemented formtype BGSNote
		BSTArray<PerkRankData*>                                 addedPerks;                                   // 4B0
		BSTArray<BGSPerk*>                                      perks;                                        // 4C8
		BSTArray<BGSPerk*>                                      standingStonePerks;                           // 4E0
		BSTArray<ObjectRefHandle>                               currentMapMarkers;                            // 4F8
		BSTArray<BSTTuple<NiPoint3, AITimeStamp>>               velocityArray;                                // 510
		BSTArray<ProjectileHandle>                              runesCast;                                    // 528
		BSTArray<void*>                                         imageSpaceModifierAnims1;                     // 540
		BSTArray<void*>                                         imageSpaceModifierAnims2;                     // 558
		BSSimpleList<TESQuestStageItem*>                        questLog;                                     // 570
		BSTArray<BGSInstancedQuestObjective>                    objectives;                                   // 580
		BSTHashMap<TESQuest*, BSTArray<TESQuestTarget*>*>       questTargets;                                 // 598
		BSTHashMap<UnkKey, UnkValue>                            currentSayOnceInfosMap;                       // 5C8
		BSSimpleList<ObjectRefHandle>                           droppedRefList;                               // 5F8
		NiTMap<std::uint32_t, std::uint8_t>                     randomDoorSpaceMap;                           // 608
		TESWorldSpace*                                          cachedWorldSpace;                             // 628
		NiPoint3                                                exteriorPosition;                             // 630
		std::uint32_t                                           pad63C;                                       // 63C
		PLAYER_TARGET_LOC                                       queuedTargetLoc;                              // 640
		BSSoundHandle                                           unusedSound;                                  // 688 - Only place it is set is an unused function
		BSSoundHandle                                           magicFailureSound;                            // 694
		BSSoundHandle                                           shoutFailureSound;                            // 6A0
		std::uint32_t                                           pad6AC;                                       // 6AC
		DialoguePackage*                                        closestConversation;                          // 6B0
		std::uint32_t                                           unk6B8;                                       // 6B8
		std::uint32_t                                           unk6BC;                                       // 6BC
		DialoguePackage*                                        aiConversationRunning;                        // 6C0
		std::int32_t                                            numberofStealWarnings;                        // 6C8
		float                                                   stealWarningTimer;                            // 6CC
		std::int32_t                                            numberofPickpocketWarnings;                   // 6D0
		float                                                   pickPocketWarningTimer;                       // 6D4
		AITimeStamp                                             warnToLeaveTimeStamp;                         // 6D8
		std::uint32_t                                           pad6DC;                                       // 6DC
		ImageSpaceModifierInstanceDOF*                          ironsightsDOFInstance;                        // 6E0
		ImageSpaceModifierInstanceDOF*                          vatsDOFInstance;                              // 6E8
		ImageSpaceModifierInstanceDOF*                          dynamicDOFInstance;                           // 6F0
		float                                                   dynamicDOFFocusTime;                          // 6F8
		bool                                                    dynamicDOFFocused;                            // 6FC
		std::uint8_t                                            unk6FD;                                       // 6FD
		std::uint16_t                                           unk6FE;                                       // 6FE
		NiPoint3                                                dynamicDOFLastAngle;                          // 700
		NiPoint3                                                dynamicDOFLastPosition;                       // 70C
		TESFaction*                                             currentPrisonFaction;                         // 718
		std::int32_t                                            jailSentence;                                 // 720
		std::uint32_t                                           pad724;                                       // 724
		void*                                                   unk728;                                       // 728 - smart ptr
		QueuedWeapon                                            queuedWeaponAttachs[WEAPON_TYPE::kTotal];     // 730 - Weapons are attached on next PlayerCharacter::Update
		std::int32_t                                            vampireFeedDetection;                         // 7D0
		std::uint32_t                                           mapMarkerIterator;                            // 7D4
		RefHandle                                               forceActivateRef;                             // 7D8
		PlayerActionObject                                      playerActionObjects[15];                      // 7DC
		PLAYER_ACTION                                           mostRecentAction;                             // 890
		ActorHandle                                             actorDoingPlayerCommand;                      // 894
		BSTSmallArray<hkRefPtr<bhkMouseSpringAction>, 4>        grabSpring;                                   // 898
		ObjectRefHandle                                         grabbedObject;                                // 8C8
		float                                                   grabObjectWeight;                             // 8CC
		float                                                   grabDistance;                                 // 8D0
		float                                                   unk8D4;                                       // 8D4
		std::uint64_t                                           unk8D8;                                       // 8D8
		std::uint32_t                                           unk8E0;                                       // 8E0 - Unused?
		std::uint32_t                                           sleepSeconds;                                 // 8E4
		BSTSmartPointer<BipedAnim>                              largeBiped;                                   // 8E8
		NiPointer<NiNode>                                       firstPerson3D;                                // 8F0
		float                                                   eyeHeight;                                    // 8F8
		float                                                   greetTimer;                                   // 8FC
		float                                                   encumberedTimer;                              // 900
		float                                                   powerAttackTimer;                             // 904
		std::int32_t                                            hoursToSleep;                                 // 908
		std::int32_t                                            amountStolenSold;                             // 90C
		std::uint32_t                                           valueStolen;                                  // 910
		ActorHandle                                             lastRiddenMount;                              // 914
		ActorHandle                                             lightTarget;                                  // 918
		float                                                   sortActorDistanceTimer;                       // 91C
		float                                                   sitHeadingDelta;                              // 920
		ObjectRefHandle                                         playerMapMarker;                              // 924 - Custom marker placed by player in map
		TeleportPath*                                           playerMarkerPath;                             // 928 - Educated guess from FO4
		std::uint32_t                                           skillTrainingsThisLevel;                      // 930
		std::uint32_t                                           unk934;                                       // 934
		TESClass*                                               defaultClass;                                 // 938
		std::uint64_t                                           unk940;                                       // 940 - Unused?
		std::uint32_t                                           crimeCounts[PackageNS::CRIME_TYPES::kTotal];  // 948
		std::uint32_t                                           unk964;                                       // 964
		AlchemyItem*                                            pendingPoison;                                // 968
		std::int64_t                                            lastPlayingTimeUpdate;                        // 970
		std::int64_t                                            totalPlayingTime;                             // 978
		std::int32_t                                            characterSeed;                                // 980
		std::uint32_t                                           unk984;                                       // 984
		TESForm*                                                lastKnownGoodLocation;                        // 988
		std::uint32_t                                           unk990;                                       // 990
		std::uint32_t                                           unk994;                                       // 994
		NiPointer<BSLight>                                      firstPersonLight;                             // 998
		NiPointer<BSLight>                                      thirdPersonLight;                             // 9A0
		float                                                   dropAngleMod;                                 // 9A8
		float                                                   lastDropAngleMod;                             // 9AC
		PlayerSkills*                                           skills;                                       // 9B0
		ActorHandle                                             autoAimActor;                                 // 9B8
		RefHandle                                               unk9BC;                                       // 9BC
		std::uint64_t                                           unk9C0;                                       // 9C0
		NiPointer<NiAVObject>                                   targeted3D;                                   // 9C8
		CombatGroup*                                            combatGroup;                                  // 9D0
		BSTArray<ActorHandle>                                   actorsToDisplayOnTheHUDArray;                 // 9D8
		TESForm*                                                advanceObject;                                // 9F0 - Part of AE8 and AEC, the object advancing the skill (eg telekinesis spell for alteration skill)
		TESBoundObject*                                         lastOneHandItems[2];                          // 9F8
		std::uint32_t                                           teammateCount;                                // A08
		float                                                   combatTimer;                                  // A0C
		float                                                   yieldTimer;                                   // A10
		float                                                   chaseTimer;                                   // A14
		float                                                   drawSheatheSafetyTimer;                       // A18
		std::uint32_t                                           unkA1C;                                       // A1C
		std::uint8_t                                            unkA20[0xA0];                                 // A20 - Unused?
		std::uint32_t                                           unkAC0;                                       // AC0
		std::uint32_t                                           unkAC4;                                       // AC4
		BGSLocation*                                            currentLocation;                              // AC8
		AITimeStamp                                             cachedVelocityTimeStamp;                      // AD0
		float                                                   telekinesisDistance;                          // AD4
		float                                                   commandTimer;                                 // AD8
		float                                                   sunGazeTimer;                                 // ADC - Upon sungazing, counts down from 0.5 seconds. When 0, applies imagespace modifier
		TESImageSpaceModifier*                                  sunGazeImageSpaceModifier;                    // AE0
		ActorValue                                              advanceSkill;                                 // AE8 - advance values set, then cleared in PlayerSkills::ModSkillPoints surronding ApplyPerkEntry
		std::uint32_t                                           advanceAction;                                // AEC - Part of AE8 and 9F0
		REX::TEnumSet<DEFAULT_OBJECT, std::int32_t>             animationObjectAction;                        // AF0
		REX::TEnumSet<GrabbingType, std::uint32_t>              grabType;                                     // AF4
		std::int32_t                                            difficulty;                                   // AF8
		ActorHandle                                             assumedIdentity;                              // AFC
		std::int8_t                                             murder;                                       // B00
		std::uint8_t                                            perkCount;                                    // B01
		REX::TEnumSet<ByCharGenFlag, std::uint8_t>              byCharGenFlag;                                // B02
		std::uint8_t                                            padB03;                                       // B03
		std::uint32_t                                           unkB04;                                       // B04
		Crime*                                                  resistArrestCrime;                            // B08
		BSTArray<TintMask*>                                     tintMasks;                                    // B10
		BSTArray<TintMask*>*                                    overlayTintMasks;                             // B28
		BGSTextureSet*                                          complexion;                                   // B30
		TESRace*                                                charGenRace;                                  // B38
		TESRace*                                                race2;                                        // B40
		std::int32_t                                            unkB48;                                       // B48
		std::uint32_t                                           padB4C;                                       // B4C
		BSTArray<std::uint64_t>                                 unkB50;                                       // B50
		std::uint64_t                                           unkB68;                                       // B68
		std::uint64_t                                           unkB70;                                       // B70
		std::uint64_t                                           unkB78;                                       // B78
		std::uint64_t                                           unkB80;                                       // B80
		std::int32_t                                            unkB88;                                       // B88
		std::uint32_t                                           padB8C;                                       // B8C
		std::uint64_t                                           unkB90;                                       // B90
		InventoryEntryData*                                     temperingItem;                                // B98
		BSTSmallArray<void*, 4>                                 unkBA0;                                       // BA0
		PreTransformationData*                                  preTransformationData;                        // BD0 - Stores equipped data when transforming to vampire/werewolf, cleared when transforming back to human
		PlayerFlags                                             playerFlags;                                  // BD8

	private:
		bool CenterOnCell_Impl(const char* a_cellName, RE::TESObjectCELL* a_cell);
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(PlayerCharacter) == 0xBE0);
#else
	static_assert(sizeof(PlayerCharacter) == 0xBF0);
#endif
}
