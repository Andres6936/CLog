# Levin

A very light-weight thread-safe extensible logging framework for C++.

This framework makes data-races in log-outputs a thing of the past.

## Framework

Levin is a very small library consisting of only two public header files:

- Log.h: This header defines the logging-methods, include it in any source-file
you want to log something in

- Logger.h: This header contains the Logger-classes. You only need to include
this file if you want to customize the logging output (style, destination, ...)

To support multi-threaded applications, any thread writing logs has its own
instance of an output-stream where it assembles the logging output in.

With the call of the *endl* function, the message is written to the output in a
thread-safe fashion.

## Usage

```cpp
    //Top of the file:
    #include <Levin/Levin.hpp>
    
    //Where you want to log:
    Levin::Debug("This is a debug message");
    Levin::Info("This is purely informational");
    Levin::Warn("Supports full C++ stream syntax, hence we can log {} as well as {}", 12, 42.42);
    Levin::Error("Something bad happened here!");
    Levin::Severe("Something really catastrophic happened! Do somthing, NOW!!");
```

## Configuration

Levin can optionally be configured in several ways:

Resetting **logger** to the `nullptr` disables logging for the remainder of the program's life. 
This also shuts down the logging-thread, so no CPU time is wasted. By default, the **LOGGER** is set to **ConsoleLogger** (see section Extensions).

## Extensions
In the current version, Levin comes with three built-in Loggers:

- ConsoleLogger: writes every log to `std::cout` and `std::cerr`, where any log with the levels **ERROR** and 
**SEVERE** are written to *std::cerr* and any other log goes to *std::cout*.

This Logger is enabled by default.
- FileLogger: Logs the output to a file, specified by a file-name given as constructor-argument.
- ColoredLogger: Writes any log to `std::cout` but uses console colors to highlight more critical messages.

To write your own Logger, simply follow this easy steps:

1. Write a Logger-class publicly extending **Logger** (in the header-file **Logger.h**) and overwrite at least **message**.
2. Use the global variable **LOGGER** to set the logger to an instance of your custom class
3. Done!

### How to use
To use this library, you need the script written by [TheLartians](https://github.com/TheLartians),
named [CPM.cmake](https://github.com/TheLartians/CPM.cmake) (acronym for CMake
Package Manager). Add it to your project, for example, under the
`CMakeModules` and then in your `CMakeFiles.txt` write the following:

```cmake
Include(CMakeModules/CPM.cmake)

CPMAddPackage(
  NAME Levin
  VERSION 2020.0602
  GITHUB_REPOSITORY Andres6936/Levin
)
 
TARGET_LINK_LIBRARIES(<TARGET> PRIVATE Levin)
```
