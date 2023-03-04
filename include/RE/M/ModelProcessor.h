#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/D/DBTraits.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;

	namespace BSModelDB
	{
		class BSModelProcessor : public BSTSingletonExplicit<BSModelProcessor>
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSModelDB__BSModelProcessor;
			inline static constexpr auto VTABLE = VTABLE_BSModelDB__BSModelProcessor;

			virtual ~BSModelProcessor();

			// add
			virtual void PostCreate(const DBTraits::ArgsType& a_args, const char* modelName, NiPointer<NiNode>& a_root, std::uint32_t& a_typeOut);
		};
	}

	namespace TESModelDB
	{
		class TESProcessor : public BSModelDB::BSModelProcessor
		{
		public:
			inline static constexpr auto RTTI = RTTI_TESModelDB____TESProcessor;
			inline static constexpr auto VTABLE = VTABLE_TESModelDB____TESProcessor;

			~TESProcessor() override;

			// override (BSModelDM::BSModelProcessor)
			void PostCreate(const BSModelDB::DBTraits::ArgsType& a_args, const char* modelName, NiPointer<NiNode>& a_root, std::uint32_t& a_typeOut) override;
		};
	}
}
