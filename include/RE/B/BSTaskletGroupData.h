#pragma once

namespace RE
{
	class BSTaskletGroupData
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSTaskletGroupData;
		inline static constexpr auto VTABLE = VTABLE_BSTaskletGroupData;

		virtual ~BSTaskletGroupData();  // 00

		// add
		virtual void WaitForCompletion(bool a_poll) = 0;     // 01
		virtual void Cancel() = 0;                           // 02
		virtual void ForceProcess(float a_ms) = 0;           // 03
		virtual void SetMaxConcurrent(std::uint32_t a_unk);  // 04 - { return; }

		// members
		bool         complete;  // 08
		std::uint8_t pad09[7];  // 09
	};
	static_assert(sizeof(BSTaskletGroupData) == 0x10);
}
