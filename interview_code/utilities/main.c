/*
	测试接口
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"


void free_fn(void *element)
{
	char *p;
	p = *((char **)element);
	free(p);
	return;
}

int main(int argc, char const *argv[])
{
	const char *friends[] = {"Alex","Bob","Caser"};
	stack stack_info;
	int i;
	char *copy;
	
	stack_new(&stack_info, sizeof(char *));
	stack_info.free_fn = free_fn;
	
	for(i = 0; i < 3; ++i)
	{
		copy = strdup(friends[i]);
		assert(NULL != copy);
		stack_push(&stack_info, &copy);
	}
	
	for (i = 0; i < 3; i++)
	{
		char *name;
		stack_pop(&stack_info, &name);
		printf("%s\n", name);
	}
	
	stack_dispose(&stack_info);
	printf("Over\n");
	
	return 0;
}