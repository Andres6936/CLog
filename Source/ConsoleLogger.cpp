// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

ConsoleLogger::ConsoleLogger() noexcept = default;

void ConsoleLogger::Message(SecurityLevel level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level >= SecurityLevel::Emergency and level <= SecurityLevel::Error)
	{
		std::wcerr << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
	else
	{
		std::wcout << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
}
