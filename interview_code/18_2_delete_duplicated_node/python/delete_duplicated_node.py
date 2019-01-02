# -*- coding: utf-8 -*-

import sys

sys.path.append('../../utilities_python')

from singly_linked_list import *


def delete_duplicated_node(head):
    return



if __name__ == "__main__":
    s_l_l = Singly_linked_list()
    s_l_l.append('A')
    s_l_l.append('B')
    s_l_l.append('C')
    s_l_l.append('D')
    s_l_l.insert(0, 0)
    s_l_l.insert(1, 1)
    s_l_l.delete(2)
    print('the singly list length is %d:' % s_l_l.length, s_l_l)
    
    print(s_l_l.head.item)


