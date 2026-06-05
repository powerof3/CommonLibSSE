#include "RE/M/MessageBoxMenu.h"

namespace RE
{
	bool MessageBoxMenu::Create(RE::BSString& a_message, const BSTSmartPointer<IMessageBoxCallback>& a_callback, std::uint8_t a_buttonPressOffset, std::int32_t a_warningType, std::int32_t a_menuDepth, const BSTArray<BSString>& a_buttons)
	{
		using func_t = bool(RE::BSString&, const BSTSmartPointer<IMessageBoxCallback>&, std::uint8_t, std::int32_t, std::int32_t, const BSTArray<BSString>&);
		static REL::Relocation<func_t> func{ RELOCATION_ID(51421, 52270) };
		return func(a_message, a_callback, a_buttonPressOffset, a_warningType, a_menuDepth, a_buttons);
	}

	MessageBoxMenu* MessageBoxMenu::GetCurrentMessageBoxMenu()
	{
		static REL::Relocation<MessageBoxMenu**> menu{ RELOCATION_ID(0, 406361) };
		return *menu;
	}

	BSTArray<MessageBoxData*>& MessageBoxMenu::GetQueue()
	{
		static REL::Relocation<BSTArray<MessageBoxData*>*> queue{ RELOCATION_ID(519819, 406362) };
		return *queue;
	}

	BSSpinLock& MessageBoxMenu::GetQueueLock()
	{
		static REL::Relocation<BSSpinLock*> lock{ RELOCATION_ID(519822, 406365) };
		return *lock;
	}

	void MessageBoxMenu::QueueMessage(MessageBoxData* a_data)
	{
		using func_t = decltype(&MessageBoxMenu::QueueMessage);
		static REL::Relocation<func_t> func{ RELOCATION_ID(51422, 52271) };
		func(a_data);
	}

	void MessageBoxMenu::RemoveMessageFromQueue(MessageBoxData* a_data)
	{
		using func_t = void (*)(MessageBoxMenu*, MessageBoxData*);
		static REL::Relocation<func_t> func{ RELOCATION_ID(51426, 52284) };
		func(nullptr, a_data);
	}
}
