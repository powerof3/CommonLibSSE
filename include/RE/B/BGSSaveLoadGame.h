#pragma once

#include "RE/B/BGSConstructFormsInAllFilesMap.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTHashMap.h"
#include "RE/T/TESDataHandler.h"

namespace RE
{
	class BGSCellFormIDArrayMap;
	class BGSConstructFormsInFileMap;
	class BGSSaveLoadChangesMap;
	class TESFile;
	class TESForm;
	struct BGSLoadGameSubBuffer;

	class BGSSaveLoadFormIDMap
	{
	public:
		// members
		BSTHashMap<FormID, std::uint32_t> formIDToIndex;  // 00
		BSTHashMap<std::uint32_t, FormID> indexToFormID;  // 30
		std::uint32_t                     nextIndex;      // 60
		std::uint32_t                     pad64;          // 64
	};
	static_assert(sizeof(BGSSaveLoadFormIDMap) == 0x68);

	class BGSCellNumericIDArrayMap : public BSTHashMap<FormID, BSTArray<FormID>>
	{
	};
	static_assert(sizeof(BGSCellNumericIDArrayMap) == 0x30);

	class BGSSaveLoadReferencesMap
	{
	public:
		// members
		BSTHashMap<FormID, FormID>                           movedReferences;  // 00
		BGSCellNumericIDArrayMap                             cellReferences;   // 30 - interior or sky cells
		BSTHashMap<std::uint32_t, BGSCellNumericIDArrayMap*> worldReferences;  // 60 - grid X/Y packed into 32 bit key
	};
	static_assert(sizeof(BGSSaveLoadReferencesMap) == 0x90);

	struct QUEUED_SUB_BUFFER_TYPES
	{
		enum QUEUED_SUB_BUFFER_TYPE
		{
			kUnk0,
			kUnk1,
			kUnk2,

			kTotal
		};
	};
	using QUEUED_SUB_BUFFER_TYPE = QUEUED_SUB_BUFFER_TYPES::QUEUED_SUB_BUFFER_TYPE;

	class BGSSaveLoadQueuedSubBufferMap
	{
	public:
		BSTHashMap<TESForm*, BGSLoadGameSubBuffer> maps[QUEUED_SUB_BUFFER_TYPES::kTotal];
	};
	static_assert(sizeof(BGSSaveLoadQueuedSubBufferMap) == 0x90);

	class BGSSaveLoadHistory
	{
	public:
		// members
		BSTArray<const char*> notes;  // 00
	};
	static_assert(sizeof(BGSSaveLoadHistory) == 0x18);

	class BGSSaveLoadGame
	{
	public:
		enum class GlobalFlags
		{
			kGlobalAllowChanges = 1 << 0,
			kSaveGameLoading = 1 << 1,
			kSaveGameSaving = 1 << 2,
			kInitingForms = 1 << 3,
			kDeferInitForms = 1 << 4,
			kPositioningPlayerCharacter = 1 << 5,
			kPlayerLocationInvalid = 1 << 6
		};

		static BGSSaveLoadGame* GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadGame**> singleton{ RELOCATION_ID(516851, 403330) };
			return *singleton;
		}

		bool GetChange(TESForm* a_form, std::uint32_t a_changes)
		{
			using func_t = decltype(&BGSSaveLoadGame::GetChange);
			static REL::Relocation<func_t> func{ RELOCATION_ID(34655, 35577) };
			return func(this, a_form, a_changes);
		}

		bool IsFormIDInUse(FormID a_formID)
		{
			using func_t = decltype(&BGSSaveLoadGame::IsFormIDInUse);
			static REL::Relocation<func_t> func{ RELOCATION_ID(34670, 35593) };
			return func(this, a_formID);
		}

		[[nodiscard]] bool GetGlobalAllowChanges() const noexcept { return globalFlags.all(GlobalFlags::kGlobalAllowChanges); }
		[[nodiscard]] bool GetSaveGameLoading() const noexcept { return globalFlags.all(GlobalFlags::kSaveGameLoading); }
		[[nodiscard]] bool GetSaveGameSaving() const noexcept { return globalFlags.all(GlobalFlags::kSaveGameSaving); }
		[[nodiscard]] bool GetInitingForms() const noexcept { return globalFlags.all(GlobalFlags::kInitingForms); }
		[[nodiscard]] bool GetDeferInitForms() const noexcept { return globalFlags.all(GlobalFlags::kDeferInitForms); }
		[[nodiscard]] bool GetPositioningPlayerCharacter() const noexcept { return globalFlags.all(GlobalFlags::kPositioningPlayerCharacter); }

		// members
		TESFileCollection                        savedFiles;                  // 000
		BGSSaveLoadFormIDMap                     worldspaceFormIDMap;         // 030
		BSTHashMap<std::uint32_t, ActorHandle>   queuedInitPackageLocations;  // 098
		BGSSaveLoadReferencesMap                 references;                  // 0C8
		BSTHashMap<FormID, FormID>               changedFormIDs;              // 158
		BGSConstructFormsInAllFilesMap           reconstructFormsMap;         // 188
		BGSSaveLoadQueuedSubBufferMap            queuedSubBuffersMap;         // 208
		BGSSaveLoadFormIDMap                     formIDMap;                   // 298
		BGSSaveLoadHistory                       history;                     // 300
		BSTArray<BGSLoadFormData*>               loadFormData;                // 318
		BGSSaveLoadChangesMap*                   changesMap;                  // 330
		BGSSaveLoadChangesMap*                   oldChangesMap;               // 338
		REX::TEnumSet<GlobalFlags, std::uint32_t> globalFlags;                 // 340
		std::uint8_t                             currentMinorVersion;         // 344
	};
	static_assert(sizeof(BGSSaveLoadGame) == 0x348);
}
