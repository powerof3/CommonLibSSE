#pragma once

namespace RE
{
	class ButtonEvent;
	class InputEvent;
	class MouseMoveEvent;
	class PlayerControlsData;
	class ThumbstickEvent;

	class PlayerInputHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerInputHandler;
		inline static constexpr auto VTABLE = VTABLE_PlayerInputHandler;

		virtual ~PlayerInputHandler() = default;  // 00

		virtual bool CanProcess(InputEvent* a_event) = 0;                                                                          // 01
		virtual void ProcessThumbstick([[maybe_unused]] ThumbstickEvent* a_event, [[maybe_unused]] PlayerControlsData* a_data) {}  // 02
		virtual void ProcessMouseMove([[maybe_unused]] MouseMoveEvent* a_event, [[maybe_unused]] PlayerControlsData* a_data) {}    // 03
		virtual void ProcessButton([[maybe_unused]] ButtonEvent* a_event, [[maybe_unused]] PlayerControlsData* a_data) {}          // 04

		[[nodiscard]] bool IsInputEventHandlingEnabled() const;
		void               SetInputEventHandlingEnabled(bool a_enabled);

		// members
		bool          inputEventHandlingEnabled{ true };  // 08
		std::uint8_t  pad09{ 0 };                         // 09
		std::uint16_t pad0A{ 0 };                         // 0A
		std::uint32_t pad0C{ 0 };                         // 0C
	};
	static_assert(sizeof(PlayerInputHandler) == 0x10);
}
