#pragma once

#include "RE/B/BSInstanceTriShape.h"

namespace RE
{
	namespace BSGraphics
	{
		struct VertexBuffer
		{
			REX::W32::ID3D11Buffer* buffer;
			void*                   m_data;
			size_t                  byteWidth;
		};
		static_assert(sizeof(VertexBuffer) == 0x18);
	}

	class BSMultiStreamInstanceTriShape : public BSInstanceTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSMultiStreamInstanceTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSMultiStreamInstanceTriShape;
		inline static constexpr auto VTABLE = VTABLE_BSMultiStreamInstanceTriShape;

		class InstanceGroup : public BSMultiBoundAABB
		{
		public:
			BSGraphics::VertexBuffer* vertexBuffer;   // 40
			std::uint32_t             triCount;       // 48
			std::uint32_t             instanceCount;  // 4C
			bool                      isVisible;      // 50
		};
		static_assert(sizeof(InstanceGroup) == 0x58);

		struct GroupHeader
		{
			RE::NiPoint3  center;
			RE::NiPoint3  size;
			std::uint32_t triCount;
			std::uint32_t groupInstanceCount;
			std::uint32_t numShortsPerInstance;
		};
		static_assert(sizeof(GroupHeader) == 0x24);

		struct GroupAttachTask
		{
			RE::BSMultiStreamInstanceTriShape*                trishape;
			RE::BSMultiStreamInstanceTriShape::InstanceGroup* instanceGroup;
			BSTArray<std::uint32_t>*                          groupIndicies;
		};
		static_assert(sizeof(GroupAttachTask) == 0x18);

		~BSMultiStreamInstanceTriShape() override;  // 00

		// override (BSInstanceTriShape)
		const NiRTTI* GetRTTI() const override;                                                                                            // 02
		NiObject*     CreateClone(NiCloningProcess& a_cloning) override;                                                                   // 17
		void          OnVisible(NiCullingProcess& a_process, std::int32_t a_alphaGroupIndex) override;                                     // 34
		std::uint32_t GetVisibleGroupsTriangleCount() override;                                                                            // 37
		void          BeginAddingInstances(std::uint32_t a_numFloatsPerInstance) override;                                                 // 38
		void          AddInstances(std::uint32_t a_numFloatsPerInstance, std::uint16_t& a_instanceData) override;                          // 39
		void          DoneAddingInstances(BSTArray<std::uint32_t>& a_instances) override;                                                  // 3A
		bool          GetIsAddingInstances() override;                                                                                     // 3B
		std::uint32_t AddGroup(std::uint32_t a_numInstances, std::uint16_t& a_instanceData, std::uint32_t a_arg3, float a_arg4) override;  // 3C
		void          RemoveGroup(std::uint32_t a_numInstance) override;                                                                   // 3D

		// members
		BSTArray<InstanceGroup*> instanceGroups;        // 160
		std::uint32_t            meshTriCount;          // 178
		std::uint32_t            maxInstancesPerGroup;  // 17C
		float                    renderDistance;        // 180
		std::uint32_t            unk184;                // 184
		void*                    groupAlloc;            // 188
		std::uint32_t            instanceCount;         // 190
		std::uint32_t            instanceSize;          // 194
		std::uint32_t            activeGroupCount;      // 198
	};
	static_assert(sizeof(BSMultiStreamInstanceTriShape) == 0x1A0);
}
