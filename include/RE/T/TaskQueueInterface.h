#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiAVObject;
	class NiNode;
	class SpellItem;
	class TESWeather;

	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton();

		static bool ShouldUseTaskQueue();

		void QueueNodeAttach(NiAVObject* a_obj, NiNode* a_root, bool a_arg3 = true, bool a_arg4 = false);  // 04
		void QueueAddRipple(float a_scale, const NiPoint3& a_pos);                                         // 45
		void QueueForceWeather(TESWeather* a_weather, bool a_forceOverride);                               // 64
		void QueueRemoveSpell(ActorHandle& a_actorHandle, SpellItem* a_spellItem);                         // 93
	};
	//static_assert(sizeof(TaskQueueInterface) == 0x);
}
