#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class BSProceduralGeomEvent;
	struct BeamProjectileImpactEvent;

	class BeamProjectile :
		public Projectile,                                 // 000
		public BSTEventSource<BeamProjectileImpactEvent>,  // 1E0
		public BSTEventSink<BSProceduralGeomEvent>         // 1D8
	{
	public:
		inline static constexpr auto RTTI = RTTI_BeamProjectile;
		inline static constexpr auto VTABLE = VTABLE_BeamProjectile;
		inline static constexpr auto FORMTYPE = FormType::ProjectileBeam;

		struct RecordFlags
		{
			enum RecordFlag : std::uint32_t
			{
			};
		};

		~BeamProjectile() override;  // 00

		// override (Projectile)
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                                                                                                                                // 0E
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                                // 0F
		void InitLoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                            // 10
		void FinishLoadGame(BGSLoadFormBuffer* a_buf) override;                                                                                                                          // 11
		void Revert(BGSLoadFormBuffer* a_buf) override;                                                                                                                                  // 12
		bool IsBeamProjectile() override;                                                                                                                                                // A5
		void Process3D() override;                                                                                                                                                       // A9
		void UpdateImpl(float a_delta) override;                                                                                                                                         // AB
		bool GetKillOnCollision() override;                                                                                                                                              // B8
		void AddImpact(TESObjectREFR* a_ref, const NiPoint3& a_targetLoc, const NiPoint3& a_velocity, hkpCollidable* a_collidable, std::int32_t a_arg6, std::uint32_t a_arg7) override;  // BD
		void Handle3DLoaded() override;                                                                                                                                                  // C0
		bool ShouldUseDesiredTarget() override;                                                                                                                                          // C1

		// override (BSTEventSink<BSProceduralGeomEvent>)
		BSEventNotifyControl ProcessEvent(const BSProceduralGeomEvent* a_event, BSTEventSource<BSProceduralGeomEvent>* a_eventSource) override;  // 01

		// members
		std::uint64_t unk238;  // 238
	};
	static_assert(sizeof(BeamProjectile) == 0x240);
}
