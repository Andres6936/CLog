#include "ImplementationLog.h"
#include "Logger.h"

#include <mutex>
#include <queue>

using namespace Levin::Internal;

// Global logger
#ifndef CPPLOG_CUSTOM_LOGGER

std::unique_ptr <Levin::Logger> Levin::LOGGER =
		std::unique_ptr <Levin::Logger>(new Levin::ConsoleLogger());

#endif

thread_local Local Levin::Internal::local;

Local::Local() noexcept : level{ Levin::Level::DEBUG }
{
}

void Levin::Internal::AppendLog(Levin::Level level, const std::wstring& basicString)
{
	Levin::LOGGER->message(level, basicString);
}
