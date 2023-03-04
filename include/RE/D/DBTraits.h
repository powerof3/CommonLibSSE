#pragma once

namespace RE
{
	namespace BSModelDB
	{
		struct DBTraits
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSModelDB__DBTraits;

			struct ArgsType
			{
			public:
				// members
				std::uint32_t LODmult{ 0 };         // 0
				std::uint32_t texLoadLevel{ 3 };    // 4
				bool          unk8{ true };         // 8
				bool          unk9{ false };        // 9
				bool          unkA{ true };         // A
				bool          postProcess{ true };  // B
			};
			static_assert(sizeof(ArgsType) == 0xC);
		};
	}
}
