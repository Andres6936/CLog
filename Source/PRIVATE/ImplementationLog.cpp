#include "ImplementationLog.h"
#include "Levin/Logger.h"
#include "Levin/ConsoleLogger.hpp"

#include <mutex>

using namespace Levin::Internal;

std::unique_ptr <Levin::Logger> Levin::logger = std::make_unique <Levin::ConsoleLogger>();

thread_local Local Levin::Internal::local;

Local::Local() noexcept : level{ Levin::Level::DEBUG }
{
}

void Levin::Internal::AppendLog(Levin::Level level, const std::wstring& basicString)
{
	Levin::logger->message(level, basicString);
}
