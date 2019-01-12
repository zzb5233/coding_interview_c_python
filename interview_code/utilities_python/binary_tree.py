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
    
    def append_complete_binary_tree(self, item):
        if isinstance(item, Node):
            node = item
        else:
            node = Node(item)
            
        if None == self.root:
            self.root = node
        else:
            cur_layer = [self.root]
            while(len(cur_layer)):
                next_layer = []
                for i in cur_layer:
                    if i.left_item:
                        next_layer.append(i.left_item)
                    else:
                        i.left_item = node
                        self.length += 1
                        return node
                    if i.right_item:
                        next_layer.append(i.right_item)
                    else:
                        i.right_item = node
                        self.length += 1
                        return node
                cur_layer = next_layer
    def append_binary_tree(self, pre_none = 0, item):
        if isinstance(item, Node):
            node = item
        elif item == None:
            node = item
        else:
            node = Node(item)
        
            if None == self.root:
                self.root = node
            else:
                cur_layer = [self.root]
                while(len(cur_layer)):
                    next_layer = []
                    for i in cur_layer:
                        if i.left_item:
                            next_layer.append(i.left_item)
                        elif pre_none:
                            pre_none -= 1
                        else:
                            i.left_item = node
                            if node == None:
                                pre_none += 1
                            else:
                                self.length += 1
                            return node, pre_none
                        if i.right_item:
                            next_layer.append(i.right_item)
                        elif pre_none:
                            pre_none -= 1
                        else:
                            i.right_item = node
                            if node == None:
                                pre_none += 1
                            else:
                                self.length += 1
                            return node, pre_none
                    cur_layer = next_layer
                    
    def preorder(self, root, r_list):
        if None == root:
            r_list += '*' + '->'
            return r_list
        r_list += str(root.item) + '->'
        r_list = self.preorder(root.left_item, r_list)
        r_list = self.preorder(root.right_item, r_list)
        
        return r_list        

    def __repr__(self, order='preorder'):
        if self.is_empty():
            return 'the singly linked list is empty'
        root = self.root
        if(order == 'preorder'):
            r_list =  self.preorder(root, '')[:-2]
        return r_list
    
if __name__ == '__main__':
    
    bt = Binary_tree()
    bt.append_complete_binary_tree('A')
    bt.append_complete_binary_tree('B')
    bt.append_complete_binary_tree('C')
    bt.append_complete_binary_tree('D')
    print('the singly list length is %d:' % bt.length, bt)