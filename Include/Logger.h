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

	class ConsoleLogger final : public Logger
	{

	public:

		ConsoleLogger() noexcept;

		ConsoleLogger(const ConsoleLogger&) = delete;

		ConsoleLogger(ConsoleLogger&&) = delete;

		~ConsoleLogger() override = default;

		ConsoleLogger& operator=(const ConsoleLogger&) = delete;

		ConsoleLogger& operator=(ConsoleLogger&&) = delete;

		void message(Level level, const std::wstring& local) override;
	};

	class FileLogger final : public Logger
	{

	public:

		explicit FileLogger(const std::string& fileName) noexcept;

		FileLogger(const FileLogger&) = delete;

		FileLogger(FileLogger&&) = delete;

		~FileLogger() override;

		FileLogger& operator=(const FileLogger&) = delete;

		FileLogger& operator=(FileLogger&&) = delete;

		void message(Level level, const std::wstring& local) override;

	private:

		std::wofstream fileStream;
	};

	class StreamLogger : public Logger
	{

	public:

		explicit StreamLogger(std::wostream& stream) noexcept;

		StreamLogger(const StreamLogger&) = delete;

		StreamLogger(StreamLogger&&) = delete;

		~StreamLogger() override = default;

		StreamLogger& operator=(const StreamLogger&) = delete;

		StreamLogger& operator=(StreamLogger&&) = delete;

		void message(Level level, const std::wstring& local) override;

	protected:

		std::wostream& stream;
	};

	class ColoredLogger final : public StreamLogger
	{

	public:

		explicit ColoredLogger(std::wostream& stream) noexcept;

		ColoredLogger(const ColoredLogger&) = delete;

		ColoredLogger(ColoredLogger&&) = delete;

		~ColoredLogger() override = default;

		ColoredLogger& operator=(const ColoredLogger&) = delete;

		ColoredLogger& operator=(ColoredLogger&&) = delete;

		void message(Level level, const std::wstring& local) override;
	};
}

#endif /* LOGGER_H */
