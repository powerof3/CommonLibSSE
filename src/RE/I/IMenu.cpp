#include "RE/I/IMenu.h"

#include "RE/B/BSInputDeviceManager.h"
#include "RE/B/BSUIScaleformData.h"
#include "RE/G/GFxValue.h"
#include "RE/I/InterfaceStrings.h"
#include "RE/U/UI.h"
#include "RE/U/UIMessage.h"
#include "RE/U/UIMessageQueue.h"

namespace RE
{
	void IMenu::Accept(CallbackProcessor*)
	{}

	void IMenu::PostCreate()
	{}

	void IMenu::Unk_03(void)
	{}

	UI_MESSAGE_RESULTS IMenu::ProcessMessage(UIMessage& a_message)
	{
		if (a_message.type != UI_MESSAGE_TYPE::kScaleformEvent) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		if (!uiMovie) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		const auto data = static_cast<BSUIScaleformData*>(a_message.data);
		if (!data) {
			return UI_MESSAGE_RESULTS::kPassOn;
		}

		uiMovie->HandleEvent(*data->scaleformEvent);
		return UI_MESSAGE_RESULTS::kHandled;
	}

	void IMenu::AdvanceMovie(float, std::uint32_t a_currentTime)
	{
		if (uiMovie) {
			const GFxValue currentTime(static_cast<double>(a_currentTime));
			uiMovie->SetVariable("CurrentTime", currentTime, GFxMovie::SetVarType::kNormal);
			uiMovie->Advance(static_cast<float>(currentTime.GetNumber()));
		}
	}

	void IMenu::PostDisplay()
	{
		if (uiMovie) {
			uiMovie->Display();
		}
	}

	void IMenu::PreDisplay()
	{}

	void IMenu::RefreshPlatform()
	{
		using func_t = decltype(&IMenu::RefreshPlatform);
		static REL::Relocation<func_t> func{ RELOCATION_ID(80287, 82309) };
		return func(this);
	}
}
