#include <stdio.h>
#include <stdlib.h>
#include <string.h>








int count_1_in_number_each(int number)
{
	int count = 0;
	int flag = 1;
	
	while(flag){
		if(number & flag){
			count++;
		}
		flag <<= 1;
	}
	
	return count;
}



int count_1_in_number_cur(int number)
{
	int count = 0;
	
	while(number){
		number = (number-1)&number;
		count++;
	}
	return count;
}








void main(void)
{
	int number = 100;
	
	printf("The number %d have %d '1' in binary\n", number, count_1_in_number_each(number));
	printf("The number %d have %d '1' in binary\n", number, count_1_in_number_cur(number));
}