// Joan Andrés (@Andres6936) Github.

#include <iostream>
#include "Levin/Log.hpp"
#include "Levin/FileLogger.hpp"
#include "Levin/ColoredLogger.hpp"

using namespace Levin;

int main()
{
	Log::Debug("Test Debug String {} {}", 12, 42.25) ;

	Log::Informational("Test Informational String {}", "Another Message") ;

	Log::Warning("Test Warning String") ;

	Log::Error("Test Error String") ;

	Log::Notice("Test Notice String") ;

	Log::logger = std::make_unique<ColoredLogger>(std::wcout);

	Log::Debug("Test Debug String {} {}", 12, 42.25) ;

	Log::Emergency("Test for a message of emergency");

	Log::Alert("Test for a message of alert");

	Log::Critical("Critical message test");

	Log::Informational("Test Informational String {}", "Another Message") ;

	Log::Warning("Test Warning String") ;

	Log::Error("Test Error String") ;

	Log::Notice("Test Notice String") ;

	Log::logger = std::make_unique<FileLogger>("Test.BasicLog.txt");

	Log::Debug("Test Debug String {} {}", 12, 42.25) ;

	Log::Informational("Test Informational String {}", "Another Message") ;

	Log::Warning("Test Warning String") ;

	Log::Error("Test Error String") ;

	Log::Notice("Test Notice String") ;
}