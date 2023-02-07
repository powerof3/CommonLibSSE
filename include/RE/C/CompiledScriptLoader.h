#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/ILoader.h"
#include "RE/I/IVMSaveLoadInterface.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class IStore;

		class CompiledScriptLoader : public ILoader
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSScript__CompiledScriptLoader;
			inline static constexpr auto VTABLE = VTABLE_BSScript__CompiledScriptLoader;

			~CompiledScriptLoader() override;  // 00

			// override (ILoader)
			ILoader* Clone() override;                                                                  // 01
			void     SetScriptStore(const BSTSmartPointer<IStore>& a_store) override;                   // 02
			bool     GetClass(const char* a_name, BSScript::UnlinkedTypes::Object& a_object) override;  // 03

			// members
			ErrorLogger*            errorHandler;         // 08
			BSTSmartPointer<IStore> scriptStore;          // 10
			ReadableStringTable     readableStringTable;  // 18 - This gets filled and cleared each time reading from a script
			std::byte               majorVersion;         // 30 - Set each time reading from a script
			std::byte               minorVersion;         // 31 - Set each time reading from a script
			std::byte               loadDebugInfo: 1;     // 32 - Set to INI setting `Papyrus::bLoadDebugInformation` in the constructor
			std::byte               loadDocStrings: 1;    // 32 - Never set true in vanilla, requires loadDebugInfo = 1 to work
		};
		static_assert(sizeof(CompiledScriptLoader) == 0x38);
	}
}
