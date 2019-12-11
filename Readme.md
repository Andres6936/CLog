# CLog

A very light-weight thread-safe extensible logging framework for C++.

This framework makes data-races in log-outputs a thing of the past.

## Framework

CppLog is a very small library consisting of only two public header files:

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
    #include "Log.h"
    
    //Where you want to log:
    CLog::Debug() << "This is a debug message" << Standard::endl;
    CLog::Info() << "This is purely informational" << Standard::endl;
    CLog::Warn() << "Supports full C++ stream syntax, hence we can log " << 12 << " as well as " << 42.42 << Standard::endl;
    CLog::Error() << "Something bad happened here!" << Standard::endl;
    CLog::Severe() << "Something really catastrophic happened! Do somthing, NOW!!" << Standard::endl;
```

## Configuration

CppLog can optionally be configured in several ways:

- Setting the global variable **LOGGER** in the framework's namespace
(by default **CLog::LOGGER**) determines the logger to be used.
Resetting **LOGGER** to the *nullptr* disables logging for the remainder of the program's life. 
This also shuts down the logging-thread, so no CPU time is wasted. By default, the **LOGGER** is set to **ConsoleLogger** (see section Extensions).

## Extensions
In the current version, CppLog comes with three built-in Loggers:

- ConsoleLogger: writes every log to *std::cout* and *std::cerr*, 
where any log with the levels **ERROR** and **SEVERE** are written to *std::cerr* and any other log goes to *std::cout*.
This Logger is enabled by default.
- FileLogger: Logs the output to a file, specified by a file-name given as constructor-argument.
- ColoredLogger: Writes any log to *std::cout* but uses console colors to highlight more critical messages.

To write your own Logger, simply follow this easy steps:

1. Write a Logger-class publicly extending **Logger** (in the header-file **Logger.h**) and overwrite at least **message**.
2. Use the global variable **LOGGER** to set the logger to an instance of your custom class
3. Done!