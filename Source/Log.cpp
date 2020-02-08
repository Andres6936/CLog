#include "Log.h"

#include "PRIVATE/ImplementationLog.h"

#include <chrono>
#include <cstdarg>
#include <iosfwd>
#include <sstream>
#include <vector>

using namespace Levin;

std::wostream& Levin::Log(Level level)
{
	Levin::Internal::local.level = level;
	return Levin::Internal::local.stream;
}

std::wostream& Levin::endl(std::wostream& stream)
{
	stream << std::endl;
	if (!Levin::Internal::local.stream.bad())
	{
		// only write to underyling logger, if we didn't set the bad-bit
		Levin::Internal::AppendLog(Levin::Internal::local.level,
				Levin::Internal::local.stream.str());
	}

	// reset stream-data (and state)
	Levin::Internal::local.stream.str(std::wstring());
	Levin::Internal::local.stream.clear();

	return Levin::Internal::local.stream;
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
