#pragma once

#include "RE/B/BGSMessage.h"
namespace RE
{
	class TESBoundObject;

	namespace SendHUDMessage
	{
		void ShowHUDMessage(const char* a_notification, const char* a_soundToPlay = nullptr, bool a_cancelIfAlreadyQueued = true);
		void ShowInventoryChangeMessage(TESBoundObject* a_object, std::uint32_t a_count, bool a_added, bool a_playSound, const char* a_objectName = nullptr);
		void ShowNotificationFromForm(BGSMessage* a_message, const char* a_soundToPlay = nullptr, bool a_cancelIfAlreadyQueued = true);

		void SetHUDMode(const char* a_mode, bool a_push);
		void PushHUDMode(const char* a_mode);
		void PopHUDMode(const char* a_mode);
	}
}
