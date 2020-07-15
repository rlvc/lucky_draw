#include "draw.h"
#include <stdio.h>

LOTUS_INTERFACE_EXPORT int LOTUS_INTERFACE_API lucky_draw (int persons[]){
	static int output = 0;
	printf("current output is %d", output++);
	return output;
}