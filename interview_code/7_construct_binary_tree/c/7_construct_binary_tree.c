// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../../utilities/binary_tree.h"


binary_tree_node* construct_core(int* start_preorder, int* end_preorder, int* start_inorder, int* end_inorder);

binary_tree_node* construct(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return construct_core(preorder, preorder + length - 1,
        inorder, inorder + length - 1);
}

binary_tree_node* construct_core(int* start_preorder, int* end_preorder, int* start_inorder, int* end_inorder)
{
    // 前序遍历序列的第一个数字是根结点的值
    int root_value = start_preorder[0];
    binary_tree_node* root = malloc(sizeof(binary_tree_node));
    root->val = root_value;
    root->p_left = root->p_right = NULL;

    if(start_preorder == end_preorder)
    {
        if(start_inorder == end_inorder && *start_preorder == *start_inorder)
            return root;
        else{
			printf("Invalid input.");
			assert(0);
		}
            
	
    }

    // 在中序遍历中找到根结点的值
    int* root_inorder = start_inorder;
    while(root_inorder <= end_inorder && *root_inorder != root_value)
        ++root_inorder;

    if(root_inorder == end_inorder && *root_inorder != root_value){
		printf("Invalid input.");
		assert(0);
	}

    int left_length = root_inorder - start_inorder;
    int* left_preorder_end = start_preorder + left_length;
    if(left_length > 0)
    {
        // 构建左子树
        root->p_left = construct_core(start_preorder + 1, left_preorder_end, 
            start_inorder, root_inorder - 1);
    }
    if(left_length < end_preorder - start_preorder)
    {
        // 构建右子树
        root->p_right = construct_core(left_preorder_end + 1, end_preorder,
            root_inorder + 1, end_inorder);
    }

    return root;
}

// ====================测试代码====================
void test(char* test_name, int* preorder, int* inorder, int length)
{
	int i;
    if(test_name != NULL)
        printf("%s begins:\n", test_name);

    printf("The preorder sequence is: ");
    for(i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

	binary_tree_node* root = construct(preorder, inorder, length);
	print_tree(root);

	destroy_tree(root);

}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test1()
{
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};

    test("test1", preorder, inorder, 8);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void test2()
{
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {5, 4, 3, 2, 1};

    test("test2", preorder, inorder, 5);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void test3()
{
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {1, 2, 3, 4, 5};

    test("test3", preorder, inorder, 5);
}

// 树中只有一个结点
void test4()
{
    int preorder[1] = {1};
    int inorder[1] = {1};

    test("test4", preorder, inorder, 1);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void test5()
{
    int preorder[8] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[8] = {4, 2, 5, 1, 6, 3, 7};

    test("test5", preorder, inorder, 8);
}

// 输入空指针
void test6()
{
    test("test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void test7()
{
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 2, 8, 1, 6, 3, 7};

    test("test7: for unmatched input", preorder, inorder, 7);
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