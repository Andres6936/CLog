// Joan Andrés (@Andres6936) Github.

#include "Levin/ColoredLogger.hpp"

using namespace Levin;

ColoredLogger::ColoredLogger(std::wostream& stream) noexcept : StreamLogger(stream)
{
}

void ColoredLogger::Message(SecurityLevel level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level == SecurityLevel::Error or level == SecurityLevel::Notice)
	{
		// Output console in Red Darker
		stream << "\033[1;31m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == SecurityLevel::Debug)
	{
		// Output console in Green Darker
		stream << "\033[1;32m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == SecurityLevel::Warning)
	{
		// Output console in Yellow Darker
		stream << "\033[1;33m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == SecurityLevel::Informational)
	{
		// Output console in Blue Darker
		stream << "\033[1;34m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else
	{
		stream << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}

	stream.flush();
}
