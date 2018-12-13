/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

struct list_node
{
    int       val;
    list_node* p_next;
};

extern list_node* create_list_node(int value);
extern void connect_list_nodes(list_node* p_current, list_node* pNext);
extern void print_list_node(list_node* pNode);
extern void print_list(list_node* p_head);
extern void destroy_list(list_node* p_head);
extern void add_to_tail(list_node** p_head, int value);
extern void remove_node(list_node** p_head, int value);