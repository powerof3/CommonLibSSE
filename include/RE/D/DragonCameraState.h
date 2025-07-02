#pragma once

#include "RE/T/ThirdPersonState.h"

namespace RE
{
	class DragonCameraState : public ThirdPersonState
	{
	public:
		inline static constexpr auto RTTI = RTTI_DragonCameraState;
		inline static constexpr auto VTABLE = VTABLE_DragonCameraState;

		~DragonCameraState() override;  // 00

		// override (ThirdPersonState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                    // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                    // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;                      // 08

		void SetCameraHandle(RefHandle& a_handle) override;        // 09 - { return; }
		void Unk_0A(void) override;                                // 0A - { return; }
		void ProcessWeaponDrawnChange(bool a_drawn) override;      // 0B
		bool GetFreeRotationMode() const override;                 // 0C
		void SetFreeRotationMode(bool a_weaponSheathed) override;  // 0D
		void UpdateRotation();                                     // 0E
		void HandleLookInput(const NiPoint2& a_input) override;    // 0F

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                          // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;  // 04
	};
}
