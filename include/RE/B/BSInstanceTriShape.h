#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTriShape.h"

namespace RE
{
	class BSInstanceTriShape : public BSTriShape
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSInstanceTriShape;
		inline static constexpr auto Ni_RTTI = NiRTTI_BSInstanceTriShape;
		inline static constexpr auto VTABLE = VTABLE_BSInstanceTriShape;

		~BSInstanceTriShape() override;  // 00

		// override (BSTriShape)
		const NiRTTI* GetRTTI() const override;  // 02

		// add
		virtual void          BeginAddingInstances(std::uint32_t a_numFloatsPerInstance) = 0;                                                 // 38
		virtual void          AddInstances(std::uint32_t a_numInstances, std::uint16_t& a_instanceData) = 0;                                  // 39
		virtual void          DoneAddingInstances(BSTArray<std::uint32_t>& a_instances) = 0;                                                  // 3A
		virtual bool          GetIsAddingInstances() = 0;                                                                                     // 3B
		virtual std::uint32_t AddGroup(std::uint32_t a_numInstances, std::uint16_t& a_instanceData, std::uint32_t a_arg3, float a_arg4) = 0;  // 3C
		virtual void          RemoveGroup(std::uint32_t a_numInstance) = 0;                                                                   // 3D
	};
	static_assert(sizeof(BSInstanceTriShape) == 0x160);
}
