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

void Levin::Log(Level level, std::string_view message)
{
	Internal::local.level = level;
	Internal::local.stream << MultiByteToWideChar(message) << End;
}