#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/N/NiNode.h"

namespace RE
{
	class BSFlattenedBoneTree : public NiNode
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSFlattenedBoneTree;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSFlattenedBoneTree;
		inline static constexpr auto VTABLE = VTABLE_BSFlattenedBoneTree;

		~BSFlattenedBoneTree() override;  // 00

		// override (NiNode)
		const NiRTTI* GetRTTI() const override;                                                         // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;                                // 17
		NiAVObject*   GetObjectByName(const BSFixedString& a_name) override;                            // 2A
		void          UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;          // 2C
		void          UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // 2D
		void          UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;     // 2E

		struct BoneEntry
		{
			NiTransform   local;             // 00
			NiTransform   world;             // 34
			std::int16_t  parentIndex;       // 68
			std::int16_t  unk6A;             // 6A
			std::uint16_t childCount;        // 6C
			std::int16_t  nextSiblingIndex;  // 6E
			NiAVObject*   node;              // 70
			BSFixedString nodeName;          // 78
		};
		static_assert(sizeof(BoneEntry) == 0x80);

		// members
		std::uint32_t                           numBones;           // 128
		std::uint32_t                           numPopulatedBones;  // 12C
		BoneEntry*                              boneEntries;        // 130
		BSTHashMap<BSFixedString, std::int32_t> boneMap;            // 138
	};
	static_assert(sizeof(BSFlattenedBoneTree) == 0x168);
}
