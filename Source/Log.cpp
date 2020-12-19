#include "Levin/Log.hpp"
#include "Private/ImplementationLog.h"

#include <cstdarg>
#include <iosfwd>
#include <sstream>
#include <vector>

using namespace Levin;

std::wostream& Levin::Log(Level level, std::string_view message)
{
	Internal::local.level = level;
	return write(Internal::local.stream, message) << Levin::endl;
}

std::wostream& Levin::endl(std::wostream& stream)
{
	stream << std::endl;
	if (!Internal::local.stream.bad())
	{
		// only write to underyling logger, if we didn't set the bad-bit
		Internal::AppendLog(Internal::local.level,
				Internal::local.stream.str());
	}

	// reset stream-data (and state)
	Internal::local.stream.str(std::wstring());
	Internal::local.stream.clear();

	return Internal::local.stream;
}

std::wostream& Levin::write(std::wostream& stream, std::string_view string)
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
