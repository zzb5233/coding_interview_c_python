// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../utilities/list.h"
#include "../../utilities/stack.h"

void print_list_reversingly_iteratively(list_node* p_head)
{
    stack nodes;
	list_node *p;
    list_node* p_node = p_head;
	
	stack_new(&nodes, sizeof(list_node *));
	
    while(p_node != NULL)
    {
        stack_push(&nodes, (void *)&p_node);
        p_node = p_node->p_next;
    }

    while(!stack_empty(&nodes))
    {
        p_node = (list_node *)stack_top(&nodes);
        printf("%d\t", p_node->val);
        stack_pop(&nodes, &p);
    }
}

void print_list_reversingly_recursively(list_node* p_head)
{
    if(p_head != NULL)
    {
        if (p_head->p_next != NULL)
        {
            print_list_reversingly_recursively(p_head->p_next);
        }
 
        printf("%d\t", p_head->val);
    }
}

// ====================测试代码====================
void test(list_node* p_head)
{
    print_list(p_head);
    print_list_reversingly_iteratively(p_head);
    printf("\n");
    print_list_reversingly_recursively(p_head);
}

// 1->2->3->4->5
void test1()
{
    printf("\ntest1 begins.\n");

    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_nodes(p_node1, p_node2);
    connect_list_nodes(p_node2, p_node3);
    connect_list_nodes(p_node3, p_node4);
    connect_list_nodes(p_node4, p_node5);

    test(p_node1);

    destory_list(p_node1);
}

// 只有一个结点的链表: 1
void test2()
{
    printf("\ntest2 begins.\n");

    list_node* p_node1 = create_list_node(1);

    test(p_node1);

    destory_list(p_node1);
}

// 空链表
void test3()
{
    printf("\ntest3 begins.\n");

    test(NULL);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();

    return 0;
}
