#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTaskManagerWaitAction.h"
#include "RE/I/InterfacedClass.h"

namespace RE
{
	//template <class key, class T>
	class SynchronizedMap :
		public InterfacedClass
	{
	public:
		~SynchronizedMap() override;  // 00

		// override (InterfacedClass)
		void* AllocateInterface(std::uint32_t a_num) override;  // 01

		// add
		virtual void          Unk02(void);                                      // 02 - GetAt?
		virtual void          Unk03(void);                                      // 03 - SetAt?
		virtual void          Unk04(void);                                      // 04 - SetAt?
		virtual void          Unk05(void);                                      // 05 - RemoveAt?
		virtual void          Unk06(void);                                      // 06 - Remove?
		virtual void          Unk07(void);                                      // 07 - Remove?
		virtual std::uint32_t GetBucketForKey(std::int64_t);                    // 08
		virtual void          Unk08(void);                                      // 09
		virtual void          CopyKey(std::int64_t);                            // 0A - template specific
		virtual void          CopyKeyDirect(std::int64_t, std::int64_t& out);   // 0B - template specific
		virtual bool          IsKeyGreaterOrEqual(std::int64_t, std::int64_t);  // 0C - template specific
		virtual bool          IsKeyEqual(std::int64_t, std::int64_t);           // 0D - template specific
		virtual void          IncrementCount();                                 // 0F
		virtual void          DecrementCount();                                 // 10
		virtual std::uint32_t GetCount();                                       // 11

		// members
		void*                  nodes;            // 08
		std::uint32_t          numBuckets;       // 10 - confirmed
		std::uint32_t          pad14;            // 14
		void*                  buckets;          // 18
		std::uint32_t          deleteBatchSize;  // 20
		std::uint32_t          pad24;            // 24
		void*                  unk28;            // 28
		volatile std::uint32_t count;            // 30 - confirmed
		std::uint32_t          pad34;            // 34
		std::uint64_t          pad38;            // 38 - smth wrong here?
	};
	static_assert(sizeof(SynchronizedMap) == 0x40);

	class BSTaskManager :
		public SynchronizedMap,
		public BSTEventSource<BSTaskManagerWaitAction>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTaskManager;
		inline static constexpr auto VTABLE = VTABLE_BSTaskManager;
	};
	static_assert(sizeof(BSTaskManager) == 0xC0);
}
