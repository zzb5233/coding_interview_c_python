// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define bool unsigned 	int
#define false 			0
#define true 			1


void swap(int *p_value_1, int *p_value_2)
{
	if(NULL == p_value_1 || NULL == p_value_2 || p_value_1 == p_value_2){
		return;
	}
	
	*p_value_1 ^= *p_value_2;
	*p_value_2 ^= *p_value_1;
	*p_value_1 ^= *p_value_2;
	return;
}


bool find_duplication(int *numbers, int length, int *duplication)
{
	int i;
	if(NULL == numbers || length <= 0){
		return false;
	}
	for(i = 0; i < length; i++){
		if(numbers[i] < 0 || numbers[i] > length-1){
			return false;
		}
	}
	
	for(i = 0; i < length; i++)
	{
		while(numbers[i] != i){
			if(numbers[i] == numbers[numbers[i]]){
				*duplication = numbers[i];
				return true;
			}
			swap(&numbers[i], &numbers[numbers[i]]);
		}
	}
	return false;
}

// ====================测试代码====================
bool contains(int *array, int length, int number)
{
	int i;
    for(i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* test_name, int *numbers, int length_numbers, int *expected, int length_expect, bool valid_argument)
{
    printf("%s begins: ", test_name);

    int duplication;
    bool valid_input = find_duplication(numbers, length_numbers, &duplication);

    if(valid_argument == valid_input)
    {
        if(valid_argument)
        {
            if(contains(expected, length_expect, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = NULL;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

void main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}




















