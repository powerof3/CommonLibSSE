#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class CombatBehaviorStack
	{
	public:
		class ObjectPtr
		{
		public:
			// members
			CombatBehaviorStack* stack;   // 00
			uint32_t             frame;   // 08
			uint32_t             pad_0C;  // 0C
		};
		static_assert(sizeof(ObjectPtr) == 0x10);

		template<typename T, typename ... Args>
		ObjectPtr Allocate(Args&&... args)
		{
			ObjectPtr ans{this, size};

			uint32_t new_size = size + sizeof(T);
			CheckBuffer(new_size);
			uint32_t old_size = size;
			size = new_size;
			new (&data[old_size]) T(std::forward<Args>(args)...);
			return ans;
		}

		template<typename T>
		void Deallocate() {
			size -= sizeof(T);
			reinterpret_cast<T*>(&data[size])->~T();
		}

		template<typename T>
		void StoreData(const T& obj)
		{
			uint32_t old_size = size;
			uint32_t new_size = size + sizeof(T);
			CheckBuffer(new_size);
			size = new_size;
			*reinterpret_cast<T*>(&data[old_size]) = obj;
		}

		template <typename T>
		T RemoveData() {
			size -= sizeof(T);
			return *reinterpret_cast<T*>(&data[size]);
		}

		template<typename T>
		T& Access(uint32_t offset)
		{
			return *reinterpret_cast<T*>(&data[offset]);
		}

		void CheckBuffer(uint32_t size);

		// members
		char*    data;      // 00
		uint32_t capasity;  // 08
		uint32_t size;      // 0C
	};
	static_assert(sizeof(CombatBehaviorStack) == 0x10);
}
