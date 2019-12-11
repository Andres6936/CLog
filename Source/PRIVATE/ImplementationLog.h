#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "Log.h"

#include <chrono>
#include <sstream>

namespace CLog::Internal
{
	class Local
	{

	public:

		std::wstringstream stream;

		CLog::Level level;

		explicit Local() noexcept;
	};

	extern thread_local Local local;

	void AppendLog(CLog::Level level, const std::wstring& basicString);
}

#endif /* LOG_IMPL_H */
