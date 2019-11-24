/*
 * File:   log.h
 * Author: doe300
 *
 * Created on September 16, 2016, 1:33 PM
 */
#ifndef LOG_H
#define LOG_H

#include <functional>
#include <memory>
#include <ostream>
#include <string>

namespace Standard
{
    /*!
     * The log-level
     */
    enum class Level : unsigned char
    {
        DEBUG = 'D',
        INFO = 'I',
        // something is not as expected
        WARNING = 'W',
        // program-error
        ERROR = 'E',
        // critical software-error
        SEVERE = 'S'
    };

    std::wostream& log(Level level);
    std::wostream& endl(std::wostream& stream);

    inline std::wostream& debug()
    {
        return Standard::log( Level::DEBUG );
    }

    inline std::wostream& info()
    {
        return Standard::log( Level::INFO );
    }

    inline std::wostream& warn()
    {
        return Standard::log( Level::WARNING );
    }

    inline std::wostream& error()
    {
        return Standard::log( Level::ERROR );
    }

    inline std::wostream& severe()
    {
        return Standard::log( Level::SEVERE );
    }

    void logf(Level level, const wchar_t* format, ...);

    /*!
     * Wrapper around a logging statement to only execute it if the level of logging
     * will be written to the output.
     * This can be used to skip complex logging statements when not required.
     */
    void logLazy(Level level, std::function<void(std::wostream&)>&& statement);

    /*!
     * Wrapper around several logging statements to only execute them if the level of
     * logging will be written to the output.
     * This can be used to skip complex logging statements when not required.
     */
    void logLazy(Level level, std::function<void()>&& statement);

    // Forward-declaration for the logger-instance
    class Logger;
    /*!
     * This is the Logger-instance being used to write the logs.
     *
     * Use this variable to set a custom Logger-instance.
     * To disable logging (or stopping running logging), set this LOGGER to nullptr
     */
    extern std::unique_ptr<Logger> LOGGER;
} // namespace Standard

/*!
 * Convenience-wrapper to allow writing std::string into std::wostream
 */
std::wostream& operator<<(std::wostream& stream, const std::string& string);

/*!
 * Convenience macro for lazy logging.
 * Within content, the logging-stream 'log' is available.
 *
 * Example usage:
 * CPPLOG_LAZY(Level::DEBUG, log << "Hello World! << endl);
 */
#define CPPLOG_LAZY( level, content ) Standard::logLazy(level, [&](std::wostream& log) { content; })

/*!
 * Convenience macro for lazy logging.
 *
 * Example usage:
 * CPPLOG_LAZY(Level::DEBUG, debug() << "Hello World! << endl; debug() << "Second statement!" << endl);
 */
#define CPPLOG_LAZY_BLOCK( level, content ) Standard::logLazy(level, [&]() { content; })

#endif /* LOG_H */
