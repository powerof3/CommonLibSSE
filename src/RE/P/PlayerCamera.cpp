#include "RE/P/PlayerCamera.h"

namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		static REL::Relocation<PlayerCamera**> singleton{ Offset::PlayerCamera::Singleton };
		return *singleton;
	}

	void PlayerCamera::ForceFirstPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceFirstPerson);
		static REL::Relocation<func_t> func{ RELOCATION_ID(49858, 50790) };
		return func(this);
	}

	void PlayerCamera::ForceThirdPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceThirdPerson);
		static REL::Relocation<func_t> func{ RELOCATION_ID(49863, 50796) };
		return func(this);
	}

	bool PlayerCamera::IsInBleedoutMode() const
	{
		return QCameraEquals(CameraState::kBleedout);
	}

	bool PlayerCamera::IsInFirstPerson() const
	{
		return QCameraEquals(CameraState::kFirstPerson);
	}

	bool PlayerCamera::IsInFreeCameraMode() const
	{
		return QCameraEquals(CameraState::kFree);
	}

	bool PlayerCamera::IsInThirdPerson() const
	{
		return QCameraEquals(CameraState::kThirdPerson);
	}

	void PlayerCamera::PushCameraState(CameraState a_state)
	{
		using func_t = decltype(&PlayerCamera::PushCameraState);
		static REL::Relocation<func_t> func{ RELOCATION_ID(49947, 50880) };
		return func(this, a_state);
	}

	bool PlayerCamera::QCameraEquals(CameraState a_cameraState) const
	{
		return currentState && currentState == cameraStates[a_cameraState];
	}

	void PlayerCamera::ToggleFreeCameraMode(bool a_freezeTime)
	{
		using func_t = decltype(&PlayerCamera::ToggleFreeCameraMode);
		static REL::Relocation<func_t> func{ RELOCATION_ID(49876, 50809) };
		return func(this, a_freezeTime);
	}

	void PlayerCamera::Update()
	{
		using func_t = decltype(&PlayerCamera::Update);
		static REL::Relocation<func_t> func{ RELOCATION_ID(49852, 50784) };
		return func(this);
	}

	void PlayerCamera::UpdateThirdPerson(bool a_weaponDrawn)
	{
		using func_t = decltype(&PlayerCamera::UpdateThirdPerson);
		static REL::Relocation<func_t> func{ Offset::PlayerCamera::UpdateThirdPerson };
		return func(this, a_weaponDrawn);
	}
}
