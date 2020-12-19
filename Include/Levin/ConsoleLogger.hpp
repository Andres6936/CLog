// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_CONSOLELOGGER_HPP
#define LEVIN_CONSOLELOGGER_HPP

#include "Log.hpp"
#include "Logger.hpp"

namespace Levin
{

	/**
	 * In computing, a log file is a file that records either events that occur
	 * in an operating system or other software runs, or messages between
	 * different users of a communication software. Logging is the act of
	 * keeping a log. In the simplest case, messages are written to a single
	 * log file.
	 */
	class ConsoleLogger final : public Logger
	{

	public:

		ConsoleLogger() noexcept;

		ConsoleLogger(const ConsoleLogger&) = delete;

		ConsoleLogger(ConsoleLogger&&) = delete;

		~ConsoleLogger() override = default;

		ConsoleLogger& operator=(const ConsoleLogger&) = delete;

		ConsoleLogger& operator=(ConsoleLogger&&) = delete;

		void Message(SecurityLevel level, std::wstring_view local) override;
	};

}

#endif //LEVIN_CONSOLELOGGER_HPP
