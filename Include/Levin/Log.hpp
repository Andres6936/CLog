#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <string_view>

#include "Logger.hpp"
#include "Flossy/Flossy.hpp"

namespace Levin
{
	void Log(Level level, std::string_view message);

	template<typename ... Values>
	inline void Debug(const std::string& message, Values&& ... values)
	{
		Levin::Log(Level::DEBUG, flossy::format(message, std::forward<Values>(values)...));
	}

	template<typename ... Values>
	inline void Info(const std::string& message, Values&& ... values)
	{
		Levin::Log(Level::INFO, flossy::format(message, std::forward<Values>(values)...));
	}

	template<typename ... Values>
	inline void Warn(const std::string& message, Values&& ... values)
	{
		Levin::Log(Level::WARNING, flossy::format(message, std::forward<Values>(values)...));
	}

	template<typename ... Values>
	inline void Error(const std::string& message, Values&& ... values)
	{
		Levin::Log(Level::ERROR, flossy::format(message, std::forward<Values>(values)...));
	}

	template<typename ... Values>
	inline void Severe(const std::string& message, Values&& ... values)
	{
		Levin::Log(Level::SEVERE, flossy::format(message, std::forward<Values>(values)...));
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
