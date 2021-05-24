#include <chrono>
#include <memory>
#include <thread>
#include <iostream>

#include "Levin/Levin.hpp"

using namespace Levin;

static void logThread()
{
	const int threadID = std::rand();

	while (true)
	{
		Log::Debug("Test from: " + std::to_string(threadID));

		std::this_thread::sleep_for(std::chrono::milliseconds(150));

		Log::Error("Test 2 from : " + std::to_string(threadID));

		Log::Informational("Lazy Standarging!");

		Log::Informational("More lazy logging");

		Log::Debug("Even more lazy logging");

		Log::Warning("Warning");

		Log::Notice("Notice");
	}
}

int main(int argc, char** argv)
{
	Log::SetNewLogger(std::make_unique<ColoredLogger>(std::wcout));

	Log::Informational("Dummy");

	for (int i = 0; i < 10; i++)
	{
		new std::thread(&logThread);
	}

	while (true)
	{
		Log::Debug(std::string("Test"));

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		Log::Error("Test2");
	}

	return 0;
}
