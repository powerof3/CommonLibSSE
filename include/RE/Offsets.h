#pragma once

#include "REL/ID.h"

namespace RE
{
	namespace Offset
	{
#ifdef SKYRIM_SUPPORT_AE
		namespace ActivateHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208723));
		}

		namespace ActiveEffect
		{
			inline constexpr REL::ID Dispel(static_cast<std::uint64_t>(34061));
		}

		namespace Actor
		{
			inline constexpr REL::ID AddSpell(static_cast<std::uint64_t>(38716));
			inline constexpr REL::ID DispelWornItemEnchantments(static_cast<std::uint64_t>(34620));
			inline constexpr REL::ID DoReset3D(static_cast<std::uint64_t>(40255));
			inline constexpr REL::ID EvaluatePackage(static_cast<std::uint64_t>(37401));
			inline constexpr REL::ID GetGhost(static_cast<std::uint64_t>(37275));
			inline constexpr REL::ID GetHostileToActor(static_cast<std::uint64_t>(37537));
			inline constexpr REL::ID GetLevel(static_cast<std::uint64_t>(37334));
			inline constexpr REL::ID HasPerk(static_cast<std::uint64_t>(37698));
			inline constexpr REL::ID InterruptCast(static_cast<std::uint64_t>(38757));
			inline constexpr REL::ID IsRunning(static_cast<std::uint64_t>(37234));
			inline constexpr REL::ID RemoveSpell(static_cast<std::uint64_t>(38717));
			inline constexpr REL::ID RequestDetectionLevel(static_cast<std::uint64_t>(37764));
			inline constexpr REL::ID StealAlarm(static_cast<std::uint64_t>(37422));
			inline constexpr REL::ID SwitchRace(static_cast<std::uint64_t>(37925));
			inline constexpr REL::ID UpdateArmorAbility(static_cast<std::uint64_t>(38751));
			inline constexpr REL::ID UpdateWeaponAbility(static_cast<std::uint64_t>(38752));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(207511));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::ID EquipObject(static_cast<std::uint64_t>(38894));
			inline constexpr REL::ID EquipShout(static_cast<std::uint64_t>(38897));
			inline constexpr REL::ID EquipSpell(static_cast<std::uint64_t>(38895));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400636));
			inline constexpr REL::ID UnequipObject(static_cast<std::uint64_t>(38901));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::ID GetArmorRatingSkillMultiplier(static_cast<std::uint64_t>(26424));
			inline constexpr REL::ID GetClampedActorValue(static_cast<std::uint64_t>(27284));
		}

		namespace AIFormulas
		{
			inline constexpr REL::ID ComputePickpocketSuccess(static_cast<std::uint64_t>(26379));
		}

		namespace AIProcess
		{
			inline constexpr REL::ID SetBaseScale(static_cast<std::uint64_t>(39588));
			inline constexpr REL::ID Update3DModel(static_cast<std::uint64_t>(39395));
		}

		namespace ArmorRatingVisitor
		{
			inline constexpr REL::ID HaveNotVisitedArmor(static_cast<std::uint64_t>(40297));
			inline constexpr REL::ID VisitArmor(static_cast<std::uint64_t>(40293));
		}

		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::ID Visit(static_cast<std::uint64_t>(40299));
		}

		namespace AttackBlockHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208719));
		}

		namespace AutoMoveHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208725));
		}

		namespace BarterMenu
		{
			inline constexpr REL::ID TargetRefHandle(static_cast<std::uint64_t>(403520));
		}

		namespace BGSAddToPlayerInventoryEvent
		{
			inline constexpr REL::ID GetIndex(static_cast<std::uint64_t>(380074));
		}

		namespace BGSCreatedObjectManager
		{
			inline constexpr REL::ID CreateArmorEnchantment(static_cast<std::uint64_t>(36166));
			inline constexpr REL::ID CreateWeaponEnchantment(static_cast<std::uint64_t>(36165));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400320));
		}

		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13894));
		}

		namespace BGSEntryPoint
		{
			inline constexpr REL::ID EntryPoints(static_cast<std::uint64_t>(368994));
			inline constexpr REL::ID HandleEntryPoint(static_cast<std::uint64_t>(23526));
		}

		namespace BGSEntryPointFunction
		{
			inline constexpr REL::ID EntryPointFunctions(static_cast<std::uint64_t>(369178));
			inline constexpr REL::ID EntryPointFunctionTypeArgumentCount(static_cast<std::uint64_t>(369210));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401262));
		}

		namespace BGSListForm
		{
			inline constexpr REL::ID AddForm(static_cast<std::uint64_t>(20913));
		}

		namespace BGSOpenCloseForm
		{
			inline constexpr REL::ID GetOpenState(static_cast<std::uint64_t>(14288));
			inline constexpr REL::ID SetOpenState(static_cast<std::uint64_t>(14287));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::ID Save(static_cast<std::uint64_t>(35727));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403340));
			inline constexpr REL::ID Load(static_cast<std::uint64_t>(35728));
		}

		namespace BGSSkillPerkTreeNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(27263));
		}

		namespace BGSStoryEventManager
		{
			inline constexpr REL::ID AddEvent(static_cast<std::uint64_t>(32359));
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(22790));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::ID BeginShutDownQuest(static_cast<std::uint64_t>(32486));
			inline constexpr REL::ID BeginStartUpQuest(static_cast<std::uint64_t>(32485));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400476));
		}

		namespace BipedAnim
		{
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15656));
			inline constexpr REL::ID RemoveAllParts(static_cast<std::uint64_t>(15659));
		}

		namespace BookMenu
		{
			inline constexpr REL::ID TargetReference(static_cast<std::uint64_t>(405840));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(67652));
			inline constexpr REL::ID BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(67666));
		}

		namespace BSFaceGenAnimationData
		{
			inline constexpr REL::ID Reset(26586);
			inline constexpr REL::ID SetExpressionOverride(26594);
		}

		namespace BSFixedString
		{
			inline constexpr REL::ID Ctor8(69161);
			inline constexpr REL::ID Ctor16(69176);
		}

		namespace BSGraphics
		{
			namespace State
			{
				inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(411479));
			}
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(402776));
		}

		namespace BSInputEventQueue
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(407374));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::ID CreateMaterial(static_cast<std::uint64_t>(106723));
		}

		namespace BSMusicManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400896));
		}

		namespace BSPointerHandleManager
		{
			inline constexpr REL::ID HandleEntries(static_cast<std::uint64_t>(400622));
		}

		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::ID GetHandle(static_cast<std::uint64_t>(16212));
			inline constexpr REL::ID GetSmartPointer(static_cast<std::uint64_t>(12332));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::ID LockForRead(static_cast<std::uint64_t>(68233));
			inline constexpr REL::ID LockForWrite(static_cast<std::uint64_t>(68234));
			inline constexpr REL::ID UnlockForRead(static_cast<std::uint64_t>(68239));
			inline constexpr REL::ID UnlockForWrite(static_cast<std::uint64_t>(68240));
		}

		namespace BSResource
		{
			namespace LooseFileLocation
			{
				inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(188191));
			}

			inline constexpr REL::ID RegisterGlobalPath(static_cast<std::uint64_t>(69833));
			inline constexpr REL::ID RegisterLocation(static_cast<std::uint64_t>(69829));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(71014));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(71016));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(71018));
			inline constexpr REL::ID SetEndianSwap(static_cast<std::uint64_t>(71021));
		}

		namespace BSScaleformExternalTexture
		{
			inline constexpr REL::ID LoadPNG(static_cast<std::uint64_t>(82321));
			inline constexpr REL::ID ReleaseTexture(static_cast<std::uint64_t>(82317));
			inline constexpr REL::ID SetTexture(static_cast<std::uint64_t>(82318));
		}

		namespace BSScaleformImageLoader
		{
			inline constexpr REL::ID AddTexture(static_cast<std::uint64_t>(84469));
			inline constexpr REL::ID RemoveTexture(static_cast<std::uint64_t>(84470));
		}

		namespace BSScaleformManager
		{
			inline constexpr REL::ID FileExists(static_cast<std::uint64_t>(82411));
			inline constexpr REL::ID IsValidName(static_cast<std::uint64_t>(82331));
			inline constexpr REL::ID LoadMovie(static_cast<std::uint64_t>(82325));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(402775));
		}

		namespace BSScaleformTranslator
		{
			inline constexpr REL::ID GetCachedString(static_cast<std::uint64_t>(69188));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242017));
		}

		namespace BSScript
		{
			namespace Object
			{
				inline constexpr REL::ID GetHandle(static_cast<std::uint64_t>(104247));
				inline constexpr REL::ID IncRef(static_cast<std::uint64_t>(104252));
				inline constexpr REL::ID DecRef(static_cast<std::uint64_t>(104253));
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(104246));
			}

			namespace ObjectBindPolicy
			{
				inline constexpr REL::ID BindObject(static_cast<std::uint64_t>(104184));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Call(static_cast<std::uint64_t>(104651));
				}
			}

			namespace Stack
			{
				inline constexpr REL::ID GetStackFrameVariable(static_cast<std::uint64_t>(104484));
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(104480));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::ID IsValid(static_cast<std::uint64_t>(67621));
			inline constexpr REL::ID Play(static_cast<std::uint64_t>(67616));
			inline constexpr REL::ID SetObjectToFollow(static_cast<std::uint64_t>(67636));
			inline constexpr REL::ID SetPosition(static_cast<std::uint64_t>(67631));
			inline constexpr REL::ID Pause(static_cast<std::uint64_t>(67618));
			inline constexpr REL::ID Stop(static_cast<std::uint64_t>(67619));
		}

		namespace BSString
		{
			inline constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(11044));
		}

		namespace BSStringPool
		{
			inline constexpr REL::ID Release8(static_cast<std::uint64_t>(69192));
			inline constexpr REL::ID Release16(static_cast<std::uint64_t>(69193));
		}

		namespace BSThreadEvent
		{
			inline constexpr REL::ID InitSDM(static_cast<std::uint64_t>(68449));
		}

		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(69200));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(109278));
		}

		namespace Calendar
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400447));
			inline constexpr REL::ID GetTimeDateString(static_cast<std::uint64_t>(36311));
		}

		namespace ChestsLooted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(51182));
		}

		namespace Console
		{
			inline constexpr REL::ID SelectedRef(static_cast<std::uint64_t>(504099));
			inline constexpr REL::ID SetSelectedRef(static_cast<std::uint64_t>(51093));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401203));
			inline constexpr REL::ID VPrint(static_cast<std::uint64_t>(51110));
		}

		namespace ContainerMenu
		{
			inline constexpr REL::ID ContainerMode(static_cast<std::uint64_t>(405937));
			inline constexpr REL::ID TargetRefHandle(static_cast<std::uint64_t>(405962));
		}

		namespace ControlMap
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400863));
		}

		namespace CraftingSubMenus
		{
			namespace EnchantConstructMenu
			{
				inline constexpr REL::ID RenameItem(static_cast<std::uint64_t>(51415));
				inline constexpr REL::ID UpdateInterface(static_cast<std::uint64_t>(51459));
			}
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::ID SizeOf32(static_cast<std::uint64_t>(12141));
			inline constexpr REL::ID SizeOf64(static_cast<std::uint64_t>(68221));
			inline constexpr REL::ID SizeOfSize(static_cast<std::uint64_t>(68219));
		}

		namespace DialogueItem
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(35220));
		}

		namespace ExtraAliasInstanceArray
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186835));
		}

		namespace ExtraAshPileRef
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186727));
		}

		namespace ExtraCannotWear
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186685));
		}

		namespace ExtraCanTalkToPlayer
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186797));
		}

		namespace ExtraCharge
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186693));
		}

		namespace ExtraContainerChanges
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186995));
		}

		namespace ExtraCount
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186679));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::ID Add(static_cast<std::uint64_t>(12315));
			inline constexpr REL::ID SetCount(static_cast<std::uint64_t>(11617));
			inline constexpr REL::ID SetExtraFlags(static_cast<std::uint64_t>(12042));
			inline constexpr REL::ID SetInventoryChanges(static_cast<std::uint64_t>(11600));
		}

		namespace ExtraEnchantment
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186753));
		}

		namespace ExtraForcedTarget
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186863));
		}

		namespace ExtraHealth
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186687));
		}

		namespace ExtraHotkey
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186699));
		}

		namespace ExtraLightData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186841));
		}

		namespace ExtraLock
		{
			inline constexpr REL::ID GetLockLevel(static_cast<std::uint64_t>(12399));
		}

		namespace ExtraOwnership
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186673));
		}

		namespace ExtraPoison
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186751));
		}

		namespace ExtraRank
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186677));
		}

		namespace ExtraReferenceHandle
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186703));
		}

		namespace ExtraSoul
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(187003));
		}

		namespace ExtraTextDisplayData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186855));
			inline constexpr REL::ID GetDisplayName(static_cast<std::uint64_t>(12768));
		}

		namespace ExtraUniqueID
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(186867));
		}

		namespace FavoritesHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(215785));
		}

		namespace FavoritesMenu
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(215307));
		}

		namespace FirstPersonState
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(214855));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400782));
		}

		namespace GASActionBufferData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242366));
		}

		namespace GASDoAction
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242413));
		}

		namespace GASDoInitAction
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242414));
		}

		namespace GFxInitImportActions
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(244866));
		}

		namespace GFxLoader
		{
			inline constexpr REL::ID CreateMovie(static_cast<std::uint64_t>(84640));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::ID InvokeNoReturn(static_cast<std::uint64_t>(82665));
		}

		namespace GFxPlaceObject2
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242592));
		}

		namespace GFxPlaceObject3
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(242593));
		}

		namespace GFxRemoveObject
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(244863));
		}

		namespace GFxRemoveObject2
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(244864));
		}

		namespace GFxSetBackgroundColor
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(244865));
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::ID AttachMovie(static_cast<std::uint64_t>(82219));
				inline constexpr REL::ID DeleteMember(static_cast<std::uint64_t>(82230));
				inline constexpr REL::ID GetArraySize(static_cast<std::uint64_t>(82237));
				inline constexpr REL::ID GetCxform(static_cast<std::uint64_t>(82238));
				inline constexpr REL::ID GetDisplayInfo(static_cast<std::uint64_t>(82239));
				inline constexpr REL::ID GetDisplayMatrix(static_cast<std::uint64_t>(82240));
				inline constexpr REL::ID GetElement(static_cast<std::uint64_t>(82241));
				inline constexpr REL::ID GetMember(static_cast<std::uint64_t>(82245));
				inline constexpr REL::ID GotoAndPlay(static_cast<std::uint64_t>(82253));
				inline constexpr REL::ID HasMember(static_cast<std::uint64_t>(82254));
				inline constexpr REL::ID Invoke(static_cast<std::uint64_t>(82256));
				inline constexpr REL::ID ObjectAddRef(static_cast<std::uint64_t>(82269));
				inline constexpr REL::ID ObjectRelease(static_cast<std::uint64_t>(82270));
				inline constexpr REL::ID PushBack(static_cast<std::uint64_t>(82273));
				inline constexpr REL::ID RemoveElements(static_cast<std::uint64_t>(82280));
				inline constexpr REL::ID SetArraySize(static_cast<std::uint64_t>(82285));
				inline constexpr REL::ID SetDisplayInfo(static_cast<std::uint64_t>(82287));
				inline constexpr REL::ID SetDisplayMatrix(static_cast<std::uint64_t>(82288));
				inline constexpr REL::ID SetCxform(static_cast<std::uint64_t>(82286));
				inline constexpr REL::ID SetElement(static_cast<std::uint64_t>(82289));
				inline constexpr REL::ID SetMember(static_cast<std::uint64_t>(82292));
				inline constexpr REL::ID SetText(static_cast<std::uint64_t>(82293));
				inline constexpr REL::ID VisitMembers(static_cast<std::uint64_t>(82302));
			}
		}

		namespace GiftMenu
		{
			inline constexpr REL::ID TargetRefHandle(static_cast<std::uint64_t>(406111));
		}

		namespace GMemory
		{
			inline constexpr REL::ID GlobalHeap(static_cast<std::uint64_t>(412058));
		}

		namespace GString
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(82562));
		}

		namespace GSysAllocPaged
		{
			inline constexpr REL::ID InitHeapEngine(static_cast<std::uint64_t>(84557));
			inline constexpr REL::ID ShutdownHeapEngine(static_cast<std::uint64_t>(84559));
		}

		namespace HandlerDictionary
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(404607));
		}

		namespace HitData
		{
			inline constexpr REL::ID Populate(static_cast<std::uint64_t>(44001));
		}

		namespace hkContainerHeapAllocator
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(383828));
		}

		namespace hkpWorld
		{
			inline constexpr REL::ID CastRay(static_cast<std::uintptr_t>(61399));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::ID AddReference(static_cast<std::uint64_t>(57010));
			inline constexpr REL::ID RemoveReference(static_cast<std::uint64_t>(57011));
		}

		namespace IFormFactory
		{
			inline constexpr REL::ID FormFactories(static_cast<std::uint64_t>(400508));
			inline constexpr REL::ID FormFactoriesInitialized(static_cast<std::uint64_t>(400503));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(410219));
		}

		namespace INISetting
		{
			namespace Interface
			{
				inline constexpr REL::ID fSafeZoneX(static_cast<std::uint64_t>(389575));
				inline constexpr REL::ID fSafeZoneY(static_cast<std::uint64_t>(389578));
				inline constexpr REL::ID fSafeZoneXWide(static_cast<std::uint64_t>(389569));
				inline constexpr REL::ID fSafeZoneYWide(static_cast<std::uint64_t>(389572));
			}
		}

		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(411155));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400446));
		}

		namespace Inventory
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(16225));
		}

		namespace Inventory3DManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403559));
			inline constexpr REL::ID UpdateItem3D(static_cast<std::uint64_t>(51757));
			inline constexpr REL::ID UpdateMagic3D(static_cast<std::uint64_t>(51758));
			inline constexpr REL::ID Clear3D(static_cast<std::uint64_t>(51759));
			inline constexpr REL::ID Render(static_cast<std::uint64_t>(51755));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::ID GetArmorInSlot(static_cast<std::uint64_t>(16113));
			inline constexpr REL::ID GetNextUniqueID(static_cast<std::uint64_t>(16148));
			inline constexpr REL::ID SendContainerChangedEvent(static_cast<std::uint64_t>(16149));
			inline constexpr REL::ID SetUniqueID(static_cast<std::uint64_t>(16149));
			inline constexpr REL::ID TransferItemUID(static_cast<std::uint64_t>(16149));
			inline constexpr REL::ID InitFromContainerExtra(static_cast<std::uint64_t>(16130));
			inline constexpr REL::ID InitLeveledItems(static_cast<std::uint64_t>(16129));
			inline constexpr REL::ID InitScripts(static_cast<std::uint64_t>(16068));
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(16050));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(16051));
		}

		namespace InventoryEntryData
		{
			inline constexpr REL::ID GetValue(static_cast<std::uint64_t>(15995));
			inline constexpr REL::ID IsQuestObject(static_cast<std::uint64_t>(16005));
			inline constexpr REL::ID IsOwnedBy(static_cast<std::uint64_t>(16020));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(51403));
		}

		namespace ItemList
		{
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(51031));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(51183));
		}

		namespace JournalMenu
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(216685));
		}

		namespace JumpHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208731));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(16325));
			inline constexpr REL::ID SetNorthRotation(static_cast<std::uint64_t>(16330));
		}

		namespace LockpickingMenu
		{
			inline constexpr REL::ID TargetReference(static_cast<std::uint64_t>(406271));
		}

		namespace LookHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208710));
		}

		namespace LooseFileStream
		{
			//inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(0));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403337));
		}

		namespace MagicItem
		{
			inline constexpr REL::ID CalculateCost(static_cast<std::uint64_t>(11321));
			inline constexpr REL::ID GetCostliestEffectItem(static_cast<std::uint64_t>(11335));
		}

		namespace MagicTarget
		{
			inline constexpr REL::ID HasMagicEffect(static_cast<std::uint64_t>(34517));
		}

		namespace Main
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403449));
			inline constexpr REL::ID QFrameAnimTime(static_cast<std::uint64_t>(403447));
		}

		namespace MemoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(11141));
			inline constexpr REL::ID Allocate(static_cast<std::uint64_t>(68115));
			inline constexpr REL::ID Deallocate(static_cast<std::uint64_t>(68117));
			inline constexpr REL::ID GetThreadScrapHeap(static_cast<std::uint64_t>(68088));
			inline constexpr REL::ID Reallocate(static_cast<std::uint64_t>(68116));
			inline constexpr REL::ID RegisterMemoryManager(static_cast<std::uint64_t>(36091));
		}

		namespace MenuControls
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401263));
		}

		namespace MenuCursor
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403551));
		}

		namespace MenuOpenHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(215783));
		}

		namespace MenuTopicManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(401099));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(52875));
		}

		namespace MovementHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208715));
		}

		namespace NiAVObject
		{
			inline constexpr REL::ID SetMotionType(static_cast<std::uint64_t>(77866));
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(70251));
		}

		namespace NiCamera
		{
			inline constexpr REL::ID WorldPtToScreenPt3(static_cast<std::uint64_t>(70640));
		}

		namespace NiMemManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(410319));
		}

		namespace NiNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(70287));
		}

		namespace NiObject
		{
			inline constexpr REL::ID ProcessClone(static_cast<std::uint64_t>(70190));
			inline constexpr REL::ID CreateDeepCopy(static_cast<std::uint64_t>(70191));
		}

		namespace NiPoint3
		{
			inline constexpr REL::ID Zero(static_cast<std::uint64_t>(410468));
		}

		namespace NiRefObject
		{
			inline constexpr REL::ID TotalObjectCount(static_cast<std::uint64_t>(410493));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(71227));
		}

		namespace NiTimeController
		{
			inline constexpr REL::ID LoadBinary(static_cast<std::uint64_t>(70810));
			inline constexpr REL::ID LinkObject(static_cast<std::uint64_t>(70811));
			inline constexpr REL::ID RegisterStreamables(static_cast<std::uint64_t>(70812));
			inline constexpr REL::ID SaveBinary(static_cast<std::uint64_t>(70813));
			inline constexpr REL::ID IsEqual(static_cast<std::uint64_t>(70814));
			inline constexpr REL::ID ProcessClone(static_cast<std::uint64_t>(70826));
			inline constexpr REL::ID Start(static_cast<std::uint64_t>(70817));
			inline constexpr REL::ID Stop(static_cast<std::uint64_t>(70818));
			inline constexpr REL::ID SetTarget(static_cast<std::uint64_t>(70819));
			inline constexpr REL::ID ComputeScaledTime(static_cast<std::uint64_t>(70824));
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(70815));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(70816));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400802));
			inline constexpr REL::ID UpdateThirdPerson(static_cast<std::uint64_t>(50841));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::ID AdvanceLevel(static_cast<std::uint64_t>(41567));
			}

			inline constexpr REL::ID ActivatePickRef(static_cast<std::uint64_t>(40548));
			inline constexpr REL::ID AddPlayerAddItemEvent(static_cast<std::uint64_t>(40456));
			inline constexpr REL::ID AttemptPickpocket(static_cast<std::uint64_t>(40654));
			inline constexpr REL::ID GetArmorValue(static_cast<std::uint64_t>(40249));
			inline constexpr REL::ID GetDamage(static_cast<std::uint64_t>(40253));
			inline constexpr REL::ID GetNumTints(static_cast<std::uint64_t>(40700));
			inline constexpr REL::ID GetTintMask(static_cast<std::uint64_t>(40698));
			inline constexpr REL::ID PlayPickupEvent(static_cast<std::uint64_t>(40456));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403521));
			inline constexpr REL::ID StartGrabObject(static_cast<std::uint64_t>(40552));
			inline constexpr REL::ID CenterOnCell(static_cast<std::uintptr_t>(40437));
			inline constexpr REL::ID AddSkillExperience(static_cast<std::uintptr_t>(40488));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208040));
		}

		namespace PlayerControls
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(42336));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400864));
		}

		namespace ProcessLists
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400315));
			inline constexpr REL::ID ClearCachedFactionFightReactions(static_cast<std::uint64_t>(41410));
			inline constexpr REL::ID StopCombatAndAlarmOnActor(static_cast<std::uint64_t>(41340));
		}

		namespace RaceSexMenu
		{
			inline constexpr REL::ID ChangeName(static_cast<std::uint64_t>(52415));
		}

		namespace ReadyWeaponHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208721));
		}

		namespace ReferenceEffectController
		{
			inline constexpr REL::ID Start(static_cast<std::uint64_t>(34761));
		}

		namespace ResponseDictionary
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403902));
		}

		namespace RunHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208729));
		}

		namespace ScrapHeap
		{
			inline constexpr REL::ID Allocate(static_cast<std::uint64_t>(68144));
			inline constexpr REL::ID Deallocate(static_cast<std::uint64_t>(68146));
		}

		namespace Script
		{
			inline constexpr REL::ID CompileAndRun(static_cast<std::uint64_t>(441582));
			inline constexpr REL::ID GetProcessScripts(static_cast<std::uint64_t>(21921));
			inline constexpr REL::ID SetProcessScripts(static_cast<std::uint64_t>(21920));
		}

		namespace ScriptEventSourceHolder
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(14298));
			inline constexpr REL::ID SendOpenCloseEvent(static_cast<std::uint64_t>(14299));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::ID FirstConsoleCommand(static_cast<std::uint64_t>(365650));
			inline constexpr REL::ID FirstScriptCommand(static_cast<std::uint64_t>(361120));
		}

		namespace ShoutHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208735));
		}

		namespace Sky
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13878));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::ID QueuePostRenderCall(static_cast<std::uint64_t>(53955));
			inline constexpr REL::ID RelayEvent(static_cast<std::uint64_t>(54033));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400475));
		}

		namespace SneakHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208733));
		}

		namespace SprintHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208717));
		}

		namespace TaskQueueInterface
		{
			inline constexpr REL::ID Attach3D(static_cast<std::uint64_t>(36897));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403759));
		}

		namespace TES
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403450));
		}

		namespace TESCamera
		{
			inline constexpr REL::ID SetState(static_cast<std::uint64_t>(33026));
		}

		namespace TESCondition
		{
			inline constexpr REL::ID IsTrue(static_cast<std::uint64_t>(29888));
		}

		namespace TESConditionItem
		{
			inline constexpr REL::ID IsTrue(static_cast<std::uint64_t>(29924));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::ID LoadScripts(static_cast<std::uint64_t>(13766));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400269));
		}

		namespace TESDescription
		{
			inline constexpr REL::ID GetDescription(static_cast<std::uint64_t>(14552));
		}

		namespace TESFaction
		{
			inline constexpr REL::ID SetFactionFightReaction(static_cast<std::uint64_t>(24516));
		}

		namespace TESFile
		{
			inline constexpr REL::ID Duplicate(static_cast<std::uint64_t>(14018));
			inline constexpr REL::ID GetCurrentSubRecordType(static_cast<std::uint64_t>(13988));
			inline constexpr REL::ID GetFormType(static_cast<std::uint64_t>(13982));
			inline constexpr REL::ID ReadData(static_cast<std::uint64_t>(13991));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(13984));
			inline constexpr REL::ID SeekNextSubrecord(static_cast<std::uint64_t>(13990));
		}

		namespace TESForm
		{
			inline constexpr REL::ID AddCompileIndex(static_cast<std::uint64_t>(14667));
			inline constexpr REL::ID AllForms(static_cast<std::uint64_t>(400507));
			inline constexpr REL::ID AllFormsMapLock(static_cast<std::uint64_t>(400517));
			inline constexpr REL::ID AllFormsByEditorID(static_cast<std::uint64_t>(400509));
			inline constexpr REL::ID AllFormsEditorIDMapLock(static_cast<std::uint64_t>(400518));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::ID FindCollidableRef(static_cast<std::uint64_t>(26003));
		}

		namespace TESNPC
		{
			inline constexpr REL::ID ChangeHeadPart(static_cast<std::uint64_t>(24750));
			inline constexpr REL::ID GetBaseOverlays(static_cast<std::uint64_t>(24791));
			inline constexpr REL::ID GetNumBaseOverlays(static_cast<std::uint64_t>(24792));
			inline constexpr REL::ID HasOverlays(static_cast<std::uint64_t>(24790));
			inline constexpr REL::ID SetSkinFromTint(static_cast<std::uint64_t>(24710));
			inline constexpr REL::ID UpdateNeck(static_cast<std::uint64_t>(24711));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(195816));
		}

		namespace TESObjectACTI
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(189485));
		}

		namespace TESObjectCELL
		{
			inline constexpr REL::ID GetbhkWorld(static_cast<std::uint64_t>(18995));
		}

		namespace TESObjectCONT
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(189633));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::ID ApplyArtObject(static_cast<std::uint64_t>(22769));
			inline constexpr REL::ID ApplyEffectShader(static_cast<std::uint64_t>(19872));
			inline constexpr REL::ID FindReferenceFor3D(static_cast<std::uint64_t>(19750));
			inline constexpr REL::ID GetCurrentLocation(static_cast<std::uint64_t>(19812));
			inline constexpr REL::ID GetDisplayFullName(static_cast<std::uint64_t>(19781));
			inline constexpr REL::ID GetLock(static_cast<std::uint64_t>(20223));
			inline constexpr REL::ID GetOwner(static_cast<std::uint64_t>(20194));
			inline constexpr REL::ID GetStealValue(static_cast<std::uint64_t>(16045));
			inline constexpr REL::ID GetWeightInContainer(static_cast<std::uint64_t>(19703));
			inline constexpr REL::ID HasQuestObject(static_cast<std::uint64_t>(19627));
			inline constexpr REL::ID InitChildActivates(static_cast<std::uint64_t>(20264));
			inline constexpr REL::ID InitInventoryIfRequired(static_cast<std::uint64_t>(16038));
			inline constexpr REL::ID IsAnOwner(static_cast<std::uint64_t>(20210));
			inline constexpr REL::ID IsCrimeToActivate(static_cast<std::uint64_t>(19827));
			inline constexpr REL::ID MakeInventoryChanges(static_cast<std::uint64_t>(16040));
			inline constexpr REL::ID MoveTo(static_cast<std::uint64_t>(56626));
			inline constexpr REL::ID PlayAnimation(static_cast<std::uint64_t>(14297));
		}

		namespace TESQuest
		{
			inline constexpr REL::ID EnsureQuestStarted(static_cast<std::uint64_t>(25003));
			inline constexpr REL::ID ResetQuest(static_cast<std::uint64_t>(25014));
		}

		namespace TESTopicInfo
		{
			namespace ResponseData
			{
				inline constexpr REL::ID PopulateResponseText(static_cast<std::uint64_t>(25491));
			}
		}

		namespace ThirdPersonState
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(205236));
		}

		namespace TogglePOVHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208737));
		}

		namespace ToggleRunHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(208727));
		}

		namespace UI
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400327));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::ID DecrementBlurCount(static_cast<std::uint64_t>(52777));
			inline constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(52776));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(403350));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::ID AddMessage(static_cast<std::uint64_t>(13631));
			inline constexpr REL::ID CreateUIMessageData(static_cast<std::uint64_t>(82169));
			inline constexpr REL::ID ProcessCommands(static_cast<std::uint64_t>(82167));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(400445));
		}

		namespace UserEvents
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(402638));
		}

		inline constexpr REL::ID CreateRefHandle(static_cast<std::uint64_t>(12326));
		inline constexpr REL::ID DebugNotification(static_cast<std::uint64_t>(52933));
		inline constexpr REL::ID GetArmorFinalRating(static_cast<std::uint64_t>(16017));
		inline constexpr REL::ID GlobalStateCounter(static_cast<std::uint64_t>(400305));
		inline constexpr REL::ID LogDirectory(static_cast<std::uint64_t>(380738));
		inline constexpr REL::ID LookupReferenceByHandle(static_cast<std::uint64_t>(12332));
		inline constexpr REL::ID PlaySound(static_cast<std::uint64_t>(52939));
		inline constexpr REL::ID RTDynamicCast(static_cast<std::uint64_t>(109689));
		inline constexpr REL::ID TlsIndex(static_cast<std::uint64_t>(415542));
#else
		namespace _CRT
		{
			inline constexpr REL::ID RTDynamicCast(static_cast<std::uint64_t>(102238));
		}

		namespace ActivateHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263060));
		}

		namespace ActiveEffect
		{
			inline constexpr REL::ID Dispel(static_cast<std::uint64_t>(33286));
		}

		namespace Actor
		{
			inline constexpr REL::ID AddSpell(static_cast<std::uint64_t>(37771));
			inline constexpr REL::ID RemoveSpell(static_cast<std::uint64_t>(37772));
			inline constexpr REL::ID DispelWornItemEnchantments(static_cast<std::uint64_t>(33828));
			inline constexpr REL::ID DoReset3D(static_cast<std::uint64_t>(39181));
			inline constexpr REL::ID EvaluatePackage(static_cast<std::uint64_t>(36407));
			inline constexpr REL::ID GetGhost(static_cast<std::uint64_t>(36286));
			inline constexpr REL::ID GetHostileToActor(static_cast<std::uint64_t>(36537));
			inline constexpr REL::ID GetLevel(static_cast<std::uint64_t>(36344));
			inline constexpr REL::ID HasPerk(static_cast<std::uint64_t>(36690));
			inline constexpr REL::ID InterruptCast(static_cast<std::uint64_t>(37808));
			inline constexpr REL::ID IsRunning(static_cast<std::uint64_t>(36252));
			inline constexpr REL::ID RequestDetectionLevel(static_cast<std::uint64_t>(36748));
			inline constexpr REL::ID StealAlarm(static_cast<std::uint64_t>(36427));
			inline constexpr REL::ID SwitchRace(static_cast<std::uint64_t>(36901));
			inline constexpr REL::ID UpdateArmorAbility(static_cast<std::uint64_t>(37802));
			inline constexpr REL::ID UpdateWeaponAbility(static_cast<std::uint64_t>(37803));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::ID EquipObject(static_cast<std::uint64_t>(37938));
			inline constexpr REL::ID EquipShout(static_cast<std::uint64_t>(37941));
			inline constexpr REL::ID EquipSpell(static_cast<std::uint64_t>(37939));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514494));
			inline constexpr REL::ID UnequipObject(static_cast<std::uint64_t>(37945));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::ID GetClampedActorValue(static_cast<std::uint64_t>(26616));
		}

		namespace AIProcess
		{
			inline constexpr REL::ID SetBaseScale(static_cast<std::uint64_t>(38568));
			inline constexpr REL::ID Update3DModel(static_cast<std::uint64_t>(38404));
		}

		namespace AttackBlockHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263058));
		}

		namespace AutoMoveHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263061));
		}

		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(10878));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(517045));
		}

		namespace BGSListForm
		{
			inline constexpr REL::ID AddForm(static_cast<std::uint64_t>(20470));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::ID Save(static_cast<std::uint64_t>(34818));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516860));
			inline constexpr REL::ID Load(static_cast<std::uint64_t>(34819));
		}

		namespace BGSSkillPerkTreeNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(26592));
		}

		namespace BGSStoryEventManager
		{
			inline constexpr REL::ID AddEvent(static_cast<std::uint64_t>(31576));
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(22317));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::ID BeginShutDownQuest(static_cast<std::uint64_t>(31718));
			inline constexpr REL::ID BeginStartUpQuest(static_cast<std::uint64_t>(31717));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514316));
		}

		namespace BipedAnim
		{
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15491));
			inline constexpr REL::ID RemoveAllParts(static_cast<std::uint64_t>(15494));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(66391));
			inline constexpr REL::ID BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(66404));
		}

		namespace BSFixedString
		{
			inline constexpr REL::ID Ctor8(static_cast<std::uint64_t>(67819));
			inline constexpr REL::ID Ctor16(static_cast<std::uint64_t>(67834));
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516574));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::ID CreateMaterial(static_cast<std::uint64_t>(100016));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::ID LockForRead(static_cast<std::uint64_t>(66976));
			inline constexpr REL::ID LockForWrite(static_cast<std::uint64_t>(66977));
			inline constexpr REL::ID UnlockForRead(static_cast<std::uint64_t>(66982));
			inline constexpr REL::ID UnlockForWrite(static_cast<std::uint64_t>(66983));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(69636));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(69638));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(69640));
			inline constexpr REL::ID SetEndianSwap(static_cast<std::uint64_t>(69643));
		}

		namespace BSScaleformManager
		{
			inline constexpr REL::ID LoadMovie(static_cast<std::uint64_t>(80302));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516573));
		}

		namespace BSScaleformTranslator
		{
			inline constexpr REL::ID GetCachedString(static_cast<std::uint64_t>(67844));
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(291278));
		}

		namespace BSScript
		{
			namespace Object
			{
				inline constexpr REL::ID GetHandle(static_cast<std::uint64_t>(97463));
				inline constexpr REL::ID IncRef(static_cast<std::uint64_t>(97468));
				inline constexpr REL::ID DecRef(static_cast<std::uint64_t>(97469));
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(97462));
			}

			namespace ObjectBindPolicy
			{
				inline constexpr REL::ID BindObject(static_cast<std::uint64_t>(97379));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Call(static_cast<std::uint64_t>(97923));
				}
			}

			namespace Stack
			{
				inline constexpr REL::ID GetStackFrameVariable(static_cast<std::uint64_t>(97746));
				inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(97742));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::ID IsValid(static_cast<std::uint64_t>(66360));
			inline constexpr REL::ID Play(static_cast<std::uint64_t>(66355));
			inline constexpr REL::ID SetObjectToFollow(static_cast<std::uint64_t>(66375));
			inline constexpr REL::ID SetPosition(static_cast<std::uint64_t>(66370));
			inline constexpr REL::ID Pause(static_cast<std::uint64_t>(66357));
			inline constexpr REL::ID Stop(static_cast<std::uint64_t>(66358));
		}

		namespace BSString
		{
			inline constexpr REL::ID Set_CStr(static_cast<std::uint64_t>(10979));
		}

		namespace BSStringPool
		{
			inline constexpr REL::ID Release8(static_cast<std::uint64_t>(67847));
			inline constexpr REL::ID Release16(static_cast<std::uint64_t>(67848));
		}

		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(67855));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(101884));
		}

		namespace Calendar
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514287));
		}

		namespace ChestsLooted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50257));
		}

		namespace Console
		{
			inline constexpr REL::ID SelectedRef(static_cast<std::uint64_t>(519394));
			inline constexpr REL::ID SetSelectedRef(static_cast<std::uint64_t>(50164));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(515064));
			inline constexpr REL::ID VPrint(static_cast<std::uint64_t>(50180));
		}

		namespace ControlMap
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514705));
		}

		namespace CraftingSubMenus
		{
			namespace EnchantConstructMenu
			{
				inline constexpr REL::ID RenameItem(static_cast<std::uint64_t>(50530));
				inline constexpr REL::ID UpdateInterface(static_cast<std::uint64_t>(50567));
			}
		}

		namespace CRC32Calculator
		{
			inline constexpr REL::ID SizeOf32(static_cast<std::uint64_t>(66963));
			inline constexpr REL::ID SizeOf64(static_cast<std::uint64_t>(66964));
			inline constexpr REL::ID SizeOfSize(static_cast<std::uint64_t>(66962));
		}

		namespace DialogueItem
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(34413));
		}

		namespace ExtraAliasInstanceArray
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229615));
		}

		namespace ExtraAshPileRef
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229561));
		}

		namespace ExtraCannotWear
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229540));
		}

		namespace ExtraCanTalkToPlayer
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229596));
		}

		namespace ExtraCharge
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229544));
		}

		namespace ExtraContainerChanges
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229886));
		}

		namespace ExtraCount
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229537));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::ID Add(static_cast<std::uint64_t>(12176));
			inline constexpr REL::ID SetCount(static_cast<std::uint64_t>(11471));
			inline constexpr REL::ID SetExtraFlags(static_cast<std::uint64_t>(11903));
			inline constexpr REL::ID SetInventoryChanges(static_cast<std::uint64_t>(11483));
		}

		namespace ExtraEnchantment
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229574));
		}

		namespace ExtraForcedTarget
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229629));
		}

		namespace ExtraHealth
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229541));
		}

		namespace ExtraHotkey
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229547));
		}

		namespace ExtraLightData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229618));
		}

		namespace ExtraOwnership
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229534));
		}

		namespace ExtraPoison
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229573));
		}

		namespace ExtraRank
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229536));
		}

		namespace ExtraReferenceHandle
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229549));
		}

		namespace ExtraSoul
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229890));
		}

		namespace ExtraTextDisplayData
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229625));
		}

		namespace ExtraUniqueID
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(229631));
		}

		namespace FavoritesHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(269539));
		}

		namespace FavoritesMenu
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(268638));
		}

		namespace FirstPersonState
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(267810));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514622));
		}

		namespace GASActionBufferData
		{
			inline constexpr std::uint64_t Vtbl(0x17BC3F0);
		}

		namespace GASDoAction
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(291613));
		}

		namespace GASDoInitAction
		{
			inline constexpr std::uint64_t Vtbl(0x17BCA00);
		}

		namespace GFxInitImportActions
		{
			inline constexpr std::uint64_t Vtbl(0x17DC4C8);
		}

		namespace GFxLoader
		{
			inline constexpr REL::ID CreateMovie(static_cast<std::uint64_t>(80620));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::ID InvokeNoReturn(static_cast<std::uint64_t>(80547));
		}

		namespace GFxPlaceObject2
		{
			inline constexpr std::uint64_t Vtbl(0x17BE0E0);
		}

		namespace GFxPlaceObject3
		{
			inline constexpr std::uint64_t Vtbl(0x17BE138);
		}

		namespace GFxRemoveObject
		{
			inline constexpr std::uint64_t Vtbl(0x17DC408);
		}

		namespace GFxRemoveObject2
		{
			inline constexpr std::uint64_t Vtbl(0x17DC448);
		}

		namespace GFxSetBackgroundColor
		{
			inline constexpr std::uint64_t Vtbl(0x17DC488);
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::ID AttachMovie(static_cast<std::uint64_t>(80197));
				inline constexpr REL::ID DeleteMember(static_cast<std::uint64_t>(80207));
				inline constexpr REL::ID GetArraySize(static_cast<std::uint64_t>(80214));
				inline constexpr REL::ID GetCxform(static_cast<std::uint64_t>(80215));
				inline constexpr REL::ID GetDisplayInfo(static_cast<std::uint64_t>(80216));
				inline constexpr REL::ID GetDisplayMatrix(static_cast<std::uint64_t>(80217));
				inline constexpr REL::ID GetElement(static_cast<std::uint64_t>(80218));
				inline constexpr REL::ID GetMember(static_cast<std::uint64_t>(80222));
				inline constexpr REL::ID GotoAndPlay(static_cast<std::uint64_t>(80230));
				inline constexpr REL::ID HasMember(static_cast<std::uint64_t>(80231));
				inline constexpr REL::ID Invoke(static_cast<std::uint64_t>(80233));
				inline constexpr REL::ID ObjectAddRef(static_cast<std::uint64_t>(80244));
				inline constexpr REL::ID ObjectRelease(static_cast<std::uint64_t>(80245));
				inline constexpr REL::ID PushBack(static_cast<std::uint64_t>(80248));
				inline constexpr REL::ID RemoveElements(static_cast<std::uint64_t>(80252));
				inline constexpr REL::ID SetArraySize(static_cast<std::uint64_t>(80261));
				inline constexpr REL::ID SetCxform(static_cast<std::uint64_t>(80262));
				inline constexpr REL::ID SetDisplayInfo(static_cast<std::uint64_t>(80263));
				inline constexpr REL::ID SetDisplayMatrix(static_cast<std::uint64_t>(80264));
				inline constexpr REL::ID SetElement(static_cast<std::uint64_t>(80265));
				inline constexpr REL::ID SetMember(static_cast<std::uint64_t>(80268));
				inline constexpr REL::ID SetText(static_cast<std::uint64_t>(80270));
				inline constexpr REL::ID VisitMembers(static_cast<std::uint64_t>(80279));
			}
		}

		namespace GMemory
		{
			inline constexpr REL::ID GlobalHeap(static_cast<std::uint64_t>(525584));
		}

		namespace GString
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(80446));
		}

		namespace hkContainerHeapAllocator
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(510713));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::ID AddReference(static_cast<std::uint64_t>(56606));
			inline constexpr REL::ID RemoveReference(static_cast<std::uint64_t>(56607));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(523673));
		}

		namespace INISettingCollection
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(524557));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514286));
		}

		namespace Inventory
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(15980));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(15812));
			inline constexpr REL::ID Dtor(static_cast<std::uint64_t>(15813));
			inline constexpr REL::ID GetNextUniqueID(static_cast<std::uint64_t>(15908));
			inline constexpr REL::ID SendContainerChangedEvent(static_cast<std::uint64_t>(15909));
			inline constexpr REL::ID SetUniqueID(static_cast<std::uint64_t>(15907));
			inline constexpr REL::ID TransferItemUID(static_cast<std::uint64_t>(15909));
		}

		namespace InventoryEntryData
		{
			inline constexpr REL::ID GetValue(static_cast<std::uint64_t>(15757));
			inline constexpr REL::ID IsOwnedBy(static_cast<std::uint64_t>(15782));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50515));
		}

		namespace ItemList
		{
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(50099));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::ID GetEventSource(static_cast<std::uint64_t>(50258));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(16084));
			inline constexpr REL::ID SetNorthRotation(static_cast<std::uint64_t>(16089));
		}

		namespace LooseFileStream
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(68663));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516858));
		}

		namespace MagicItem
		{
			inline constexpr REL::ID CalculateCost(static_cast<std::uint64_t>(11213));
			inline constexpr REL::ID GetCostliestEffectItem(static_cast<std::uint64_t>(11216));
		}

		namespace MagicTarget
		{
			inline constexpr REL::ID HasMagicEffect(static_cast<std::uint64_t>(33733));
		}

		namespace Main
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516943));
		}

		namespace MemoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(11045));
			inline constexpr REL::ID Allocate(static_cast<std::uint64_t>(66859));
			inline constexpr REL::ID Deallocate(static_cast<std::uint64_t>(66861));
			inline constexpr REL::ID GetThreadScrapHeap(static_cast<std::uint64_t>(66841));
			inline constexpr REL::ID Reallocate(static_cast<std::uint64_t>(66860));
			inline constexpr REL::ID RegisterMemoryManager(static_cast<std::uint64_t>(35199));
		}

		namespace MenuControls
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(515124));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(22843));
		}

		namespace NiAVObject
		{
			inline constexpr REL::ID SetMotionType(static_cast<std::uint64_t>(76033));
			inline constexpr REL::ID Update(static_cast<std::uint64_t>(68900));
		}

		namespace NiCamera
		{
			inline constexpr REL::ID WorldPtToScreenPt3(static_cast<std::uint64_t>(69270));
		}

		namespace NiMemManager
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(523759));
		}

		namespace NiNode
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(68936));
		}

		namespace NiObject
		{
			inline constexpr REL::ID CreateDeepCopy(static_cast<std::uint64_t>(68839));
		}

		namespace NiPoint3
		{
			inline constexpr REL::ID Zero(static_cast<std::uint64_t>(523887));
		}

		namespace NiRefObject
		{
			inline constexpr REL::ID TotalObjectCount(static_cast<std::uint64_t>(523912));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(69804));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514642));
			inline constexpr REL::ID UpdateThirdPerson(static_cast<std::uint64_t>(49908));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::ID AdvanceLevel(static_cast<std::uint64_t>(40560));
			}

			inline constexpr REL::ID ActivatePickRef(static_cast<std::uint64_t>(39471));
			inline constexpr REL::ID GetArmorValue(static_cast<std::uint64_t>(39175));
			inline constexpr REL::ID GetDamage(static_cast<std::uint64_t>(39179));
			inline constexpr REL::ID GetNumTints(static_cast<std::uint64_t>(39614));
			inline constexpr REL::ID GetTintMask(static_cast<std::uint64_t>(39612));
			inline constexpr REL::ID PlayPickupEvent(static_cast<std::uint64_t>(39384));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(517014));
			inline constexpr REL::ID StartGrabObject(static_cast<std::uint64_t>(39475));
		}

		namespace PlayerControls
		{
			inline constexpr REL::ID Ctor(static_cast<std::uint64_t>(41257));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514706));
		}

		namespace RaceSexMenu
		{
			inline constexpr REL::ID ChangeName(static_cast<std::uint64_t>(51540));
		}

		namespace ReferenceEffectController
		{
			inline constexpr REL::ID Start(static_cast<std::uint64_t>(33961));
		}

		namespace ReadyWeaponHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263059));
		}

		namespace RunHandler
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(263063));
		}

		namespace ScrapHeap
		{
			inline constexpr REL::ID Allocate(static_cast<std::uint64_t>(66884));
			inline constexpr REL::ID Deallocate(static_cast<std::uint64_t>(66885));
		}

		namespace Script
		{
			inline constexpr REL::ID CompileAndRun(static_cast<std::uint64_t>(21416));
			inline constexpr REL::ID GetProcessScripts(static_cast<std::uint64_t>(21436));
			inline constexpr REL::ID SetProcessScripts(static_cast<std::uint64_t>(21435));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::ID FirstConsoleCommand(static_cast<std::uint64_t>(501797));
			inline constexpr REL::ID FirstScriptCommand(static_cast<std::uint64_t>(501789));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::ID QueuePostRenderCall(static_cast<std::uint64_t>(53144));
			inline constexpr REL::ID RelayEvent(static_cast<std::uint64_t>(53221));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514315));
		}

		namespace TES
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516923));
		}

		namespace TESCamera
		{
			inline constexpr REL::ID SetState(static_cast<std::uint64_t>(32290));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::ID LoadScripts(static_cast<std::uint64_t>(13657));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514141));
		}

		namespace TESDescription
		{
			inline constexpr REL::ID GetDescription(static_cast<std::uint64_t>(14399));
		}

		namespace TESFile
		{
			inline constexpr REL::ID Duplicate(static_cast<std::uint64_t>(13923));
			inline constexpr REL::ID GetCurrentSubRecordType(static_cast<std::uint64_t>(13902));
			inline constexpr REL::ID GetFormType(static_cast<std::uint64_t>(13897));
			inline constexpr REL::ID ReadData(static_cast<std::uint64_t>(13904));
			inline constexpr REL::ID Seek(static_cast<std::uint64_t>(13898));
			inline constexpr REL::ID SeekNextSubrecord(static_cast<std::uint64_t>(13903));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::ID FindCollidableRef(static_cast<std::uint64_t>(25466));
		}

		namespace TESNPC
		{
			inline constexpr REL::ID ChangeHeadPart(static_cast<std::uint64_t>(24246));
			inline constexpr REL::ID GetBaseOverlays(static_cast<std::uint64_t>(24275));
			inline constexpr REL::ID GetNumBaseOverlays(static_cast<std::uint64_t>(24276));
			inline constexpr REL::ID HasOverlays(static_cast<std::uint64_t>(24274));
			inline constexpr REL::ID SetSkinFromTint(static_cast<std::uint64_t>(24206));
			inline constexpr REL::ID UpdateNeck(static_cast<std::uint64_t>(24207));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::ID FindReferenceFor3D(static_cast<std::uint64_t>(19323));
			inline constexpr REL::ID GetDisplayFullName(static_cast<std::uint64_t>(19354));
			inline constexpr REL::ID GetLock(static_cast<std::uint64_t>(19818));
			inline constexpr REL::ID GetOwner(static_cast<std::uint64_t>(19789));
			inline constexpr REL::ID GetStealValue(static_cast<std::uint64_t>(15807));
			inline constexpr REL::ID InitInventoryIfRequired(static_cast<std::uint64_t>(15800));
			inline constexpr REL::ID MoveTo(static_cast<std::uint64_t>(56227));
			inline constexpr REL::ID PlayAnimation(static_cast<std::uint64_t>(14189));
		}

		namespace TESQuest
		{
			inline constexpr REL::ID EnsureQuestStarted(static_cast<std::uint64_t>(24481));
			inline constexpr REL::ID ResetQuest(static_cast<std::uint64_t>(24486));
		}

		namespace UI
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514178));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::ID DecrementBlurCount(static_cast<std::uint64_t>(51900));
			inline constexpr REL::ID IncrementBlurCount(static_cast<std::uint64_t>(51899));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516871));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::ID AddMessage(static_cast<std::uint64_t>(13530));
			inline constexpr REL::ID CreateUIMessageData(static_cast<std::uint64_t>(80061));
			inline constexpr REL::ID ProcessCommands(static_cast<std::uint64_t>(80059));
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(514285));
		}

		namespace UserEvents
		{
			inline constexpr REL::ID Singleton(static_cast<std::uint64_t>(516458));
		}

		inline constexpr REL::ID CreateRefHandle(static_cast<std::uint64_t>(12193));
		inline constexpr REL::ID DebugNotification(static_cast<std::uint64_t>(52050));
		inline constexpr REL::ID LookupReferenceByHandle(static_cast<std::uint64_t>(12204));
		inline constexpr REL::ID PlaySound(static_cast<std::uint64_t>(52054));
		inline constexpr REL::ID TlsIndex(static_cast<std::uint64_t>(528600));
		inline constexpr REL::ID GlobalStateCounter(static_cast<std::uint64_t>(514157));
#endif
	}
}
