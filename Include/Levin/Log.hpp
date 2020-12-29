#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <string_view>

#include "Levin/Logger.hpp"
#include "Levin/Format/Flossy.hpp"

namespace Levin
{
	void Log(SecurityLevel level, std::string_view message);

	/**
	 * System is unusable.
	 */
	template<typename ... Values>
	inline void Emergency(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Emergency, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Action must be taken immediately.
	 */
	template<typename ... Values>
	inline void Alert(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Alert, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Critical conditions.
	 */
	template<typename ... Values>
	inline void Critical(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Critical, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Error conditions.
	 */
	template<typename ... Values>
	inline void Error(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Error, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Warning conditions.
	 */
	template<typename ... Values>
	inline void Warning(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Warning, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Normal but significant conditions.
	 */
	template<typename ... Values>
	inline void Notice(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Notice, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Informational messages.
	 */
	template<typename ... Values>
	inline void Informational(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Informational, flossy::format(message, std::forward<Values>(values)...));
	}

	/**
	 * Debug-level messages.
	 */
	template<typename ... Values>
	inline void Debug(const std::string& message, Values&& ... values)
	{
		Levin::Log(SecurityLevel::Debug, flossy::format(message, std::forward<Values>(values)...));
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
