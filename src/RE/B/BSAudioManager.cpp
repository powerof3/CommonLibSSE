#include "RE/B/BSAudioManager.h"

#include "RE/B/BGSSoundDescriptorForm.h"
#include "RE/B/BSAudio.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/F/FormTraits.h"
#include "RE/N/NiAVObject.h"
#include "RE/T/TESForm.h"

namespace RE
{
	BSAudioManager* BSAudioManager::GetSingleton()
	{
		using func_t = decltype(&BSAudioManager::GetSingleton);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSAudioManager::QInstance) };
		return func();
	}

	BSAudio* BSAudioManager::QPlatformInstance()
	{
		using func_t = decltype(&BSAudioManager::QPlatformInstance);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSAudioManager::QPlatformInstance) };
		return func();
	}

	void BSAudioManager::ClearCache()
	{
		REL::Relocation<BSSpinLock*> cacheSpinLock{ STATIC_OFFSET(BSAudioManager::CacheSpinLock) };
		BSSpinLockGuard locker{ *cacheSpinLock };

		for (auto it = audioCache.begin(); it != audioCache.end();) {
			const auto gameSound = *it;
			it = audioCache.erase(it);
			QPlatformInstance()->ReleaseGameSound(gameSound);
		}

		audioCacheSize = 0;
	}

	void BSAudioManager::ComposeMessage(SOUND_MSG a_message, std::uint32_t a_id, std::int32_t a_iData, void* a_pData, NiPointer<NiAVObject> a_spData, const NiPoint3& a_vector3)
	{
		using func_t = decltype(&BSAudioManager::ComposeMessage);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSAudioManager::ComposeMessage) };
		return func(this, a_message, a_id, a_iData, a_pData, a_spData, a_vector3);
	}

	bool BSAudioManager::GetSoundHandle(BSSoundHandle& a_soundHandle, BSISoundDescriptor* a_descriptor, std::uint32_t a_flags)
	{
		using func_t = decltype(&BSAudioManager::GetSoundHandle);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSAudioManager::GetSoundHandle) };
		return func(this, a_soundHandle, a_descriptor, a_flags);
	}

	void BSAudioManager::KillAll(bool a_waitForCompletion, std::uint32_t a_waitTicks)
	{
		using func_t = decltype(&BSAudioManager::KillAll);
		REL::Relocation<func_t> func{ STATIC_OFFSET(BSAudioManager::KillAll) };
		return func(this, a_waitForCompletion, a_waitTicks);
	}

	bool BSAudioManager::Play(RE::FormID a_soundFormID)
	{
		auto descriptor = TESForm::LookupByID<BGSSoundDescriptorForm>(a_soundFormID);
		return descriptor && Play(descriptor);
	}

	bool BSAudioManager::Play(BSISoundDescriptor* a_descriptor)
	{
		BSSoundHandle sound;
		return GetSoundHandle(sound, a_descriptor) && sound.Play();
	}

	bool BSAudioManager::BuildSoundDataFromDescriptor(BSSoundHandle& a_soundHandle, BSISoundDescriptor* a_descriptor, std::uint32_t a_flags)
	{
		using func_t = decltype(&BSAudioManager::BuildSoundDataFromDescriptor);
		static REL::Relocation<func_t> func{ Offset::BSAudioManager::BuildSoundDataFromDescriptor };
		return func(this, a_soundHandle, a_descriptor, a_flags);
	}

	void BSAudioManager::BuildSoundDataFromEditorID(BSSoundHandle& a_soundHandle, const char* a_editorID, std::uint32_t a_flags)
	{
		using func_t = decltype(&BSAudioManager::BuildSoundDataFromEditorID);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66403, 67665) };
		return func(this, a_soundHandle, a_editorID, a_flags);
	}

	void BSAudioManager::BuildSoundDataFromFile(BSSoundHandle& a_soundHandle, const BSResource::ID& a_file, std::uint32_t a_flags, std::uint32_t a_priority)
	{
		using func_t = decltype(&BSAudioManager::BuildSoundDataFromFile);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66402, 67664) };
		return func(this, a_soundHandle, a_file, a_flags, a_priority);
	}

	void BSAudioManager::PrecacheDescriptor(const BSISoundDescriptor* a_descriptor, std::uint32_t a_flags)
	{
		using func_t = decltype(&BSAudioManager::PrecacheDescriptor);
		REL::Relocation<func_t> func{ Offset::BSAudioManager::PrecacheDescriptor };
		return func(this, a_descriptor, a_flags);
	}

	void BSAudioManager::SetCacheEnabled(bool a_enabled)
	{
		if (a_enabled) {
			flags.set(Flags::CacheEnabled);
		} else {
			flags.reset(Flags::CacheEnabled);
			ClearCache();
		}
	}
}
