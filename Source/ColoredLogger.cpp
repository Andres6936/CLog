// Joan Andrés (@Andres6936) Github.

#include "Levin/ColoredLogger.hpp"

using namespace Levin;

ColoredLogger::ColoredLogger(std::wostream& stream) noexcept : StreamLogger(stream)
{
}

/**
 * @brief Printing a colored output.
 *
 * A script can use escape sequences to produce colored text on the terminal.
 *
 * Colors for text are represented by color codes, including, reset = 0,
 * black = 30, red = 31, green = 32, yellow = 33, blue = 34, magenta = 35,
 * cyan = 36, and white = 37.
 *
 * To print colored text, enter the following command:
 *
 * @example echo -e "\e[1;31m This is red text \e[0m"
 *
 * Here, \e[1;31m is the escape string to set the color to red and \e[0m resets
 * the color back. Replace 31 with the required color code.
 *
 * For a colored background, reset = 0, black = 40, red = 41, green = 42,
 * yellow = 43, blue = 44, magenta = 45, cyan = 46, and white=47, are the
 * commonly used color codes.
 *
 * To print a colored background, enter the following command:
 *
 * @example echo -e "\e[1;42m ...
 *
 * Reference: Linux Shell Scripting Cookbook - Third Edition
 *
 * @param level
 * @param local
 */
void ColoredLogger::Message(SeverityLevel level, std::wstring_view local)
{
	std::lock_guard <std::mutex> guard(writeLock);

	if (level >= SeverityLevel::Emergency and level <= SeverityLevel::Critical)
	{
		// Output console in Red Darker
		stream << "\033[1;31m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else if (level == SeverityLevel::Error)
	{
		// Output console in Magenta Darker
		stream << "\033[1;35m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else if (level == SeverityLevel::Warning)
	{
		// Output console in Yellow Darker
		stream << "\033[1;33m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else if (level == SeverityLevel::Notice)
	{
		// Output console in Blue Darker
		stream << "\033[1;34m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else if (level == SeverityLevel::Informational)
	{
		// Output console in Cyan Darker
		stream << "\033[1;36m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else if (level == SeverityLevel::Debug)
	{
		// Output console in Green Darker
		stream << "\033[1;32m" << ToString(level) << " " << GetCurrentTime() << ": " << local << "\033[0m" << '\n';
	}
	else
	{
		stream << ToString(level) << " " << GetCurrentTime() << ": " << local << '\n';
	}
}
