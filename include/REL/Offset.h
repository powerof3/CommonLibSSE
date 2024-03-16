#pragma once

#include "REL/Module.h"

namespace REL
{
	class Offset
	{
	public:
		constexpr Offset() noexcept = default;

		explicit constexpr Offset(std::size_t a_offset) noexcept :
			_offset(a_offset)
		{}

		constexpr Offset& operator=(std::size_t a_offset) noexcept
		{
			_offset = a_offset;
			return *this;
		}

		[[nodiscard]] std::uintptr_t        address() const { return base() + offset(); }
		[[nodiscard]] constexpr std::size_t offset() const noexcept { return _offset; }

	private:
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }

		std::size_t _offset{ 0 };
	};
}
