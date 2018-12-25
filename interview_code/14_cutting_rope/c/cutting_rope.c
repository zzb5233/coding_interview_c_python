#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int max_product_after_cutting_solution(int length)
{
	if(length < 2){
		return 0;
	}
	if(2 == length){
		return 1;
	}
	
	if(3 == length){
		return 2;
	}
	
	int *max_product = malloc(sizeof(int) * (length+1));
	assert(max_product);
	
	memset(max_product, 0, sizeof(int) * length);
	int i, j;
	int cur_product;
	int max;
	max_product[0] = 0;
	max_product[1] = 1;
	max_product[2] = 2;
	max_product[3] = 3;
	
	for(i = 4;i <= length; i++){
		for(j = 1; j <= i/2; j++){
			cur_product = max_product[j] * max_product[i-j];
			if(cur_product > max_product[i]){
				max_product[i] = cur_product;
			}
		}
	}
	max = max_product[length];
	free(max_product);
	return max;
}

int max_product_after_cutting_solution_greedy(int length)
{
	if(length < 2){
		return 0;
	}
	
	if(2 == length){
		return 1;
	}
	
	if(3 == length){
		return 2;
	}
	
	int times_of_3 = length / 3;
	
	if(length - times_of_3 * 3 == 1){
		times_of_3 -= 1;
	}
	
	int times_of_2 = (length - times_of_3 * 3) / 2;
	return (int)(pow(3, times_of_3)) * (int)(pow(2, times_of_2));
}

void main(void)
{
	int length = 10;
	printf("max: %d\n", max_product_after_cutting_solution(length));
	printf("max: %d\n", max_product_after_cutting_solution_greedy(length));
}



