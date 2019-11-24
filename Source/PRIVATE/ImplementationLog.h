#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "Log.h"

#include <chrono>
#include <sstream>

namespace Standard
{
    namespace Internal
    {
        class Local
        {

        public:

            std::wstringstream stream;

            Standard::Level level;

            explicit Local() noexcept;
        };

        extern thread_local Local local;

        void AppendLog( Standard::Level level, const std::wstring &basicString );
    }
}

#endif /* LOG_IMPL_H */
