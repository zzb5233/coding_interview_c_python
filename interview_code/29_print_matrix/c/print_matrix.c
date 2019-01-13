#include <stdio.h>
#include <string.h>
#include <stdlib.h>





void print_matrix_in_cicle(int** numbers, int columns, int rows, int start)
{
    int end_x = columns - 1 - start;
    int end_y = rows - 1 - start;
	int i;
	int number;

    // 从左到右打印一行
    for(i = start; i <= end_x; ++i)
    {
        number = numbers[start][i];
		printf("%d ", number);
    }

    // 从上到下打印一列
    if(start < end_y)
    {
        for(i = start + 1; i <= end_y; ++i)
        {
            number = numbers[i][end_x];
            printf("%d ", number);
        }
    }

    // 从右到左打印一行
    if(start < end_x && start < end_y)
    {
        for(i = end_x - 1; i >= start; --i)
        {
            number = numbers[end_y][i];
            printf("%d ", number);
        }
    }

    // 从下到上打印一行
    if(start < end_x && start < end_y - 1)
    {
        for(i = end_y - 1; i >= start + 1; --i)
        {
            number = numbers[i][start];
            printf("%d ", number);
        }
    }
}



void print_matrix_clock_wisely(int **numbers, int rows, int columns)
{
	if(NULL == numbers || rows <= 0 || columns <= 0){
		return;
	}
	
	int start = 0;
	while(rows > start * 2 && columns > start * 2){
		print_matrix_in_cicle(numbers, rows, columns, start);
		start++;
	}
	return;
}



// ====================测试代码====================
void test(int columns, int rows)
{
	int i, j;
    printf("test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = malloc(sizeof(int *) * rows);
    for(i = 0; i < rows; ++i)
    {
        numbers[i] = malloc(sizeof(int) * columns);
        for(j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    print_matrix_clock_wisely(numbers, columns, rows);
    printf("\n");

    for(i = 0; i < rows; ++i){
		free((int*)numbers[i]);
	}

    free(numbers);
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    test(1, 1);

    /*
    1    2
    3    4
    */
    test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    test(4, 5);

    /*
    1    2    3    4    5
    */
    test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    test(5, 4);

    return 0;
}