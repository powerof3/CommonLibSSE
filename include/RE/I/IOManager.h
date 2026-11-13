#pragma once

#include "RE/B/BSTaskManager.h"

namespace RE
{
	class IOManager : public BSTaskManager
	{
	public:
		inline static constexpr auto RTTI = RTTI_IOManager;
		inline static constexpr auto VTABLE = VTABLE_IOManager;

		static IOManager* GetSingleton()
		{
			static REL::Relocation<IOManager**> singleton{ RELOCATION_ID(524542, 411121) };
			return *singleton;
		}

		//virtual ~IOManager();  // 00
	};
	static_assert(sizeof(IOManager) == 0x128);
}
