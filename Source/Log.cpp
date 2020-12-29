#include "Levin/Log.hpp"
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

// Initialize the static variable
std::unique_ptr <Levin::Logger> Levin::Log::logger = std::make_unique <Levin::ConsoleLogger>();

// Methods

void Levin::Log::SendMessage(SeverityLevel severity, std::string_view message)
{
	stream << MultiByteToWideChar(message.data()) << std::endl;

	if (not stream.bad())
	{
		// Only write to underyling logger, if we didn't set the bad-bit.
		logger->Message(severity, stream.str());
	}

	// Reset stream-data (and state)
	stream.str({});
	stream.clear();
}

void Log::SetNewLogger(std::unique_ptr<Logger> newLogger)
{
	// Take the own of newLogger and clear the current logger (the old)
	logger = std::move(newLogger);
}
