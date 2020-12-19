// Joan Andrés (@Andres6936) Github.

#ifndef LEVIN_SECURITYLEVEL_HPP
#define LEVIN_SECURITYLEVEL_HPP

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
	 *
	 * The server process which handles display of messages usually includes
	 * all lower (more severe) levels when display of less severe levels is
	 * requested. That is, if messages are separated by individual severity, a
	 * Warning level entry will also be included when filtering for Notice,
	 * Info and Debug messages.
	 *
	 * Reference: RFC 5424 - Table 2. Syslog Message Severities
	 */
	enum class SecurityLevel : unsigned char
	{
		// System is unusable
		Emergency = 0,
		// Action must be taken immediately
		Alert = 1,
		// Critical conditions
		Critical = 2,
		// Error conditions
		Error = 3,
		// Warning conditions
		Warning = 4,
		// 	Normal but significant conditions
		Notice = 5,
		// 	Informational messages
		Informational = 6,
		// 	Debug-level messages
		Debug = 7,
	};

}

#endif //LEVIN_SECURITYLEVEL_HPP
