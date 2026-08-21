#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSString.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class BSSaveDataEvent;

	class BSSaveDataSystemUtility :
		public BSTEventSource<BSSaveDataEvent>  // 008
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSSaveDataSystemUtility;
		inline static constexpr auto VTABLE = VTABLE_BSSaveDataSystemUtility;

		class Entry
		{
		public:
			inline static constexpr auto RTTI = RTTI_BSSaveDataSystemUtility__Entry;
			inline static constexpr auto VTABLE = VTABLE_BSSaveDataSystemUtility__Entry;

			virtual void Read(const char* a_path);  // 00

			enum class SaveType : std::uint32_t
			{
				kAutosave = 0x0,
				kSave = 0x1,
				kQuicksave = 0x2,
				kCustom = 0x3
			};

			// members
			const char                            fileName[0x104];  // 008
			std::uint32_t                         pad0C;            // 00C
			BSString                              fileNamePtr;      // 110
			std::uint64_t                         unk120;           // 120
			std::uint32_t                         unk128;           // 128
			std::uint32_t                         pad12C;           // 12C
			BSString                              locationName;     // 130
			BSString                              unk140;           // 140
			BSString                              characterName;    // 150
			std::uint64_t                         unk160;           // 160
			std::uint32_t                         unk168;           // 168
			std::uint32_t                         pad16C;           // 16C
			std::uint64_t                         unk170;           // 170
			std::uint32_t                         unk178;           // 178
			std::uint32_t                         saveNumber;       // 17C
			std::uint32_t                         characterID;      // 180
			std::uint32_t                         unk184;           // 184
			bool                                  fileNameValid;    // 188
			bool                                  modded;           // 189
			std::uint8_t                          unk18A;           // 18A
			std::uint8_t                          pad18B;           // 18B
			std::uint32_t                         pad18C;           // 18C
			BSFixedString                         saveTypeName;     // 190
			REX::TEnumSet<SaveType, std::uint32_t> saveType;         // 198
			std::uint32_t                         pad19C;           // 19C
		};
		static_assert(sizeof(Entry) == 0x1A0);

		virtual ~BSSaveDataSystemUtility();  // 00

		// add
		virtual bool    CreateSaveDirectory(const char* a_pathName, bool a_ignoreINI) = 0;                               // 01
		virtual errno_t PrepareFileSavePath(const char* a_fileName, char* a_dst, bool a_tmpSave, bool a_ignoreINI) = 0;  // 02 - a_dst must be 0x104 in length
		virtual void    Unk_03(void);                                                                                    // 03 - { return Unk_04(); }
		virtual void    Unk_04(void);                                                                                    // 04 - { return; }
		virtual void    Unk_05(void);                                                                                    // 05
		virtual void    Unk_06(void) = 0;                                                                                // 06
		virtual void    Unk_07(void);                                                                                    // 07
		virtual void    Unk_08(void);                                                                                    // 08 - { return; }
		virtual void    Unk_09(void);                                                                                    // 09 - { return; }
		virtual void    Unk_0A(void);                                                                                    // 0A
		virtual void    Unk_0B(void);                                                                                    // 0B - { return; }
		virtual void    Unk_0C(void);                                                                                    // 0C
		virtual void    Unk_0D(void);                                                                                    // 0D - { return; }
		virtual void    Unk_0E(void);                                                                                    // 0E - { return 1; }
		virtual void    Unk_0F(void);                                                                                    // 0F - { return 1; }
		virtual void    Unk_10(void);                                                                                    // 10 - { return 0; }
		virtual void    Unk_11(void);                                                                                    // 11 - { return; }

		// members
		std::uint8_t  unk060;              // 060
		std::uint8_t  pad061;              // 061
		std::uint16_t pad062;              // 062
		std::uint32_t currentCharacterID;  // 064
		std::uint8_t  unk068;              // 068
		std::uint8_t  pad069;              // 069
		std::uint16_t pad06A;              // 06A
		std::uint32_t pad06C;              // 06C
		Entry         entry;               // 070
		std::uint32_t unk210;              // 210
		std::uint32_t pad214;              // 214
		std::uint64_t unk218;              // 218
		std::uint64_t unk220;              // 220
	};
	static_assert(sizeof(BSSaveDataSystemUtility) == 0x228);
}
