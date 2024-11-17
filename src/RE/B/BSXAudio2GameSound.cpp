#include "RE/B/BSXAudio2GameSound.h"

namespace RE
{
	BSXAudio2Audio* BSXAudio2GameSound::GetAudioImplementation()
	{
		REL::Relocation<BSXAudio2Audio**> audioImplementation{ STATIC_OFFSET(BSXAudio2GameSound::pAudioImplementation) };
		return *audioImplementation;
	}

	void BSXAudio2GameSound::SetAudioImplementation(BSXAudio2Audio* a_impl)
	{
		REL::Relocation<BSXAudio2Audio**> audioImplementation{ STATIC_OFFSET(BSXAudio2GameSound::pAudioImplementation) };
		*audioImplementation = a_impl;
	}
}
