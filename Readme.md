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

Currently, Levin's severity levels (log functions) are based on the standard 
[RFC5424](https://tools.ietf.org/html/rfc5424), that define the follow severity levels.

| Value | Severity  | Description |
|------ | --------- | ----------- |
| 0     | Emergency | System is unusable |
| 1     | Alert     | Action must be taken immediately |
| 2     | Critical  | Critical conditions |
| 3     | Error     | Error conditions |
| 4     | Warning   | Warning conditions |
| 5     | Notice    | Normal but significant conditions |
| 6     | Informational | Informational messages |
| 7     | Debug     | Debug-level messages |

```cpp
//Top of the file:
#include <Levin/Levin.hpp>

//Where you want to log:
Levin::Debug("This is a debug message");
Levin::Informational("This is purely informational");
Levin::Warning("Supports full C++ stream syntax, hence we can log {} as well as {}", 12, 42.42);
Levin::Error("Something bad happened here!");
Levin::Critical("Something really catastrophic happened! Do somthing, NOW!!");
Levin::Emergency("Imminent failure, the system will shut down");
Levin::Alert("This is a {} message", "alert");
```

It is important to note that Levin uses [Flossy](https://github.com/Andres6936/Flossy) 
to format the strings, resulting in  a formatting of strings inspired in Python 3.

```cpp
Levin::Information("The first value passed is {}, and the second is {}!", 42, "foo");
```

###### For see the Format Specification Language consult the documentation of Flossy

## Configuration

Levin can optionally be configured in several ways:

Resetting **logger** to the `nullptr` disables logging for the remainder of the program's life. 
This also shuts down the logging-thread, so no CPU time is wasted. By default, the **LOGGER** is set to **ConsoleLogger** (see section Extensions).

## Extensions
In the current version, Levin comes with three built-in Loggers:

- ConsoleLogger: writes every log to `std::cout` and `std::cerr`, where any log with the levels **Error** and 
**Notice** are written to *std::cerr* and any other log goes to *std::cout*.

This Logger is enabled by default.
- FileLogger: Logs the output to a file, specified by a file-name given as constructor-argument.
- ColoredLogger: Writes any log to `std::cout` but uses console colors to highlight more critical messages.

To write your own Logger, simply follow this easy steps:

1. Write a Logger-class publicly extending **Logger** (in the header-file **Logger.h**) and overwrite at least **message**.
2. Use the global variable **LOGGER** to set the logger to an instance of your custom class
3. Done!

### How to Compile

```shell
git clone --depth=1 https://github.com/Andres6936/Levin.git
cd Levin && mkdir Build
cd Build && cmake ..
make 
```

### How to use the library as a downloadable dependency

To use this library, you need the script written by [TheLartians](https://github.com/TheLartians),
named [CPM.cmake](https://github.com/TheLartians/CPM.cmake) (acronym for CMake
Package Manager). Add it to your project, for example, under the
`CMakeModules` and then in your `CMakeFiles.txt` write the following:

- The directory `CMakeModules` is used to store CMake Scripts,
  in case you use another directory for these purposes it will be necessary that
  references properly CPM.cmake to be able to download the dependency.

```cmake
Include(CMakeModules/CPM.cmake)

CPMAddPackage(
  NAME Levin
  VERSION 2020.0602
  GITHUB_REPOSITORY Andres6936/Levin
)
 
TARGET_LINK_LIBRARIES(<TARGET> PRIVATE Levin::Framework)
```
