#pragma once

namespace RE
{
	class InterfacedClass
	{
	public:
		inline static constexpr auto RTTI = RTTI_InterfacedClass;
		inline static constexpr auto VTABLE = VTABLE_InterfacedClass;

		virtual ~InterfacedClass();  // 00

		// add
		virtual void* AllocateInterface(std::uint32_t a_num) = 0;  // 01
	};
	static_assert(sizeof(InterfacedClass) == 0x8);
}
