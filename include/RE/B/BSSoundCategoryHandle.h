#pragma once

namespace RE
{
	class BSISoundCategory;

	class BSSoundCategoryHandle
	{
	public:
		BSSoundCategoryHandle() noexcept = default;

		explicit BSSoundCategoryHandle(BSISoundCategory* a_category) noexcept :
			category(a_category)
		{}

		void SetFrequency(float a_frequency)
		{
			using func_t = decltype(&BSSoundCategoryHandle::SetFrequency);
			static REL::Relocation<func_t> func{ RELOCATION_ID(66606, 67846) };
			return func(this, a_frequency);
		}

		// members
		BSISoundCategory* category{ nullptr };  // 0
	};
	static_assert(sizeof(BSSoundCategoryHandle) == 0x8);
}
