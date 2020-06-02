#ifndef LOGGER_H
#define LOGGER_H

#include "Log.h"

#include <chrono>
#include <fstream>
#include <mutex>

namespace Levin
{
	class Logger
	{

	public:

		Logger(const Logger&) = delete;

		Logger(Logger&&) = delete;

		virtual ~Logger() = default;

		Logger& operator=(const Logger&) = delete;

		Logger& operator=(Logger&&) = delete;

		/*
		 * @brief Writes the log to the output beneath
		 *
		 * @note: Implementations of this method need to be thread-safe, e.g.
		 * this method can be written to from multiple threads concurrently.
		 */
		virtual void message(Level level, const std::wstring& local) = 0;

	protected:

		std::mutex writeLock;

		Logger() noexcept;

		[[nodiscard]] std::string GetCurrentTime() const noexcept;

		[[nodiscard]] std::wstring ToString(Level level) const noexcept;
	};
}

#endif /* LOGGER_H */
