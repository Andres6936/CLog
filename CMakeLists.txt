CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Set C++ standard to C++11 without any extensions (e.g. GNU)
SET(CMAKE_CXX_STANDARD 11)
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

# For in-tree build, move libraries to build
IF (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Build)
ENDIF ()

IF (WIN32)
    ADD_LIBRARY(CLog STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(CLog PRIVATE /W3 /D_UNICODE /DUNICODE)
ELSE ()
    ADD_LIBRARY(CLog SHARED ${SRCS})
    ADD_LIBRARY(CLogStatic STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(CLog PRIVATE -O3 -Wall -Wextra -Wold-style-cast -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
    TARGET_COMPILE_OPTIONS(CLogStatic PRIVATE -O3 -Wall -Wextra -Wold-style-cast -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
ENDIF ()

IF (TARGET CLogStatic)
    TARGET_INCLUDE_DIRECTORIES(CLogStatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)
ENDIF ()

# "For shared libraries VERSION and SOVERSION can be used to specify the build version and API version respectively."
SET_TARGET_PROPERTIES(
        CLog PROPERTIES
        # This corresponds to the project/library-version
        VERSION "${PROJECT_VERSION}"
        # This corresponds to the API-version
        SOVERSION "0")


# Test-program
IF (CPPLOG_BUILD_TEST)
    ADD_EXECUTABLE(CLogTest "Main.cpp")
    TARGET_LINK_LIBRARIES(CLogTest CLog)
    SET_TARGET_PROPERTIES(CLogTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Build")

    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(CLogTest ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()
