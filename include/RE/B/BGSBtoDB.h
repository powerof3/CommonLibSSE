#pragma once

namespace RE
{
	class BGSDistantObjectBlock;
	class BGSTerrainNode;

	namespace BGSBtoDB
	{
		struct DBTraits
		{
		public:
			inline static constexpr auto          RTTI = RTTI_BGSBtoDB__DBTraits;
			inline static constexpr std::uint32_t LOAD_QUEUE_SIZE = 8;
			inline static constexpr std::uint32_t RELEASE_QUEUE_SIZE = 2;

			using U_Type = BGSDistantObjectBlock*;

			struct ArgsType
			{
			public:
				// members
				BGSTerrainNode* node;     // 00
				std::int32_t    cellX;    // 08
				std::int32_t    cellY;    // 0C
				void*           diffuse;  // 10
				void*           normal;   // 18
			};
			static_assert(sizeof(ArgsType) == 0x20);
		};
		static_assert(std::is_empty_v<DBTraits>);
	}
}
