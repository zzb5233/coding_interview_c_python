#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int match_core(const char *str, const char *pattern)
{
	if('\0' == *str && '\0' == *pattern){
		return 1;
	}
	
	if('\0' != *str && '\0' == *pattern){
		return 0;
	}
	
	if(*(pattern+1) == '*'){
		if(*pattern == *str || (*pattern == '.' && *str != '\0')){
			return match_core(str+1, pattern+2) || match_core(str+1, pattern) || match_core(str, pattern+2);
		}else{
			return match(str, pattern+2);
		}
	}
	
	if(*pattern == *str || *pattern == '.'){
		return match_core(str+1, pattern+1);
	}
	return 0;
}



int match(const char *str, const char *pattern)
{
	if(NULL == str || NULL == pattern){
		return 0;
	}
	
	return match_core(str, pattern);
}


// ====================测试代码====================
void test(const char* test_name, const char* string, const char* pattern, int expected)
{
    if(test_name != NULL){
		printf("%s begins: ", test_name);
	}

    if(match(string, pattern) == expected){
		printf("Passed.\n");
	}else{
		printf("FAILED.\n");
	}
}


int main(int argc, char* argv[])
{
    test("test01", "", "", 1);
    test("test02", "", ".*", 1);
    test("test03", "", ".", 0);
    test("test04", "", "c*", 1);
    test("test05", "a", ".*", 1);
    test("test06", "a", "a.", 0);
    test("test07", "a", "", 0);
    test("test08", "a", ".", 1);
    test("test09", "a", "ab*", 1);
    test("test10", "a", "ab*a", 0);
    test("test11", "aa", "aa", 1);
    test("test12", "aa", "a*", 1);
    test("test13", "aa", ".*", 1);
    test("test14", "aa", ".", 0);
    test("test15", "ab", ".*", 1);
    test("test16", "ab", ".*", 1);
    test("test17", "aaa", "aa*", 1);
    test("test18", "aaa", "aa.a", 0);
    test("test19", "aaa", "a.a", 1);
    test("test20", "aaa", ".a", 0);
    test("test21", "aaa", "a*a", 1);
    test("test22", "aaa", "ab*a", 0);
    test("test23", "aaa", "ab*ac*a", 1);
    test("test24", "aaa", "ab*a*c*a", 1);
    test("test25", "aaa", ".*", 1);
    test("test26", "aab", "c*a*b", 1);
    test("test27", "aaca", "ab*a*c*a", 1);
    test("test28", "aaba", "ab*a*c*a", 0);
    test("test29", "bbbba", ".*a*a", 1);
    test("test30", "bcbbabab", ".*a*a", 0);

    return 0;
}