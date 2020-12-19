#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <string_view>

#include "Logger.hpp"

namespace Levin
{
	void Log(Level level, std::string_view message);

	inline void Debug(std::string_view message)
	{
		Levin::Log(Level::DEBUG, message);
	}

	inline void Info(std::string_view message)
	{
		Levin::Log(Level::INFO, message);
	}

	inline void Warn(std::string_view message)
	{
		Levin::Log(Level::WARNING, message);
	}

	inline void Error(std::string_view message)
	{
		Levin::Log(Level::ERROR, message);
	}

	inline void Severe(std::string_view message)
	{
		Levin::Log(Level::SEVERE, message);
	}

	/*!
	 * This is the Logger-instance being used to write the logs.
	 *
	 * Use this variable to set a custom Logger-instance.
	 * To disable logging (or stopping running logging), set this LOGGER to nullptr
	 */
	extern std::unique_ptr <Logger> logger;
}

#endif /* LOG_H */
