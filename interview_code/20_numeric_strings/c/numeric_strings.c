#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int scan_unsigned_inter(const char **str)
{
	const char *before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9'){
		(*str)++;
	}
	return *str > before;
}

int scan_inter(const char **str)
{
	if(**str == '-' || **str == '+'){
		(*str)++;
	}
	return scan_unsigned_inter(str);
}

int is_numeric(const char *str)
{
	int numeric = 0;
	if(NULL == str){
		return 0;
	}
	
	numeric = scan_inter(&str);
	if(*str == '.'){
		str++;
		numeric = scan_unsigned_inter(&str) || numeric;
	}
	
	if(*str == 'e' || *str == 'E'){
		str++;
		numeric = numeric && scan_inter(&str);
	}
	return numeric && *str == '\0';
}



// ====================测试代码====================
void test(const char* test_name, const char* str, unsigned int expected)
{
    if(test_name != NULL){
		printf("%s begins: ", test_name);
	}
        
    if(is_numeric(str) == expected){
		printf("Passed.\n");
	}
    else{
		printf("FAILED.\n");
	}
}


int main(int argc, char* argv[])
{
    test("test1", "100", 1);
    test("test2", "123.45e+6", 1);
    test("test3", "+500", 1);
    test("test4", "5e2", 1);
    test("test5", "3.1416", 1);
    test("test6", "600.", 1);
    test("test7", "-.123", 1);
    test("test8", "-1E-16", 1);
    test("test9", "1.79769313486232E+308", 1);

    printf("\n\n");

    test("test10", "12e", 0);
    test("test11", "1a3.14", 0);
    test("test12", "1+23", 0);
    test("test13", "1.2.3", 0);
    test("test14", "+-5", 0);
    test("test15", "12e+5.4", 0);
    test("test16", ".", 0);
    test("test17", ".e1", 0);
    test("test18", "e1", 0);
    test("test19", "+.", 0);
    test("test20", "", 0);
    test("test21", NULL, 0);

    return 0;
}