#pragma once

#include "RE/B/BSReloadShaderI.h"
#include "RE/B/BSShader.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	class BSComputeShader : public NiRefObject, public BSReloadShaderI
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSComputeShader;
		inline static constexpr auto VTABLE = VTABLE_BSComputeShader;

		~BSComputeShader() override;  // 00

		// override (BSReloadShaderI)
		void ReloadShaders(void* stream) override;  // 00

		// add
		virtual void Dispatch(uint32_t techniqueId, uint32_t threadGroupCountX, uint32_t threadGroupCountY, uint32_t threadGroupCountZ);  // 02

		const char*                                      name;        // 18
		BSTHashMap<uint32_t, BSGraphics::ComputeShader*> shadersMap;  // 20

	private:
		KEEP_FOR_RE()
	};
	static_assert(sizeof(BSComputeShader) == 0x50);
}
