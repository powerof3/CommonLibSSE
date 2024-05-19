#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/B/BSTSingleton.h"
#include "RE/F/FormTypes.h"
#include "RE/I/InventoryChanges.h"
#include "RE/N/NiTArray.h"
#include "RE/N/NiTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSPrimitive;
	class InventoryChanges;
	class NiPoint3;
	class TESFile;
	class TESRegionDataManager;
	class TESRegionList;

	struct TESObjectList
	{
	public:
		// members
		std::uint8_t pad0;  // 0
	};
	static_assert(sizeof(TESObjectList) == 0x1);

	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;       // 00
		BSTArray<TESFile*> smallFiles;  // 18
	};
	static_assert(sizeof(TESFileCollection) == 0x30);

	class TESDataHandler : public BSTSingletonSDM<TESDataHandler>
	{
	public:
		inline static RE::TESFileCollection* VRcompiledFileCollection = nullptr;  // used by SkyrimVRESL to store pointer to VR version
		static TESDataHandler*               GetSingleton(bool a_VRESL = true);

		bool AddFormToDataHandler(TESForm* a_form);

		std::uint32_t LoadScripts();
		TESForm*      LookupForm(FormID a_rawFormID, std::string_view a_modName);
		template <class T>
		T*     LookupForm(FormID a_rawFormID, std::string_view a_modName);
		FormID LookupFormID(FormID a_rawFormID, std::string_view a_modName);

		const TESFile*              LookupModByName(std::string_view a_modName);
		std::optional<std::uint8_t> GetModIndex(std::string_view a_modName);

		const TESFile*              LookupLoadedModByName(std::string_view a_modName);
		const TESFile*              LookupLoadedModByIndex(std::uint8_t a_index);
		std::optional<std::uint8_t> GetLoadedModIndex(std::string_view a_modName);

		const TESFile*               LookupLoadedLightModByName(std::string_view a_modName);
		const TESFile*               LookupLoadedLightModByIndex(std::uint16_t a_index);
		std::optional<std::uint16_t> GetLoadedLightModIndex(std::string_view a_modName);

		bool IsGeneratedID(FormID a_formID);

		BSTArray<TESForm*>& GetFormArray(FormType a_formType);
		template <class T>
		BSTArray<T*>& GetFormArray();

		ObjectRefHandle CreateReferenceAtLocation(TESBoundObject* a_base, const NiPoint3& a_location, const NiPoint3& a_rotation, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, TESObjectREFR* a_alreadyCreatedRef, BGSPrimitive* a_primitive, const ObjectRefHandle& a_linkedRoomRefHandle, bool a_forcePersist, bool a_arg11);

		// members
		std::uint8_t                      pad001;                                         // 001
		std::uint16_t                     pad002;                                         // 002
		std::uint32_t                     pad004;                                         // 004
		TESObjectList*                    objectList;                                     // 008
		BSTArray<TESForm*>                formArrays[std::to_underlying(FormType::Max)];  // 010
		TESRegionList*                    regionList;                                     // D00
		NiTPrimitiveArray<TESObjectCELL*> interiorCells;                                  // D08
		NiTPrimitiveArray<BGSAddonNode*>  addonNodes;                                     // D20
		NiTList<TESForm*>                 badForms;                                       // D38
		FormID                            nextID;                                         // D50
		std::uint32_t                     padD54;                                         // D54
		TESFile*                          activeFile;                                     // D58
		BSSimpleList<TESFile*>            files;                                          // D60
#ifndef SKYRIMVR
		TESFileCollection     compiledFileCollection;  // D70 broken in SKYRIMVR, iterate over files/loadedMods instead
		bool                  masterSave;              // DA0
		bool                  blockSave;               // DA1
		bool                  saveLoadGame;            // DA2
		bool                  autoSaving;              // DA3
		bool                  exportingPlugin;         // DA4
		bool                  clearingData;            // DA5
		bool                  hasDesiredFiles;         // DA6
		bool                  checkingModels;          // DA7
		bool                  loadingFiles;            // DA8
		bool                  dontRemoveIDs;           // DA9
		std::uint8_t          unkDAA;                  // DAA
		std::uint8_t          padDAB;                  // DAB
		std::uint32_t         padDAC;                  // DAC
		TESRegionDataManager* regionDataManager;       // DB0
		InventoryChanges*     merchantInventory;       // DB8
#else
		std::uint32_t         loadedModCount;     // D70 this should be avoided if SkyrimVRESL is available
		std::uint32_t         pad14;              // D74
		TESFile*              loadedMods[0xFF];   // D78 this should be avoided if SkyrimVRESL is available
		bool                  masterSave;         // 1570
		bool                  blockSave;          // 1571
		bool                  saveLoadGame;       // 1572
		bool                  autoSaving;         // 1574
		bool                  exportingPlugin;    // 1575
		bool                  clearingData;       // 1576 - init'd to 1
		bool                  hasDesiredFiles;    // 1577
		bool                  checkingModels;     // 1578
		bool                  loadingFiles;       // 1579
		bool                  dontRemoveIDs;      // 157A
		std::uint8_t          pad157B[5];         // 157B
		TESRegionDataManager* regionDataManager;  // 1580
		InventoryChanges*     merchantInventory;  // 1588
#endif
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(TESDataHandler) == 0xDC0);
#else
	static_assert(sizeof(TESDataHandler) == 0x1590);
#endif
	template <class T>
	T* TESDataHandler::LookupForm(FormID a_rawFormID, std::string_view a_modName)
	{
		auto form = LookupForm(a_rawFormID, a_modName);
		if (!form) {
			return 0;
		}

		return form->Is(T::FORMTYPE) ? static_cast<T*>(form) : 0;
	}

	template <class T>
	BSTArray<T*>& TESDataHandler::GetFormArray()
	{
		return reinterpret_cast<BSTArray<T*>&>(GetFormArray(T::FORMTYPE));
	}
}
