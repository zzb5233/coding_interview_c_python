# -*- coding: utf-8 -*-

def find(matrix, number):
    if matrix == None or 0 == len(matrix):
        return False
    for i in matrix:
        if 0 == len(i):
            return False
        
    rows = len(matrix)
    columns = len(matrix[0])
    row = 0
    column = columns - 1
    
    while row < rows and column >= 0:
        if matrix[row][column] == number:
            return True
        elif matrix[row][column] > number:
            column -= 1
        else:
            row += 1
    return False

def test(test_name, matrix, number, expected):
    if test_name:
        print("%s "% test_name, end="")
    result = find(matrix, number)
    if result == expected:
        print("passed")
    else:
        print("failed")
    
def test1():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test1", matrix, 7, True)
    
def test2():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test2", matrix, 1, True)
    
def test3():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test3", matrix, 15, True)
    
def test4():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test4", matrix, 14, False)
    
def test5():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test5", matrix, 0, False)
    
def test6():
    matrix = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    test("test6", matrix, 20, False)
    
def test7():
    test("test7", None, 7, False)
    
if __name__ == "__main__":
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()
    test7()