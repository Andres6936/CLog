// Joan Andrés (@Andres6936) Github.

#include "Levin/StreamLogger.hpp"

using namespace Levin;


StreamLogger::StreamLogger(std::wostream& stream) noexcept : stream(stream)
{
}

void StreamLogger::message(Level level, const std::wstring& local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	stream << ToString(level) << " " << GetCurrentTime() << ": " << local;
}
