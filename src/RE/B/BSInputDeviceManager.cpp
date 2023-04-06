#include "RE/B/BSInputDeviceManager.h"

#include "RE/B/BSInputDeviceFactory.h"
#include "RE/B/BSPCGamepadDeviceDelegate.h"
#include "RE/B/BSPCGamepadDeviceHandler.h"
#include "RE/B/BSWin32KeyboardDevice.h"
#include "RE/B/BSWin32MouseDevice.h"
#include "RE/B/BSWin32VirtualKeyboardDevice.h"

namespace RE
{
	BSInputDeviceManager* BSInputDeviceManager::GetSingleton()
	{
		REL::Relocation<BSInputDeviceManager**> singleton{ Offset::BSInputDeviceManager::Singleton };
		return *singleton;
	}

	BSPCGamepadDeviceDelegate* BSInputDeviceManager::GetGamepad()
	{
		auto handler = GetGamepadHandler();
		return handler ? handler->currentPCGamePadDelegate : nullptr;
	}

	BSPCGamepadDeviceHandler* BSInputDeviceManager::GetGamepadHandler()
	{
		return static_cast<BSPCGamepadDeviceHandler*>(devices[stl::to_underlying(INPUT_DEVICE::kGamepad)]);
	}

	BSWin32KeyboardDevice* BSInputDeviceManager::GetKeyboard()
	{
		return static_cast<BSWin32KeyboardDevice*>(devices[stl::to_underlying(INPUT_DEVICE::kKeyboard)]);
	}

	BSWin32MouseDevice* BSInputDeviceManager::GetMouse()
	{
		return static_cast<BSWin32MouseDevice*>(devices[stl::to_underlying(INPUT_DEVICE::kMouse)]);
	}

	BSWin32VirtualKeyboardDevice* BSInputDeviceManager::GetVirtualKeyboard()
	{
		return static_cast<BSWin32VirtualKeyboardDevice*>(devices[stl::to_underlying(INPUT_DEVICE::kVirtualKeyboard)]);
	}

	bool BSInputDeviceManager::IsGamepadConnected()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->currentPCGamePadDelegate;
	}

	bool BSInputDeviceManager::IsGamepadEnabled()
	{
		auto handler = GetGamepadHandler();
		return handler && handler->currentPCGamePadDelegate && handler->currentPCGamePadDelegate->IsEnabled();
	}

	bool BSInputDeviceManager::IsMouseBackground()
	{
		auto mouse = GetMouse();
		return mouse && mouse->backgroundMouse;
	}

	bool BSInputDeviceManager::GetDeviceKeyMapping(INPUT_DEVICE a_device, std::uint32_t a_key, BSFixedString& a_mapping)
	{
		auto device = devices[stl::to_underlying(a_device)];
		return device && device->GetKeyMapping(a_key, a_mapping);
	}

	bool BSInputDeviceManager::GetDeviceMappedKeycode(INPUT_DEVICE a_device, std::uint32_t a_key, uint32_t& a_outKeyCode)
	{
		auto device = devices[stl::to_underlying(a_device)];
		return device && device->GetMappedKeycode(a_key, a_outKeyCode);
	}

	void BSInputDeviceManager::ProcessGamepadEnabledChange()
	{
		if (valueQueued) {
			bool* pGamepadEnable = reinterpret_cast<bool*>(RELOCATION_ID(511901, 388465).address());
			*pGamepadEnable = true;
			valueQueued = false;
		}
	}

	void BSInputDeviceManager::ReinitializeMouse()
	{
		auto mouse = GetMouse();
		if (mouse) {
			mouse->Reinitialize();
		}
	}

	void BSInputDeviceManager::CreateInputDevices()
	{
		for (std::uint32_t i = 0; i < INPUT_DEVICE::kTotal; i++) {
			devices[i] = BSInputDeviceFactory::CreateInputDevice(static_cast<INPUT_DEVICE>(i));
			devices[i]->Initialize();
		}
	}

	void BSInputDeviceManager::ResetInputDevices()
	{
		for (std::uint32_t i = 0; i < INPUT_DEVICE::kTotal; i++) {
			if (devices[i]) {
				devices[i]->Reset();
			}
		}
	}

	void BSInputDeviceManager::DestroyInputDevices()
	{
		for (std::uint32_t i = 0; i < INPUT_DEVICE::kTotal; i++) {
			if (devices[i]) {
				devices[i]->Release();
				BSInputDeviceFactory::DestroyInputDevice(devices[i]);
			}
		}
	}

	// Called by Main::Update()
	void BSInputDeviceManager::PollInputDevices(float a_secsSinceLastFrame)
	{
		// Calls Process() on each device
		// Calls ControlMap::sub_140C11600(InputEvent*)
		// Calls Rumble::Update_140C10860(float secsSinceLastFrame)
		// Emits the last InputEvent
		// resets the global BSInputEventQueue
		using func_t = decltype(&BSInputDeviceManager::PollInputDevices);
		REL::Relocation<func_t> func{ RELOCATION_ID(67315, 68617) };
		return func(this, a_secsSinceLastFrame);
	}
}
