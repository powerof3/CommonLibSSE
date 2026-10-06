#pragma once

namespace RE
{
	class BSGeometry;

	struct BSProceduralGeomEvent
	{
	public:
		// members
		BSGeometry* changedGeom;  // 00
	};
	static_assert(sizeof(BSProceduralGeomEvent) == 0x8);
}
