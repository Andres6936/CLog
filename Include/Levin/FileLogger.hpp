// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_FILELOGGER_HPP
#define LEVIN_FILELOGGER_HPP

#include "Logger.hpp"

namespace Levin
{

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

}

#endif //LEVIN_FILELOGGER_HPP
