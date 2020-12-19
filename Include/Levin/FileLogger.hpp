// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_FILELOGGER_HPP
#define LEVIN_FILELOGGER_HPP

#include "Log.hpp"
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

		void Message(Level level, std::wstring_view local) override;

	private:

		std::wofstream fileStream;
	};

}

#endif //LEVIN_FILELOGGER_HPP
