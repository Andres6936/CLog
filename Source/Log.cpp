#include "Log.h"

#include "PRIVATE/ImplementationLog.h"

#include <chrono>
#include <cstdarg>
#include <iosfwd>
#include <sstream>
#include <vector>

using namespace CLog;

std::wostream& CLog::Log(Level level)
{
	CLog::Internal::local.level = level;
	return CLog::Internal::local.stream;
}

std::wostream& CLog::endl(std::wostream& stream)
{
	stream << std::endl;
	if (!CLog::Internal::local.stream.bad())
	{
		// only write to underyling logger, if we didn't set the bad-bit
		CLog::Internal::AppendLog(CLog::Internal::local.level,
				CLog::Internal::local.stream.str());
	}

	// reset stream-data (and state)
	CLog::Internal::local.stream.str(std::wstring());
	CLog::Internal::local.stream.clear();

	return CLog::Internal::local.stream;
}

std::wostream& operator<<(std::wostream& stream, const std::string& string)
{
	std::vector <wchar_t> result(string.size());
	size_t res = std::mbstowcs(result.data(), string.data(), string.size());
	if (res == static_cast<std::size_t>(-1))
	{
		// TODO handle error
		return stream;
	}
	return stream << std::wstring(result.data(), res);
}
