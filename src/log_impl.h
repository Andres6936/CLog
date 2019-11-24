/*
 * File:   log_impl.h
 * Author: doe300
 *
 * Created on September 16, 2016, 1:46 PM
 */

#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "log.h"

#include <chrono>
#include <sstream>

namespace Standard
{
    namespace internal
    {
        struct Local
        {
            std::wstringstream stream;
            std::chrono::system_clock::time_point start;
            Standard::Level level;

            explicit Local() noexcept;
        };

        extern thread_local Local local;

        void appendLog(
                Standard::Level level, const std::wstring &local, std::chrono::system_clock::time_point timestamp );
    } // namespace internal
} // namespace Standard

#endif /* LOG_IMPL_H */
