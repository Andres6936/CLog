// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/Log.hpp"
#include "Levin/ColoredLogger.hpp"

using namespace Levin;

int main()
{
	Levin::Debug() << "Test Debug String" << Levin::endl;

	Levin::Info() << "Test Info String" << Levin::endl;

	Levin::Warn() << "Test Warn String" << Levin::endl;

	Levin::Error() << "Test Error String" << Levin::endl;

	Levin::Severe() << "Test Severe String" << Levin::endl;

	Levin::logger = std::make_unique<ColoredLogger>(std::wcout);

	Levin::Debug() << "Test Debug String" << Levin::endl;

	Levin::Info() << "Test Info String" << Levin::endl;

	Levin::Warn() << "Test Warn String" << Levin::endl;

	Levin::Error() << "Test Error String" << Levin::endl;

	Levin::Severe() << "Test Severe String" << Levin::endl;
}