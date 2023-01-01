#pragma once

#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	struct BGSDecalGroup;

	class GrenadeProjectile : public Projectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_GrenadeProjectile;
		inline static constexpr auto VTABLE = VTABLE_GrenadeProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileGrenade;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~GrenadeProjectile() override;  // 00

		// override (Projectile)
		void           SaveGame(BGSSaveFormBuffer* a_buf) override;                                                                                                                                // 0E
		void           LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                                // 0F
		void           InitLoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                            // 10
		void           FinishLoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                          // 11
		void           Revert(BGSLoadFormBuffer* a_buf) override;                                                                                                                                  // 12
		BGSDecalGroup* GetDecalGroup() const override;                                                                                                                                             // 9F - { return decalGroup; }
		bool           IsGrenadeProjectile() override;                                                                                                                                             // A3 - { return 1; }
		void           OnKill() override;                                                                                                                                                          // A8
		void           Process3D() override;                                                                                                                                                       // A9
		void           UpdateImpl(float a_delta) override;                                                                                                                                         // AB
		void           Unk_AE(void) override;                                                                                                                                                      // AE
		void           ReportHavokDeactivation() override;                                                                                                                                         // B2
		bool           TurnOff(Actor* a_owner, bool a_noDeactivateSound) override;                                                                                                                 // B3
		bool           IsPermanent() const override;                                                                                                                                               // B4
		bool           TargetsWholeBody() override;                                                                                                                                                // BA - { return 1; }
		std::uint32_t  GetCollisionGroup() override;                                                                                                                                               // BB
		void           AddImpact(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7) override;  // BD
		void           OnTriggerEnter() override;                                                                                                                                                  // BF - { flags |= 1 << 30; }
		void           Handle3DLoaded() override;                                                                                                                                                  // C0

		// members
		BGSDecalGroup* decalGroup;           // 1D8
		bool           collisionGroupReset;  // 1E0
		std::uint8_t   pad1E1;               // 1E1
		std::uint16_t  pad1E2;               // 1E2
		std::uint32_t  pad1E4;               // 1E4
	};
	static_assert(sizeof(GrenadeProjectile) == 0x1E8);
}
