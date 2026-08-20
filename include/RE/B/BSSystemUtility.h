#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class BSSystemEvent;
	struct BSGamepadEvent;

	class BSSystemUtility :
		public BSTEventSink<BSGamepadEvent>,  // 000
		public BSTEventSource<BSSystemEvent>  // 008
	{
	public:
		virtual ~BSSystemUtility();  // 00

		// override (BSTEventSink<BSGamepadEvent>)
		BSEventNotifyControl ProcessEvent(const BSGamepadEvent* a_event, BSTEventSource<BSGamepadEvent>* a_eventSource) override;  // 01

		// add
#ifdef SKYRIM_SUPPORT_AE
		virtual void Unk_02(void* a_result);  // 02
#endif
		virtual void GetAuthenticationInfo(char*& a_userAuthID, std::uint64_t& a_size);  // 02
		virtual void Unk_03(void);                                                       // 03
		virtual void DoInitialize();                                                     // 04
		virtual void Unk_05(void);                                                       // 05
		virtual void DoUpdate();                                                         // 06
		virtual void Unk_07(void);                                                       // 07
		virtual void DoGetUserName(char* a_buffer, std::uint64_t a_size);                // 08
		virtual void Unk_09(void);                                                       // 09
		virtual void Unk_0A(void);                                                       // 0A
		virtual void Unk_0B(void);                                                       // 0B
		virtual void Unk_0C(void);                                                       // 0C
		virtual void DoGetComputerName(char* a_buffer, std::uint64_t a_size);            // 0D
		virtual void Unk_0E(void);                                                       // 0E
		virtual void Unk_0F(void);                                                       // 0F
		virtual void DoAuthenticateUser();                                               // 10
		virtual void Unk_11(void);                                                       // 11
		virtual bool Unk_12();                                                           // 12 - added in 1.6.1130

		// members
		std::uint64_t unk060[24];  // 060
		std::uint8_t  unk120;      // 120 - added in 1.6.1130
		std::uint8_t  unk121;      // 121 - added in 1.6.1130
		std::uint16_t pad122;      // 122
		std::uint32_t pad124;      // 124
	};
	static_assert(sizeof(BSSystemUtility) == 0x128);
}
