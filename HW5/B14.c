#include <stdio.h>

//~ Дана последовательность ненулевых целых чисел, в конце последовательности число 0. 
//~ Подсчитать количество чисел. 

int main(void)
{
	unsigned int a, count = 0;
	do 
	{
		scanf("%d", &a);
		if (a%2 == 0 || a%2 !=0);
		count ++;
	}
	while (a != 0);
	printf("%d", count - 1 );
	
	return 0;
}
