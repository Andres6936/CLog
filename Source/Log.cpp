#include "Levin/Log.hpp"
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

// Initialize the static variable
std::unique_ptr <Levin::Logger> Levin::Log::logger = std::make_unique <Levin::ConsoleLogger>();

// Methods

void Log::SetFilter(SeverityLevel severity)
{
	filter = severity;
}

void Levin::Log::SendMessage(SeverityLevel severity, std::string_view message)
{
	// Only processing and/or notify messages with a severity level greater
	// than filter, please see the documentation.
	if (filter >= severity)
	{
		// Only write to underyling logger, if we didn't set the bad-bit.
		logger->Message(severity, MultiByteToWideChar(message.data()));
	}
}

void Log::SetNewLogger(std::unique_ptr<Logger> newLogger)
{
	// Take the own of newLogger and clear the current logger (the old)
	logger = std::move(newLogger);
}
