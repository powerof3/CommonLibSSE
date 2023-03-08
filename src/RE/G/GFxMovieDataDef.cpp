#include "RE/G/GFxMovieDataDef.h"

#include "RE/G/GMemory.h"

namespace RE
{
	void* GFxMovieDataDef::Allocator::Alloc(std::size_t a_size)
	{
		if (a_size > 0xFF8) {
			auto newBlock = static_cast<void**>(heap->Alloc(a_size + 8, 0));
			if (!newBlock) {
				return nullptr;
			}

			newBlock[0] = lastBlock;
			lastBlock = newBlock;

			return &newBlock[1];
		}

		if (a_size > memAvailable) {
			auto newBlock = static_cast<void**>(heap->Alloc(0x1FF8, 0));
			if (!newBlock) {
				return nullptr;
			}

			newBlock[0] = lastBlock;
			lastBlock = newBlock;

			allocPtr = &newBlock[1];
			memAvailable = 0x1FF0;
		}

		auto memPtr = allocPtr;

		memAvailable -= a_size;
		allocPtr = static_cast<char*>(allocPtr) + a_size;

		return memPtr;
	}

	void GFxMovieDataDef::Allocator::Free()
	{
		const auto globalHeap = GMemory::GetGlobalHeap();
		void*      block = lastBlock;
		while (block) {
			globalHeap->Free(block);
			block = static_cast<void**>(block)[0];
		}
	}
}
