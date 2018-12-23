#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min_number_in_rotated_array(int *numbers, int count, int *return_number)
{
	int i;
	int min;
	
	if(NULL == numbers || count <= 0){
		return -1;
	}
	min = numbers[0];
	for(i = 1; i < count; i++){
		if(numbers[i] < min){
			min = numbers[i];
		}
	}
	*return_number = min;
	return 0;
}


int get_min(int *numbers, int count, int *return_number)
{
	if(NULL == numbers || count <= 0){
		return -1;
	}
	
	int start_index = 0;
	int end_index = count-1;
	int middle_index = start_index;
	while(numbers[start_index] >= numbers[end_index]){
		if(end_index - start_index == 1){
			middle_index = end_index;
			break;
		}
		
		middle_index = (start_index+end_index)/2;
		
		if(numbers[start_index] == numbers[middle_index] && numbers[middle_index] == numbers[end_index]){
			return min_number_in_rotated_array(numbers, count, return_number);
		}
		if(numbers[middle_index] >= numbers[end_index]){
			start_index = middle_index;
		}else{
			end_index = middle_index;
		}
	}
	*return_number = numbers[middle_index];
	return 0;
}

// ====================测试代码====================
void test(int* numbers, int length, int expected_1, int expected_2)
{
    int result = 0;
	int i;
	
	for(i = 0; i < length; ++i){
		printf("%d ", numbers[i]);
	}
	
	if(expected_2 == get_min(numbers, length, &result)){
		if(result == expected_1){
			printf("\tpassed\n");
		}else{
			printf("\tfailed\n");
		}
	}else{
		printf("test failed.\n");
	}
}

int main(int argc, char* argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    test(array1, sizeof(array1) / sizeof(int), 1, 0);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    test(array2, sizeof(array2) / sizeof(int), 1, 0);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    test(array3, sizeof(array3) / sizeof(int), 1, 0);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    test(array4, sizeof(array4) / sizeof(int), 0, 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    test(array5, sizeof(array5) / sizeof(int), 1, 0);

    // 数组中只有一个数字
    int array6[] = { 2 };
    test(array6, sizeof(array6) / sizeof(int), 2, 0);

    // 输入NULL
    test(NULL, 0, 0, -1);

    return 0;
}