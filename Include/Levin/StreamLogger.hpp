// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_STREAMLOGGER_HPP
#define LEVIN_STREAMLOGGER_HPP

#include "Levin/Log.hpp"
#include "Levin/Logger.hpp"

namespace Levin
{

	class StreamLogger : public Logger
	{

	public:

		explicit StreamLogger(std::wostream& stream) noexcept;

		StreamLogger(const StreamLogger&) = delete;

		StreamLogger(StreamLogger&&) = delete;

		~StreamLogger() override = default;

		StreamLogger& operator=(const StreamLogger&) = delete;

		StreamLogger& operator=(StreamLogger&&) = delete;

		void Message(SeverityLevel level, std::wstring_view local) override;

	protected:

		std::wostream& stream;
	};

}

#endif //LEVIN_STREAMLOGGER_HPP
