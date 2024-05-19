#pragma once

#include "RE/B/BSScaleformExternalTexture.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTEvent.h"
#include "RE/G/GPtr.h"
#include "RE/I/IMenu.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/SimpleAnimationGraphManagerHolder.h"

namespace RE
{
	struct BSAnimationGraphEvent;

	class BSGeometry;
	class ExtraDataList;
	class NiAVObject;
	class NiSourceTexture;
	class TESObjectBOOK;
	class TESObjectREFR;

	// menuDepth = 1
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kRequiresUpdate | kTopmostRenderedMenu | kRendersOffscreenTargets
	// context = kBook
	class BookMenu :
		public IMenu,                               // 00
		public SimpleAnimationGraphManagerHolder,   // 30
		public BSTEventSink<BSAnimationGraphEvent>  // 48
	{
	public:
		inline static constexpr auto      RTTI = RTTI_BookMenu;
		inline static constexpr auto      VTABLE = VTABLE_BookMenu;
		constexpr static std::string_view MENU_NAME = "Book Menu";

		~BookMenu() override;  // 00

		// override (IMenu)
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;                         // 04
		void               AdvanceMovie(float a_interval, std::uint32_t a_currentTime) override;  // 05
		void               PostDisplay() override;                                                // 06
		void               PreDisplay() override;                                                 // 07

		// override (BSTEventSink<BSAnimationGraphEvent>)
		BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* a_event, BSTEventSource<BSAnimationGraphEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TESObjectBOOK* GetTargetForm();
		[[nodiscard]] static TESObjectREFR* GetTargetReference();  // returns null if opened from inventory

		static void OpenBookMenu(const BSString& a_description, const ExtraDataList* a_extraList, TESObjectREFR* a_ref, TESObjectBOOK* a_book, const NiPoint3& a_pos, const NiMatrix3& a_rot, float a_scale, bool a_useDefaultPos);

		// members
		BSTArray<BSScaleformExternalTexture> bookTextures;      // 50
		GPtr<GFxMovieView>                   book;              // 68
		NiPointer<NiAVObject>                bookModel;         // 70
		std::uint32_t                        numRenderTargets;  // 78
		std::uint32_t                        pad7C;             // 7C
		NiSourceTexture*                     pageTexture;       // 80
		NiPointer<BSGeometry>                pageTextGeo;       // 88 - smart ptr
		std::uint16_t                        unk90;             // 90
		std::uint16_t                        startAnimating;    // 92
		bool                                 closeMenu;         // 94
		bool                                 isNote;            // 95
		bool                                 bookInitialized;   // 96
		std::uint8_t                         pad97;             // 97
	private:
		KEEP_FOR_RE()
	};
#ifndef SKYRIMVR
	static_assert(sizeof(BookMenu) == 0x98);
#else
	//static_assert(sizeof(BookMenu) == 0xB0);
#endif
}
