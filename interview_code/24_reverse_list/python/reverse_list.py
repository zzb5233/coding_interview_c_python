# -*- coding: utf-8 -*-

import sys

sys.path.append('../../utilities_python')

from singly_linked_list import *


def reverse_list(head):
    pre = None
    p_next = head
    
    while head:
        p_next = head.next_item
        head.next_item = pre
        pre = head
        head = p_next
        
    return pre

def test(s_l_l):
    print(s_l_l)
    head = reverse_list(s_l_l.head)
    s_l_l.head = head
    print(s_l_l)

def test1():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    s_l_l.append(2)
    s_l_l.append(3)
    s_l_l.append(4)
    s_l_l.append(5)
    test(s_l_l) 
    
def test2():
    s_l_l = Singly_linked_list()
    s_l_l.append(1)
    test(s_l_l)
    
def test3():
    s_l_l = Singly_linked_list()
    test(s_l_l)
    
if __name__ == "__main__":
    test1()
    test2()
    test3()
    