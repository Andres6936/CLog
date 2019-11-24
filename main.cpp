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
        Standard::debug( ) << "Test from: " << threadID << Standard::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        Standard::error( ) << "Test 2 from : " << threadID << Standard::endl;
        CPPLOG_LAZY( Standard::Level::INFO, log << "Lazy Standardging!" << Standard::endl );
        CPPLOG_LAZY_BLOCK( Standard::Level::INFO, Standard::info( ) << "More lazy logging" << Standard::endl;
                Standard::debug( ) << "Even more lazy logging" << Standard::endl );
    }
}

/*
 *
 */
int main(int argc, char** argv)
{
    Standard::LOGGER.reset( new Standard::ColoredLogger( std::wcout ));

    Standard::info( ) << "Dummy" << Standard::endl;

    for(int i = 0; i < 10; i++)
    {
        new std::thread(&logThread);
    }

    while(true)
    {
        Standard::debug( ) << std::string( "Test" ) << Standard::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        Standard::error( ) << "Test2" << Standard::endl;
    }

    return 0;
}
