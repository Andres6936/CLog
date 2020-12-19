// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/Log.hpp"
#include "Levin/FileLogger.hpp"
#include "Levin/ColoredLogger.hpp"

using namespace Levin;

int main()
{
	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Informational("Test Informational String {}", "Another Message") ;

	Levin::Warning("Test Warning String") ;

	Levin::Error("Test Error String") ;

	Levin::Notice("Test Notice String") ;

	Levin::logger = std::make_unique<ColoredLogger>(std::wcout);

	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Emergency("Test for a message of emergency");

	Levin::Alert("Test for a message of alert");

	Levin::Critical("Critical message test");

	Levin::Informational("Test Informational String {}", "Another Message") ;

	Levin::Warning("Test Warning String") ;

	Levin::Error("Test Error String") ;

	Levin::Notice("Test Notice String") ;

	Levin::logger = std::make_unique<FileLogger>("Test.BasicLog.txt");

	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Informational("Test Informational String {}", "Another Message") ;

	Levin::Warning("Test Warning String") ;

	Levin::Error("Test Error String") ;

	Levin::Notice("Test Notice String") ;
}