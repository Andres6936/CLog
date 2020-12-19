// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_LEVEL_HPP
#define LEVIN_LEVEL_HPP

namespace Levin
{

	/**
	 * Each message is labeled with a facility code, indicating the software
	 * type generating the message, and assigned a severity level.
	 */
	enum class Level : unsigned char
	{
		DEBUG = 'D',
		INFO = 'I',
		WARNING = 'W',
		ERROR = 'E',
		SEVERE = 'S'
	};

}

#endif //LEVIN_LEVEL_HPP
