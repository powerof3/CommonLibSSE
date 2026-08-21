#include "RE/B/BSLightingShaderMaterialBase.h"

#include "RE/B/BSLightingShaderMaterial.h"
#include "RE/B/BSLightingShaderMaterialEnvmap.h"
#include "RE/B/BSLightingShaderMaterialEye.h"
#include "RE/B/BSLightingShaderMaterialFacegen.h"
#include "RE/B/BSLightingShaderMaterialFacegenTint.h"
#include "RE/B/BSLightingShaderMaterialGlowmap.h"
#include "RE/B/BSLightingShaderMaterialHairTint.h"
#include "RE/B/BSLightingShaderMaterialLODLandscape.h"
#include "RE/B/BSLightingShaderMaterialLandscape.h"
#include "RE/B/BSLightingShaderMaterialMultiLayerParallax.h"
#include "RE/B/BSLightingShaderMaterialParallax.h"
#include "RE/B/BSLightingShaderMaterialParallaxOcc.h"
#include "RE/B/BSLightingShaderMaterialSnow.h"
#include "RE/B/BSTextureSet.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	void BSLightingShaderMaterialBase::CopyBaseMembers(BSLightingShaderMaterialBase* a_other)
	{
		texCoordOffset[0] = a_other->texCoordOffset[0];
		texCoordOffset[1] = a_other->texCoordOffset[1];
		texCoordScale[0] = a_other->texCoordScale[0];
		texCoordScale[1] = a_other->texCoordScale[1];

		diffuseTexture = a_other->diffuseTexture;
		normalTexture = a_other->normalTexture;
		rimSoftLightingTexture = a_other->rimSoftLightingTexture;
		specularBackLightingTexture = a_other->specularBackLightingTexture;
		textureClampMode = a_other->textureClampMode;
		textureSet = a_other->textureSet;

		materialAlpha = a_other->materialAlpha;
		specularPower = a_other->specularPower;
		specularColor = a_other->specularColor;
		specularColorScale = a_other->specularColorScale;
		refractionPower = a_other->refractionPower;
		subSurfaceLightRolloff = a_other->subSurfaceLightRolloff;
		rimLightPower = a_other->rimLightPower;
	}

	BSLightingShaderMaterialBase* BSLightingShaderMaterialBase::CreateMaterial(Feature a_feature)
	{
		auto scrapHeap = MemoryManager::GetSingleton()->GetThreadScrapHeap();
		switch (a_feature) {
		case Feature::kDefault:
			{
				auto material = static_cast<BSLightingShaderMaterial*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterial), 8));
				if (material) {
					std::memset((void*)material, 0, sizeof(BSLightingShaderMaterial));
					material->Ctor();
					REX::EMPLACE_VTABLE<BSLightingShaderMaterial>(material);
				}
				return material;
			}
		case Feature::kEnvironmentMap:
			{
				auto material = static_cast<BSLightingShaderMaterialEnvmap*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialEnvmap), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kGlowMap:
			{
				auto material = static_cast<BSLightingShaderMaterialGlowmap*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialGlowmap), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kParallax:
			{
				auto material = static_cast<BSLightingShaderMaterialParallax*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialParallax), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kFaceGen:
			{
				auto material = static_cast<BSLightingShaderMaterialFacegen*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialFacegen), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kFaceGenRGBTint:
			{
				auto material = static_cast<BSLightingShaderMaterialFacegenTint*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialFacegenTint), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kHairTint:
			{
				auto material = static_cast<BSLightingShaderMaterialHairTint*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialHairTint), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kParallaxOcc:
			{
				auto material = static_cast<BSLightingShaderMaterialParallaxOcc*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialParallaxOcc), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kMultiTexLand:
		case Feature::kMultiTexLandLODBlend:
			{
				auto material = static_cast<BSLightingShaderMaterialLandscape*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialLandscape), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kLODLand:
		case Feature::kLODLandNoise:
			{
				auto material = static_cast<BSLightingShaderMaterialLODLandscape*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialLODLandscape), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kUnknown:
		case Feature::kMultiIndexTriShapeSnow:
			{
				auto material = static_cast<BSLightingShaderMaterialSnow*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialSnow), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kMultilayerParallax:
			{
				auto material = static_cast<BSLightingShaderMaterialMultiLayerParallax*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialMultiLayerParallax), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		case Feature::kEye:
			{
				auto material = static_cast<BSLightingShaderMaterialEye*>(scrapHeap->Allocate(sizeof(BSLightingShaderMaterialEye), 8));
				if (material) {
					material->Ctor();
				}
				return material;
			}
		default:
			return nullptr;
		}
	}

	NiPointer<BSTextureSet> BSLightingShaderMaterialBase::GetTextureSet() const
	{
		return textureSet;
	}

	void BSLightingShaderMaterialBase::SetTextureSet(NiPointer<BSTextureSet> a_textureSet)
	{
		textureSet = a_textureSet;
	}
}
