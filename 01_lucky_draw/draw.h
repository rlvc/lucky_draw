#ifndef _LUCKY_DRAW_H_
#define _LUCKY_DRAW_H_

#if defined(__CYGWIN32__)
	#define LOTUS_INTERFACE_API __stdcall
	#define LOTUS_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY)
	#define LOTUS_INTERFACE_API __stdcall
	#define LOTUS_INTERFACE_EXPORT __declspec(dllexport)
#elif defined(__MACH__) || defined(__ANDROID__) || defined(__linux__) || defined(__QNX__)
	#define LOTUS_INTERFACE_API
	#define LOTUS_INTERFACE_EXPORT
#else
	#define LOTUS_INTERFACE_API
	#define LOTUS_INTERFACE_EXPORT
#endif

LOTUS_INTERFACE_EXPORT int lucky_draw (int persons[]);
 
#endif