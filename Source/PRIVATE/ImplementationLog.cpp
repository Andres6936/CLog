#include "ImplementationLog.h"
#include "Logger.h"

#include <mutex>
#include <queue>

using namespace CLog::Internal;

// Global logger
#ifndef CPPLOG_CUSTOM_LOGGER

std::unique_ptr <CLog::Logger> CLog::LOGGER =
		std::unique_ptr <CLog::Logger>(new CLog::ConsoleLogger());

#endif

thread_local Local CLog::Internal::local;

Local::Local() noexcept : level{ CLog::Level::DEBUG }
{
}

void CLog::Internal::AppendLog(CLog::Level level, const std::wstring& basicString)
{
	CLog::LOGGER->message(level, basicString);
}
