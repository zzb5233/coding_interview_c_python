#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int increment(char *p_number)
{
	int over_flow = 0;
	int pre_value = 0;
	int cur_sum = 0;
	int length;
	int i;
	
	length = strlen(p_number);
	for(i = length-1; i >= 0; i--){
		cur_sum = p_number[i]-'0'+pre_value;
		if(length-1 == i){
			cur_sum++;
		}
		
		if(cur_sum >= 10){
			if(i==0){
				over_flow = 1;
			}else{
				cur_sum -= 10;
				p_number[i] = cur_sum+'0';
				pre_value = 1;
			}
		}else{
			p_number[i] = cur_sum+'0';
			break;
		}
	}
	return over_flow;
}

void print_number(char *p_number)
{
	int length;
	int i;
	
	while(*p_number++ == '0');
	printf("%s\n", --p_number);
	return;
}



void print_1_to_max_of_n_dights(int number)
{
	char *p_number = NULL;
	if(number <= 0){
		return;
	}
	
	p_number = malloc(sizeof(char) * (number + 1));
	memset(p_number, '0', sizeof(char) * number);
	p_number[number] = 0;
	
	while(!increment(p_number)){
		print_number(p_number);
	}
	free(p_number);
	return;
}

void main(void)
{
	int number = 2;
	print_1_to_max_of_n_dights(number);
}