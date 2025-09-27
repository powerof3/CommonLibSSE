#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"
#include "RE/I/InterfaceLightSchemes.h"
#include "RE/M/MenuEventHandler.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class InventoryEntryData;
	class NewInventoryMenuItemLoadTask;
	class NiAVObject;
	class TESBoundObject;
	class TESObjectREFR;

	struct LoadedInventoryModel
	{
	public:
		// members
		TESForm*               itemBase;     // 00 - smart ptr
		TESBoundObject*        modelObj;     // 08
		NiPointer<NiAVObject>  spModel;      // 10
		INTERFACE_LIGHT_SCHEME lightScheme;  // 18
		float                  boundRadius;  // 1C
	};
	static_assert(sizeof(LoadedInventoryModel) == 0x20);

	class Inventory3DManager :
		public BSTSingletonSDM<Inventory3DManager>,  // 10
		public MenuEventHandler                      // 00
	{
	public:
		~Inventory3DManager() override;  // 00

		static Inventory3DManager* GetSingleton();

		static void SetMouseRotation(bool a_active);
		static void StartMouseRotation() { SetMouseRotation(true); }
		static void StopMouseRotation() { SetMouseRotation(false); }

		void Begin3D(INTERFACE_LIGHT_SCHEME a_scheme);
		void End3D();
		void LoadInventoryItem(InventoryEntryData* a_objDesc);
		void LoadInventoryItem(TESBoundObject* a_object, ExtraDataList* a_extraDataList);
		void Render();
		bool ToggleItemZoom();
		void UnloadInventoryItem();

		// members
		std::uint8_t                                  unk011;              // 011
		std::uint16_t                                 unk012;              // 012
		NiPoint3                                      itemPosCopy;         // 014
		NiPoint3                                      itemPos;             // 020
		float                                         itemScaleCopy;       // 02C
		float                                         itemScale;           // 030
		INTERFACE_LIGHT_SCHEME                        currentLightScheme;  // 034 - kInventory or kInventoryMagic
		TESObjectREFR*                                tempRef;             // 038
		ExtraDataList                                 originalExtra;       // 040
		BSTSmallArray<LoadedInventoryModel, 7>        loadedModels;        // 058
		float                                         zoomDistance;        // 148
		float                                         zoomProgress;        // 14C - 1 if zoomed in, 0 if not, in-between during transition
		BSTSmartPointer<NewInventoryMenuItemLoadTask> loadTask;            // 150
		bool                                          enableUserInput;     // 158
		std::uint8_t                                  unk159;              // 159
		bool                                          startedZoom;         // 15A
		std::uint8_t                                  pad15B;              // 15B
		std::uint32_t                                 pad15C;              // 15C
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(Inventory3DManager) == 0x160);
#else
	static_assert(sizeof(Inventory3DManager) == 0x168);
#endif
}
