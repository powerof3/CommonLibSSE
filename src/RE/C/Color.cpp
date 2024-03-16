#include "RE/C/Color.h"

#include "RE/N/NiColor.h"

namespace RE
{
	Color::Color(const NiColor& a_rhs) :
		red(static_cast<std::uint8_t>(255.0f / a_rhs.red)),
		green(static_cast<std::uint8_t>(255.0f / a_rhs.green)),
		blue(static_cast<std::uint8_t>(255.0f / a_rhs.blue)),
		alpha(0)
	{}

	std::uint32_t Color::ToInt() const
	{
		return ((red & 0xFF) << 24) + ((green & 0xFF) << 16) + ((blue & 0xFF) << 8) + (alpha & 0xFF);
	}

	std::string Color::ToHex() const
	{
		return std::format("{:X}{:X}{:X}{:X}", red, green, blue, alpha);
	}
}
