#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>

#include "Logger.hpp"

namespace Levin
{


	std::wostream& Log(Level level);

	std::wostream& endl(std::wostream& stream);

	inline std::wostream& Debug()
	{
		return Levin::Log(Level::DEBUG);
	}

	inline std::wostream& Info()
	{
		return Levin::Log(Level::INFO);
	}

	inline std::wostream& Warn()
	{
		return Levin::Log(Level::WARNING);
	}

	inline std::wostream& Error()
	{
		return Levin::Log(Level::ERROR);
	}

	inline std::wostream& Severe()
	{
		return Levin::Log(Level::SEVERE);
	}

	/*!
	 * This is the Logger-instance being used to write the logs.
	 *
	 * Use this variable to set a custom Logger-instance.
	 * To disable logging (or stopping running logging), set this LOGGER to nullptr
	 */
	extern std::unique_ptr <Logger> logger;
}

/*!
 * Convenience-wrapper to allow writing std::string into std::wostream
 */
std::wostream& operator<<(std::wostream& stream, const std::string& string);

#endif /* LOG_H */
