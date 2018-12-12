# -*- coding: utf-8 -*-

'''面试题5：替换空格
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
'''

def replace_space(the_str):
    return the_str.replace(' ', '%20')

def test(test_name, the_str, expected):
    if test_name:
        print('%s ' % test_name, end="")
        
    the_str = replace_space(the_str)
    
    if None == the_str and None == expected:
        print('passed')
    elif None == expected and the_str:
        print('failed')
    elif expected == the_str:
        print('passed')
    else:
        print('failed')



def test1():
    the_str = 'hello world'
    test('test1', the_str, 'hello%20world')
    

if __name__ == "__main__":
    test1()
    '''test2()
    test3()
    test4()
    test5()
    test6()
    test7()
    test8()
    test9()'''
    
    