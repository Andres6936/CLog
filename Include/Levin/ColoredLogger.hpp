// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_COLOREDLOGGER_HPP
#define LEVIN_COLOREDLOGGER_HPP

#include "Log.hpp"
#include "StreamLogger.hpp"

namespace Levin
{

	class ColoredLogger final : public StreamLogger
	{

	public:

		explicit ColoredLogger(std::wostream& stream) noexcept;

		ColoredLogger(const ColoredLogger&) = delete;

		ColoredLogger(ColoredLogger&&) = delete;

		~ColoredLogger() override = default;

		ColoredLogger& operator=(const ColoredLogger&) = delete;

		ColoredLogger& operator=(ColoredLogger&&) = delete;

		void message(Level level, std::wstring_view local) override;
	};

}

#endif //LEVIN_COLOREDLOGGER_HPP
