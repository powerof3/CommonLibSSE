#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/G/GFxValue.h"
#include "RE/I/IGiftMenuScriptCallback.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class BGSListForm;
	class Actor;

	struct ItemCard;
	struct ItemList;

	// menuDepth = 3
	// flags = kPausesGame | kUsesMenuContext | kDisablePauseMenu | kUpdateUsesCursor | kInventoryItemMenu | kCustomRendering
	// context = kItemMenu
	class GiftMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_GiftMenu;
		inline static constexpr auto      VTABLE = VTABLE_GiftMenu;
		constexpr static std::string_view MENU_NAME = "GiftMenu";

		~GiftMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04
		void               PostDisplay() override;                           // 06

		[[nodiscard]] static RefHandle                GetGifterRefHandle();
		[[nodiscard]] static RefHandle                GetReceiverRefHandle();
		[[nodiscard]] static bool                     GetShowStolenItems();
		[[nodiscard]] static BGSListForm*             GetFilterList();
		[[nodiscard]] static IGiftMenuScriptCallback* GetCallbackFn();

		static void OpenMenuAsGifter(Actor* a_receiver);
		static void OpenMenuAsGifter(Actor* a_receiver, GiftMenuCallback_t a_callbackFn, BGSListForm* a_filterList, bool a_showStolenItems);
		static void OpenMenuAsGifter(Actor* a_receiver, BSTSmartPointer<IGiftMenuScriptCallback>* a_callbackFn, BGSListForm* a_filterList, bool a_showStolenItems);
		static void OpenMenuAsReceiver(Actor* a_gifter);
		static void OpenMenuAsReceiver(Actor* a_gifter, GiftMenuCallback_t a_callbackFn, BGSListForm* a_filterList, bool a_showStolenItems);
		static void OpenMenuAsReceiver(Actor* a_gifter, BSTSmartPointer<IGiftMenuScriptCallback>* a_callbackFn, BGSListForm* a_filterList, bool a_showStolenItems);

		bool IsPlayerGifting();
		bool IsPlayerReceiving();

		// members
		GFxValue        root;                   // 30 - "Menu_mc"
		ItemList*       itemList;               // 48
		ItemCard*       itemCard;               // 50
		BSTArray<void*> unk58;                  // 58
		std::int32_t    totalValueTransferred;  // 70 - gold value, argument of the callback after menu is closed
		std::uint32_t   unk74;                  // 74
		bool            pcControlsReady;        // 78
		std::uint8_t    pad79;                  // 79
		std::uint16_t   pad7A;                  // 7A
		std::uint32_t   pad7C;                  // 7C

	private:
		static void OpenMenu_Impl(Actor* a_gifter, Actor* a_receiver, BSTSmartPointer<IGiftMenuScriptCallback>* a_callbackFn, BGSListForm* a_filterList, bool a_showStolenItems, bool a_useFavorPoints = false);  // value of a_useFavorPoints is always ignored
	};
	static_assert(sizeof(GiftMenu) == 0x80);
}
