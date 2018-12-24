#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int get_digit_sum(int number)
{
	int sum = 0;
	
	while(number){
		sum += number%10;
		number /= 10;
	}
	return sum;
}

int check(int threshold, int rows, int cols, int row, int col, int *visited)
{
	if(row >= 0 && col >= 0 && rows > 0 && cols > 0 && row < rows && col < cols && get_digit_sum(row)+get_digit_sum(col)<=threshold && !visited[row*cols+col]){
		return 1;
	}
	return 0;
}

int moving_count_core(int threshold, int rows, int cols, int row, int col, int *visited)
{
	int count = 0;
	
	if(check(threshold, rows, cols, row, col, visited)){
		visited[row*cols+col] = 1;
		count = 1 + moving_count_core(threshold, rows, cols, row-1, col, visited) +
			moving_count_core(threshold, rows, cols, row+1, col, visited) +
			moving_count_core(threshold, rows, cols, row, col-1, visited) +
			moving_count_core(threshold, rows, cols, row, col+1, visited);
	}
	return count;
}



int moving_count(int threshold, int rows, int cols)
{
	int malloc_size = sizeof(int) * rows * cols;
	int count;
	
	int *visited = malloc(malloc_size);
	assert(visited);
	memset(visited, 0, malloc_size);
	
	count = moving_count_core(threshold, rows, cols, 0, 0, visited);
	
	free(visited);
	return count;
}





void main(void)
{
	int threshold = 10;
	int m = 10, n = 10;
	
	printf("%d\n", moving_count(threshold, m, n));
}
