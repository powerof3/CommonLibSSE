#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSMultiBoundAABB;
	class NiAVObject;

	class BGSAutoWater : public BSTSingletonSDM<BGSAutoWater>
	{
	public:
		BGSAutoWater* GetSingleton()
		{
			static REL::Relocation<BGSAutoWater**> singleton{ RELOCATION_ID(514289, 400449) };
			return *singleton;
		}

		// members
		std::uint8_t                          unk00[0x2028];                  // 0000 - related to flow map
		BSTArray<NiPointer<BSMultiBoundAABB>> multiBounds;                    // 2028
		NiPointer<NiAVObject>                 defaultCellWaterObject;         // 2040
		NiPointer<NiAVObject>                 defaultCellWaterRipplesObject;  // 2048
	};
	static_assert(sizeof(BGSAutoWater) == 0x2050);
}
