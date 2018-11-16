# -*- coding: utf-8 -*-


class Duplication:
    def __init__(self):
        self.duplication = -2
    def find_duplication(self, numbers):
        if None == numbers or len(numbers) <= 0:
            return False
        for i in numbers:
            if i < 0 or i > len(numbers)-1:
                return False
        for i in range(len(numbers)):
            while numbers[i] != i:
                if numbers[i] == numbers[numbers[i]]:
                    self.duplication = numbers[i]
                    return True
                temp = numbers[numbers[i]]
                numbers[numbers[i]] = numbers[i]
                numbers[i] = temp
        return False


def contains(numbers, number):
    for i in numbers:
        if i == number:
            return True
    return False


def test(test_name, numbers, expected, valid_argument):
    print('%s begins:' % test_name, end='')
    duplication = Duplication()
    valid_input = duplication.find_duplication(numbers)
    if valid_input == valid_argument:
        if valid_argument:
            if True == contains(expected, duplication.duplication):
                print('Passed')
            else:
                print('Failed')
        else:
            print('Passed')
        
def test1():
    numbers = [2, 1, 3, 1, 4]
    duplication = [1]
    test('Test1', numbers, duplication, True)
    
def test1():
    numbers = [2, 1, 3, 1, 4]
    duplication = [1]
    test('Test1', numbers, duplication, True)
    
def test2():
    numbers = [2, 4, 3, 1, 4]
    duplication = [4]
    test('Test2', numbers, duplication, True)
    
def test3():
    numbers = [2, 4, 2, 1, 4]
    duplication = [2, 4]
    test('Test3', numbers, duplication, True)
    
def test4():
    numbers = [2, 1, 3, 0, 4]
    duplication = [1]
    test('Test4', numbers, duplication, False)
    
def test5():
    numbers = [2, 1, 3, 5, 4]
    duplication = [-1]
    test('Test5', numbers, duplication, False)
    
def test6():
    numbers = None
    duplication = [-1]
    test('Test6', numbers, duplication, False)


if __name__ == '__main__':
    test1()
    test2()
    test3()
    test4()
    test5()
    test6()