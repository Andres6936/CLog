CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Set C++ standard to C++11 without any extensions (e.g. GNU)
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

PROJECT(CLog VERSION 0.4)

OPTION(CPPLOG_BUILD_TEST "Build the concurrency test-application" ON)

INCLUDE_DIRECTORIES(Include)

SET(SRCS
        Include/Log.h
        Include/Logger.h
        Source/Log.cpp
        Source/Logger.cpp
        Source/PRIVATE/ImplementationLog.h
        Source/PRIVATE/ImplementationLog.cpp
        )

IF (WIN32)
    ADD_LIBRARY(CLog STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(CLog PRIVATE /W3 /D_UNICODE /DUNICODE)
ELSE ()
    ADD_LIBRARY(CLog SHARED ${SRCS})
    ADD_LIBRARY(CLogStatic STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(CLog PRIVATE -O3 -Wall -Wextra -Wno-return-type -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
    TARGET_COMPILE_OPTIONS(CLogStatic PRIVATE -O3 -Wall -Wextra -Wno-return-type -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
ENDIF ()

IF (TARGET CLogStatic)
    TARGET_INCLUDE_DIRECTORIES(CLogStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
ENDIF ()

# Test-program
IF (CPPLOG_BUILD_TEST)
    FIND_PACKAGE(Threads)

    ADD_EXECUTABLE(CLogTest "Main.cpp")

    TARGET_LINK_LIBRARIES(CLogTest CLog)
    TARGET_LINK_LIBRARIES(CLogTest ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()
