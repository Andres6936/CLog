#include "Levin/Logger.hpp"

#include <vector>
#include <cstring>

using namespace Levin;

std::wstring Levin::MultiByteToWideChar(const char* source)
{
	// Why not used std::mbstowcs:
	// In most implementations, this function updates a global static object of
	// type std::mbstate_t as it processes through the string, and cannot be
	// called simultaneously by two threads, std::mbsrtowcs should be used in
	// such cases.
	// Each called to function have their own state (std::mbstate_t)
	std::mbstate_t state = std::mbstate_t();

	std::vector<wchar_t> result(std::strlen(source));
	// Converts a multibyte character string from the array whose first element
	// is pointed to by src to its wide character representation. Converted
	// characters are stored in the successive elements of the array pointed to
	// by dst. No more than len wide characters are written to the destination
	// array.
	// The firm of method std::mbstowcs is (dst, src, len)

	// Each character is converted as if by a call to std::mbtowc, except that
	// the mbtowc conversion state is unaffected. The conversion stops if:
	// - The multibyte null character was converted and stored.
	// - An invalid (in the current C locale) multibyte character was encountered.
	// - The next wide character to be stored would exceed len.
	std::size_t status = std::mbsrtowcs(result.data(), &source, std::strlen(source), &state);
	// Return the conversion made to text (std::wstring)
	return { result.data(), status };
}

Logger::Logger() noexcept : writeLock()
{
}

std::wstring Logger::GetCurrentTime() const noexcept
{
	time_t now = std::time(nullptr);
	// Converts given time since epoch to a calendar local time and then to a
	// textual representation, the type of return is char*, should be convert
	// to std::string
	std::string text = std::ctime(&now);
	// required, since ctime (asctime) append a new-line
	text.erase(text.find_last_of('\n'), 1);

	return MultiByteToWideChar(text.data());
}

std::wstring Logger::ToString(Level level) const noexcept
{
	switch (level)
	{
	case Level::Debug:
		return L"[D]";
	case Level::Informational:
		return L"[I]";
	case Level::Warning:
		return L"[W]";
	case Level::Error:
		return L"[E]";
	case Level::Notice:
		return L"[S]";
	default:
		return L"[U]";
	}
}