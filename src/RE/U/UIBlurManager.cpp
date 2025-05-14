#include "RE/U/UIBlurManager.h"

namespace RE
{
	UIBlurManager* UIBlurManager::GetSingleton()
	{
		static REL::Relocation<UIBlurManager**> singleton{ Offset::UIBlurManager::Singleton };
		return *singleton;
	}

	void UIBlurManager::DecrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::DecrementBlurCount);
		static REL::Relocation<func_t> func{ Offset::UIBlurManager::DecrementBlurCount };
		return func(this);
	}

	void UIBlurManager::IncrementBlurCount()
	{
		using func_t = decltype(&UIBlurManager::IncrementBlurCount);
		static REL::Relocation<func_t> func{ Offset::UIBlurManager::IncrementBlurCount };
		return func(this);
	}
}
