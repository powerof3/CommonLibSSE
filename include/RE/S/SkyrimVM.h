#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTFreeList.h"
#include "RE/B/BSTHashMap.h"
#include "RE/B/BSTMessageQueue.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/CompiledScriptLoader.h"
#include "RE/D/DelayFunctor.h"
#include "RE/F/FragmentSystem.h"
#include "RE/H/HandlePolicy.h"
#include "RE/I/IFreezeQuery.h"
#include "RE/I/IStackCallbackSaveInterface.h"
#include "RE/L/Logger.h"
#include "RE/P/Profiler.h"
#include "RE/S/SavePatcher.h"
#include "RE/S/SimpleAllocMemoryPagePolicy.h"
#include "RE/S/SkyrimScriptObjectBindPolicy.h"
#include "RE/S/SkyrimScriptStore.h"

namespace RE
{
	namespace BSScript
	{
		class IFunctionArguments;
		class IVirtualMachine;
		class IVMDebugInterface;
		class IVMSaveLoadInterface;
		struct StatsEvent;
	}

	struct PositionPlayerEvent;
	struct TESActivateEvent;
	struct TESActiveEffectApplyRemoveEvent;
	struct TESActorLocationChangeEvent;
	struct TESBookReadEvent;
	struct TESCellAttachDetachEvent;
	struct TESCellFullyLoadedEvent;
	struct TESCombatEvent;
	struct TESContainerChangedEvent;
	struct TESDeathEvent;
	struct TESDestructionStageChangedEvent;
	struct TESEnterBleedoutEvent;
	struct TESEquipEvent;
	struct TESFastTravelEndEvent;
	struct TESFormDeleteEvent;
	struct TESFurnitureEvent;
	struct TESGrabReleaseEvent;
	struct TESHitEvent;
	struct TESInitScriptEvent;
	struct TESLoadGameEvent;
	struct TESLockChangedEvent;
	struct TESMagicEffectApplyEvent;
	struct TESMagicWardHitEvent;
	struct TESMoveAttachDetachEvent;
	struct TESObjectLoadedEvent;
	struct TESObjectREFRTranslationEvent;
	struct TESOpenCloseEvent;
	struct TESPackageEvent;
	struct TESPerkEntryRunEvent;
	struct TESPlayerBowShotEvent;
	struct TESQuestInitEvent;
	struct TESQuestStageEvent;
	struct TESResetEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESSceneActionEvent;
	struct TESSceneEvent;
	struct TESScenePhaseEvent;
	struct TESSellEvent;
	struct TESSleepStartEvent;
	struct TESSleepStopEvent;
	struct TESSpellCastEvent;
	struct TESSwitchRaceCompleteEvent;
	struct TESTopicInfoEvent;
	struct TESTrackedStatsEvent;
	struct TESTrapHitEvent;
	struct TESTriggerEnterEvent;
	struct TESTriggerEvent;
	struct TESTriggerLeaveEvent;
	struct TESUniqueIDChangeEvent;

	class SkyrimVM :
		public BSTSingletonSDM<SkyrimVM>,                      // 01A0
		public BSScript::IFreezeQuery,                         // 0000
		public BSScript::IStackCallbackSaveInterface,          // 0008
		public BSTEventSink<TESActivateEvent>,                 // 0010
		public BSTEventSink<TESActiveEffectApplyRemoveEvent>,  // 0018
		public BSTEventSink<TESActorLocationChangeEvent>,      // 0020
		public BSTEventSink<TESBookReadEvent>,                 // 0028
		public BSTEventSink<TESCellAttachDetachEvent>,         // 0030
		public BSTEventSink<TESCellFullyLoadedEvent>,          // 0038
		public BSTEventSink<TESCombatEvent>,                   // 0040
		public BSTEventSink<TESContainerChangedEvent>,         // 0048
		public BSTEventSink<TESDeathEvent>,                    // 0050
		public BSTEventSink<TESDestructionStageChangedEvent>,  // 0058
		public BSTEventSink<TESEnterBleedoutEvent>,            // 0060
		public BSTEventSink<TESEquipEvent>,                    // 0068
		public BSTEventSink<TESFormDeleteEvent>,               // 0070
		public BSTEventSink<TESFurnitureEvent>,                // 0078
		public BSTEventSink<TESGrabReleaseEvent>,              // 0080
		public BSTEventSink<TESHitEvent>,                      // 0088
		public BSTEventSink<TESInitScriptEvent>,               // 0090
		public BSTEventSink<TESLoadGameEvent>,                 // 0098
		public BSTEventSink<TESLockChangedEvent>,              // 00A0
		public BSTEventSink<TESMagicEffectApplyEvent>,         // 00A8
		public BSTEventSink<TESMagicWardHitEvent>,             // 00B0
		public BSTEventSink<TESMoveAttachDetachEvent>,         // 00B8
		public BSTEventSink<TESObjectLoadedEvent>,             // 00C0
		public BSTEventSink<TESObjectREFRTranslationEvent>,    // 00C8
		public BSTEventSink<TESOpenCloseEvent>,                // 00D0
		public BSTEventSink<TESPackageEvent>,                  // 00D8
		public BSTEventSink<TESPerkEntryRunEvent>,             // 00E0
		public BSTEventSink<TESQuestInitEvent>,                // 00E8
		public BSTEventSink<TESQuestStageEvent>,               // 00F0
		public BSTEventSink<TESResetEvent>,                    // 00F8
		public BSTEventSink<TESResolveNPCTemplatesEvent>,      // 0100
		public BSTEventSink<TESSceneEvent>,                    // 0108
		public BSTEventSink<TESSceneActionEvent>,              // 0110
		public BSTEventSink<TESScenePhaseEvent>,               // 0118
		public BSTEventSink<TESSellEvent>,                     // 0120
		public BSTEventSink<TESSleepStartEvent>,               // 0128
		public BSTEventSink<TESSleepStopEvent>,                // 0130
		public BSTEventSink<TESSpellCastEvent>,                // 0138
		public BSTEventSink<TESTopicInfoEvent>,                // 0140
		public BSTEventSink<TESTrackedStatsEvent>,             // 0148
		public BSTEventSink<TESTrapHitEvent>,                  // 0150
		public BSTEventSink<TESTriggerEvent>,                  // 0158
		public BSTEventSink<TESTriggerEnterEvent>,             // 0160
		public BSTEventSink<TESTriggerLeaveEvent>,             // 0168
		public BSTEventSink<TESUniqueIDChangeEvent>,           // 0170
		public BSTEventSink<TESSwitchRaceCompleteEvent>,       // 0178
		public BSTEventSink<TESPlayerBowShotEvent>,            // 0180
		public BSTEventSink<TESFastTravelEndEvent>,            // 0188
		public BSTEventSink<PositionPlayerEvent>,              // 0190
		public BSTEventSink<BSScript::StatsEvent>,             // 0198
		public BSTEventSource<BSScript::StatsEvent>            // 01A8
	{
	public:
		inline static constexpr auto RTTI = RTTI_SkyrimVM;
		inline static constexpr auto VTABLE = VTABLE_SkyrimVM;

		struct UpdateDataEvent : public BSIntrusiveRefCounted
		{
		public:
			enum class UpdateType : bool
			{
				kRepeat = 0,    // RegisterForUpdate/RegisterForUpdateGameTime
				kNoRepeat = 1,  // RegisterForSingleUpdate/RegisterForSingleUpdateGameTime
			};

			// members
			UpdateType    updateType;       // 04
			std::uint16_t pad06;            // 06
			std::uint32_t timeToSendEvent;  // 08 - updateTime + currentVMMenuMode/currentVMDaysPassed
			std::uint32_t updateTime;       // 0C
			VMHandle      handle;           // 10
		};
		static_assert(sizeof(UpdateDataEvent) == 0x18);

		struct WaitCall
		{
		public:
			// members
			std::uint32_t              timeToSendEvent;  // 00 - Same as UpdateDataEvent, updateTime is discarded
			VMStackID                  stackID;          // 04 - used for vm->ReturnFromLatent()
			BSScript::IVirtualMachine* vm;               // 08
		};
		static_assert(sizeof(WaitCall) == 0x10);

		struct LOSDataEvent : public BSIntrusiveRefCounted
		{
		public:
			enum class LOSEventType
			{
				kGain = 0,
				kLost,
				kBoth,
			};

			enum class PreviousLOS
			{
				kLOS = 1,
				kNoLOS = 2
			};

			// members
			std::uint32_t pad04;               // 04
			VMHandle      handle;              // 08
			FormID        akViewerFormID;      // 10
			FormID        akTargetFormID;      // 14
			LOSEventType  losEventType;        // 18
			PreviousLOS   lastLOSCheckResult;  // 1C - (2 - (akViewer::HasLOS(akTarget) != 0))
		};
		static_assert(sizeof(LOSDataEvent) == 0x20);

		struct InventoryEventFilterLists : public BSIntrusiveRefCounted
		{
			// members
			BSTSet<FormID> itemsForFiltering;      // 08
			BSTSet<FormID> itemListsForFiltering;  // 38
		};
		static_assert(sizeof(InventoryEventFilterLists) == 0x68);

		struct ISendEventFilter
		{
			virtual bool matchesFilter(VMHandle handle) = 0;
		};

		~SkyrimVM() override;  // 00

		static SkyrimVM* GetSingleton();

		bool QueuePostRenderCall(const BSTSmartPointer<SkyrimScript::DelayFunctor>& a_functor);
		void RelayEvent(VMHandle handle, BSFixedString* event, BSScript::IFunctionArguments* args, ISendEventFilter* optionalFilter);
		void SendAndRelayEvent(VMHandle handle, BSFixedString* event, BSScript::IFunctionArguments* args, ISendEventFilter* optionalFilter);

		// members
		BSTSmartPointer<BSScript::IVirtualMachine>                            impl;                         // 0200
		BSScript::IVMSaveLoadInterface*                                       saveLoadInterface;            // 0208
		BSScript::IVMDebugInterface*                                          debugInterface;               // 0210
		BSScript::SimpleAllocMemoryPagePolicy                                 memoryPagePolicy;             // 0218
		BSScript::CompiledScriptLoader                                        scriptLoader;                 // 0240
		SkyrimScript::Logger                                                  logger;                       // 0278
		SkyrimScript::HandlePolicy                                            handlePolicy;                 // 0328
		SkyrimScript::ObjectBindPolicy                                        objectBindPolicy;             // 0398
		BSTSmartPointer<SkyrimScript::Store>                                  scriptStore;                  // 0470
		SkyrimScript::FragmentSystem                                          fragmentSystem;               // 0478
		SkyrimScript::Profiler                                                profiler;                     // 0590
		SkyrimScript::SavePatcher                                             savePatcher;                  // 0670
		mutable BSSpinLock                                                    frozenLock;                   // 0678
		std::uint32_t                                                         isFrozen;                     // 0680
		mutable BSSpinLock                                                    currentVMTimeLock;            // 0684
		std::uint32_t                                                         currentVMTime;                // 068C
		std::uint32_t                                                         currentVMMenuModeTime;        // 0690
		std::uint32_t                                                         currentVMGameTime;            // 0694
		std::uint32_t                                                         currentVMDaysPassed;          // 0698 - Calender.GetDaysPassed() * 1000
		mutable BSSpinLock                                                    queuedWaitEventLock;          // 069C
		std::uint32_t                                                         pad06A4;                      // 06A4
		BSTArray<WaitCall>                                                    queuedWaitCalls;              // 06A8 - Utility.Wait() calls
		BSTArray<WaitCall>                                                    queuedWaitMenuModeCalls;      // 06C0 - Utility.WaitMenuMode() calls
		BSTArray<WaitCall>                                                    queuedWaitGameCalls;          // 06D8 - Utility.WaitGameTime() calls
		mutable BSSpinLock                                                    queuedLOSEventCheckLock;      // 06F0
		BSTArray<BSTSmartPointer<LOSDataEvent>>                               queuedLOSEventChecks;         // 06F8 - OnGainLOS/OnLostLOS
		std::uint32_t                                                         currentLOSEventCheckIndex;    // 0710
		mutable BSSpinLock                                                    queuedOnUpdateEventLock;      // 0714
		std::uint32_t                                                         pad071C;                      // 071C
		BSTArray<BSTSmartPointer<UpdateDataEvent>>                            queuedOnUpdateEvents;         // 0720
		BSTArray<BSTSmartPointer<UpdateDataEvent>>                            queuedOnUpdateGameEvents;     // 0738
		std::uint32_t                                                         unk0750;                      // 0750
		mutable BSSpinLock                                                    registeredSleepEventsLock;    // 0754
		std::uint32_t                                                         pad075C;                      // 075C
		BSTSet<VMHandle>                                                      registeredSleepEvents;        // 0760 - RegisterForSleep
		mutable BSSpinLock                                                    registeredStatsEventsLock;    // 0790
		BSTSet<VMHandle>                                                      registeredStatsEvents;        // 0798 - RegisterForTrackedStats
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>   renderSafeFunctorPool1;       // 07C8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>  renderSafeFunctorQueue1;      // 27E0
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>   renderSafeFunctorPool2;       // 2808
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>  renderSafeFunctorQueue2;      // 4820
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>   postRenderFunctorPool1;       // 4848
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>  postRenderFunctorQueue1;      // 6860
		BSTStaticFreeList<BSTSmartPointer<SkyrimScript::DelayFunctor>, 512>   postRenderFunctorPool2;       // 6888
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>  postRenderFunctorQueue2;      // 88A0
		mutable BSSpinLock                                                    renderSafeQueueLock;          // 88C8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>* renderSafeQueueToReadFrom;    // 88D0
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>* renderSafeQueueToWriteTo;     // 88D8
		mutable BSSpinLock                                                    postRenderQueueLock;          // 88E0
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>* postRenderQueueToReadFrom;    // 88E8
		BSTCommonLLMessageQueue<BSTSmartPointer<SkyrimScript::DelayFunctor>>* postRenderQueueToWriteTo;     // 88F0
		mutable BSSpinLock                                                    userLogMapLock;               // 88F8
		BSTHashMap<const char*, SkyrimScript::Logger*>                        userLogMap;                   // 8900 - Debug.OpenUserLog()
		mutable BSSpinLock                                                    currentVMOverstressTimeLock;  // 8930
		std::uint32_t                                                         currentVMOverstressTime;      // 8938
		std::uint32_t                                                         lastVMStackDumpTime;          // 893C
		mutable BSSpinLock                                                    InventoryEventFilterMapLock;  // 8940
		BSTHashMap<VMHandle, InventoryEventFilterLists*>                      InventoryEventFilterMap;      // 8948 - AddInventoryEventFilter()
	};
	static_assert(sizeof(SkyrimVM) == 0x8978);
}
