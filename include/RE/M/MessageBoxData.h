#pragma once

#include "RE/B/BSString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IUIMessageData.h"

namespace RE
{
	class IMessageBoxCallback;

	enum class WARNING_TYPES;
	enum class UI_DEPTH_PRIORITY;

	class MessageBoxData : public IUIMessageData
	{
	public:
		inline static constexpr auto             RTTI = RTTI_MessageBoxData;
		inline static constexpr auto             VTABLE = VTABLE_MessageBoxData;
		inline static constexpr std::string_view CLASS_NAME = "MessageBoxData";

		~MessageBoxData() override;  // 00

		// members
		BSString                                    bodyText;           // 10
		BSTArray<BSString>                          buttonText;         // 20
		REX::TEnum<WARNING_TYPES, std::int32_t>     warningType;        // 38
		std::int32_t                                cancelButtonIndex;  // 3C
		BSTSmartPointer<IMessageBoxCallback>        callback;           // 40
		REX::TEnum<UI_DEPTH_PRIORITY, std::int32_t> menuDepth;          // 48
		std::uint8_t                                buttonPressOffset;  // 4C - offset that is added to the button that was pressed
		bool                                        useHtml;            // 4D
		bool                                        verticalButtons;    // 4E
		bool                                        isCancellable;      // 4F
	};
	static_assert(sizeof(MessageBoxData) == 0x50);
}
