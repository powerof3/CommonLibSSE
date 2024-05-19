#include "RE/T/TESDataHandler.h"

#include "RE/T/TESFile.h"
#include "RE/T/TESForm.h"

namespace RE
{
	TESDataHandler* TESDataHandler::GetSingleton(bool a_VRESL)
	{
		REL::Relocation<TESDataHandler**> singleton{ Offset::TESDataHandler::Singleton };
#ifdef SKYRIMVR
		if (a_VRESL && !TESDataHandler::VRcompiledFileCollection) {
			const auto VRhandle = REX::W32::GetModuleHandleW(L"skyrimvresl");
			if (VRhandle != NULL) {
				const auto GetCompiledFileCollection = reinterpret_cast<const RE::TESFileCollection* (*)()>(REX::W32::GetProcAddress(VRhandle, "GetCompiledFileCollectionExtern"));
				if (GetCompiledFileCollection != nullptr) {
					TESDataHandler::VRcompiledFileCollection = const_cast<RE::TESFileCollection*>(GetCompiledFileCollection());
				}
			}
		}
#endif
		return *singleton;
	}

	bool TESDataHandler::AddFormToDataHandler(TESForm* a_form)
	{
		using func_t = decltype(&TESDataHandler::AddFormToDataHandler);
		REL::Relocation<func_t> func{ RELOCATION_ID(13597, 13693) };
		return func(this, a_form);
	}

	std::uint32_t TESDataHandler::LoadScripts()
	{
		using func_t = decltype(&TESDataHandler::LoadScripts);
		REL::Relocation<func_t> func{ Offset::TESDataHandler::LoadScripts };
		return func(this);
	}

	TESForm* TESDataHandler::LookupForm(FormID a_rawFormID, std::string_view a_modName)
	{
		auto file = LookupModByName(a_modName);
		if (!file || file->compileIndex == 0xFF) {
			return nullptr;
		}
#ifndef SKYRIMVR
		FormID formID = file->compileIndex << (3 * 8);
		formID += file->smallFileCompileIndex << ((1 * 8) + 4);
		formID += a_rawFormID;

		return TESForm::LookupByID(formID);
#else
		if (VRcompiledFileCollection) {
			FormID formID = file->compileIndex << (3 * 8);
			formID += file->smallFileCompileIndex << ((1 * 8) + 4);
			formID += a_rawFormID;
			return TESForm::LookupByID(formID);
		} else
			return TESForm::LookupByID(a_rawFormID & 0xFFFFFF | (file->compileIndex << 24));
#endif
	}

	FormID TESDataHandler::LookupFormID(FormID a_rawFormID, std::string_view a_modName)
	{
		auto file = LookupModByName(a_modName);
		if (!file || file->compileIndex == 0xFF) {
			return 0;
		}

		FormID formID = file->compileIndex << (3 * 8);
		formID += file->smallFileCompileIndex << ((1 * 8) + 4);
		formID += a_rawFormID;

		return formID;
	}

	const TESFile* TESDataHandler::LookupModByName(std::string_view a_modName)
	{
		for (auto& file : files) {
			if (a_modName.size() == strlen(file->fileName) &&
				_strnicmp(file->fileName, a_modName.data(), a_modName.size()) == 0) {
				return file;
			}
		}
		return nullptr;
	}

	std::optional<std::uint8_t> TESDataHandler::GetModIndex(std::string_view a_modName)
	{
		auto mod = LookupModByName(a_modName);
		return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
	}

	const TESFile* TESDataHandler::LookupLoadedModByName(std::string_view a_modName)
	{
		if (!VRcompiledFileCollection) {
			for (auto& file :
#ifndef SKYRIMVR
				compiledFileCollection.files
#else
				loadedMods
#endif
			) {
				if (file && a_modName.size() == strlen(file->fileName) &&
					_strnicmp(file->fileName, a_modName.data(), a_modName.size()) == 0) {
					return file;
				}
			}
		} else {  // support SkyrimVRESL
			for (auto& file : VRcompiledFileCollection->files) {
				if (file && a_modName.size() == strlen(file->fileName) &&
					_strnicmp(file->fileName, a_modName.data(), a_modName.size()) == 0) {
					return file;
				}
			}
			return nullptr;
		}
		return nullptr;
	}

	const TESFile* TESDataHandler::LookupLoadedModByIndex(std::uint8_t a_index)
	{
		if (!VRcompiledFileCollection) {
			for (auto& file :
#ifndef SKYRIMVR
				compiledFileCollection.files
#else
				loadedMods
#endif
			) {
				if (file && file->compileIndex == a_index) {
					return file;
				}
			}
		} else {
			for (auto& file : VRcompiledFileCollection->files) {
				if (file && file->compileIndex == a_index) {
					return file;
				}
			}
		}
		return nullptr;
	}

	std::optional<std::uint8_t> TESDataHandler::GetLoadedModIndex(std::string_view a_modName)
	{
		auto mod = LookupLoadedModByName(a_modName);
		return mod ? std::make_optional(mod->compileIndex) : std::nullopt;
	}

	const TESFile* TESDataHandler::LookupLoadedLightModByName(std::string_view
			a_modName)
	{
#ifndef SKYRIMVR
		for (auto& smallFile : compiledFileCollection.smallFiles) {
			if (a_modName.size() == strlen(smallFile->fileName) &&
				_strnicmp(smallFile->fileName, a_modName.data(), a_modName.size()) == 0) {
				return smallFile;
			}
		}
		return nullptr;
#else
		if (!VRcompiledFileCollection) {
			return LookupLoadedModByName(a_modName);
		} else {
			for (auto& smallFile : VRcompiledFileCollection->smallFiles) {
				if (a_modName.size() == strlen(smallFile->fileName) &&
					_strnicmp(smallFile->fileName, a_modName.data(), a_modName.size()) == 0) {
					return smallFile;
				}
			}
			return nullptr;
		}
#endif
	}

	const TESFile* TESDataHandler::LookupLoadedLightModByIndex(std::uint16_t
			a_index)
	{
#ifndef SKYRIMVR
		for (auto& smallFile : compiledFileCollection.smallFiles) {
			if (smallFile->smallFileCompileIndex == a_index) {
				return smallFile;
			}
		}
		return nullptr;
#else
		if (!VRcompiledFileCollection) {
			return LookupLoadedModByIndex(a_index);
		} else {
			for (auto& smallFile : VRcompiledFileCollection->smallFiles) {
				if (smallFile->smallFileCompileIndex == a_index) {
					return smallFile;
				}
			}
		}
		return nullptr;
#endif
	}

	std::optional<std::uint16_t> TESDataHandler::GetLoadedLightModIndex(std::string_view a_modName)
	{
		auto mod = LookupLoadedLightModByName(a_modName);
		return mod ? std::make_optional(mod->smallFileCompileIndex) : std::nullopt;
	}

	bool TESDataHandler::IsGeneratedID(FormID a_formID)
	{
		return a_formID >= 0xFF000000;
	}

	BSTArray<TESForm*>& TESDataHandler::GetFormArray(FormType a_formType)
	{
		return formArrays[std::to_underlying(a_formType)];
	}

	ObjectRefHandle TESDataHandler::CreateReferenceAtLocation(TESBoundObject* a_base, const NiPoint3& a_location, const NiPoint3& a_rotation, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, TESObjectREFR* a_alreadyCreatedRef, BGSPrimitive* a_primitive, const ObjectRefHandle& a_linkedRoomRefHandle, bool a_forcePersist, bool a_arg11)
	{
		using func_t = decltype(&TESDataHandler::CreateReferenceAtLocation);
		REL::Relocation<func_t> func{ RELOCATION_ID(13625, 13723) };
		return func(this, a_base, a_location, a_rotation, a_targetCell, a_selfWorldSpace, a_alreadyCreatedRef, a_primitive, a_linkedRoomRefHandle, a_forcePersist, a_arg11);
	}
}
