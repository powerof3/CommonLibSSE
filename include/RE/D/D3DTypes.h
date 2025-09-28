#pragma once

namespace RE
{
	struct D3DVECTOR
	{
		float x;  // 0
		float y;  // 4
		float z;  // 8
	};
	static_assert(sizeof(D3DVECTOR) == 0xC);
}
