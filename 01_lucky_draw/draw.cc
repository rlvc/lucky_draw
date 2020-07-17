#include "draw.h"
#include <stdio.h>
#include <stdlib.h>
static int call_count = 0;
static int* random_data;
void Shuffle_FisherYates(int *arr, const int len);

LOTUS_INTERFACE_EXPORT int lucky_draw (int persons[]){
	int output = 0;
	if (NULL == persons) {
		throw ERROR_INVALID_PARAM;
	}
	if (ID_QTY == call_count) {
		printf("ALL ID CALLED !\n");
		call_count = 0;
		throw WARNNING_LOOP_FINISH;
	}
	if (0 == call_count) {
		random_data = new int[ID_QTY];
		Shuffle_FisherYates(persons, ID_QTY);
		for (size_t i = 0; i < ID_QTY; i++) {
			random_data[i] = persons[i];
		}
	}
	output = persons[call_count];
	call_count++;
	if (ID_QTY == call_count) {
		printf("Loop Finished!\n");
		delete[] random_data;
	}
	return output;
}

void Shuffle_FisherYates(int *arr, const int len) {
	for (int i = len - 1; i > 0; i--)
	{
		int a = rand() % (i + 1);
		int temp = arr[i];
		arr[i] = arr[a];
		arr[a] = temp;
	}
}