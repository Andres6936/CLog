// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_LEVEL_HPP
#define LEVIN_LEVEL_HPP

namespace Levin
{

	/**
	 * Each message is labeled with a facility code, indicating the software
	 * type generating the message, and assigned a severity level.
	 *
	 * The meaning of severity levels other than Emergency and Debug are
	 * relative to the application. For example, if the purpose of the system
	 * is to process transactions to update customer account balance
	 * information, an error in the final step should be assigned Alert level.
	 * However, an error occurring in an attempt to display the ZIP code of the
	 * customer may be assigned Error or even Warning level.
	 */
	enum class Level : unsigned char
	{
		Emergency = 0,
		Alert = 1,
		Critical = 2,
		Error = 3,
		Warning = 4,
		Notice = 5,
		Informational = 6,
		Debug = 7,
	};

}

#endif //LEVIN_LEVEL_HPP
