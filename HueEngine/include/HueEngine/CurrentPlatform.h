#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define HUE_WINDOWS
#elif defined(__linux__)
#define HUE_LINUX
#elif defined(__APPLE__)
#define HUE_MACOS
#endif

#if defined(HUE_WINDOWS)
#define HUE_API __declspec(dllexport)
#elif defined(HUE_LINUX) || defined(HUE_MACOS)
#define HUE_API
#endif

#if defined(HUE_WINDOWS)
#define HUE_CALL __stdcall
#elif defined(HUE_LINUX) || defined(HUE_MACOS)
#define HUE_CALL
#endif

#if defined(HUE_WINDOWS)
#define HUE_INLINE __forceinline
#elif defined(HUE_LINUX) || defined(HUE_MACOS)
#define HUE_INLINE inline
#endif

#if defined(HUE_WINDOWS)
#include <Windows.h>
#include <assert.h> 
#elif defined(HUE_LINUX)
#include <unistd.h>   // For POSIX functionality
#include <fcntl.h>    // For file control
#include <pthread.h>  // For POSIX threads
#include <stdio.h>    // For standard input/output
#include <stdlib.h>   // For general utility functions
#include <signal.h>   // For handling signals
#include <time.h>     // For date and time manipulation
#include <sys/types.h>  // For system data types
#include <sys/stat.h>   // For system file and directory manipulation
#include <cassert>     // For assert
#endif

