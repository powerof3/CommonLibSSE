#include "RE/P/Projectile.h"
#include "RE/A/AIProcess.h"
#include "RE/E/Effect.h"
#include "RE/F/FormTraits.h"
#include "RE/M/MagicCaster.h"

namespace RE
{
	Projectile::Manager* Projectile::Manager::GetSingleton()
	{
		static REL::Relocation<Manager**> singleton{ RELOCATION_ID(514313, 400473) };
		return *singleton;
	}

	Projectile::LaunchData::LaunchData(BGSProjectile* a_bproj, Actor* a_shooter, const NiPoint3& a_origin, const ProjectileRot& a_angles) :
		origin(a_origin),
		contactNormal(NiPoint3()),
		projectileBase(a_bproj),
		shooter(a_shooter),
		combatController(a_shooter->combatController),
		weaponSource(nullptr),
		ammoSource(nullptr),
		angleZ(a_angles.z),
		angleX(a_angles.x),
		unk50(nullptr),
		desiredTarget(nullptr),
		unk60(0.0f),
		unk64(0.0f),
		parentCell(a_shooter->GetParentCell()),
		spell(nullptr),
		castingSource(MagicSystem::CastingSource::kOther),
		pad7C(0),
		enchantItem(nullptr),
		poison(nullptr),
		area(0),
		power(1.0f),
		scale(1.0f),
		alwaysHit(false),
		noDamageOutsideCombat(false),
		autoAim(true),
		chainShatter(false),
		useOrigin(false),
		deferInitialization(false),
		forceConeOfFire(false)
	{
		REX::EMPLACE_VTABLE(this);
	}

	Projectile::LaunchData::LaunchData(Actor* a_shooter, const NiPoint3& a_origin, const ProjectileRot& a_angles, MagicItem* a_spell) :
		LaunchData(a_spell->GetAVEffect()->data.projectileBase, a_shooter, a_origin, a_angles)
	{
		const auto costliestEffect = a_spell->GetCostliestEffectItem();

		spell = a_spell;
		area = costliestEffect ? costliestEffect->GetArea() : 0;
		useOrigin = true;
		autoAim = false;
	}

	Projectile::LaunchData::LaunchData(Actor* a_shooter, const NiPoint3& a_origin, const ProjectileRot& a_angles, TESAmmo* a_ammo, TESObjectWEAP* a_weap) :
		LaunchData(a_ammo->data.projectile, a_shooter, a_origin, a_angles)
	{
		weaponSource = a_weap;
		ammoSource = a_ammo;
		useOrigin = true;
		autoAim = false;
	}

	BGSProjectile* Projectile::GetProjectileBase() const
	{
		auto obj = GetObjectReference();
		return obj ? obj->As<BGSProjectile>() : nullptr;
	}

	float Projectile::GetHeight() const
	{
		if (const auto baseProjectile = GetProjectileBase()) {
			return baseProjectile->data.collisionRadius * 2;
		}
		return 0.0f;
	}

	float Projectile::GetSpeed() const
	{
		if (const auto baseProjectile = GetProjectileBase()) {
			return baseProjectile->data.speed * GetPowerSpeedMult() * GetWeaponSpeedMult() * speedMult;
		}
		return 0.0f;
	}

	ProjectileHandle* Projectile::Launch(ProjectileHandle* a_result, LaunchData& a_data) noexcept
	{
		using func_t = decltype(&Projectile::Launch);
		static REL::Relocation<func_t> func{ RELOCATION_ID(42928, 44108) };
		return func(a_result, a_data);
	}

	ProjectileHandle* Projectile::LaunchSpell(ProjectileHandle* a_result, Actor* a_shooter, SpellItem* a_spell, const NiPoint3& a_origin, const ProjectileRot& a_angles) noexcept
	{
		LaunchData launchData(a_shooter, a_origin, a_angles, a_spell);
		return Launch(a_result, launchData);
	}

	ProjectileHandle* Projectile::LaunchSpell(ProjectileHandle* a_result, Actor* a_shooter, SpellItem* a_spell, MagicSystem::CastingSource a_source) noexcept
	{
		const auto caster = a_shooter->GetMagicCaster(a_source);
		if (!caster) {
			return a_result;
		}

		NiPoint3 origin;
		if (const auto node = caster->GetMagicNode()) {
			origin = node->world.translate;
		} else {
			origin = a_shooter->GetPosition();
			const auto bound_max = a_shooter->GetBoundMax();
			const auto bound_min = a_shooter->GetBoundMin();
			origin.z += (bound_max.z - bound_min.z) * 0.7f;
		}

		ProjectileRot angles{ a_shooter->GetAimAngle(), a_shooter->GetAimHeading() };

		return LaunchSpell(a_result, a_shooter, a_spell, origin, angles);
	}

	ProjectileHandle* Projectile::LaunchArrow(ProjectileHandle* a_result, Actor* a_shooter, TESAmmo* a_ammo, TESObjectWEAP* a_weap, const NiPoint3& a_origin, const ProjectileRot& a_angles) noexcept
	{
		LaunchData launchData(a_shooter, a_origin, a_angles, a_ammo, a_weap);
		return Launch(a_result, launchData);
	}

	ProjectileHandle* Projectile::LaunchArrow(ProjectileHandle* a_result, Actor* a_shooter, TESAmmo* a_ammo, TESObjectWEAP* a_weap) noexcept
	{
		NiAVObject* fireNode;

		if (const auto currentProcess = a_shooter->currentProcess) {
			const auto& biped = a_shooter->GetBiped2();
			fireNode = a_weap->IsCrossbow() ? currentProcess->GetMagicNode(biped) : currentProcess->GetWeaponNode(biped);
		} else {
			fireNode = a_weap->GetFireNode(a_shooter->IsPlayerRef() ? a_shooter->GetCurrent3D() : a_shooter->Get3D2());
		}

		NiPoint3      origin;
		ProjectileRot angles{};

		if (fireNode) {
			origin = fireNode->world.translate;
			a_shooter->Unk_A0(fireNode, angles.x, angles.z, origin);
		} else {
			origin = a_shooter->GetPosition();
			origin.z += 96.0f;

			angles.x = a_shooter->GetAimAngle();
			angles.z = a_shooter->GetAimHeading();
		}

		return LaunchArrow(a_result, a_shooter, a_ammo, a_weap, origin, angles);
	}

	void Projectile::Kill()
	{
		using func_t = decltype(&Projectile::Kill);
		static REL::Relocation<func_t> func{ RELOCATION_ID(42930, 44110) };

		return func(this);
	}

}
