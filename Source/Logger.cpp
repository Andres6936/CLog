#include "Levin/Logger.hpp"

using namespace Levin;

Logger::Logger() noexcept : writeLock()
{
}

std::wstring Logger::GetCurrentTime() const noexcept
{
	time_t now = std::time(nullptr);
	// Converts given time since epoch to a calendar local time and then to a
	// textual representation, the type of return is char*, should be convert
	// to std::string
	std::string text = std::ctime(&now);
	// required, since ctime (asctime) append a new-line
	text.erase(text.find_last_of('\n'), 1);
	// Convert the std::string to std::wstring
	// Note, this code only works if all the characters are single byte, i.e.
	// ASCII or ISO-8859-1. Anything multi-byte will fail miserably, including
	// UTF-8.
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
	default:
		return L"[U]";
	}
}