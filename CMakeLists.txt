CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

# Set C++ standard to C++11 without any extensions (e.g. GNU)
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

PROJECT(cpplog VERSION 0.4)

OPTION(CPPLOG_BUILD_TEST "Build the concurrency test-application" ON)
OPTION(ENABLE_SANITIZERS "Enable build with various sanitizers" OFF)
SET(CPPLOG_NAMESPACE "log" CACHE STRING "Namespace for the cpplog library")

SET(SRCS
        include/log.h
        include/logger.h
        src/log.cpp
        src/logger.cpp
        src/log_impl.h
        src/log_impl.cpp
        )

# For in-tree build, move libraries to build
IF (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
ENDIF ()

IF (WIN32)
    ADD_LIBRARY(cpplog STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(cpplog PRIVATE /W3 /D_UNICODE /DUNICODE)
ELSE ()
    ADD_LIBRARY(cpplog SHARED ${SRCS})
    ADD_LIBRARY(cpplog-static STATIC ${SRCS})
    TARGET_COMPILE_OPTIONS(cpplog PRIVATE -O3 -Wall -Wextra -Wold-style-cast -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
    TARGET_COMPILE_OPTIONS(cpplog-static PRIVATE -O3 -Wall -Wextra -Wold-style-cast -Wno-unused-parameter -Wno-missing-field-initializers -Wpedantic -pthread -fPIC)
ENDIF ()

TARGET_COMPILE_DEFINITIONS(cpplog PUBLIC -DCPPLOG_NAMESPACE=${CPPLOG_NAMESPACE})

# If CPPLOG_CUSTOM_LOGGER is set via command-line, the global CPPLOG_NAMESPACE::LOGGER variable needs to be given by the application including this library
IF (CPPLOG_CUSTOM_LOGGER)
    TARGET_COMPILE_DEFINITIONS(cpplog PUBLIC -DCPPLOG_CUSTOM_LOGGER)
ENDIF ()

IF (TARGET cpplog-static)
    TARGET_COMPILE_DEFINITIONS(cpplog-static PUBLIC -DCPPLOG_NAMESPACE=${CPPLOG_NAMESPACE})
    TARGET_INCLUDE_DIRECTORIES(cpplog-static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

    IF (CPPLOG_CUSTOM_LOGGER)
        TARGET_COMPILE_DEFINITIONS(cpplog-static PUBLIC -DCPPLOG_CUSTOM_LOGGER)
    ENDIF ()
ENDIF ()

# Enable sanitizers
IF (ENABLE_SANITIZERS)
    TARGET_COMPILE_OPTIONS(cpplog PRIVATE -fsanitize=address -fsanitize=leak -fsanitize=undefined)
    TARGET_COMPILE_OPTIONS(cpplog PRIVATE -fdelete-null-pointer-checks -Wnull-dereference -Wuninitialized -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wsuggest-override -Wconversion -Wzero-as-null-pointer-constant)

    IF (TARGET cpplog-static)
        TARGET_COMPILE_OPTIONS(cpplog-static PRIVATE -fsanitize=address -fsanitize=leak -fsanitize=undefined)
        TARGET_COMPILE_OPTIONS(cpplog-static PRIVATE -fdelete-null-pointer-checks -Wnull-dereference -Wuninitialized -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn -Wsuggest-attribute=format -Wsuggest-override -Wconversion -Wzero-as-null-pointer-constant)
    ENDIF ()

ENDIF ()

# "For shared libraries VERSION and SOVERSION can be used to specify the build version and API version respectively."
SET_TARGET_PROPERTIES(
        cpplog PROPERTIES
        # This corresponds to the project/library-version
        VERSION "${PROJECT_VERSION}"
        # This corresponds to the API-version
        SOVERSION "0"
)


# Test-program
IF (CPPLOG_BUILD_TEST)
    ADD_EXECUTABLE(cpplog-test "main.cpp")
    TARGET_LINK_LIBRARIES(cpplog-test cpplog)
    SET_TARGET_PROPERTIES(cpplog-test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")

    FIND_PACKAGE(Threads)
    TARGET_LINK_LIBRARIES(cpplog-test ${CMAKE_THREAD_LIBS_INIT})
ENDIF ()


##
# Installation targets
##
# Adds the public headers to the target, so they are exported
TARGET_INCLUDE_DIRECTORIES(cpplog PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include/cpplog>)
# Creates the install target for the library
INSTALL(TARGETS cpplog EXPORT cpplog-targets LIBRARY DESTINATION lib)
# Creates the export target (to be used by CMake to find the INSTALLED library)
INSTALL(EXPORT cpplog-targets DESTINATION share/cpplog)
# Creates the install target for the headers
INSTALL(DIRECTORY include/ DESTINATION include/cpplog FILES_MATCHING PATTERN "*.h")
# Exports the target (to be used by CMake to find the SOURCE library)
EXPORT(TARGETS cpplog FILE cpplog-exports.cmake)
# Adds custom uninstall command
ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "cmake_uninstall.cmake")
