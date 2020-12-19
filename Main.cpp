#include <chrono>
#include <memory>
#include <thread>
#include <iostream>

#include "Levin/Levin.hpp"

static void logThread()
{
	const int threadID = std::rand();

	while (true)
	{
		Levin::Debug() << "Test from: " << threadID << Levin::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(150));

		Levin::Error() << "Test 2 from : " << threadID << Levin::endl;

		Levin::Info() << "Lazy Standarging!" << Levin::endl;

		Levin::Info() << "More lazy logging" << Levin::endl;

		Levin::Debug() << "Even more lazy logging" << Levin::endl;

		Levin::Warn() << "Warning" << Levin::endl;

		Levin::Severe() << "Notice" << Levin::endl;
	}
}

int main(int argc, char** argv)
{
	Levin::logger = std::make_unique <Levin::ColoredLogger>(std::wcout);

	Levin::Info() << "Dummy" << Levin::endl;

	for (int i = 0; i < 10; i++)
	{
		new std::thread(&logThread);
	}

	while (true)
	{
		Levin::Debug() << std::string("Test") << Levin::endl;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		Levin::Error() << "Test2" << Levin::endl;
	}

	return 0;
}
