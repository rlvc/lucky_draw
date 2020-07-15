#include <iostream>

#define ERROR_UNDEFINED			  0x80000000
#define ERROR_INVALID_PARAM		  0x80000001

int find_in_integral_map(int* integral_map, int rows, int cols, int target, int &target_row, int & target_col) {
	if (NULL == integral_map || rows < 0 || cols < 0) {
		return ERROR_INVALID_PARAM;
	}
	int target_located = -1;
	int current_row = 0;
	int current_col = cols - 1;
	while (current_row < rows && current_col >= 0) {
		if (target == integral_map[current_row * cols + current_col]) {
			target_located = 0;
			break;
		}
		else if (target < integral_map[current_row * cols + current_col]) {
			--current_col;
		}
		else
			++current_row;
	}
	if (0 == target_located) {
		target_row = current_row;
		target_col = current_col;
	}
	else{
		target_row = -1;
		target_col = -1;
	}
	
	return target_located;
}

int main()
{
	int a[16] = { 1 ,2, 8, 9, 2, 4, 9, 12, 4, 7, 10 ,13, 6, 8 ,11, 15 };
	int target = 6;
	int target_row = -1;
	int target_col = -1;
	int ret = find_in_integral_map(&a[0], 4, 4, target, target_row, target_col);
	if (0 == ret) {
		std::cout << "Find target " << target << " in : row " << target_row + 1 << " col " << target_col + 1 << std::endl;
	}
    
}

