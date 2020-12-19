#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>
#include <string_view>

#include "Logger.hpp"

namespace Levin
{

	/*!
 	* Convenience-wrapper to allow writing std::string into std::wostream
 	*/
	std::wostream& write(std::wostream& stream, std::string_view string);

	std::wostream& Log(Level level);

	std::wostream& endl(std::wostream& stream);

	inline void Debug(std::string_view message)
	{
		write(Levin::Log(Level::DEBUG) ,message) << Levin::endl;
	}

	inline void Info(std::string_view message)
	{
		write(Levin::Log(Level::INFO), message) << Levin::endl;
	}

	inline void Warn(std::string_view message)
	{
		write(Levin::Log(Level::WARNING), message) << Levin::endl;
	}

	inline void Error(std::string_view message)
	{
		write(Levin::Log(Level::ERROR) ,message) << Levin::endl;
	}

	inline void Severe(std::string_view message)
	{
		write(Levin::Log(Level::SEVERE) ,message) << Levin::endl;
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
