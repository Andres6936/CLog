#include "Logger.h"

#include <ctime>
#include <ios>
#include <iostream>

using namespace Levin;

Logger::Logger() noexcept : writeLock()
{
}

std::string Logger::GetCurrentTime() const noexcept
{
	time_t now = std::time(nullptr);
	std::string text = std::ctime(&now);
	// required, since ctime (asctime) append a new-line
	text.erase(text.find_last_of('\n'), 1);
	return text;
}

std::wstring Logger::ToString(Level level) const noexcept
{
	switch (level)
	{
	case Level::DEBUG:
		return L"[D]";
	case Level::INFO:
		return L"[I]";
	case Level::WARNING:
		return L"[W]";
	case Level::ERROR:
		return L"[E]";
	case Level::SEVERE:
		return L"[S]";
	}
}

ConsoleLogger::ConsoleLogger() noexcept = default;

void ConsoleLogger::message(Level level, const std::wstring& local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level == Level::ERROR or level == Level::SEVERE)
	{
		std::wcerr << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
	else
	{
		std::wcout << ToString(level) << " " << GetCurrentTime() << ": " << local;
	}
}

FileLogger::FileLogger(const std::string& fileName) noexcept : fileStream(fileName, std::ios::out)
{
}

FileLogger::~FileLogger()
{
	fileStream.flush();
	fileStream.close();
}

void FileLogger::message(Level level, const std::wstring& local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	fileStream << ToString(level) << " " << GetCurrentTime() << ": " << local;
}

StreamLogger::StreamLogger(std::wostream& stream) noexcept : stream(stream)
{
}

void StreamLogger::message(Level level, const std::wstring& local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	stream << ToString(level) << " " << GetCurrentTime() << ": " << local;
}

ColoredLogger::ColoredLogger(std::wostream& stream) noexcept : StreamLogger(stream)
{
}

void ColoredLogger::message(Level level, const std::wstring& local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level == Level::ERROR or level == Level::SEVERE)
	{
		// Output console in Red Darker
		stream << "\033[1;31m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == Level::DEBUG)
	{
		// Output console in Green Darker
		stream << "\033[1;32m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == Level::WARNING)
	{
		// Output console in Yellow Darker
		stream << "\033[1;33m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m";
	}
	else if (level == Level::INFO)
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
