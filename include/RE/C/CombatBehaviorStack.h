#pragma once

namespace RE
{
	class CombatBehaviorStack
	{
	public:
		class ObjectPtr
		{
		public:
			template <typename T>
			T* GetObject()
			{
				return stack ? stack->GetObject<T>(pos) : nullptr;
			}

			template <typename T>
			const T* GetObject() const
			{
				return stack ? stack->GetObject<T>(pos) : nullptr;
			}

			// members
			const CombatBehaviorStack* stack;  // 00
			std::uint32_t              pos;    // 08
			std::uint32_t              pad0C;  // 0C
		};
		static_assert(sizeof(ObjectPtr) == 0x10);

		template <typename T>
		T* GetObject(std::uint32_t pos)
		{
			return buffer ? reinterpret_cast<T*>(&buffer[pos]) : nullptr;
		}

		template <typename T>
		const T* GetObject(std::uint32_t pos) const
		{
			return buffer ? reinterpret_cast<const T*>(&buffer[pos]) : nullptr;
		}

		// members
		char*         buffer;      // 00
		std::uint32_t bufferSize;  // 08
		std::uint32_t size;        // 0C
	};
	static_assert(sizeof(CombatBehaviorStack) == 0x10);
}
