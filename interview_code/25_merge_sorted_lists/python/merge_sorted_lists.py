# -*- coding: utf-8 -*-


import sys


sys.path.append('../../utilities_python')
from singly_linked_list import *


def merge(head_1, head_2):
    if None == head_1:
        return head_2
    if None == head_2:
        return head_1
    
    if head_1.item < head_2.item:
        head = head_1
        head_1.next_item = merge(head_1.next_item, head_2)
    else:
        head = head_2
        head_2.next_item = merge(head_1, head_2.next_item)
        
    return head

def test(s_l_l_1, s_l_l_2):
    print('first linked list:', s_l_l_1)
    print('second linked list:', s_l_l_2)
    
    head = merge(s_l_l_1.head, s_l_l_2.head)
    if head == s_l_l_1.head:
        print('merge linked list:', s_l_l_1)
    else:
        print('merge linked list:', s_l_l_2)
    print()
    
'''
1: 1->3->5
2: 2->4->6
'''
def test1():
    s_l_l_1 = Singly_linked_list()
    s_l_l_1.append(1)
    s_l_l_1.append(3)
    s_l_l_1.append(5)
    
    s_l_l_2 = Singly_linked_list()
    s_l_l_2.append(2)
    s_l_l_2.append(4)
    s_l_l_2.append(6)    
    test(s_l_l_1, s_l_l_2)
    

'''
1: 1->3->5
2: 1->3->6
'''
def test2():
    s_l_l_1 = Singly_linked_list()
    s_l_l_1.append(1)
    s_l_l_1.append(3)
    s_l_l_1.append(5)
    
    s_l_l_2 = Singly_linked_list()
    s_l_l_2.append(1)
    s_l_l_2.append(3)
    s_l_l_2.append(6)    
    test(s_l_l_1, s_l_l_2)


'''
1: 1
2: 1
'''
def test3():
    s_l_l_1 = Singly_linked_list()
    s_l_l_1.append(1)
    
    s_l_l_2 = Singly_linked_list()
    s_l_l_2.append(1)
    
    test(s_l_l_1, s_l_l_2)
    
'''
1: 1->3->5
2: 
'''
def test4():
    s_l_l_1 = Singly_linked_list()
    s_l_l_1.append(1)
    s_l_l_1.append(3)
    s_l_l_1.append(5)
    
    s_l_l_2 = Singly_linked_list()
    test(s_l_l_1, s_l_l_2)
    
'''
1: 
2: 
'''
def test5():
    s_l_l_1 = Singly_linked_list()
    
    s_l_l_2 = Singly_linked_list()
    test(s_l_l_1, s_l_l_2)
    
    
if __name__ == '__main__':
    test1()
    test2()
    test3()
    test4()
    test5()