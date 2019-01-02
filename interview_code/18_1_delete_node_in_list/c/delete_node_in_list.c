#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utilities/list.h"




void delete_node(list_node **head, list_node *node)
{
	list_node *cur = *head;
	
	if(!head || !node){
		return;
	}
	if(node == *head){
		*head = NULL;
		free(node);
	}else if(node->p_next == NULL){
		while(cur->p_next != node){
			cur = cur->p_next;
		}
		
		cur->p_next = NULL;
		free(node);
	}else{
		node->val = node->p_next->val;
		node->p_next = node->p_next->p_next;
		free(node->p_next);
	}
}


void main(void)
{
	
}