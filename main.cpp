/*
 * File:   main.cpp
 * Author: doe300
 *
 * Created on September 16, 2016, 2:36 PM
 */

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "log.h"
#include "logger.h"

using namespace std;

static void logThread()
{
    const int threadID = std::rand();

    while(true)
    {
        Standard::Debug( ) << "Test from: " << threadID << Standard::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        Standard::Error( ) << "Test 2 from : " << threadID << Standard::endl;

        Standard::Info( ) << "Lazy Standarging!" << Standard::endl;

        Standard::Info( ) << "More lazy logging" << Standard::endl;

        Standard::Debug( ) << "Even more lazy logging" << Standard::endl;

        Standard::Warn( ) << "Warning" << Standard::endl;

        Standard::Severe( ) << "Severe" << Standard::endl;
    }
}

/*
 *
 */
int main(int argc, char** argv)
{
    Standard::LOGGER.reset( new Standard::ColoredLogger( std::wcout ));

    Standard::Info( ) << "Dummy" << Standard::endl;

    for(int i = 0; i < 10; i++)
    {
        new std::thread(&logThread);
    }

    while(true)
    {
        Standard::Debug( ) << std::string( "Test" ) << Standard::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        Standard::Error( ) << "Test2" << Standard::endl;
    }

    return 0;
}
