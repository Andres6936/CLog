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

		Levin::SecurityLevel level;

		explicit Local() noexcept;
	};

	extern thread_local Local local;

	void AppendLog(Levin::SecurityLevel level, std::wstring_view basicString);
}

#endif /* LOG_IMPL_H */
