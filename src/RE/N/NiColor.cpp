#include "RE/N/NiColor.h"

#include "RE/C/Color.h"

namespace RE
{
	NiColor::NiColor(const Color& a_rhs) :
		red(a_rhs.red / 255.0f),
		green(a_rhs.green / 255.0f),
		blue(a_rhs.blue / 255.0f)
	{}

	std::uint32_t NiColor::ToInt() const
	{
		auto r = static_cast<std::uint32_t>(red * 255);
		auto g = static_cast<std::uint32_t>(green * 255);
		auto b = static_cast<std::uint32_t>(blue * 255);

		return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
	}

	std::string NiColor::ToHex() const
	{
		auto r = static_cast<std::uint32_t>(red * 255);
		auto g = static_cast<std::uint32_t>(green * 255);
		auto b = static_cast<std::uint32_t>(blue * 255);

		return std::format("{:X}{:X}{:X}", r, g, b);
	}

	NiColorA::NiColorA(const Color& a_rhs) :
		red(a_rhs.red / 255.0f),
		green(a_rhs.green / 255.0f),
		blue(a_rhs.blue / 255.0f),
		alpha(0.0f)
	{}
}
