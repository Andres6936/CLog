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

	/**
	 * Currently, Levin's severity levels (log functions) are based on the
	 * standard <a href="https://tools.ietf.org/html/rfc5424">RFC5424</a>,
	 * that define the follow severity levels.
	 * <br><br>
	 *
	 * The concept of the class is be a static class, where only a unique
	 * instance can be exist.
	 *
	 * @note This class cannot be inherited from.
	 */
	class Log final
	{

	private:

		/**
		 * This is the Logger-instance being used to write the logs.
		 *
		 * Use this variable to set a custom Logger-instance.
		 * To disable logging (or stopping running logging), set this LOGGER to nullptr
		 */
		static std::unique_ptr <Logger> logger;

		/**
		 * Generic function for print the message in the stream.
		 * @param severity The severity severity of message.
		 * @param message The messsage to print in the stream.
		 */
		static void SendMessage(SeverityLevel severity, std::string_view message);

	public:

		/**
		 * Allow change the logger used for default.
		 */
		static void SetNewLogger(std::unique_ptr<Logger> newLogger);

		/**
		 * System is unusable.
		 */
		template<typename ... Values>
		static void Emergency(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Emergency, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Action must be taken immediately.
		 */
		template<typename ... Values>
		static void Alert(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Alert, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Critical conditions.
		 */
		template<typename ... Values>
		static void Critical(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Critical, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Error conditions.
		 */
		template<typename ... Values>
		static void Error(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Error, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Warning conditions.
		 */
		template<typename ... Values>
		static void Warning(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Warning, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Normal but significant conditions.
		 */
		template<typename ... Values>
		static void Notice(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Notice, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Informational messages.
		 */
		template<typename ... Values>
		static void Informational(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Informational, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Debug-level messages.
		 */
		template<typename ... Values>
		static void Debug(const std::string& message, Values&& ... values)
		{
			SendMessage(SeverityLevel::Debug, flossy::format(message, std::forward<Values>(values)...));
		}

	};

}

#endif /* LOG_H */
