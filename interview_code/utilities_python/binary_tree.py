# -*- coding: utf-8 -*-


class Node():
    def __init__(self, item, left_item = None, right_item = None):
        self.item = item
        self.left_item = left_item
        self.right_item = right_item
    
    def __repr__(self):
        return str(self.item)
    
    
class Binary_tree():
    def __init__(self):
        self.root = None
        self.length = 0
        
    def is_empty(self):
        return self.length == 0
    
    def append_left(self, item):
        if isinstance(item, Node):
            node = item
        else:
            node = Node(item)
            
        if None == self.root:
            self.root = node
        else:
            cur_node = self.head
            while cur_node.next_item:
                cur_node = cur_node.next_item
            cur_node.next_item = node
        self.length += 1
        return node           

        
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