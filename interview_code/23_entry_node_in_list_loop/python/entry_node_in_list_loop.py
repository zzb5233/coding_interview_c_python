# -*- coding: utf-8 -*-
import sys

sys.path.append('../../utilities_python')

from singly_linked_list import *


def meet_node(head):
    if None == head:
        return head
    fast = head
    slow = head
    while fast:
        fast = fast.next_item
        if fast == slow:
            return fast
        if fast:
            fast = fast.next_item
        slow = slow.next_item
    return None
	
def entry_node_of_loop(head):
    if None == head:
        return head
    cur = meet_node(head)
    if None == cur:
        return cur
    node = cur.next_item
    num_loop = 1
    
    while node != cur:
        node = node.next_item
        num_loop += 1
    node = head
    cur = head
    for i in range(num_loop):
        node = node.next_item
    while cur != node:
        node = node.next_item
        cur = cur.next_item
    return cur
    
def test(test_name, head, expected):
    print(test_name, end='')
    if entry_node_of_loop(head) == expected:
        print(' passed')
    else:
        print(' failed')
# A list has a node, without a loop
def test1():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    test('test1', s_l_l.head, None)


#A list has a node, with a loop
def test2():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(s_l_l.head)
    test('test2', s_l_l.head, s_l_l.head)


# A list has multiple nodes, with a loop 
def test3():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(2)
    the_node = s_l_l.append(3)
    s_l_l.append(4)
    s_l_l.append(5)
    s_l_l.append(the_node)
    test('test3', s_l_l.head, the_node)

# A list has multiple nodes, with a loop 
def test4():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(2)
    s_l_l.append(3)
    s_l_l.append(4)
    s_l_l.append(5)
    s_l_l.append(s_l_l.head)
    test('test4', s_l_l.head, s_l_l.head)

# A list has multiple nodes, with a loop 
def test5():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(2)
    s_l_l.append(3)
    s_l_l.append(4)
    the_node = s_l_l.append(5)
    s_l_l.append(the_node)
    test('test5', s_l_l.head, the_node)  

# A list has multiple nodes, without a loop 
def test6():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(2)
    s_l_l.append(3)
    s_l_l.append(4)
    s_l_l.append(5)

    test('test6', s_l_l.head, None)

# Empty list
def test7():
    test('test7', None, None)
	

if __name__ == "__main__":
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
    test7()
	