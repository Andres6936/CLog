#include "Levin/Log.hpp"
#include "Levin/ConsoleLogger.hpp"

using namespace Levin;

// Initialize the static variable
std::unique_ptr <Levin::Logger> Levin::Log::logger = std::make_unique <Levin::ConsoleLogger>();

// Methods

void Levin::Log::SendMessage(SecurityLevel _level, std::string_view message)
{
	level = _level;
	stream << MultiByteToWideChar(message.data()) << std::endl;

	if (not stream.bad())
	{
		// Only write to underyling logger, if we didn't set the bad-bit.
		logger->Message(level, stream.str());
	}

	// Reset stream-data (and state)
	stream.str({});
	stream.clear();
}