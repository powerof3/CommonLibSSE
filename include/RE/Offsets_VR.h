#pragma once

namespace RE
{
	namespace Offset
	{
		namespace ActivateHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F22E8));
		}

		namespace ActiveEffect
		{
			inline constexpr REL::Offset Dispel(static_cast<std::uint64_t>(0x541100));
		}

		namespace Actor
		{
			inline constexpr REL::Offset AddSpell(static_cast<std::uint64_t>(0x638430));
			inline constexpr REL::Offset RemoveSpell(static_cast<std::uint64_t>(0x6385F0));
			inline constexpr REL::Offset DispelWornItemEnchantments(static_cast<std::uint64_t>(0x55CCB0));
			inline constexpr REL::Offset DoReset3D(static_cast<std::uint64_t>(0x69C710));
			inline constexpr REL::Offset EvaluatePackage(static_cast<std::uint64_t>(0x5E3990));
			inline constexpr REL::Offset GetGhost(static_cast<std::uint64_t>(0x5DAAE0));
			inline constexpr REL::Offset GetHostileToActor(static_cast<std::uint64_t>(0x5F0560));
			inline constexpr REL::Offset GetLevel(static_cast<std::uint64_t>(0x5DE910));
			inline constexpr REL::Offset HasPerk(static_cast<std::uint64_t>(0x6025A0));
			inline constexpr REL::Offset InterruptCast(static_cast<std::uint64_t>(0x63AB50));
			inline constexpr REL::Offset IsRunning(static_cast<std::uint64_t>(0x5D9770));
			inline constexpr REL::Offset RequestDetectionLevel(static_cast<std::uint64_t>(0x605190));
			inline constexpr REL::Offset StealAlarm(static_cast<std::uint64_t>(0x5E5DC0));
			inline constexpr REL::Offset SwitchRace(static_cast<std::uint64_t>(0x610000));
			inline constexpr REL::Offset UpdateArmorAbility(static_cast<std::uint64_t>(0x63A230));
			inline constexpr REL::Offset UpdateWeaponAbility(static_cast<std::uint64_t>(0x63A2A0));
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16CE888));
		}

		namespace ActorEquipManager
		{
			inline constexpr REL::Offset EquipObject(static_cast<std::uint64_t>(0x640A90));
			inline constexpr REL::Offset EquipShout(static_cast<std::uint64_t>(0x6556848));
			inline constexpr REL::Offset EquipSpell(static_cast<std::uint64_t>(0x6556624));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F896D8));
			inline constexpr REL::Offset UnequipObject(static_cast<std::uint64_t>(0x6411A0));
		}

		namespace ActorValueOwner
		{
			inline constexpr REL::Offset GetArmorRatingSkillMultiplier(static_cast<std::uint64_t>(0x3CE200));
			inline constexpr REL::Offset GetClampedActorValue(static_cast<std::uint64_t>(0x3F4DA0));
		}

		namespace AIFormulas
		{
			inline constexpr REL::Offset ComputePickpocketSuccess(static_cast<std::uint64_t>(0x3CCD90));
		}

		namespace AIProcess
		{
			inline constexpr REL::Offset SetBaseScale(static_cast<std::uint64_t>(0x665BD0));
			inline constexpr REL::Offset Update3DModel(static_cast<std::uint64_t>(0x65A140));
		}

		namespace ArmorRatingVisitor
		{
			inline constexpr REL::Offset HaveNotVisitedArmor(static_cast<std::uint64_t>(0x69DAA0));
			inline constexpr REL::Offset VisitArmor(static_cast<std::uint64_t>(0x69DA00));
		}

		namespace ArmorRatingVisitorBase
		{
			inline constexpr REL::Offset Visit(static_cast<std::uint64_t>(0x69DB00));
		}

		namespace AttackBlockHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2258));
		}

		namespace AutoMoveHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2338));
		}

		namespace BarterMenu
		{
			inline constexpr REL::Offset TargetRefHandle(static_cast<std::uint64_t>(0x3011184));
		}

		namespace BookMenu
		{
			inline constexpr REL::Offset TargetReference(static_cast<std::uint64_t>(0x3011228));
		}

		namespace BGSAddToPlayerInventoryEvent
		{
			inline constexpr REL::Offset GetIndex(static_cast<std::uint64_t>(0x1DED188));
		}

		namespace BGSCreatedObjectManager
		{
			inline constexpr REL::Offset CreateArmorEnchantment(static_cast<std::uint64_t>(0x5A6850));
			inline constexpr REL::Offset CreateWeaponEnchantment(static_cast<std::uint64_t>(0x5A67B0));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F831C8));
		}

		namespace BGSDefaultObjectManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x1077C0));
		}

		namespace BGSEntryPoint
		{
			inline constexpr REL::Offset EntryPoints(static_cast<std::uint64_t>(0x1E90190));
			inline constexpr REL::Offset HandleEntryPoint(static_cast<std::uint64_t>(0x33E5A0));
		}

		namespace BGSEntryPointFunction
		{
			inline constexpr REL::Offset EntryPointFunctions(static_cast<std::uint64_t>(0x1E90D10));
			inline constexpr REL::Offset EntryPointFunctionTypeArgumentCount(static_cast<std::uint64_t>(0x1E90E90));
		}

		namespace BGSFootstepManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEBC50));
		}

		namespace BGSListForm
		{
			inline constexpr REL::Offset AddForm(static_cast<std::uint64_t>(0x2D6B40));
		}

		namespace BGSOpenCloseForm
		{
			inline constexpr REL::Offset GetOpenState(static_cast<std::uint64_t>(0x199480));
			inline constexpr REL::Offset SetOpenState(static_cast<std::uint64_t>(0x199220));
		}

		namespace BSResource
		{
			namespace LooseFileLocation
			{
				inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15B8FB8));
			}

			inline constexpr REL::Offset RegisterGlobalPath(static_cast<std::uint64_t>(0xC89AB0));
			inline constexpr REL::Offset RegisterLocation(static_cast<std::uint64_t>(0xC89960));
		}

		namespace BGSSaveLoadManager
		{
			inline constexpr REL::Offset Save(static_cast<std::uint64_t>(0x58E310));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB248));
			inline constexpr REL::Offset Load(static_cast<std::uint64_t>(0x58E920));
		}

		namespace BGSSkillPerkTreeNode
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x3F4420));
		}

		namespace BGSStoryEventManager
		{
			inline constexpr REL::Offset AddEvent(static_cast<std::uint64_t>(0x4E0860));
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x321C30));
		}

		namespace BGSStoryTeller
		{
			inline constexpr REL::Offset BeginShutDownQuest(static_cast<std::uint64_t>(0x4E8240));
			inline constexpr REL::Offset BeginStartUpQuest(static_cast<std::uint64_t>(0x4E8120));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F889E0));
		}

		namespace BipedAnim
		{
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x1D6200));
			inline constexpr REL::Offset RemoveAllParts(static_cast<std::uint64_t>(0x1D6530));
		}

		namespace BSAudioManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0xC29430));
			inline constexpr REL::Offset BuildSoundDataFromDescriptor(static_cast<std::uint64_t>(0xC29F60));
		}

		namespace BSFaceGenAnimationData
		{
			inline constexpr REL::Offset Reset(static_cast<std::uint64_t>(0x3D3160));
			inline constexpr REL::Offset SetExpressionOverride(static_cast<std::uint64_t>(0x3D3780));
		}

		namespace BSFixedString
		{
			inline constexpr REL::Offset Ctor8(static_cast<std::uint64_t>(0xC6DB20));
			inline constexpr REL::Offset Ctor_Copy(static_cast<std::uint64_t>(0xC6DBB0));
			inline constexpr REL::Offset Set_CStr(static_cast<std::uint64_t>(0xC6DC90));
			inline constexpr REL::Offset Set_Copy(static_cast<std::uint64_t>(0xC6DD50));
			inline constexpr REL::Offset Dtor8(static_cast<std::uint64_t>(0xC6DC70));
			inline constexpr REL::Offset Ctor16(static_cast<std::uint64_t>(0xC6E440));
			inline constexpr REL::Offset Dtor16(static_cast<std::uint64_t>(0xC6E550));
		}

		namespace BSGraphics
		{
			namespace State
			{
				inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x3186C10));
			}
		}

		namespace BSInputEventQueue
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x30A8BB8));
		}

		namespace BSMusicManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F8ABB0));
		}

		namespace BSInputDeviceManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEA520));
		}

		namespace BSLightingShaderMaterialBase
		{
			inline constexpr REL::Offset CreateMaterial(static_cast<std::uint64_t>(0x130EAD0));
		}

		namespace BSOpenVR
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB9B0));
		}

		namespace BSPointerHandleManager
		{
			inline constexpr REL::Offset HandleEntries(static_cast<std::uint64_t>(0x1F89660));
		}

		namespace BSPointerHandleManagerInterface
		{
			inline constexpr REL::Offset GetHandle(static_cast<std::uint64_t>(0x1FF150));
			inline constexpr REL::Offset GetSmartPointer(static_cast<std::uint64_t>(0x143180));
		}

		namespace BSReadWriteLock
		{
			inline constexpr REL::Offset LockForRead(static_cast<std::uint64_t>(0xC42150));
			inline constexpr REL::Offset LockForWrite(static_cast<std::uint64_t>(0xC421D0));
			inline constexpr REL::Offset UnlockForRead(static_cast<std::uint64_t>(0xC42410));
			inline constexpr REL::Offset UnlockForWrite(static_cast<std::uint64_t>(0xC42420));
		}

		namespace BSResourceNiBinaryStream
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xCBC490));
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0xCBC770));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(0xCBC8C0));
			inline constexpr REL::Offset SetEndianSwap(static_cast<std::uint64_t>(0xCBC9B0));
		}

		namespace BSScaleformExternalTexture
		{
			inline constexpr REL::Offset LoadPNG(static_cast<std::uint64_t>(0xF2AD00));
			inline constexpr REL::Offset ReleaseTexture(static_cast<std::uint64_t>(0xF2ABD0));
			inline constexpr REL::Offset SetTexture(static_cast<std::uint64_t>(0xF2AC40));
		}

		namespace BSScaleformImageLoader
		{
			inline constexpr REL::Offset AddTexture(static_cast<std::uint64_t>(0xFA2050));
			inline constexpr REL::Offset RemoveTexture(static_cast<std::uint64_t>(0xFA2520));
		}

		namespace BSScaleformManager
		{
			inline constexpr REL::Offset FileExists(static_cast<std::uint64_t>(0xF20EF0));
			inline constexpr REL::Offset IsValidName(static_cast<std::uint64_t>(0xF2BB20));
			inline constexpr REL::Offset LoadMovie(static_cast<std::uint64_t>(0xF2B480));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEA518));
		}

		namespace BSScaleformTranslator
		{
			inline constexpr REL::ID     GetCachedString(static_cast<std::uint64_t>(67844));
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x1866FA0));
		}

		namespace BSScript
		{
			namespace Object
			{
				inline constexpr REL::Offset GetHandle(static_cast<std::uint64_t>(0x126BBD0));
				inline constexpr REL::Offset IncRef(static_cast<std::uint64_t>(0x126C810));
				inline constexpr REL::Offset DecRef(static_cast<std::uint64_t>(0x126C8C0));
				inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x126BB20));
			}

			namespace ObjectTypeInfo
			{
				inline constexpr REL::Offset ReleaseData(static_cast<std::uint64_t>(0x1270B80));
			}

			namespace ObjectBindPolicy
			{
				inline constexpr REL::Offset BindObject(static_cast<std::uint64_t>(0x1265F80));
			}

			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::Offset Call(static_cast<std::uint64_t>(0x129DD90));
				}
			}

			namespace Stack
			{
				inline constexpr REL::Offset GetStackFrameVariable(static_cast<std::uint64_t>(0x129A720));
				inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x129A210));
			}
		}

		namespace BSSoundHandle
		{
			inline constexpr REL::Offset IsValid(static_cast<std::uint64_t>(0xC28540));
			inline constexpr REL::Offset Play(static_cast<std::uint64_t>(0xC283E0));
			inline constexpr REL::Offset SetObjectToFollow(static_cast<std::uint64_t>(0xC289C0));
			inline constexpr REL::Offset SetPosition(static_cast<std::uint64_t>(0xC287D0));
			inline constexpr REL::Offset Pause(static_cast<std::uint64_t>(0xC28470));
			inline constexpr REL::Offset Stop(static_cast<std::uint64_t>(0xC284B0));
		}

		namespace BSString
		{
			inline constexpr REL::Offset Set_CStr(static_cast<std::uint64_t>(0x10A440));
		}

		namespace BSStringPool
		{
			inline constexpr REL::Offset Release8(static_cast<std::uint64_t>(0xC6EDB0));
			inline constexpr REL::Offset Release16(static_cast<std::uint64_t>(0xC6EF20));
		}

		namespace BSThreadEvent
		{
			inline constexpr REL::Offset InitSDM(static_cast<std::uint64_t>(0xC485E0));
		}

		namespace BSUntypedPointerHandle
		{
			inline constexpr REL::Offset NullHandle(static_cast<std::uint64_t>(0x1F8319C));
		}

		namespace BSWin32SaveDataSystemUtility
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x137C200));
		}

		namespace BucketTable
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0xC6F400));
		}

		namespace Calendar
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F85108));
			inline constexpr REL::Offset GetTimeDateString(static_cast<std::uint64_t>(0x5ADD00));
		}

		namespace ChestsLooted
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x88D4E0));
		}

		namespace Console
		{
			inline constexpr REL::Offset SelectedRef(static_cast<std::uint64_t>(0x30115FC));
			inline constexpr REL::Offset SetSelectedRef(static_cast<std::uint64_t>(0x8864D0));
		}

		namespace ConsoleLog
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC4FE0));
			inline constexpr REL::Offset VPrint(static_cast<std::uint64_t>(0x886DF0));
		}

		namespace ContainerMenu
		{
			inline constexpr REL::Offset ContainerMode(static_cast<std::uint64_t>(0x3011720));
			inline constexpr REL::Offset TargetRefHandle(static_cast<std::uint64_t>(0x30117E8));
		}

		namespace ControlMap
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F8AAA0));
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
			inline constexpr REL::Offset SizeOf32(static_cast<std::uint64_t>(0xC41370));
			inline constexpr REL::Offset SizeOf64(static_cast<std::uint64_t>(0xC413F0));
			inline constexpr REL::Offset SizeOfSize(static_cast<std::uint64_t>(0xC41310));
		}

		namespace DialogueItem
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x572FD0));
		}

		namespace ExtraAliasInstanceArray
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3CF0));
		}

		namespace ExtraAshPileRef
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3630));
		}

		namespace ExtraCannotWear
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3390));
		}

		namespace ExtraCanTalkToPlayer
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3A90));
		}

		namespace ExtraCharge
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3410));
		}

		namespace ExtraContainerChanges
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A65D0));
		}

		namespace ExtraCount
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3330));
		}

		namespace ExtraDataList
		{
			inline constexpr REL::Offset Add(static_cast<std::uint64_t>(0x142140));
			inline constexpr REL::ID     SetCount(static_cast<std::uint64_t>(11471));
			inline constexpr REL::Offset SetExtraFlags(static_cast<std::uint64_t>(0x136360));
			inline constexpr REL::Offset SetInventoryChanges(static_cast<std::uint64_t>(0x11FBA0));
		}

		namespace ExtraEnchantment
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A37D0));
		}

		namespace ExtraForcedTarget
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3EB0));
		}

		namespace ExtraHealth
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A33B0));
		}

		namespace ExtraHotkey
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3470));
		}

		namespace ExtraLightData
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3D50));
		}

		namespace ExtraLock
		{
			inline constexpr REL::Offset GetLockLevel(static_cast<std::uint64_t>(0x145380));
		}

		namespace ExtraOwnership
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A32D0));
		}

		namespace ExtraPoison
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A37B0));
		}

		namespace ExtraRank
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3310));
		}

		namespace ExtraReferenceHandle
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A34B0));
		}

		namespace ExtraSoul
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A6650));
		}

		namespace ExtraTextDisplayData
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3E30));
			inline constexpr REL::Offset GetDisplayName(static_cast<std::uint64_t>(0x14D130));
		}

		namespace ExtraUniqueID
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15A3EF0));
		}

		namespace FavoritesHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x173C9C0));
		}

		namespace FavoritesMenu
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x1734F50));
		}

		namespace FirstPersonState
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x172CEB0));
		}

		namespace GameSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F8A780));
		}

		namespace GASActionBufferData
		{
			inline constexpr std::uint64_t Vtbl(0x186c990);
		}

		namespace GASDoAction
		{
			inline constexpr REL::ID Vtbl(static_cast<std::uint64_t>(291613));
		}

		namespace GASDoInitAction
		{
			inline constexpr std::uint64_t Vtbl(0x186cfa0);
		}

		namespace GFxInitImportActions
		{
			inline constexpr std::uint64_t Vtbl(0x188c9a8);
		}

		namespace GFxLoader
		{
			inline constexpr REL::Offset CreateMovie(static_cast<std::uint64_t>(0xF38CA0));
		}

		namespace GFxMovieView
		{
			inline constexpr REL::Offset InvokeNoReturn(static_cast<std::uint64_t>(0xF30F20));
		}

		namespace GFxPlaceObject2
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x186E680));
		}

		namespace GFxPlaceObject3
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x186E6D8));
		}

		namespace GFxRemoveObject
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x188C9A8));
		}

		namespace GFxRemoveObject2
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x188C9E8));
		}

		namespace GFxSetBackgroundColor
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x188CA28));
		}

		namespace GFxValue
		{
			namespace ObjectInterface
			{
				inline constexpr REL::Offset AttachMovie(static_cast<std::uint64_t>(0xF24EF0));
				inline constexpr REL::Offset DeleteMember(static_cast<std::uint64_t>(0xF25FE0));
				inline constexpr REL::Offset GetArraySize(static_cast<std::uint64_t>(0xF26720));
				inline constexpr REL::ID     GetCxform(static_cast<std::uint64_t>(80215));
				inline constexpr REL::Offset GetDisplayInfo(static_cast<std::uint64_t>(0xF26770));
				inline constexpr REL::ID     GetDisplayMatrix(static_cast<std::uint64_t>(80217));
				inline constexpr REL::Offset GetElement(static_cast<std::uint64_t>(0xF26A80));
				inline constexpr REL::Offset GetMember(static_cast<std::uint64_t>(0xF26CA0));
				inline constexpr REL::Offset GotoAndPlay(static_cast<std::uint64_t>(0xF270C0));
				inline constexpr REL::Offset HasMember(static_cast<std::uint64_t>(0xF27170));
				inline constexpr REL::Offset Invoke(static_cast<std::uint64_t>(0xF273B0));
				inline constexpr REL::Offset ObjectAddRef(static_cast<std::uint64_t>(0xF27BD0));
				inline constexpr REL::Offset ObjectRelease(static_cast<std::uint64_t>(0xF27C30));
				inline constexpr REL::Offset PushBack(static_cast<std::uint64_t>(0xF27E50));
				inline constexpr REL::Offset RemoveElements(static_cast<std::uint64_t>(0xF28210));
				inline constexpr REL::Offset SetArraySize(static_cast<std::uint64_t>(0xF28870));
				inline constexpr REL::ID     SetCxform(static_cast<std::uint64_t>(80262));
				inline constexpr REL::Offset SetDisplayInfo(static_cast<std::uint64_t>(0xF28900));
				inline constexpr REL::ID     SetDisplayMatrix(static_cast<std::uint64_t>(80264));
				inline constexpr REL::Offset SetElement(static_cast<std::uint64_t>(0xF294B0));
				inline constexpr REL::Offset SetMember(static_cast<std::uint64_t>(0xF296F0));
				inline constexpr REL::Offset SetText(static_cast<std::uint64_t>(0xF29840));
				inline constexpr REL::ID     VisitMembers(static_cast<std::uint64_t>(80279));
			}
		}

		namespace GiftMenu
		{
			inline constexpr REL::Offset TargetRefHandle(static_cast<std::uint64_t>(0x3011CE8));
		}

		namespace GlobalLookupInfo
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F88B10));
		}

		namespace GMemory
		{
			inline constexpr REL::Offset GlobalHeap(static_cast<std::uint64_t>(0x318CE40));
		}

		namespace GString
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xF2DA40));
		}

		namespace GSysAllocPaged
		{
			inline constexpr REL::Offset InitHeapEngine(static_cast<std::uint64_t>(0xFA4F70));
			inline constexpr REL::Offset ShutdownHeapEngine(static_cast<std::uint64_t>(0xFA5060));
		}

		namespace HandlerDictionary
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x300D6A0));
		}

		namespace HitData
		{
			inline constexpr REL::Offset Populate(static_cast<std::uint64_t>(0x76D400));
		}

		namespace hkContainerHeapAllocator
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1EB59C8));
		}

		namespace hkpWorld
		{
			inline constexpr REL::Offset CastRay(static_cast<std::uint64_t>(0xAB5A00));
		}

		namespace hkReferencedObject
		{
			inline constexpr REL::Offset AddReference(static_cast<std::uint64_t>(0xA01280));
			inline constexpr REL::Offset RemoveReference(static_cast<std::uint64_t>(0xA01340));
		}

		namespace IFormFactory
		{
			inline constexpr REL::Offset FormFactories(static_cast<std::uint64_t>(0x1F88B40));
			inline constexpr REL::Offset FormFactoriesInitialized(static_cast<std::uint64_t>(0x1F88B13));
		}

		namespace INIPrefSettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x30C3B18));
		}

		namespace INISetting
		{
			namespace Interface
			{
				inline constexpr REL::Offset fSafeZoneX(static_cast<std::uint64_t>(0x1ECFB28));
				inline constexpr REL::Offset fSafeZoneY(static_cast<std::uint64_t>(0x1ECFB40));
				inline constexpr REL::Offset fSafeZoneXWide(static_cast<std::uint64_t>(0x1ECFAF8));
				inline constexpr REL::Offset fSafeZoneYWide(static_cast<std::uint64_t>(0x1ECFB10));
			}
		}

		namespace INISettingCollection
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x3175FE0));
		}

		namespace InterfaceStrings
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F85100));
		}

		namespace Inventory
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x1FFE10));
		}

		namespace Inventory3DManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEBC80));
			inline constexpr REL::Offset UpdateItem3D(static_cast<std::uint64_t>(0x8B4EA0));
			inline constexpr REL::Offset UpdateMagic3D(static_cast<std::uint64_t>(0x8B4ED0));
			inline constexpr REL::Offset Clear3D(static_cast<std::uint64_t>(0x8B5240));
			inline constexpr REL::Offset Render(static_cast<std::uint64_t>(0x8B4C90));
		}

		namespace InventoryChanges
		{
			inline constexpr REL::Offset GenerateLeveledListChanges(static_cast<std::uint64_t>(0x1F1470));
			inline constexpr REL::Offset GetNextUniqueID(static_cast<std::uint64_t>(0x1FD8A0));
			inline constexpr REL::Offset InitFromContainerExtra(static_cast<std::uint64_t>(0x1FAB90));
			inline constexpr REL::Offset InitLeveledItems(static_cast<std::uint64_t>(0x1FA900));
			inline constexpr REL::Offset InitScripts(static_cast<std::uint64_t>(0x1F1470));
			inline constexpr REL::Offset SendContainerChangedEvent(static_cast<std::uint64_t>(0x1FD990));
			inline constexpr REL::Offset SetUniqueID(static_cast<std::uint64_t>(0x1FD7D0));
			inline constexpr REL::Offset TransferItemUID(static_cast<std::uint64_t>(0x1FD990));
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x1E9DA0));
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0x1E9E90));
		}

		namespace InventoryEntryData
		{
			inline constexpr REL::Offset GetValue(static_cast<std::uint64_t>(0x1E7280));
			inline constexpr REL::Offset IsQuestObject(static_cast<std::uint64_t>(0x1E7740));
			inline constexpr REL::Offset IsOwnedBy(static_cast<std::uint64_t>(0x1E8130));
		}

		namespace ItemCrafted
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x89BE30));
		}

		namespace ItemList
		{
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(0x880E10));
		}

		namespace ItemsPickpocketed
		{
			inline constexpr REL::Offset GetEventSource(static_cast<std::uint64_t>(0x88D5D0));
		}

		namespace JournalMenu
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x174E278));
		}

		namespace JumpHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2408));
		}

		namespace LocalMapCamera
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x205EF0));
			inline constexpr REL::Offset SetNorthRotation(static_cast<std::uint64_t>(0x2062B0));
		}

		namespace LockpickingMenu
		{
			inline constexpr REL::Offset TargetReference(static_cast<std::uint64_t>(0x3013728));
		}

		namespace LookHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2070));
		}

		namespace LooseFileStream
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xC90A40));
		}

		namespace MagicFavorites
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB238));
		}

		namespace MagicItem
		{
			inline constexpr REL::Offset CalculateCost(static_cast<std::uint64_t>(0x111FE0));
			inline constexpr REL::Offset GetCostliestEffectItem(static_cast<std::uint64_t>(0x112270));
			inline constexpr REL::ID     GetAVEffectSetting(static_cast<std::uint64_t>(11194));
		}

		namespace MagicTarget
		{
			inline constexpr REL::Offset HasMagicEffect(static_cast<std::uint64_t>(0x557380));
		}

		namespace Main
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB7A0));
			inline constexpr REL::Offset QFrameAnimTime(static_cast<std::uint64_t>(0x2FEB794));
		}

		namespace MemoryManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x10D590));
			inline constexpr REL::Offset Allocate(static_cast<std::uint64_t>(0xC3D0E0));
			inline constexpr REL::Offset Deallocate(static_cast<std::uint64_t>(0xC3D3E0));
			inline constexpr REL::Offset GetThreadScrapHeap(static_cast<std::uint64_t>(0xC3C680));
			inline constexpr REL::Offset Reallocate(static_cast<std::uint64_t>(0xC3D330));
			inline constexpr REL::Offset RegisterMemoryManager(static_cast<std::uint64_t>(0x5A2800));
		}

		namespace MenuControls
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC52E8));
		}

		namespace MenuCursor
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEBC40));
		}

		namespace MenuOpenHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x173C970));
		}

		namespace MenuTopicManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FC4878));
		}

		namespace MessageDataFactoryManager
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x335CA0));
		}

		namespace MovementHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F21C8));
		}

		namespace NiAVObject
		{
			inline constexpr REL::Offset SetMotionType(static_cast<std::uint64_t>(0xDFD160));
			inline constexpr REL::Offset Update(static_cast<std::uint64_t>(0xC9BC10));
		}

		namespace NiCamera
		{
			inline constexpr REL::Offset WorldPtToScreenPt3(static_cast<std::uint64_t>(0xCAC0E0));
		}

		namespace NiMemManager
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x30CF888));
		}

		namespace NiNode
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xC9CCD0));
		}

		namespace NiObject
		{
			inline constexpr REL::Offset ProcessClone(static_cast<std::uint64_t>(0xC979C0));
			inline constexpr REL::Offset CreateDeepCopy(static_cast<std::uint64_t>(0xC97A60));
		}

		namespace NiPoint3
		{
			inline constexpr REL::ID Zero(static_cast<std::uint64_t>(523887));
		}

		namespace NiRefObject
		{
			inline constexpr REL::Offset TotalObjectCount(static_cast<std::uint64_t>(0x316AD20));
		}

		namespace NiSkinInstance
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xCC5250));
		}

		namespace NiTimeController
		{
			inline constexpr REL::Offset LoadBinary(static_cast<std::uint64_t>(0xCB2EE0));
			inline constexpr REL::Offset LinkObject(static_cast<std::uint64_t>(0xCB3030));
			inline constexpr REL::Offset RegisterStreamables(static_cast<std::uint64_t>(0xCB30A0));
			inline constexpr REL::Offset SaveBinary(static_cast<std::uint64_t>(0xCB30F0));
			inline constexpr REL::Offset IsEqual(static_cast<std::uint64_t>(0xCB3250));
			inline constexpr REL::Offset ProcessClone(static_cast<std::uint64_t>(0xCB39A0));
			inline constexpr REL::Offset Start(static_cast<std::uint64_t>(0xCB33C0));
			inline constexpr REL::Offset Stop(static_cast<std::uint64_t>(0xCB33E0));
			inline constexpr REL::Offset SetTarget(static_cast<std::uint64_t>(0xCB3410));
			inline constexpr REL::Offset ComputeScaledTime(static_cast<std::uint64_t>(0xCB3770));
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0xCB32E0));
			inline constexpr REL::Offset Dtor(static_cast<std::uint64_t>(0xCB3360));
		}

		namespace PlayerCamera
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F8A888));
			inline constexpr REL::Offset UpdateThirdPerson(static_cast<std::uint64_t>(0x877DB0));
		}

		namespace PlayerCharacter
		{
			namespace PlayerSkills
			{
				inline constexpr REL::Offset AdvanceLevel(static_cast<std::uint64_t>(0x70D630));
			}

			inline constexpr REL::Offset ActivatePickRef(static_cast<std::uint64_t>(0x6CBCE0));
			inline constexpr REL::Offset AddPlayerAddItemEvent(static_cast<std::uint64_t>(0x6C0640));
			inline constexpr REL::Offset AttemptPickpocket(static_cast<std::uint64_t>(0x6D58A0));
			inline constexpr REL::Offset GetArmorValue(static_cast<std::uint64_t>(0x69C2D0));
			inline constexpr REL::Offset GetDamage(static_cast<std::uint64_t>(0x69C650));
			inline constexpr REL::Offset GetNumTints(static_cast<std::uint64_t>(0x6D8730));
			inline constexpr REL::Offset GetPickpocketChance(static_cast<std::uint64_t>(0x3CCD90));
			inline constexpr REL::Offset GetTintMask(static_cast<std::uint64_t>(0x6D8580));
			inline constexpr REL::Offset PlayPickupEvent(static_cast<std::uint64_t>(0x6C0640));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB9F0));
			inline constexpr REL::Offset StartGrabObject(static_cast<std::uint64_t>(0x6CC000));
			inline constexpr REL::Offset CenterOnCell(static_cast<std::uint64_t>(0x6BC6C0));
			inline constexpr REL::Offset AddSkillExperience(static_cast<std::uint64_t>(0x6C30B0));
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16E2230));
		}

		namespace PlayerControls
		{
			inline constexpr REL::Offset Ctor(static_cast<std::uint64_t>(0x72B900));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2F8AAA8));
		}

		namespace ProcessLists
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F831B0));
			inline constexpr REL::Offset ClearCachedFactionFightReactions(static_cast<std::uint64_t>(0x705B00));
			inline constexpr REL::Offset StopCombatAndAlarmOnActor(static_cast<std::uint64_t>(0x700330));
		}

		namespace RaceSexMenu
		{
			inline constexpr REL::ID ChangeName(static_cast<std::uint64_t>(51540));
		}

		namespace ReadyWeaponHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F22A8));
		}

		namespace ReferenceEffectController
		{
			inline constexpr REL::ID Start(static_cast<std::uint64_t>(33961));
		}

		namespace REFR_LOCK
		{
			inline constexpr REL::Offset GetLockLevel(static_cast<std::uint64_t>(0x145380));
		}

		namespace ResponseDictionary
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FFE470));
		}

		namespace RunHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F23B8));
		}

		namespace ScrapHeap
		{
			inline constexpr REL::Offset Allocate(static_cast<std::uint64_t>(0xC3E320));
			inline constexpr REL::Offset Deallocate(static_cast<std::uint64_t>(0xC3E940));
		}

		namespace Script
		{
			inline constexpr REL::Offset CompileAndRun(static_cast<std::uint64_t>(0x2F8AF0));
		}

		namespace ScriptEventSourceHolder
		{
			inline constexpr REL::Offset GetSingleton(static_cast<std::uint64_t>(0x1964C0));
			inline constexpr REL::Offset SendActivateEvent(static_cast<std::uint64_t>(0x2B37E0));
			inline constexpr REL::Offset SendOpenCloseEvent(static_cast<std::uint64_t>(0x199CF0));
		}

		namespace SCRIPT_FUNCTION
		{
			inline constexpr REL::Offset FirstConsoleCommand(static_cast<std::uint64_t>(0x1E83FB0));
			inline constexpr REL::Offset FirstScriptCommand(static_cast<std::uint64_t>(0x1E75A00));
		}

		namespace ShoutHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2488));
		}

		namespace Sky
		{
			inline constexpr REL::ID GetSingleton(static_cast<std::uint64_t>(13789));
			inline constexpr REL::ID SetWeather(static_cast<std::uint64_t>(25694));
			inline constexpr REL::ID ForceWeather(static_cast<std::uint64_t>(25696));
			inline constexpr REL::ID ResetWeather(static_cast<std::uint64_t>(25695));
		}

		namespace SkyrimVM
		{
			inline constexpr REL::Offset QueuePostRenderCall(static_cast<std::uint64_t>(0x95FD10));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F889D8));
		}

		namespace SneakHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2448));
		}

		namespace SprintHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2208));
		}

		namespace TaskQueueInterface
		{
			inline constexpr REL::Offset Attach3D(static_cast<std::uint64_t>(0x5CAB50));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FFD778));
		}

		namespace TES
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB6F8));
		}

		namespace TESCamera
		{
			inline constexpr REL::Offset SetState(static_cast<std::uint64_t>(0x505F60));
		}

		namespace TESCondition
		{
			namespace Node
			{
				inline constexpr REL::Offset Run(static_cast<std::uint64_t>(0x455010));
			}

			inline constexpr REL::Offset IsTrue(static_cast<std::uint64_t>(0x4542F0));
			inline constexpr REL::Offset Run(static_cast<std::uint64_t>(0x4542F0));
		}

		namespace TESConditionItem
		{
			inline constexpr REL::Offset IsTrue(static_cast<std::uint64_t>(0x455010));
		}

		namespace TESDataHandler
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F82AD8));
			inline constexpr REL::Offset LoadScripts(static_cast<std::uint64_t>(0x181B80));
		}

		namespace TESDescription
		{
			inline constexpr REL::Offset GetDescription(static_cast<std::uint64_t>(0x1A01B0));
		}

		namespace TESFaction
		{
			inline constexpr REL::Offset SetFactionFightReaction(static_cast<std::uint64_t>(0x365200));
		}

		namespace TESFile
		{
			inline constexpr REL::Offset Duplicate(static_cast<std::uint64_t>(0x18E210));
			inline constexpr REL::Offset GetCurrentSubRecordType(static_cast<std::uint64_t>(0x18D6F0));
			inline constexpr REL::Offset GetFormType(static_cast<std::uint64_t>(0x18D2A0));
			inline constexpr REL::Offset ReadData(static_cast<std::uint64_t>(0x18D7F0));
			inline constexpr REL::Offset Seek(static_cast<std::uint64_t>(0x18D330));
			inline constexpr REL::Offset SeekNextSubrecord(static_cast<std::uint64_t>(0x18D740));
		}

		namespace TESForm
		{
			inline constexpr REL::Offset AddCompileIndex(static_cast<std::uint64_t>(0x001A5510));
			inline constexpr REL::Offset AllForms(static_cast<std::uint64_t>(0x01F88B18));
			inline constexpr REL::Offset AllFormsMapLock(static_cast<std::uint64_t>(0x01F88FB0));
			inline constexpr REL::Offset AllFormsByEditorID(static_cast<std::uint64_t>(0x01F88B20));
			inline constexpr REL::Offset AllFormsEditorIDMapLock(static_cast<std::uint64_t>(0x01F88FB8));
		}

		namespace TESHavokUtilities
		{
			inline constexpr REL::Offset FindCollidableRef(static_cast<std::uint64_t>(0x3B4940));
		}

		namespace TESNPC
		{
			inline constexpr REL::Offset ChangeHeadPart(static_cast<std::uint64_t>(0x375550));
			inline constexpr REL::Offset GetBaseOverlays(static_cast<std::uint64_t>(0x378490));
			inline constexpr REL::Offset GetNumBaseOverlays(static_cast<std::uint64_t>(0x378520));
			inline constexpr REL::Offset HasOverlays(static_cast<std::uint64_t>(0x378380));
			inline constexpr REL::Offset SetSkinFromTint(static_cast<std::uint64_t>(0x36FD80));
			inline constexpr REL::Offset UpdateNeck(static_cast<std::uint64_t>(0x36FFD0));
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x1616E60));
		}

		namespace TESObjectACTI
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15CF2C0));
		}

		namespace TESObjectCELL
		{
			inline constexpr REL::Offset GetbhkWorld(static_cast<std::uint64_t>(0x276A90));
		}

		namespace TESObjectCONT
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x15D1500));
		}

		namespace TESObjectREFR
		{
			inline constexpr REL::Offset ApplyArtObject(static_cast<std::uint64_t>(0x320EB0));
			inline constexpr REL::Offset ApplyEffectShader(static_cast<std::uint64_t>(0x2AE290));
			inline constexpr REL::Offset GetCurrentLocation(static_cast<std::uint64_t>(0x2AABF0));
			inline constexpr REL::Offset GetDisplayFullName(static_cast<std::uint64_t>(0x2A78F0));
			inline constexpr REL::Offset GetLock(static_cast<std::uint64_t>(0x2B8C30));
			inline constexpr REL::Offset GetOwner(static_cast<std::uint64_t>(0x2B7DE0));
			inline constexpr REL::Offset GetStealValue(static_cast<std::uint64_t>(0x1E9C20));
			inline constexpr REL::Offset GetWeightInContainer(static_cast<std::uint64_t>(0x29FAF0));
			inline constexpr REL::Offset HasQuestObject(static_cast<std::uint64_t>(0x29D070));
			inline constexpr REL::Offset InitChildActivates(static_cast<std::uint64_t>(0x2BA430));
			inline constexpr REL::Offset IsAnOwner(static_cast<std::uint64_t>(0x2B8650));
			inline constexpr REL::Offset FindReferenceFor3D(static_cast<std::uint64_t>(0x2A5CF0));
			inline constexpr REL::Offset InitInventoryIfRequired(static_cast<std::uint64_t>(0x1E98B0));
			inline constexpr REL::Offset IsCrimeToActivate(static_cast<std::uint64_t>(0x2ABA40));
			inline constexpr REL::Offset MakeInventoryChanges(static_cast<std::uint64_t>(0x1E99E0));
			inline constexpr REL::Offset MoveTo(static_cast<std::uint64_t>(0x9E90E0));
			inline constexpr REL::Offset PlayAnimation(static_cast<std::uint64_t>(0x199B60));
		}

		namespace TESQuest
		{
			inline constexpr REL::Offset EnsureQuestStarted(static_cast<std::uint64_t>(0x3802B0));
			inline constexpr REL::Offset ResetQuest(static_cast<std::uint64_t>(0x380830));
		}

		namespace TESTopicInfo
		{
			namespace ResponseData
			{
				inline constexpr REL::Offset PopulateResponseText(static_cast<std::uint64_t>(0x39D1C0));
			}
		}

		namespace ThirdPersonState
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16A57A0));
		}

		namespace TogglePOVHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F24C8));
		}

		namespace ToggleRunHandler
		{
			inline constexpr REL::Offset Vtbl(static_cast<std::uint64_t>(0x16F2378));
		}

		namespace UI
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F83200));
		}

		namespace UIBlurManager
		{
			inline constexpr REL::Offset DecrementBlurCount(static_cast<std::uint64_t>(0x902C50));
			inline constexpr REL::Offset IncrementBlurCount(static_cast<std::uint64_t>(0x902C10));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEB288));
		}

		namespace UIMessageQueue
		{
			inline constexpr REL::Offset AddMessage(static_cast<std::uint64_t>(0x175A10));
			inline constexpr REL::Offset CreateUIMessageData(static_cast<std::uint64_t>(0xF1FCA0));
			inline constexpr REL::Offset ProcessCommands(static_cast<std::uint64_t>(0xF1FBC0));
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x1F850F8));
		}

		namespace UserEvents
		{
			inline constexpr REL::Offset Singleton(static_cast<std::uint64_t>(0x2FEA140));
		}

		inline constexpr REL::Offset ApplyPerkEntries(static_cast<std::uint64_t>(0x33E5A0));
		inline constexpr REL::Offset CreateRefHandle(static_cast<std::uint64_t>(0x1428A0));
		inline constexpr REL::Offset DebugNotification(static_cast<std::uint64_t>(0x908170));
		inline constexpr REL::Offset GetArmorFinalRating(static_cast<std::uint64_t>(0x1E7ED0));
		inline constexpr REL::Offset LogDirectory(static_cast<std::uint64_t>(0x1EABD50));
		inline constexpr REL::Offset LookupReferenceByHandle(static_cast<std::uint64_t>(0x143180));
		inline constexpr REL::Offset PlaySound(static_cast<std::uint64_t>(0x90B1D0));
		inline constexpr REL::Offset RTDynamicCast(static_cast<std::uint64_t>(0x138BABA));
		inline constexpr REL::Offset TlsIndex(static_cast<std::uint64_t>(0x36F2F58));
		inline constexpr REL::ID     GlobalStateCounter(static_cast<std::uint64_t>(514157));
	}
}
