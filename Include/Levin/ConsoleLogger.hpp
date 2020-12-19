// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_CONSOLELOGGER_HPP
#define LEVIN_CONSOLELOGGER_HPP

#include "Log.hpp"
#include "Logger.hpp"

namespace Levin
{

	class ConsoleLogger final : public Logger
	{

	public:

		ConsoleLogger() noexcept;

		ConsoleLogger(const ConsoleLogger&) = delete;

		ConsoleLogger(ConsoleLogger&&) = delete;

		~ConsoleLogger() override = default;

		ConsoleLogger& operator=(const ConsoleLogger&) = delete;

		ConsoleLogger& operator=(ConsoleLogger&&) = delete;

		void message(Level level, std::wstring_view local) override;
	};

}

#endif //LEVIN_CONSOLELOGGER_HPP
