#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class BSSpinLock;
	class IMessageBoxCallback;
	class MessageBoxData;

	// menuDepth = 10
	// flags = kPausesGame | kAlwaysOpen | kUsesCursor | kModal
	// context = kMenuMode
	class MessageBoxMenu : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_MessageBoxMenu;
		inline static constexpr auto      VTABLE = VTABLE_MessageBoxMenu;
		constexpr static std::string_view MENU_NAME = "MessageBoxMenu";

		~MessageBoxMenu() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

		template <class... Args>
		static bool Create(const char* a_message, void (*a_callback)(std::uint8_t), std::uint8_t a_buttonPressOffset, std::int32_t a_warningType, std::int32_t a_menuDepth, Args... a_buttons)
		{
			// It reads the buttons starting with the first button until it reaches nullptr
			static_assert((std::is_same_v<std::decay_t<Args>, const char*> && ...), "arguments must all be const char*");
			using func_t = bool(const char*, void (*)(std::uint8_t), std::uint8_t, std::int32_t, std::int32_t, ...);
			static REL::Relocation<func_t> func{ RELOCATION_ID(51420, 52269) };
			return func(a_message, a_callback, a_buttonPressOffset, a_warningType, a_menuDepth, a_buttons..., nullptr);
		}

		static bool Create(RE::BSString& a_message, const BSTSmartPointer<IMessageBoxCallback>& a_callback, std::uint8_t a_buttonPressOffset, std::int32_t a_warningType, std::int32_t a_menuDepth, const BSTArray<BSString>& a_buttons);

		static MessageBoxMenu*            GetCurrentMessageBoxMenu();  // inlined in SE
		static BSTArray<MessageBoxData*>& GetQueue();
		static BSSpinLock&                GetQueueLock();  // used while adding and removing
		static void                       QueueMessage(MessageBoxData* a_data);
		static void                       RemoveMessageFromQueue(MessageBoxData* a_data);

		// members
		bool          isPopulated;  // 30
		std::uint8_t  pad31;        // 31
		std::uint16_t pad32;        // 32
		std::uint32_t pad34;        // 34
	};
	static_assert(sizeof(MessageBoxMenu) == 0x38);
}
