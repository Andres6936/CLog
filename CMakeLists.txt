CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(Levin VERSION 2021.0109 LANGUAGES CXX)

# The shared libraries are libraries that can be linked dynamically and loaded at runtime.
OPTION(LEVIN_SHARED_LIBRARIES "Generate the Shared Libraries" OFF)
OPTION(LEVIN_BUILD_TEST "Build the concurrency test-application" OFF)

### Support to Command <make install>

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
INCLUDE(GNUInstallDirs)

ADD_LIBRARY(Levin.Framework.Object OBJECT
        Source/Log.cpp
        Source/Logger.cpp
        Source/FileLogger.cpp
        Source/StreamLogger.cpp
        Source/ColoredLogger.cpp
        Source/ConsoleLogger.cpp
        )

SET_TARGET_PROPERTIES(Levin.Framework.Object PROPERTIES CXX_STANDARD 17)
# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
TARGET_INCLUDE_DIRECTORIES(Levin.Framework.Object
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

IF (LEVIN_SHARED_LIBRARIES)

    # The POSITION_INDEPENDENT_CODE property determines whether position independent executables or
    # shared libraries will be created. This property is True by default for SHARED and MODULE library
    # targets and False otherwise.

    # Property: SHARED, POSITION_INDEPENDENT_CODE
    ADD_LIBRARY(Levin.Framework SHARED $<TARGET_OBJECTS:Levin.Framework.Object>)

ELSE()

    ADD_LIBRARY(Levin.Framework STATIC $<TARGET_OBJECTS:Levin.Framework.Object>)

ENDIF()

ADD_LIBRARY(Levin::Framework ALIAS Levin.Framework)
# It is necessary to repeat these instructions again, in case of not doing it, the executables
# will be unable to locate the Headers needed to perform the linking
TARGET_INCLUDE_DIRECTORIES(Levin.Framework
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )

# Test-program
IF (LEVIN_BUILD_TEST)
    FIND_PACKAGE(Threads)

    ADD_EXECUTABLE(LevinTest "Main.cpp")

    TARGET_LINK_LIBRARIES(LevinTest PRIVATE Levin)
    TARGET_LINK_LIBRARIES(LevinTest PRIVATE ${CMAKE_THREAD_LIBS_INIT})

    # Execute the test content in the directory
    ADD_SUBDIRECTORY(Test/)
ENDIF ()
