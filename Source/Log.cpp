#include "Levin/Log.hpp"
#include "Private/ImplementationLog.h"

#include <cstdarg>

using namespace Levin;

static std::wostream& End(std::wostream& stream)
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

/**
 * Convenience-wrapper to allow writing std::string into std::wostream
 */
static std::wostream& Write(std::wostream& stream, std::string_view string)
{
	std::vector <wchar_t> result(string.size());
	// Converts a multibyte character string from the array whose first element
	// is pointed to by src to its wide character representation. Converted
	// characters are stored in the successive elements of the array pointed to
	// by dst. No more than len wide characters are written to the destination
	// array.
	// The firm of method std::mbstowcs is (dst, src, len)
	size_t res = std::mbstowcs(result.data(), string.data(), string.size());
	if (res == static_cast<std::size_t>(-1))
	{
		// TODO handle error
		return stream;
	}
	return stream << std::wstring(result.data(), res);
}

std::wostream& Levin::Log(Level level, std::string_view message)
{
	Internal::local.level = level;
	return Write(Internal::local.stream, message) << End;
}