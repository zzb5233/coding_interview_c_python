#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utilities/list.h"





list_node *merge(list_node *head_1, list_node *head_2)
{
	list_node *head;
	if(NULL == head_1){
		return head_2;
	}
	
	if(NULL == head_2){
		return head_1;
	}
	
	if(head_1->val < head_2->val){
		head = head_1;
		head_1->p_next = merge(head_1->p_next, head_2);
	}else{
		head = head_2;
		head_2->p_next = merge(head_1, head_2->p_next);
	}
	return head;
}

// ====================测试代码====================
list_node* test(char* test_name, list_node* p_head1, list_node* p_head2)
{
    if(test_name != NULL)
        printf("%s begins:\n", test_name);

    printf("The first list is:\n");
    print_list(p_head1);

    printf("The second list is:\n");
    print_list(p_head2);

    printf("The merged list is:\n");
    list_node* p_merge_head = merge(p_head1, p_head2);
    print_list(p_merge_head);
    
    printf("\n\n");

    return p_merge_head;
}

// list1: 1->3->5
// list2: 2->4->6
void test1()
{
    list_node* p_node1 = create_list_node(1);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node3);
    connect_list_node(p_node3, p_node5);

    list_node* p_node2 = create_list_node(2);
    list_node* p_node4 = create_list_node(4);
    list_node* p_node6 = create_list_node(6);

    connect_list_node(p_node2, p_node4);
    connect_list_node(p_node4, p_node6);

    list_node* p_merge_head = test("test1", p_node1, p_node2);

    destroy_list(p_merge_head);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void test2()
{
    list_node* p_node1 = create_list_node(1);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node3);
    connect_list_node(p_node3, p_node5);

    list_node* p_node2 = create_list_node(1);
    list_node* p_node4 = create_list_node(3);
    list_node* p_node6 = create_list_node(5);

    connect_list_node(p_node2, p_node4);
    connect_list_node(p_node4, p_node6);

    list_node* p_merge_head = test("test2", p_node1, p_node2);

    destroy_list(p_merge_head);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void test3()
{
    list_node* p_node1 = create_list_node(1);
    list_node* p_node2 = create_list_node(2);

    list_node* p_merge_head = test("test3", p_node1, p_node2);

    destroy_list(p_merge_head);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void test4()
{
    list_node* p_node1 = create_list_node(1);
    list_node* p_node3 = create_list_node(3);
    list_node* p_node5 = create_list_node(5);

    connect_list_node(p_node1, p_node3);
    connect_list_node(p_node3, p_node5);

    list_node* p_merge_head = test("test4", p_node1, NULL);

    destroy_list(p_merge_head);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void test5()
{
    list_node* p_merge_head = test("test5", NULL, NULL);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}