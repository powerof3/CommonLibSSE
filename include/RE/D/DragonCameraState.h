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
		void Begin() override;                                     // 01
		void End() override;                                       // 02
		void SaveGame(BGSSaveFormBuffer* a_buf) override;          // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;          // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;            // 08
		void SetCameraHandle(RefHandle& a_handle) override;        // 09 - { return; }
		void Unk_0A(void) override;                                // 0A - { return; }
		void ProcessWeaponDrawnChange(bool a_drawn) override;      // 0B
		bool GetFreeRotationMode() const override;                 // 0C
		void SetFreeRotationMode(bool a_weaponSheathed) override;  // 0D
		void UpdateRotation() override;                            // 0E
		void HandleLookInput(const NiPoint2& a_input) override;    // 0F

		ObjectRefHandle dragonHandle;      // 0E8
		std::uint32_t   unkEC;             // 0EC - bool?
		std::uint32_t   unkF0;             // 0F0 - bool?
		std::uint32_t   unkF4;             // 0F4 - float?
		bool            lockedOnTarget;    // 0F8
		std::uint8_t    padF9[3];          // 0F9
		std::uint32_t   unkFC;             // 0FC - float?
		std::uint32_t   unk100;            // 100
		std::uint32_t   unk104;            // 104 - float?
		std::uint32_t   unk108;            // 108
		ObjectRefHandle targetLockHandle;  // 10C
	};
	static_assert(sizeof(DragonCameraState) == 0x110);
}
