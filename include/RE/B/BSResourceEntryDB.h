#pragma once

namespace RE
{
	namespace BSResource
	{
		// TBD
		class IEntryDB
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSResource__IEntryDB;
			inline static constexpr auto VTABLE = VTABLE_BSResource__IEntryDB;

			virtual ~IEntryDB();

			// add
			virtual void Unk_01(void) = 0;  // 01
			virtual void Unk_02(void) = 0;  // 02
			virtual void Unk_03(void) = 0;  // 03
			virtual void Unk_04(void) = 0;  // 04
			virtual void Unk_05(void) = 0;  // 05

			// members
			std::uint8_t unk00[0xC8];  // 08
		};
		static_assert(sizeof(IEntryDB) == 0xD0);
	}
}
