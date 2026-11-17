#pragma once

namespace RE
{
	class BSTaskletGroupData;

	class BSTaskletGroup
	{
	public:
		// members
		BSTaskletGroupData* data;  // 00
	};
	static_assert(sizeof(BSTaskletGroup) == 0x8);
}
