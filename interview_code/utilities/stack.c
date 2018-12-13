/*
	支持泛型的栈，push、pop、new、dispose。
	支持对真实内存释放。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"


void stack_new(stack *s, int element_size)
{
	s->max_length = DEFIND_LENGTH;
	s->cur_length = 0;
	s->element_size = element_size;
	s->element = malloc(s->max_length * element_size);
	s->free_fn = NULL;
	assert(NULL != s->element);
	return;
}


void stack_grow(stack *s)
{
	s->max_length *= 2;
	s->element = realloc(s->element, s->max_length * s->element_size);
	assert(NULL != s->element);
	return;
}
void stack_dispose(stack *s)
{
	int i; 
	
	if(s->free_fn){
		for(i = 0; i < s->cur_length; i++){
			s->free_fn((char *)s->element + i * s->element_size);
		}
	}
	
	free(s->element);
	return;
}
void stack_push(stack *s, void *element_addr)
{
	void *target = NULL;
	if(s->cur_length >= s->max_length){
		stack_grow(s);
	}
	target = (char *)s->element + s->element_size * s->cur_length++;
	memcpy(target, element_addr, s->element_size);
	
	return;
}

void stack_pop(stack *s, void *element_addr)
{
	void *source = NULL;
	
	assert(s->cur_length--);
	source = (char *)s->element + s->cur_length * s->element_size;
	memcpy(element_addr, source, s->element_size);
	return;
}

