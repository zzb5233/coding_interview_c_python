# -*- coding: utf-8 -*-


def equal(num_1, num_2):
    if num_1 - num_2 < 0.0000001 and num_1 - num_2 > -0.0000001:
        return True
    else:
        return False
    
    
def power_with_unsigned_exponent(base, abs_exponent):
    result = 1.0
    
    for i in range(abs_exponent):
        result *= base
    return result
    
def power(base, exponent):
    if equal(0.0, base) and exponent < 0:
        return 0, True
    
    abs_exponent = abs(exponent)
    
    result = power_with_unsigned_exponent(base, abs_exponent)
    if exponent < 0:
        result = 1.0 / result
        
    return result, False

    
    
def test(test_name, base, exponent, expected_result, expected_flag):
    result, flag = power(base, exponent)
    if equal(expected_result, result) and flag == expected_flag:
        print('%s: passed' % test_name)
    else:
        print('%s: failed' % test_name)
        
    
    
if __name__ == '__main__':

    # 底数、指数都为正数
    test("Test1", 2, 3, 8, False)
    
    # 底数为负数、指数为正数
    test("Test2", -2, 3, -8, False)
    
    # 指数为负数
    test("Test3", 2, -3, 0.125, False)
    
    # 指数为0
    test("Test4", 2, 0, 1, False)
    
    # 底数、指数都为0
    test("Test5", 0, 0, 1, False)
    
    # 底数为0、指数为正数
    test("Test6", 0, 4, 0, False)
    
    # 底数为0、指数为负数
    test("Test7", 0, -4, 0, True)

    
    
    
    
    
    
    