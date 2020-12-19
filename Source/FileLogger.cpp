// Joan Andrés (@Andres6936) Github.

#include "Levin/FileLogger.hpp"

using namespace Levin;

FileLogger::FileLogger(const std::string& fileName) noexcept : fileStream(fileName, std::ios::out)
{
}

FileLogger::~FileLogger()
{
	fileStream.flush();
	fileStream.close();
}

void FileLogger::Message(Level level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	fileStream << ToString(level) << " " << GetCurrentTime() << ": " << local;
}
