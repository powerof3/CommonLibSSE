#pragma once

namespace RE
{
	class BoundAnimationData;
	class ClipGeneratorData;

	namespace AnimationSystemUtils
	{
		class UtilsClipData
		{
		public:
			const ClipGeneratorData*  clipData;       // 00
			const BoundAnimationData* animData;       // 08
			float                     playbackSpeed;  // 10
			float                     motionWeight;   // 14
			float                     currentTime;    // 18
		};
		static_assert(sizeof(UtilsClipData) == 0x20);
	}
}
