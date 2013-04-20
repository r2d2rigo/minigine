#pragma once
// disable warnings on extern before template instantiation
#pragma warning (disable : 4231)

#if _WINDOWS
    #ifdef MINIGINE_EXPORTS
        #define MINIGINE_API __declspec(dllexport)
        #define MINIGINE_EXPIMP
    #else
        #define MINIGINE_API __declspec(dllimport)
        #define MINIGINE_EXPIMP extern
    #endif
#else
    #define MINIGINE_API
    #define MINIGINE_EXPIMP
#endif

typedef unsigned char byte;