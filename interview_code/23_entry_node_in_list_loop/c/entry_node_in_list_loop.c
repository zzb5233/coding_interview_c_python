#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../utilities/list.h"



list_node *meet_node(list_node *p_head)
{
	if(NULL == p_head){
		return NULL;
	}
	
	list_node *p_fast, *p_slow;
	p_fast = p_head;
	p_slow = p_head;
	while(p_fast){
		p_fast = p_fast->p_next;
		if(p_fast == p_slow){
			return p_fast;
		}
		p_slow = p_slow->p_next;
		if(p_fast){
			p_fast = p_fast->p_next;
		}
	}
	return NULL;
}


list_node *entry_node_of_loop(list_node *p_head)
{
	if(NULL == p_head){
		return NULL;
	}
	
	int num_loop = 0;
	list_node *p_cur = meet_node(p_head);
	list_node *p_next;
	int i;
	if(NULL == p_cur){
		return p_cur;
	}
	
	p_next = p_cur->p_next;
	num_loop++;
	while(p_cur != p_next){
		num_loop++;
		p_next = p_next->p_next;
	}
	p_cur = p_head;
	p_next = p_head;
	for(i = 0; i < num_loop; i++){
		p_cur = p_cur->p_next;
	}
	while(p_cur != p_next){
		p_cur = p_cur->p_next;
		p_next = p_next->p_next;
	}
	return p_cur;
}


// ==================== test Code ====================
void test(char* test_name, list_node* p_head, list_node* entry_node)
{
    if(test_name != NULL)
        printf("%s begins: ", test_name);

    if(entry_node_of_loop(p_head) == entry_node)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void test1()
{
    list_node* p_node1 = create_list_node(1);

    test("test1", p_node1, NULL);

    destroy_list(p_node1);
}

// A list has a node, with a loop
void test2()
{
    list_node* p_node1 = create_list_node(1);
    connect_list_node(p_node1, p_node1);

    test("test2", p_node1, p_node1);

    free(p_node1) ;
    p_node1 = NULL;
}

// A list has multiple nodes, with a loop 
void test3()
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
    connect_list_node(p_node5, p_node3);

    test("test3", p_node1, p_node3);

    free(p_node1) ;
    p_node1 = NULL;
    free(p_node2) ;
    p_node2 = NULL;
    free(p_node3) ;
    p_node3 = NULL;
    free(p_node4) ;
    p_node4 = NULL;
    free(p_node5) ;
    p_node5 = NULL;
}

// A list has multiple nodes, with a loop 
void test4()
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
    connect_list_node(p_node5, p_node1);

    test("test4", p_node1, p_node1);

    free(p_node1) ;
    p_node1 = NULL;
    free(p_node2) ;
    p_node2 = NULL;
    free(p_node3) ;
    p_node3 = NULL;
    free(p_node4) ;
    p_node4 = NULL;
    free(p_node5) ;
    p_node5 = NULL;
}

// A list has multiple nodes, with a loop 
void test5()
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
    connect_list_node(p_node5, p_node5);

    test("test5", p_node1, p_node5);

    free(p_node1) ;
    p_node1 = NULL;
    free(p_node2) ;
    p_node2 = NULL;
    free(p_node3) ;
    p_node3 = NULL;
    free(p_node4) ;
    p_node4 = NULL;
    free(p_node5) ;
    p_node5 = NULL;
}

// A list has multiple nodes, without a loop 
void test6()
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

    test("test6", p_node1, NULL);

    destroy_list(p_node1);
}

// Empty list
void test7()
{
    test("test7", NULL, NULL);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}



