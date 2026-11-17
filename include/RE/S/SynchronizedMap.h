#pragma once

#include "RE/B/BSAtomic.h"
#include "RE/I/InterfacedClass.h"

namespace RE
{
	template <class Key, class T>
	class SynchronizedMap :
		public InterfacedClass
	{
	public:
		using key_type = Key;
		using mapped_type = T;

		struct Node
		{
		public:
			// members
			key_type    key;    // 00
			mapped_type value;  // 08
			Node*       next;   // 10
		};

		struct ThreadInterface
		{
		public:
			// members
			SynchronizedMap* ownerMap;            // 00
			Node**           referencedNodes[3];  // 08
			Node**           prev;                // 20
			Node*            cur;                 // 28
			Node*            next;                // 30
			Node*            retired;             // 38
			std::uint32_t    numRetired;          // 40
			std::uint32_t    pad44;               // 44
		};

		struct InterfaceEntry
		{
		public:
			// members
			std::uint32_t    threadID;         // 00
			std::uint32_t    pad04;            // 04
			ThreadInterface* threadInterface;  // 08
		};

		struct InterfaceTable
		{
		public:
			// members
			std::uint32_t          maxInterfaces;            // 00
			std::uint32_t          threadLocalStorageIndex;  // 04
			InterfaceEntry*        entries;                  // 08
			volatile std::uint32_t numInterfaces;            // 10
			std::uint32_t          pad14;                    // 14
		};

		class SynchronizedMapIterator
		{
		public:
			virtual ~SynchronizedMapIterator();  // 00

			// add
			virtual void ClearKey();  // 01

			// members
			std::uint32_t bucket;  // 08
			std::uint32_t pad0C;   // 0C
			key_type      key;     // 10
			std::uint8_t  flags;   // 18
			std::uint8_t  pad19;   // 19
			std::uint16_t pad1A;   // 1A
			std::uint32_t pad1C;   // 1C
		};

		~SynchronizedMap() override;  // 00

		// override (InterfacedClass)
		void* AllocateInterface(std::uint32_t a_num) override;  // 01

		// add
		virtual bool          GetAt(key_type a_key, mapped_type& a_value);                                                      // 02
		virtual bool          SetAtBucket(std::uint32_t a_bucket, key_type a_key, const mapped_type& a_value, bool a_replace);  // 03
		virtual bool          SetAt(key_type a_key, const mapped_type& a_value, bool a_replace);                                // 04
		virtual bool          RemoveAt(key_type a_key);                                                                         // 05
		virtual bool          RemoveValueFromBucket(std::uint32_t a_bucket, mapped_type a_value);                               // 06
		virtual bool          RemoveValue(mapped_type a_value);                                                                 // 07
		virtual std::uint32_t GetBucketForKey(key_type a_key);                                                                  // 08 - { return a_key % numBuckets; }
		virtual void          DestroyKey(key_type a_key);                                                                       // 09 - { return; }
		virtual key_type      CopyKey(key_type a_key);                                                                          // 0A - { return a_key; }
		virtual void          CopyKeyDirect(key_type a_src, key_type& a_dst);                                                   // 0B - { a_dst = a_src; }
		virtual bool          IsKeyGreaterOrEqual(key_type a_lhs, key_type a_rhs);                                              // 0C - { return a_lhs >= a_rhs; }
		virtual bool          IsKeyEqual(key_type a_lhs, key_type a_rhs);                                                       // 0D - { return a_lhs == a_rhs; }
		virtual void          IncrementCount();                                                                                 // 0E
		virtual void          DecrementCount();                                                                                 // 0F
		virtual std::uint32_t GetCount();                                                                                       // 10 - { return count; }

		// members
		Node**                 nodes;            // 08
		std::uint32_t          numBuckets;       // 10
		std::uint32_t          pad14;            // 14
		Node**                 buckets;          // 18
		std::uint32_t          deleteBatchSize;  // 20
		std::uint32_t          pad24;            // 24
		InterfaceTable*        interfaces;       // 28
		volatile std::uint32_t count;            // 30
		BSSpinLock             lock;             // 34
		std::uint32_t          pad3C;            // 3C
	};
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>) == 0x40);
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>::Node) == 0x18);
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>::ThreadInterface) == 0x48);
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>::InterfaceEntry) == 0x10);
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>::InterfaceTable) == 0x18);
	static_assert(sizeof(SynchronizedMap<std::int64_t, std::int64_t>::SynchronizedMapIterator) == 0x20);
}
