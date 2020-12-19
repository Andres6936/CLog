// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

ConsoleLogger::ConsoleLogger() noexcept = default;

void ConsoleLogger::message(Level level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level == Level::ERROR or level == Level::SEVERE)
	{
		std::wcerr << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
	else
	{
		std::wcout << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
}
