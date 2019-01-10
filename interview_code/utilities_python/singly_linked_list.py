# -*- coding: utf-8 -*-


class Node():
    def __init__(self, item, next_item=None):
        self.item = item
        self.next_item = next_item
    
    def __repr__(self):
        return str(self.item)
    
    
class Singly_linked_list():
    def __init__(self):
        self.head = None
        self.length = 0
        
    def is_empty(self):
        return self.length == 0
    
    def append(self, item):
        if isinstance(item, Node):
            node = item
        else:
            node = Node(item)
            
        if None == self.head:
            self.head = node
        else:
            cur_node = self.head
            while cur_node.next_item:
                cur_node = cur_node.next_item
            cur_node.next_item = node
        self.length += 1
        return node
    #eg. :
    #    if index is 0, then the item will be head
    #    if index is 1, then the item will be the second item
    def insert(self, index, item):
        if index < 0 or index >= self.length:
            print('Invalid index')
            return
            
        node = Node(item)
            
        if 0 == index:
            if self.head:
                self.head, self.head.next_item = node, self.head
            else:
                self.head == node
        else:
            target_node = self.head
            index -= 1
            while index:
                target_node = target_node.next_item
                index -= 1
            node.next_item, target_node.next_item = target_node.next_item, node
    #eg. :
    #    if index is 0, then we will delete head
    #    if index is 1, then we will delete the second item               
    def delete(self, index):
        if index < 0 or index >= self.length:
            print('Invalid index')
            return
        
        if 0 == index:
            self.head = self.head.next_item
        else:
            pre_node = self.head
            #target_node = self.head.next_item
            index -= 1
            while index:
                pre_node = pre_node.next_item
                #target_node = target_node.next_item
                index -= 1
            #pre_node.next_item = target_node.next_item
            pre_node.next_item = pre_node.next_item.next_item
        self.length -= 1
        
    def __repr__(self):
        if self.is_empty():
            return 'the singly linked list is empty'
        the_list = ''
        cur_node = self.head
        while cur_node.next_item:
            the_list += str(cur_node.item) + '->'
            cur_node = cur_node.next_item
        the_list += str(cur_node.item)
        
        return the_list
    
if __name__ == '__main__':
    
    s_l_l = Singly_linked_list()
    s_l_l.append('A')
    s_l_l.append('B')
    s_l_l.append('C')
    s_l_l.append('D')
    s_l_l.insert(0, 0)
    s_l_l.insert(1, 1)
    s_l_l.delete(2)
    print('the singly list length is %d:' % s_l_l.length, s_l_l)
    
        
            