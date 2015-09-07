#define PLATFORM_WIN32

#ifdef PLATFORM_WIN32
#define ext __declspec(dllexport) __stdcall
#endif
