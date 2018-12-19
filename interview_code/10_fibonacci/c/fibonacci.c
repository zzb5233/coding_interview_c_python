#include <stdio.h>
#include <stdlib.h>
#include <string.h>







/*0, 1, 1, 2, 3, 5, 8...*/

int fibonacci_soulution_1(int number)
{
	if(number <= 0)
        return 0;

    if(number == 1)
        return 1;
	return fibonacci_soulution_1(number-1) + fibonacci_soulution_1(number-2);
}





int fibonacci_soulution_2(int number)
{
	if(number <= 0)
        return 0;

    if(number == 1)
        return 1;
	
	int i;
	
	int fib_1 = 0;
	int fib_2 = 1;
	int fib_3;
	for(i = 1; i < number; i++){
		fib_3 = fib_1 + fib_2;
		fib_1 = fib_2;
		fib_2 = fib_3;
	}
	return fib_3;
}










void main(void)
{
	printf("%d\n", fibonacci_soulution_1(10));
	printf("%d\n", fibonacci_soulution_2(10));
}