#include "ImplementationLog.h"
#include "Logger.h"

#include <mutex>
#include <queue>

using namespace Standard::Internal;

// Global logger
#ifndef CPPLOG_CUSTOM_LOGGER

std::unique_ptr <Standard::Logger> Standard::LOGGER =
        std::unique_ptr <Standard::Logger>( new Standard::ConsoleLogger( ));
#endif

thread_local Local Standard::Internal::local;

Local::Local( ) noexcept : level{ Standard::Level::DEBUG }
{ }

void Standard::Internal::AppendLog( Standard::Level level, const std::wstring &basicString )
{
    Standard::LOGGER->message( level, basicString );
}
