#pragma once

#include "RE/B/BSResourceEntryDB.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;

	namespace BSModelDB
	{
		struct DBTraits;
	}

	namespace BSResource
	{
		template <class T_Entry, class T_EntryDB>
		class RHandleType
		{
		public:
			using U_Entry = T_Entry;
			using U_EntryDB = T_EntryDB;

			[[nodiscard]] constexpr T_Entry* get() const noexcept
			{
				return _entry;
			}

			[[nodiscard]] explicit constexpr operator bool() const noexcept
			{
				return static_cast<bool>(_entry);
			}

			[[nodiscard]] constexpr T_Entry& operator*() const noexcept
			{
				assert(static_cast<bool>(*this));
				return *_entry;
			}

			[[nodiscard]] constexpr T_Entry* operator->() const noexcept
			{
				assert(static_cast<bool>(*this));
				return _entry;
			}

		protected:
			// members
			T_Entry* _entry;  // 00
		};
	}

	using ModelDBHandle = BSResource::RHandleType<BSResource::Entry<NiPointer<NiNode>, BSResource::EntryDBTraits<BSModelDB::DBTraits, BSResource::EntryDB<BSModelDB::DBTraits>>::CArgs>, BSResource::EntryDB<BSModelDB::DBTraits>>;
}
