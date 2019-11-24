/*
 * File:   log_impl.cpp
 * Author: doe300
 *
 * Created on September 16, 2016, 1:46 PM
 */
#include "log_impl.h"
#include "../include/logger.h"

#include <chrono>
#include <mutex>
#include <queue>
#include <utility>

using namespace Standard::internal;

// Global logger
#ifndef CPPLOG_CUSTOM_LOGGER

std::unique_ptr <Standard::Logger> Standard::LOGGER =
        std::unique_ptr <Standard::Logger>( new Standard::ConsoleLogger( ));
#endif

thread_local Local Standard::internal::local;

Local::Local( ) noexcept : level{ Standard::Level::DEBUG }
{ }

void Standard::internal::appendLog( const Standard::Level level, const std::wstring &local,
    const std::chrono::system_clock::time_point timestamp)
{
    Standard::LOGGER->logMessage( level, local, timestamp );
}
