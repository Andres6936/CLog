// Joan Andrés (@Andres6936) Github.

#include "Levin/Log.hpp"

using namespace Levin;

int main()
{
	Log::Debug("Show: Test Debug String") ;
	Log::Informational("Show: Test Informational String") ;
	Log::Warning("Show: Test Warning String") ;
	Log::Error("Show: Test Error String") ;
	Log::Notice("Show: Test Notice String") ;

	Log::Informational("Set the filter to Warning");
	Log::SetFilter(SeverityLevel::Warning);

	Log::Debug("Not Show: Test Debug String") ;
	Log::Informational("Not Show: Test Informational String") ;
	Log::Notice("Not Show: Test Notice String") ;
	Log::Warning("Show: Test Warning String") ;
	Log::Error("Show: Test Error String") ;

	Log::SetFilter(SeverityLevel::Informational);
	Log::Informational("The filter has been established to Debug");

	Log::Debug("Not Show: Test Debug String") ;
	Log::Debug("Not Show: Test Debug String") ;
	Log::Debug("Not Show: Test Debug String") ;
	Log::Debug("Not Show: Test Debug String") ;
}

