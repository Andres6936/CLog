#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "Log.h"
#include "Logger.h"

using namespace std;

static void logThread()
{
	const int threadID = std::rand();

	while (true)
	{
		CLog::Debug() << "Test from: " << threadID << CLog::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		CLog::Error() << "Test 2 from : " << threadID << CLog::endl;

		CLog::Info() << "Lazy Standarging!" << CLog::endl;

		CLog::Info() << "More lazy logging" << CLog::endl;

		CLog::Debug() << "Even more lazy logging" << CLog::endl;

		CLog::Warn() << "Warning" << CLog::endl;

		CLog::Severe() << "Severe" << CLog::endl;
	}
}

/*
 *
 */
int main(int argc, char** argv)
{
	CLog::LOGGER.reset(new CLog::ColoredLogger(std::wcout));

	CLog::Info() << "Dummy" << CLog::endl;

	for (int i = 0; i < 10; i++)
	{
		new std::thread(&logThread);
	}

	while (true)
	{
		CLog::Debug() << std::string("Test") << CLog::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

		CLog::Error() << "Test2" << CLog::endl;
	}

	return 0;
}
