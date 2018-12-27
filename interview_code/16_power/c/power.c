#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_error_value = 0;


int equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)){
		return 1;
	}else{
		return 0;
	}
}
        

double power_with_unsigned_exponent(double base, unsigned int exponent)
{
	double result = 1.0;
	int i;
	
	for(i = 0; i < exponent; i++){
		result *= base;
	}
	
	return result;
}



double power(double base, int exponent)
{
	unsigned int abs_exponent;
	g_error_value = 0;
	double result;
	
	if(equal(base, 0.0) && exponent < 0){
		g_error_value = 1;
		return 0;
	}
	
	if(exponent < 0){
		abs_exponent = (unsigned int)(-exponent);
	}else{
		abs_exponent = (unsigned int )exponent;
	}
	
	result = power_with_unsigned_exponent(base, abs_exponent);
	if(exponent < 0){
		result = 1.0 / result;
	}
	
	return result;
}




/*
void main(void)
{
	double base = -5;
	int exponent = -1;
	
	printf("%.3f\n", power(base, exponent));
}*/


// ====================测试代码====================
void test(const char* test_name, double base, int exponent, double expected_result, int expected_flag)
{
    double result = power(base, exponent);
    if (equal(result, expected_result) && g_error_value == expected_flag){
		printf("%s: passed\n", test_name);
	}
    else{
		printf("%s: failed\n", test_name);
	}
}

int main(int argc, char* argv[])
{
    // 底数、指数都为正数
    test("Test1", 2, 3, 8, 0);

    // 底数为负数、指数为正数
    test("Test2", -2, 3, -8, 0);

    // 指数为负数
    test("Test3", 2, -3, 0.125, 0);

    // 指数为0
    test("Test4", 2, 0, 1, 0);

    // 底数、指数都为0
    test("Test5", 0, 0, 1, 0);

    // 底数为0、指数为正数
    test("Test6", 0, 4, 0, 0);

    // 底数为0、指数为负数
    test("Test7", 0, -4, 0, 1);

    return 0;
}