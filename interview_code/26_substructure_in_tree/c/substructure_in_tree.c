// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool 	unsigned int
#define true	1
#define false	0



typedef struct binary_tree_node
{
    double                 db_value;
    struct binary_tree_node*        p_left;
    struct binary_tree_node*        p_right;
}binary_tree_node;

bool does_tree1_have_tree2(binary_tree_node* p_root1, binary_tree_node* p_root2);
bool equal(double num1, double num2);

bool has_subtree(binary_tree_node* p_root1, binary_tree_node* p_root2)
{
    bool result = false;

    if(p_root1 != NULL && p_root2 != NULL)
    {
        if(equal(p_root1->db_value, p_root2->db_value))
            result = does_tree1_have_tree2(p_root1, p_root2);
        if(!result)
            result = has_subtree(p_root1->p_left, p_root2);
        if(!result)
            result = has_subtree(p_root1->p_right, p_root2);
    }

    return result;
}

bool does_tree1_have_tree2(binary_tree_node* p_root1, binary_tree_node* p_root2)
{
    if(p_root2 == NULL)
        return true;

    if(p_root1 == NULL)
        return false;

    if(!equal(p_root1->db_value, p_root2->db_value))
        return false;

    return does_tree1_have_tree2(p_root1->p_left, p_root2->p_left) &&
        does_tree1_have_tree2(p_root1->p_right, p_root2->p_right);
}

bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

// ====================辅助测试代码====================
binary_tree_node* create_binary_tree_node(double db_value)
{
    binary_tree_node* p_node = malloc(sizeof(binary_tree_node));
    p_node->db_value = db_value;
    p_node->p_left = NULL;
    p_node->p_right = NULL;

    return p_node;
}

void connect_tree_nodes(binary_tree_node* p_parent, binary_tree_node* p_left, binary_tree_node* p_right)
{
    if(p_parent != NULL)
    {
        p_parent->p_left = p_left;
        p_parent->p_right = p_right;
    }
}

void destroy_tree(binary_tree_node* p_root)
{
    if(p_root != NULL)
    {
        binary_tree_node* p_left = p_root->p_left;
        binary_tree_node* p_right = p_root->p_right;

        free(p_root) ;
        p_root = NULL;

        destroy_tree(p_left);
        destroy_tree(p_right);
    }
}

// ====================测试代码====================
void test(char* test_name, binary_tree_node* p_root1, binary_tree_node* p_root2, bool expected)
{
    if(has_subtree(p_root1, p_root2) == expected)
        printf("%s passed.\n", test_name);
    else
        printf("%s failed.\n", test_name);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void test1()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(7);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(2);
    binary_tree_node* p_nodeA6 = create_binary_tree_node(4);
    binary_tree_node* p_nodeA7 = create_binary_tree_node(7);

    connect_tree_nodes(p_nodeA1, p_nodeA2, p_nodeA3);
    connect_tree_nodes(p_nodeA2, p_nodeA4, p_nodeA5);
    connect_tree_nodes(p_nodeA5, p_nodeA6, p_nodeA7);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, p_nodeB2, p_nodeB3);

    test("test1", p_nodeA1, p_nodeB1, true);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void test2()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(7);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(3);
    binary_tree_node* p_nodeA6 = create_binary_tree_node(4);
    binary_tree_node* p_nodeA7 = create_binary_tree_node(7);

    connect_tree_nodes(p_nodeA1, p_nodeA2, p_nodeA3);
    connect_tree_nodes(p_nodeA2, p_nodeA4, p_nodeA5);
    connect_tree_nodes(p_nodeA5, p_nodeA6, p_nodeA7);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, p_nodeB2, p_nodeB3);

    test("test2", p_nodeA1, p_nodeB1, false);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void test3()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(2);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(5);

    connect_tree_nodes(p_nodeA1, p_nodeA2, NULL);
    connect_tree_nodes(p_nodeA2, p_nodeA3, NULL);
    connect_tree_nodes(p_nodeA3, p_nodeA4, NULL);
    connect_tree_nodes(p_nodeA4, p_nodeA5, NULL);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, p_nodeB2, NULL);
    connect_tree_nodes(p_nodeB2, p_nodeB3, NULL);

    test("test3", p_nodeA1, p_nodeB1, true);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5
void test4()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(2);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(5);

    connect_tree_nodes(p_nodeA1, p_nodeA2, NULL);
    connect_tree_nodes(p_nodeA2, p_nodeA3, NULL);
    connect_tree_nodes(p_nodeA3, p_nodeA4, NULL);
    connect_tree_nodes(p_nodeA4, p_nodeA5, NULL);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(3);

    connect_tree_nodes(p_nodeB1, p_nodeB2, NULL);
    connect_tree_nodes(p_nodeB2, p_nodeB3, NULL);

    test("test4", p_nodeA1, p_nodeB1, false);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                   \
//           9                   2
//            \      
//             2        
//              \
//               5
void test5()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(2);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(5);

    connect_tree_nodes(p_nodeA1, NULL, p_nodeA2);
    connect_tree_nodes(p_nodeA2, NULL, p_nodeA3);
    connect_tree_nodes(p_nodeA3, NULL, p_nodeA4);
    connect_tree_nodes(p_nodeA4, NULL, p_nodeA5);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, NULL, p_nodeB2);
    connect_tree_nodes(p_nodeB2, NULL, p_nodeB3);

    test("test5", p_nodeA1, p_nodeB1, true);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                 / \
//           9               3   2
//            \      
//             2        
//              \
//               5
void test6()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(2);
    binary_tree_node* p_nodeA5 = create_binary_tree_node(5);

    connect_tree_nodes(p_nodeA1, NULL, p_nodeA2);
    connect_tree_nodes(p_nodeA2, NULL, p_nodeA3);
    connect_tree_nodes(p_nodeA3, NULL, p_nodeA4);
    connect_tree_nodes(p_nodeA4, NULL, p_nodeA5);

    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(3);
    binary_tree_node* p_nodeB4 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, NULL, p_nodeB2);
    connect_tree_nodes(p_nodeB2, p_nodeB3, p_nodeB4);

    test("test6", p_nodeA1, p_nodeB1, false);

    destroy_tree(p_nodeA1);
    destroy_tree(p_nodeB1);
}

// 树A为空树
void test7()
{
    binary_tree_node* p_nodeB1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeB2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeB3 = create_binary_tree_node(3);
    binary_tree_node* p_nodeB4 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeB1, NULL, p_nodeB2);
    connect_tree_nodes(p_nodeB2, p_nodeB3, p_nodeB4);

    test("test7", NULL, p_nodeB1, false);

    destroy_tree(p_nodeB1);
}

// 树B为空树
void test8()
{
    binary_tree_node* p_nodeA1 = create_binary_tree_node(8);
    binary_tree_node* p_nodeA2 = create_binary_tree_node(9);
    binary_tree_node* p_nodeA3 = create_binary_tree_node(3);
    binary_tree_node* p_nodeA4 = create_binary_tree_node(2);

    connect_tree_nodes(p_nodeA1, NULL, p_nodeA2);
    connect_tree_nodes(p_nodeA2, p_nodeA3, p_nodeA4);

    test("test8", p_nodeA1, NULL, false);

    destroy_tree(p_nodeA1);
}

// 树A和树B都为空
void test9()
{
    test("test9", NULL, NULL, false);
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
    test8();
    test9();

    return 0;
}

