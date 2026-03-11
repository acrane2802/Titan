#ifndef TITAN_CORE_H
#define TITAN_CORE_H

#ifdef TITAN_PLATFORM_WINDOWS
    #ifdef TITAN_BUILD_DLL
        #define TITAN_API __declspec(dllexport)
    #else
        #define TITAN_API __declspec(dllimport)
    #endif
#endif

#ifdef TITAN_PLATFORM_LINUX
// Linux Compilation Code Here
#endif

#ifdef TITAN_PLATFORM_MACOS
// Mac Compilation Code Here
#endif

#endif