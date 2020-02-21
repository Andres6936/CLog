CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Set C++ standard to C++20 without any extensions (e.g. GNU)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(Levin VERSION 0.4)

OPTION(LEVIN_BUILD_TEST "Build the concurrency test-application" ON)

INCLUDE_DIRECTORIES(Include)

SET(LEVIN_SOURCE
        Include/Log.h
        Include/Logger.h
        Source/Log.cpp
        Source/Logger.cpp
        Source/PRIVATE/ImplementationLog.h
        Source/PRIVATE/ImplementationLog.cpp
        )

IF (WIN32)
    ADD_LIBRARY(Levin STATIC ${LEVIN_SOURCE})
    TARGET_COMPILE_OPTIONS(Levin PRIVATE /W3 /D_UNICODE /DUNICODE)
ELSE ()
    ADD_LIBRARY(Levin SHARED ${LEVIN_SOURCE})
    TARGET_COMPILE_OPTIONS(Levin PRIVATE -O3 -Wall -Wextra -Wno-return-type)
ENDIF ()


# Test-program
IF (LEVIN_BUILD_TEST)
    FIND_PACKAGE(Threads)

    ADD_EXECUTABLE(LevinTest "Main.cpp")

    TARGET_LINK_LIBRARIES(LevinTest PRIVATE Levin)
    TARGET_LINK_LIBRARIES(LevinTest PRIVATE ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()
