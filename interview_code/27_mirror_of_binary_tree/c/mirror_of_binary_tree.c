#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../utilities/binary_tree.h"




void mirror_recursively(binary_tree_node *p_node)
{
	if(NULL == p_node){
		return;
	}
	
	if(NULL == p_node->p_left && NULL == p_node->p_left){
		return;
	}
	
	binary_tree_node *temp = p_node->p_left;
	p_node->p_left = p_node->p_right;
	p_node->p_right = temp;
	
	if(p_node->p_left){
		mirror_recursively(p_node->p_left);
	}
	if(p_node->p_right){
		mirror_recursively(p_node->p_right);
	}
	
	return;
}



// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void test1()
{
    printf("=====test1 starts:=====\n");
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node6 = create_binary_tree_node(6);
    binary_tree_node* p_node10 = create_binary_tree_node(10);
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node7 = create_binary_tree_node(7);
    binary_tree_node* p_node9 = create_binary_tree_node(9);
    binary_tree_node* p_node11 = create_binary_tree_node(11);

    connect_tree_nodes(p_node8, p_node6, p_node10);
    connect_tree_nodes(p_node6, p_node5, p_node7);
    connect_tree_nodes(p_node10, p_node9, p_node11);

    print_tree(p_node8);

    printf("=====test1: mirror_recursively=====\n");
    mirror_recursively(p_node8);
    print_tree(p_node8);

    //printf("=====test1: MirrorIteratively=====\n");
    //MirrorIteratively(p_node8);
    //print_tree(p_node8);

    destroy_tree(p_node8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void test2()
{
    printf("=====test2 starts:=====\n");
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node7 = create_binary_tree_node(7);
    binary_tree_node* p_node6 = create_binary_tree_node(6);
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node4 = create_binary_tree_node(4);

    connect_tree_nodes(p_node8, p_node7, NULL);
    connect_tree_nodes(p_node7, p_node6, NULL);
    connect_tree_nodes(p_node6, p_node5, NULL);
    connect_tree_nodes(p_node5, p_node4, NULL);

    print_tree(p_node8);

    printf("=====test2: mirror_recursively=====\n");
    mirror_recursively(p_node8);
    print_tree(p_node8);

    //printf("=====test2: MirrorIteratively=====\n");
    //MirrorIteratively(p_node8);
    //print_tree(p_node8);

    destroy_tree(p_node8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void test3()
{
    printf("=====test3 starts:=====\n");
    binary_tree_node* p_node8 = create_binary_tree_node(8);
    binary_tree_node* p_node7 = create_binary_tree_node(7);
    binary_tree_node* p_node6 = create_binary_tree_node(6);
    binary_tree_node* p_node5 = create_binary_tree_node(5);
    binary_tree_node* p_node4 = create_binary_tree_node(4);

    connect_tree_nodes(p_node8, NULL, p_node7);
    connect_tree_nodes(p_node7, NULL, p_node6);
    connect_tree_nodes(p_node6, NULL, p_node5);
    connect_tree_nodes(p_node5, NULL, p_node4);

    print_tree(p_node8);

    printf("=====test3: mirror_recursively=====\n");
    mirror_recursively(p_node8);
    print_tree(p_node8);

    //printf("=====test3: MirrorIteratively=====\n");
    //MirrorIteratively(p_node8);
    //print_tree(p_node8);

    destroy_tree(p_node8);
}

// 测试空二叉树：根结点为空指针
void test4()
{
    printf("=====test4 starts:=====\n");
    binary_tree_node* p_node = NULL;

    print_tree(p_node);

    printf("=====test4: mirror_recursively=====\n");
    mirror_recursively(p_node);
    print_tree(p_node);

    //printf("=====test4: MirrorIteratively=====\n");
    //MirrorIteratively(p_node);
    //print_tree(p_node);
}


// 测试只有一个结点的二叉树
void test5()
{
    printf("=====test5 starts:=====\n");
    binary_tree_node* p_node8 = create_binary_tree_node(8);

    print_tree(p_node8);

    printf("=====test4: mirror_recursively=====\n");
    mirror_recursively(p_node8);
    print_tree(p_node8);

    //printf("=====test4: MirrorIteratively=====\n");
    //MirrorIteratively(p_node8);
    //print_tree(p_node8);
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