#ifndef _LUCKY_DRAW_H_
#define _LUCKY_DRAW_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(WINAPI_FAMILY) || defined(__CYGWIN32__)
	#define LOTUS_INTERFACE_EXPORT __declspec(dllexport)
#else
	#define LOTUS_INTERFACE_EXPORT
#endif
#define ERROR_UNDEFINED			  0x08000000
#define ERROR_INVALID_PARAM		  0x08000001
#define WARNNING_LOOP_FINISH	  0x08000002

#define ID_QTY 100

LOTUS_INTERFACE_EXPORT int lucky_draw(int persons[]);
 
#endif