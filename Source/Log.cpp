#include "Log.h"

#include "PRIVATE/ImplementationLog.h"

#include <chrono>
#include <cstdarg>
#include <iosfwd>
#include <sstream>
#include <vector>

using namespace Standard;

std::wostream &Standard::Log( Level level )
{
    Standard::Internal::local.level = level;
    return Standard::Internal::local.stream;
}

std::wostream &Standard::endl( std::wostream &stream )
{
    stream << std::endl;
    if ( !Standard::Internal::local.stream.bad( ))
    {
        // only write to underyling logger, if we didn't set the bad-bit
        Standard::Internal::AppendLog( Standard::Internal::local.level,
                                       Standard::Internal::local.stream.str( ));
    }

    // reset stream-data (and state)
    Standard::Internal::local.stream.str( std::wstring( ));
    Standard::Internal::local.stream.clear( );

    return Standard::Internal::local.stream;
}

std::wostream& operator<<(std::wostream& stream, const std::string& string)
{
    std::vector<wchar_t> result(string.size());
    size_t res = std::mbstowcs(result.data(), string.data(), string.size());
    if(res == static_cast<std::size_t>(-1))
    {
        // TODO handle error
        return stream;
    }
    return stream << std::wstring(result.data(), res);
}