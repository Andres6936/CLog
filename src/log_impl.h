#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "log.h"

#include <chrono>
#include <sstream>

namespace Standard
{
    namespace internal
    {
        class Local
        {

        public:

            std::wstringstream stream;
            std::chrono::system_clock::time_point start;
            Standard::Level level;

            explicit Local() noexcept;
        };

        extern thread_local Local local;

        void AppendLog( Standard::Level level, const std::wstring &local );
    }
}

#endif /* LOG_IMPL_H */
