#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../utilities/binary_tree.h"


#define bool 	unsigned int
#define false	0
#define	true 	1


bool is_symmetrical(binary_tree_node *root_1, binary_tree_node *root_2)
{
	if(NULL == root_1 && NULL == root_2){
		return true;
	}
	
	if(NULL == root_1 || root_2 == NULL){
		return false;
	}
	
	if(root_1->val != root_2->val){
		return false;
	}
	return is_symmetrical(root_1->p_left, root_2->p_right) && is_symmetrical(root_1->p_right, root_2->p_left);
}

bool is_symmetrical_binary_node(binary_tree_node *root)
{
	return is_symmetrical(root, root);
}



// ====================测试代码====================
void test(char* test_name, binary_tree_node* pRoot, bool expected)
{
    if(test_name != NULL)
        printf("%s begins: ", test_name);

    if(is_symmetrical_binary_node(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void test1()
{
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node61 = create_binary_tree_node(6);
    binary_tree_node* p_node62 = create_binary_tree_node(6);
    binary_tree_node* p_node51 = create_binary_tree_node(5);
    binary_tree_node* p_node71 = create_binary_tree_node(7);
    binary_tree_node* p_node72 = create_binary_tree_node(7);
    binary_tree_node* p_node52 = create_binary_tree_node(5);

    connect_tree_nodes(p_node8, p_node61, p_node62);
    connect_tree_nodes(p_node61, p_node51, p_node71);
    connect_tree_nodes(p_node62, p_node72, p_node52);

    test("test1", p_node8, true);

    destroy_tree(p_node8);
}

//            8
//        6      9
//       5 7    7 5
void test2()
{
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node61 = create_binary_tree_node(6);
    binary_tree_node* p_node9 = create_binary_tree_node(9);
    binary_tree_node* p_node51 = create_binary_tree_node(5);
    binary_tree_node* p_node71 = create_binary_tree_node(7);
    binary_tree_node* p_node72 = create_binary_tree_node(7);
    binary_tree_node* p_node52 = create_binary_tree_node(5);

    connect_tree_nodes(p_node8, p_node61, p_node9);
    connect_tree_nodes(p_node61, p_node51, p_node71);
    connect_tree_nodes(p_node9, p_node72, p_node52);

    test("test2", p_node8, false);

    destroy_tree(p_node8);
}

//            8
//        6      6
//       5 7    7
void test3()
{
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node61 = create_binary_tree_node(6);
    binary_tree_node* p_node62 = create_binary_tree_node(6);
    binary_tree_node* p_node51 = create_binary_tree_node(5);
    binary_tree_node* p_node71 = create_binary_tree_node(7);
    binary_tree_node* p_node72 = create_binary_tree_node(7);

    connect_tree_nodes(p_node8, p_node61, p_node62);
    connect_tree_nodes(p_node61, p_node51, p_node71);
    connect_tree_nodes(p_node62, p_node72, NULL);

    test("test3", p_node8, false);

    destroy_tree(p_node8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void test4()
{
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node31 = create_binary_tree_node(3);
    binary_tree_node* p_node32 = create_binary_tree_node(3);
    binary_tree_node* p_node41 = create_binary_tree_node(4);
    binary_tree_node* p_node42 = create_binary_tree_node(4);
    binary_tree_node* p_node21 = create_binary_tree_node(2);
    binary_tree_node* p_node22 = create_binary_tree_node(2);
    binary_tree_node* p_node11 = create_binary_tree_node(1);
    binary_tree_node* p_node12 = create_binary_tree_node(1);

    connect_tree_nodes(p_node5, p_node31, p_node32);
    connect_tree_nodes(p_node31, p_node41, NULL);
    connect_tree_nodes(p_node32, NULL, p_node42);
    connect_tree_nodes(p_node41, p_node21, NULL);
    connect_tree_nodes(p_node42, NULL, p_node22);
    connect_tree_nodes(p_node21, p_node11, NULL);
    connect_tree_nodes(p_node22, NULL, p_node12);

    test("test4", p_node5, true);

    destroy_tree(p_node5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void test5()
{
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node31 = create_binary_tree_node(3);
    binary_tree_node* p_node32 = create_binary_tree_node(3);
    binary_tree_node* p_node41 = create_binary_tree_node(4);
    binary_tree_node* p_node42 = create_binary_tree_node(4);
    binary_tree_node* p_node6 = create_binary_tree_node(6);
    binary_tree_node* p_node22 = create_binary_tree_node(2);
    binary_tree_node* p_node11 = create_binary_tree_node(1);
    binary_tree_node* p_node12 = create_binary_tree_node(1);

    connect_tree_nodes(p_node5, p_node31, p_node32);
    connect_tree_nodes(p_node31, p_node41, NULL);
    connect_tree_nodes(p_node32, NULL, p_node42);
    connect_tree_nodes(p_node41, p_node6, NULL);
    connect_tree_nodes(p_node42, NULL, p_node22);
    connect_tree_nodes(p_node6, p_node11, NULL);
    connect_tree_nodes(p_node22, NULL, p_node12);

    test("test5", p_node5, false);

    destroy_tree(p_node5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void test6()
{
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node31 = create_binary_tree_node(3);
    binary_tree_node* p_node32 = create_binary_tree_node(3);
    binary_tree_node* p_node41 = create_binary_tree_node(4);
    binary_tree_node* p_node42 = create_binary_tree_node(4);
    binary_tree_node* p_node21 = create_binary_tree_node(2);
    binary_tree_node* p_node22 = create_binary_tree_node(2);
    binary_tree_node* p_node12 = create_binary_tree_node(1);

    connect_tree_nodes(p_node5, p_node31, p_node32);
    connect_tree_nodes(p_node31, p_node41, NULL);
    connect_tree_nodes(p_node32, NULL, p_node42);
    connect_tree_nodes(p_node41, p_node21, NULL);
    connect_tree_nodes(p_node42, NULL, p_node22);
    connect_tree_nodes(p_node21, NULL, NULL);
    connect_tree_nodes(p_node22, NULL, p_node12);

    test("test6", p_node5, false);

    destroy_tree(p_node5);
}

// 只有一个结点
void test7()
{
    binary_tree_node* p_node1 = create_binary_tree_node(1);
    test("test7", p_node1, true);

    destroy_tree(p_node1);
}

// 没有结点
void test8()
{
    test("test8", NULL, true);
}

// 所有结点都有相同的值，树对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void test9()
{
    binary_tree_node* p_node1 = create_binary_tree_node(5);
    binary_tree_node* p_node21 = create_binary_tree_node(5);
    binary_tree_node* p_node22 = create_binary_tree_node(5);
    binary_tree_node* p_node31 = create_binary_tree_node(5);
    binary_tree_node* p_node32 = create_binary_tree_node(5);
    binary_tree_node* p_node41 = create_binary_tree_node(5);
    binary_tree_node* p_node42 = create_binary_tree_node(5);

    connect_tree_nodes(p_node1, p_node21, p_node22);
    connect_tree_nodes(p_node21, p_node31, NULL);
    connect_tree_nodes(p_node22, NULL, p_node32);
    connect_tree_nodes(p_node31, p_node41, NULL);
    connect_tree_nodes(p_node32, NULL, p_node42);
    connect_tree_nodes(p_node41, NULL, NULL);
    connect_tree_nodes(p_node42, NULL, NULL);

    test("test9", p_node1, true);

    destroy_tree(p_node1);
}

// 所有结点都有相同的值，树不对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void test10()
{
    binary_tree_node* p_node1 = create_binary_tree_node(5);
    binary_tree_node* p_node21 = create_binary_tree_node(5);
    binary_tree_node* p_node22 = create_binary_tree_node(5);
    binary_tree_node* p_node31 = create_binary_tree_node(5);
    binary_tree_node* p_node32 = create_binary_tree_node(5);
    binary_tree_node* p_node41 = create_binary_tree_node(5);
    binary_tree_node* p_node42 = create_binary_tree_node(5);

    connect_tree_nodes(p_node1, p_node21, p_node22);
    connect_tree_nodes(p_node21, p_node31, NULL);
    connect_tree_nodes(p_node22, NULL, p_node32);
    connect_tree_nodes(p_node31, p_node41, NULL);
    connect_tree_nodes(p_node32, p_node42, NULL);
    connect_tree_nodes(p_node41, NULL, NULL);
    connect_tree_nodes(p_node42, NULL, NULL);

    test("test10", p_node1, false);

    destroy_tree(p_node1);
}

void main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}