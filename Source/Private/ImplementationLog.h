#ifndef LOG_IMPL_H
#define LOG_IMPL_H

#include "Levin/Log.hpp"

#include <chrono>
#include <sstream>

namespace Levin::Internal
{
	class Local final
	{

	public:

		std::wstringstream stream;

		Levin::Level level;

		explicit Local() noexcept;
	};

	extern thread_local Local local;

	void AppendLog(Levin::Level level, const std::wstring& basicString);
}

#endif /* LOG_IMPL_H */
