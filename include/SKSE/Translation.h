#pragma once

namespace SKSE
{
	namespace Translation
	{
		void ParseTranslation(const std::string& a_name);

		bool Translate(const std::string& a_key, std::string& a_result);
	}
}
