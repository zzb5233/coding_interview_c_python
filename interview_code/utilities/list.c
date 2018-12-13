#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_node* create_list_node(int value)
{
    list_node* p_node = new list_node();
    p_node->val = value;
    p_node->p_next = NULL;

    return p_node;
}

void connect_list_nodes(list_node* p_current, list_node* p_next)
{
    if(p_current == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    p_current->p_next = p_next;
}

void print_list_node(list_node* p_node)
{ 
    if(p_node == NULL)
    {
        printf("The node is NULL\n");
    }
    else
    {
        printf("The key in node is %d.\n", p_node->val);
    }
}

void print_list(list_node* p_head)
{
    printf("PrintList starts.\n");
    
    list_node* p_node = p_head;
    while(p_node != NULL)
    {
        printf("%d\t", p_node->val);
        p_node = p_node->p_next;
    }

    printf("\nPrintList ends.\n");
}

void destroy_list(list_node* p_head)
{
    list_node* p_node = p_head;
    while(p_node != NULL)
    {
        p_head = p_head->p_next;
        delete p_node;
        p_node = p_head;
    }
}

void add_to_tail(list_node** p_head, int value)
{
    list_node* p_new = new list_node();
    p_new->val = value;
    p_new->p_next = NULL;

    if(*p_head == NULL)
    {
        *p_head = p_new;
    }
    else
    {
        list_node* p_node = *p_head;
        while(p_node->p_next != NULL)
            p_node = p_node->p_next;

        p_node->p_next = p_new;
    }
}

void remove_node(list_node** p_head, int value)
{
    if(p_head == NULL || *p_head == NULL)
        return;

    list_node* p_to_be_deleted = NULL;
    if((*p_head)->val == value)
    {
        p_to_be_deleted = *p_head;
        *p_head = (*p_head)->p_next;
    }
    else
    {
        list_node* p_node = *p_head;
        while(p_node->p_next != NULL && p_node->p_next->val != value)
            p_node = p_node->p_next;

        if(p_node->p_next != NULL && p_node->p_next->val == value)
        {
            p_to_be_deleted = p_node->p_next;
            p_node->p_next = p_node->p_next->p_next;
        }
    }

    if(p_to_be_deleted != NULL)
    {
        delete p_to_be_deleted;
        p_to_be_deleted = NULL;
    }
}