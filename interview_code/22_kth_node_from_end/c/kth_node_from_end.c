#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utilities/list.h"


list_node *find_kth_to_tail(list_node *head, int k)
{
	if(NULL == head || k <= 0)
	{
		return NULL;
	}
	
	list_node *fast = head;
	list_node *slow = head;
	
	while(--k){
		if(fast->p_next){
			fast = fast->p_next;
		}else{
			return NULL;
		}
	}
	
	while(fast->p_next){
		fast = fast->p_next;
		slow = slow->p_next;
	}
	return slow;
}


// ====================测试代码====================
// 测试要找的结点在链表中间
void test1()
{
    printf("=====test1 starts:=====\n");
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    printf("expected result: 4.\n");
    list_node* p_node = find_kth_to_tail(p_node1, 2);
    print_list_node(p_node);

    destroy_list(p_node1);
}

// 测试要找的结点是链表的尾结点
void test2()
{
    printf("=====test2 starts:=====\n");
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    printf("expected result: 5.\n");
    list_node* p_node = find_kth_to_tail(p_node1, 1);
    print_list_node(p_node);

    destroy_list(p_node1);
}

// 测试要找的结点是链表的头结点
void test3()
{
    printf("=====test3 starts:=====\n");
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    printf("expected result: 1.\n");
    list_node* p_node = find_kth_to_tail(p_node1, 5);
    print_list_node(p_node);

    destroy_list(p_node1);
}

// 测试空链表
void test4()
{
    printf("=====test4 starts:=====\n");
    printf("expected result: NULL.\n");
    list_node* p_node = find_kth_to_tail(NULL, 100);
    print_list_node(p_node);
}

// 测试输入的第二个参数大于链表的结点总数
void test5()
{
    printf("=====test5 starts:=====\n");
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    printf("expected result: NULL.\n");
    list_node* p_node = find_kth_to_tail(p_node1, 6);
    print_list_node(p_node);

    destroy_list(p_node1);
}

// 测试输入的第二个参数为0
void test6()
{
    printf("=====test6 starts:=====\n");
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    printf("expected result: NULL.\n");
    list_node* p_node = find_kth_to_tail(p_node1, 0);
    print_list_node(p_node);

    destroy_list(p_node1);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}



