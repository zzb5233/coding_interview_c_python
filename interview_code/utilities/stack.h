/*
	支持泛型的栈，push、pop、new、dispose。
	支持对真实内存释放。
*/


#ifndef __STACK_H__
#define __STACK_H__


#define DEFIND_LENGTH	4


typedef struct stack{
	void *element;
	int element_size;
	int cur_length;
	int max_length;
	void (*free_fn)(void *element);
}stack;



void stack_new(stack *s, int element_size);
void stack_grow(stack *s);
void stack_dispose(stack *s);
void stack_push(stack *s, void *element_addr);
void stack_pop(stack *s, void *element_addr);


#endif