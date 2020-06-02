CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(Levin VERSION 2020.0602 LANGUAGES CXX)

OPTION(LEVIN_BUILD_TEST "Build the concurrency test-application" ON)

ADD_LIBRARY(Levin
        Source/Log.cpp
        Source/Logger.cpp
        Source/FileLogger.cpp
        Source/StreamLogger.cpp
        Source/ColoredLogger.cpp
        Source/ConsoleLogger.cpp
        Source/Private/ImplementationLog.cpp)

SET_TARGET_PROPERTIES(Levin PROPERTIES CXX_STANDARD 17)

TARGET_INCLUDE_DIRECTORIES(Levin PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
        $<INSTALL_INTERFACE:Include/>)

# Test-program
IF (LEVIN_BUILD_TEST)
    FIND_PACKAGE(Threads)

    ADD_EXECUTABLE(LevinTest "Main.cpp")

    TARGET_LINK_LIBRARIES(LevinTest PRIVATE Levin)
    TARGET_LINK_LIBRARIES(LevinTest PRIVATE ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()
