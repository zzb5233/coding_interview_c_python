# -*- coding: utf-8 -*-



def count_range(numbers, start, end):
    if None == numbers or 0 == len(numbers):
        return 0
    count = 0
    for i in numbers:
        if i >= start and i <= end:
            count += 1
    return count

def get_duplication(numbers):
    if None == numbers or 0 == len(numbers):
        return -1
    start = 1
    end = len(numbers)-1
    while(end>=start):
        middle = (end-start)//2+start
        count = count_range(numbers, start, middle)
        if(end == start):
            if count > 1:
                return start
            else:
                break
        if count > (middle-start+1):
            end = middle
        else:
            start = middle+1
    return -1

def test(test_name, numbers, duplications):
    for i in duplications:
        if i == get_duplication(numbers):
            print('%s passed' % test_name)
            return
    print('%s failed' % test_name)


def test1():
    numbers = [2, 3, 5, 4, 3, 2, 6, 7];
    duplications = [2, 3];
    test("test1", numbers, duplications)
    
def test2():
    numbers = [3, 2, 1, 4, 4, 5, 6, 7];
    duplications = [4];
    test("test2", numbers, duplications)
    
def test3():
    numbers = [1, 2, 3, 4, 5, 6, 7, 1, 8];
    duplications = [1];
    test("test3", numbers, duplications)
    
def test4():
    numbers = [1, 7, 3, 4, 5, 6, 8, 2, 8];
    duplications = [8];
    test("test4", numbers, duplications)
    
def test5():
    numbers = [1, 1 ];
    duplications = [1];
    test("test5", numbers, duplications)
    
def test6():
    numbers = [3, 2, 1, 3, 4, 5, 6, 7];
    duplications = [3];
    test("test6", numbers, duplications)
    
def test7():
    numbers = [1, 2, 2, 6, 4, 5, 2];
    duplications = [2];
    test("test7", numbers, duplications)
    
def test7():
    numbers = [1, 2, 2, 6, 4, 5, 2];
    duplications = [2];
    test("test7", numbers, duplications)
    
def test8():
    numbers = [1, 2, 6, 4, 5, 3];
    duplications = [-1];
    test("test8", numbers, duplications)
    
def test9():
    numbers = None;
    duplications = [-1];
    test("test9", numbers, duplications)
    
	
if __name__ == '__main__':
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
    test7()
    test8()
    test9()
