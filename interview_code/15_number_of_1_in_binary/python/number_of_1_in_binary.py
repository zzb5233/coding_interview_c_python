# -*- coding: utf-8 -*-


'''
def count_1_in_number_each_bit(number):
    flag = 1
    count = 0
    i = 0
    
    while(int(flag)):
        if number & flag:
            count += 1
        flag <<= 1
        i += 1
    return count
'''

def count_1_in_number_cur_bit(number):
    count = 0
    
    while(number):
        number = number&(number-1)
        count += 1
        
    return count



if __name__ == '__main__':
    number = 100
    #print('The number %d have %d "1" in binary' % (number, count_1_in_number_each_bit(number)))
    print('The number %d have %d "1" in binary' % (number, count_1_in_number_cur_bit(number)))