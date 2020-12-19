// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/Log.hpp"
#include "Levin/FileLogger.hpp"
#include "Levin/ColoredLogger.hpp"

using namespace Levin;

int main()
{
	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Info("Test Info String {}", "Another Message") ;

	Levin::Warn("Test Warn String") ;

	Levin::Error("Test Error String") ;

	Levin::Severe("Test Notice String") ;

	Levin::logger = std::make_unique<ColoredLogger>(std::wcout);

	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Info("Test Info String {}", "Another Message") ;

	Levin::Warn("Test Warn String") ;

	Levin::Error("Test Error String") ;

	Levin::Severe("Test Notice String") ;

	Levin::logger = std::make_unique<FileLogger>("Test.BasicLog.txt");

	Levin::Debug("Test Debug String {} {}", 12, 42.25) ;

	Levin::Info("Test Info String {}", "Another Message") ;

	Levin::Warn("Test Warn String") ;

	Levin::Error("Test Error String") ;

	Levin::Severe("Test Notice String") ;
}