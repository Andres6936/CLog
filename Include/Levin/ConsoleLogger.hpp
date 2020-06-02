// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_CONSOLELOGGER_HPP
#define LEVIN_CONSOLELOGGER_HPP

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

		void message(Level level, const std::wstring& local) override;
	};

}

#endif //LEVIN_CONSOLELOGGER_HPP
