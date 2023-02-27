#pragma once

namespace RE
{
	class BGSLoadGameBuffer
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSLoadGameBuffer;
		inline static constexpr auto VTABLE = VTABLE_BGSLoadGameBuffer;

		virtual ~BGSLoadGameBuffer();

		// add
		virtual std::uint8_t GetVersion(void);  // 01

		// members
		void*         buffer;          // 08
		std::uint64_t unk10;           // 10
		std::uint32_t unk18;           // 18
		std::uint32_t unk1C;           // 1C
		std::uint32_t unk20;           // 20
		std::uint32_t bufferPosition;  // 24
	};
	static_assert(sizeof(BGSLoadGameBuffer) == 0x28);
}
