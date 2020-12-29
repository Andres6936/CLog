// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

ConsoleLogger::ConsoleLogger() noexcept = default;

void ConsoleLogger::Message(SeverityLevel level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level >= SeverityLevel::Emergency and level <= SeverityLevel::Error)
	{
		std::wcerr << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
	else
	{
		std::wcout << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
}
