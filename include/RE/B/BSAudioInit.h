#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace LipSynchAnimDB
	{
		class LipAudioInterface;
	}

	class BSISoundDescriptor;

	struct BSAudioCallbacks
	{
	public:
		using NumericIDCallbackFunc = bool(FormID, const BSISoundDescriptor*&);
		using NameIDCallbackFunc = bool(const char*, const BSISoundDescriptor*&);
		using UnkCallbackFunc = bool(void*, void*);

		// members
		NumericIDCallbackFunc* numericIDCallback;  // 40
		NameIDCallbackFunc*    nameIDCallback;     // 48
		UnkCallbackFunc*       unk50;              // 50
	};

	struct BSAudioInit
	{
	public:
		// members
		BSFixedString                      audioAPI;               // 00
		WinAPI::HWND                       wnd;                    // 08
		bool                               disableAudio;           // 10
		bool                               enableAudioCache;       // 11
		std::byte                          pad12[2];               // 12
		std::uint32_t                      initialCacheSize;       // 14
		std::uint32_t                      maxAudioCacheSize;      // 18
		std::uint32_t                      maxSizeForCachedSound;  // 1C
		std::uint32_t                      audioHWThread;          // 20
		std::uint32_t                      streamingThreshold;     // 24
		float                              defaultMasterVolume;    // 28
		std::byte                          pad2C[4];               // 2C
		LipSynchAnimDB::LipAudioInterface* lipAudioInterface;      // 30
		BSFixedString                      missingAssetSoundFile;  // 38
		BSAudioCallbacks                   audioCallbacks;         // 40
	};
	static_assert(sizeof(BSAudioInit) == 0x58);
}
