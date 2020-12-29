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

	class Log
	{

	public:

		/**
		 * The string stream is used for save the current message to send.
		 */
		static inline std::wstringstream stream {};

		/**
		 * The severity level of message.
		 */
		static inline SecurityLevel level = SecurityLevel::Debug;

		/**
		 * This is the Logger-instance being used to write the logs.
		 *
		 * Use this variable to set a custom Logger-instance.
		 * To disable logging (or stopping running logging), set this LOGGER to nullptr
		 */
		static std::unique_ptr <Logger> logger;

		/**
		 * Generic function for print the message in the stream.
		 * @param level The severity level of message.
		 * @param message The messsage to print in the stream.
		 */
		static void SendMessage(SecurityLevel level, std::string_view message);

	public:

		/**
		 * System is unusable.
		 */
		template<typename ... Values>
		static void Emergency(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Emergency, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Action must be taken immediately.
		 */
		template<typename ... Values>
		static void Alert(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Alert, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Critical conditions.
		 */
		template<typename ... Values>
		static void Critical(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Critical, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Error conditions.
		 */
		template<typename ... Values>
		static void Error(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Error, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Warning conditions.
		 */
		template<typename ... Values>
		static void Warning(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Warning, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Normal but significant conditions.
		 */
		template<typename ... Values>
		static void Notice(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Notice, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Informational messages.
		 */
		template<typename ... Values>
		static void Informational(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Informational, flossy::format(message, std::forward<Values>(values)...));
		}

		/**
		 * Debug-level messages.
		 */
		template<typename ... Values>
		static void Debug(const std::string& message, Values&& ... values)
		{
			SendMessage(SecurityLevel::Debug, flossy::format(message, std::forward<Values>(values)...));
		}

	};

}

#endif /* LOG_H */
