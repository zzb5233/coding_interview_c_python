#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
#define LENGTH	100 

void replace_space(char *str, int length)
{
	int new_length;
	int original_length = 0;
	int space_number = 0;
	int i = 0;
	
	if(NULL == str || 0 >= length){
		return;
	}
	
	while(str[original_length] != '\0'){
		if(str[original_length] == ' '){
			space_number++;
		}
		original_length++;
	}
	new_length = original_length + space_number * 2;
	if(new_length > length){
		return;
	}
	
	while(original_length >= 0){
		if(str[original_length] != ' '){
			str[new_length--] = str[original_length--];
		}else{
			original_length--;
			str[new_length--] = '0';
			str[new_length--] = '2';
			str[new_length--] = '%';
		}
	}
}


void test(char* testName, char str[], int length, char expected[])
{
    if(testName != NULL){
		printf("%s begins: ", testName);
	}
    
    replace_space(str, length);

    if(expected == NULL && str == NULL){
		printf("passed.\n");
	}   
    else if(expected == NULL && str != NULL){
		printf("failed.\n");
	}
    else if(strcmp(str, expected) == 0){
		printf("passed.\n");
	}
    else{
		printf("failed.\n");
	}
}


// 空格在句子中间
void test1()
{
    char str[LENGTH] = "hello world";
    test("test1", str, LENGTH, "hello%20world");
}

// 空格在句子开头
void test2()
{
    char str[LENGTH] = " helloworld";
    test("test2", str, LENGTH, "%20helloworld");
}

// 空格在句子末尾
void test3()
{
    char str[LENGTH] = "helloworld ";
    test("test3", str, LENGTH, "helloworld%20");
}

// 连续有两个空格
void test4()
{
    char str[LENGTH] = "hello  world";
    test("test4", str, LENGTH, "hello%20%20world");
}

// 传入NULL
void test5()
{
    test("test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void test6()
{
    char str[LENGTH] = "";
    test("test6", str, LENGTH, "");
}

//传入内容为一个空格的字符串
void test7()
{
    char str[LENGTH] = " ";
    test("test7", str, LENGTH, "%20");
}

// 传入的字符串没有空格
void test8()
{
    char str[LENGTH] = "helloworld";
    test("test8", str, LENGTH, "helloworld");
}

// 传入的字符串全是空格
void test9()
{
    char str[LENGTH] = "   ";
    test("test9", str, LENGTH, "%20%20%20");
}


void main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
}



