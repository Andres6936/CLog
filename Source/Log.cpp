#include "Levin/Log.hpp"
#include "Private/ImplementationLog.h"

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
	return stream << ToMultibyteCharacter(string);
}

std::wostream& Levin::Log(Level level, std::string_view message)
{
	Internal::local.level = level;
	return Write(Internal::local.stream, message) << End;
}