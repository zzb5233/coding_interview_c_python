#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utilities/list.h" 




list_node *reverse_list(list_node *head)
{
	list_node *pre = NULL;
	list_node *next = head;
	
	while(head){
		next = head->p_next;
		head->p_next = pre;
		pre = head;
		head = next;
	}
	return pre;
}



// ====================测试代码====================
list_node* test(list_node* p_head)
{
    printf("The original list is: \n");
    print_list(p_head);

    list_node* p_reverse_head = reverse_list(p_head);

    printf("The reversed list is: \n");
    print_list(p_reverse_head);

    return p_reverse_head;
}


// 输入的链表有多个结点
void test1()
{
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node2);
    connect_list_node(p_node2, p_node3);
    connect_list_node(p_node3, p_node4);
    connect_list_node(p_node4, p_node5);

    list_node* p_reverse_head = test(p_node1);

    destroy_list(p_reverse_head);
}

// 输入的链表只有一个结点
void test2()
{
    list_node* p_node1 = create_list_node(1);

    list_node* p_reverse_head = test(p_node1);

    destroy_list(p_reverse_head);
}

// 输入空链表
void test3()
{
    test(NULL);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();

    return 0;
} 