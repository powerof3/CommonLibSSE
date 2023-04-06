#pragma once

#include "RE/H/hkbContext.h"

namespace RE
{
	class hkbClipGenerator;

	class IAnimationClipLoaderSingleton
	{
	public:
		inline static auto RTTI = RTTI_IAnimationClipLoaderSingleton;
		inline static auto VTABLE = VTABLE_IAnimationClipLoaderSingleton;

		virtual ~IAnimationClipLoaderSingleton();  // 00

		// add
		virtual void          Unk_01(void);                                                                                // 01
		virtual std::uint64_t Load(const hkbContext& a_context, hkbClipGenerator* a_clipGenerator, std::uint64_t a_arg4);  // 02
		virtual void          Unk_03(void);                                                                                // 03
		virtual void          Unk_04(void);                                                                                // 04
		virtual void          Unk_05(void);                                                                                // 05
	};
}
