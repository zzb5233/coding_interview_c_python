#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../utilities/list.h"


void delete_duplicated_node(list_node **head)
{
	if(NULL == head || NULL == *head){
		return;
	}
	
	list_node *p_cur = *head;
	list_node *p_pre, *p_next, *p_to_be_del;
	int need_delete_flag = 0;
	int value;
	while(p_cur)
	{
		p_next = p_cur->p_next;
		if(p_next != NULL && p_next->val == p_cur->val){
			need_delete_flag = 1;
		}
		
		if(!need_delete_flag){
			p_pre = p_cur;
			p_next = p_cur->p_next;
		}else{
			p_to_be_del = p_cur;
			value = p_to_be_del->val;
			while(p_to_be_del != NULL && value == p_to_be_del->val){
				p_next = p_to_be_del->p_next;
				free(p_to_be_del);
				p_to_be_del = p_next;
			}
		}
		
		if(NULL == p_pre){
			*head = p_next;
		}else{
			p_pre->p_next = p_next;
		}
		p_cur = p_next;
	}
}



void main(void)
{
	;
}