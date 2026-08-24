#include "RE/H/HeapBlock.h"

namespace RE
{
	std::uint32_t HeapBlock::Used::GetCheckPoint() const
	{
		return REX::BITS_TO_VALUE<std::uint32_t>(memContext1, memContext2, memContext3, memContext4, memContext5, memContext6, memContext7, memContext8);
	}

	std::uint32_t HeapBlock::Used::GetMemContext() const
	{
		return REX::BITS_TO_VALUE<std::uint32_t>(stackTrace1, stackTrace2, stackTrace3, stackTrace4, stackTrace5, stackTrace6, stackTrace7, stackTrace8, stackTrace9, stackTrace10, stackTrace11, stackTrace12, stackTrace13, stackTrace14, stackTrace15, stackTrace16, stackTrace17, stackTrace18, stackTrace19, stackTrace20, stackTrace21, stackTrace22);
	}

	std::uint32_t HeapBlock::Used::GetStackTrace() const
	{
		return REX::BITS_TO_VALUE<std::uint32_t>(checkPoint1, checkPoint2);
	}
}
