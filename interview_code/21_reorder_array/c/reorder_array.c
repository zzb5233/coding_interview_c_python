#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 	1
#define false 	0
#define bool 	unsigned int





void reorder_odd_even_1(int *array, int length)
{
	int *p_start, *p_end;
	int temp;
	if(NULL == array){
		return;
	}
	
	p_start = array;
	p_end = array + length - 1;
	
	while(p_start < p_end){
		while(p_start < p_end && (*p_start & 0x1) != 0){
			p_start++;
		}
		while(p_start < p_end && (*p_end & 0x1) == 0){
			p_end--;
		}
		if(p_start < p_end){
			temp = *p_end;
			*p_end = *p_start;
			*p_start = temp;
		}
	}
	return;
}

bool is_even(int num)
{
	return (0x1 & num) == 0;
}

void reorder(int *array, int length, bool (*func)(int))
{
	int *p_start, *p_end;
	int temp;
	
	if(NULL == array){
		return;
	}
	
	p_start = array;
	p_end = array + length - 1;
	
	while(p_start < p_end){
		while(p_start < p_end && !func(*p_start)){
			p_start++;
		}
		while(p_start < p_end && func(*p_end)){
			p_end--;
		}
		if(p_start < p_end){
			temp = *p_end;
			*p_end = *p_start;
			*p_start = temp;
		}
		
	}
}

void reorder_odd_even_2(int *array, int length)
{
	return reorder(array, length, is_even);
}

// ====================测试代码====================
void print_array(int numbers[], int length)
{
	int i;
    if(length < 0)
        return;

    for(i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void test(char* test_name, int numbers[], int length)
{
	int i;
    if(test_name != NULL){
		printf("%s begins:\n", test_name);
	}

	int *copy = malloc(sizeof(int) * length);
    for(i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("test for solution 1:\n");
    print_array(numbers, length);
    reorder_odd_even_1(numbers, length);
    print_array(numbers, length);

    printf("test for solution 2:\n");
    print_array(copy, length);
    reorder_odd_even_2(copy, length);
    print_array(copy, length);

    free(copy);
	copy = NULL;
}

void test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    test("test1", numbers, sizeof(numbers)/sizeof(int));
}

void test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    test("test2", numbers, sizeof(numbers)/sizeof(int));
}

void test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    test("test3", numbers, sizeof(numbers)/sizeof(int));
}

void test4()
{
    int numbers[] = {1};
    test("test4", numbers, sizeof(numbers)/sizeof(int));
}

void test5()
{
    int numbers[] = {2};
    test("test5", numbers, sizeof(numbers)/sizeof(int));
}

void test6()
{
    test("test6", NULL, 0);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
