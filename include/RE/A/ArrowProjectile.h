#pragma once

#include "RE/M/MissileProjectile.h"

namespace RE
{
	class AlchemyItem;

	class ArrowProjectile : public MissileProjectile
	{
	public:
		inline static constexpr auto RTTI = RTTI_ArrowProjectile;
		inline static constexpr auto VTABLE = VTABLE_ArrowProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileArrow;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~ArrowProjectile() override;  // 00

		// override (MissileProjectile)
		void  SaveGame(BGSSaveFormBuffer* a_buf) override;                                                                                                                                // 0E
		void  LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                                // 0F
		void  PostLoad3D(NiAVObject* a_root) override;                                                                                                                                    // AA
		void  UpdateImpl(float a_delta) override;                                                                                                                                         // AB
		bool  ProcessImpacts() override;                                                                                                                                                  // AC
		void  Update3D() override;                                                                                                                                                        // AD
		float GetPowerSpeedMult() const override;                                                                                                                                         // AF
		float GetWeaponSpeedMult() const override;                                                                                                                                        // B0
		bool  GetStopMainSoundAfterImpact() override;                                                                                                                                     // B1 - { return 1; }
		float GetGravity() override;                                                                                                                                                      // B5
		bool  ShouldBeLimited() override;                                                                                                                                                 // B9 - { return (unk1CC >> 22) & 1; }
		void  AddImpact(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7) override;  // BD
		void  Handle3DLoaded() override;                                                                                                                                                  // C0
		void  Unk_C2(void) override;                                                                                                                                                      // C2 - { return 1; }
		void  Unk_C3(void) override;                                                                                                                                                      // C3 - { return 1; }

		// members
		EnchantmentItem* enchantItem;  // 1E0
		AlchemyItem*     poison;       // 1E8
	};
#ifndef SKYRIM_SUPPORT_AE
	static_assert(sizeof(ArrowProjectile) == 0x1F0);
#else
	static_assert(sizeof(ArrowProjectile) == 0x1F8);
#endif
}
