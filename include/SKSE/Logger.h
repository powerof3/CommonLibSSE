#pragma once

namespace SKSE::log
{
	[[nodiscard]] std::optional<std::filesystem::path> log_directory();

	void add_papyrus_sink(std::regex a_filter);
	void remove_papyrus_sink();
}
