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
    enum class Level : unsigned char
    {
        DEBUG = 'D',
        INFO = 'I',
        WARNING = 'W',
        ERROR = 'E',
        SEVERE = 'S'
    };

    std::wostream &Log( Level level );

    std::wostream& endl(std::wostream& stream);

    inline std::wostream &Debug( )
    {
        return Standard::Log( Level::DEBUG );
    }

    inline std::wostream &Info( )
    {
        return Standard::Log( Level::INFO );
    }

    inline std::wostream &Warn( )
    {
        return Standard::Log( Level::WARNING );
    }

    inline std::wostream &Error( )
    {
        return Standard::Log( Level::ERROR );
    }

    inline std::wostream &Severe( )
    {
        return Standard::Log( Level::SEVERE );
    }

    // Forward-declaration for the logger-instance
    class Logger;

    /*!
     * This is the Logger-instance being used to write the logs.
     *
     * Use this variable to set a custom Logger-instance.
     * To disable logging (or stopping running logging), set this LOGGER to nullptr
     */
    extern std::unique_ptr<Logger> LOGGER;
}

/*!
 * Convenience-wrapper to allow writing std::string into std::wostream
 */
std::wostream& operator<<(std::wostream& stream, const std::string& string);

#endif /* LOG_H */
