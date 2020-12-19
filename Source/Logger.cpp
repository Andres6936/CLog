#include "Levin/Logger.hpp"

#include <ctime>
#include <ios>

using namespace Levin;

Logger::Logger() noexcept : writeLock()
{
}

std::wstring Logger::GetCurrentTime() const noexcept
{
	time_t now = std::time(nullptr);
	std::string text = std::ctime(&now);
	// required, since ctime (asctime) append a new-line
	text.erase(text.find_last_of('\n'), 1);
	// Return the std::wstring (overload of std::string)
	return { text.begin(), text.end() };
}

std::wstring Logger::ToString(Level level) const noexcept
{
	switch (level)
	{
	case Level::DEBUG:
		return L"[D]";
	case Level::INFO:
		return L"[I]";
	case Level::WARNING:
		return L"[W]";
	case Level::ERROR:
		return L"[E]";
	case Level::SEVERE:
		return L"[S]";
	}
}