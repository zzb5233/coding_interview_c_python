# -*- coding: utf-8 -*-

def get_min_each(numbers, start_index, end_index):
    if numbers == None or end_index >= len(numbers) or start_index < 0 or start_index > end_index:
        raise('argument error!')
        
    min_number = numbers[end_index]
    for i in numbers[start_index:end_index]:
        if i < min_number:
            min_number = i
            
    return min_number

def get_min(numbers):
    if None == numbers or len(numbers) <= 0:
        raise('argument error!')
    
    start_index = 0
    end_index = len(numbers) - 1
    middle_index = start_index
    
    while numbers[start_index] >= numbers[end_index]:
        if end_index - start_index == 1:
            middle_index = end_index
            break
        middle_index = (start_index+end_index)//2
        
        if numbers[start_index] == numbers[middle_index] and numbers[middle_index] == numbers[end_index]:
            return get_min_each(numbers, start_index, end_index)
        
        if numbers[middle_index] >= numbers[start_index]:
            start_index = middle_index
        elif numbers[middle_index] <= numbers[end_index]:
            end_index = middle_index
            
    return numbers[middle_index]



def test(numbers, expetced):
    try:
        min_number = get_min(numbers)
        for i in numbers:
            print(i, end=' ')
            
        if min_number == expetced:
            print('test successed\n')
        else:
            print('test failed\n')
    except:
        if expetced == None:
            print('test successed\n')
        else:
            print('test failed\n')
            
            
            
if __name__ == '__main__':
    array1 = [3, 4, 5, 1, 2]
    test(array1, 1)
    
    array2 = [3, 4, 5, 1, 1, 2]
    test(array2, 1)

    array3 = [3, 4, 5, 1, 2, 2]
    test(array3, 1)

    array4 = [1, 0, 1, 1, 1]
    test(array4, 0)

    array5 = [1, 2, 3, 4, 5]
    test(array5, 1)

    array6 = [2]
    test(array6, 2)

    test(None, None)
            
            
        