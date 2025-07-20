/*
 * B15_1.c
Количество четных чисел
Дана последовательность ненулевых целых чисел, в конце 
последовательности число 0. 
Подсчитать количество четных чисел. 

Данные на входе:		Последовательность ненулевых целых чисел. 
В конце последовательности число ноль. 
Данные на выходе:	Одно целое число - количество чётных чисел.
 */


#include <stdio.h>

int main(void)
{
	unsigned int a, count = 0;
	do 
	{
		scanf("%d", &a);
		if (a%2 == 0)
		{
		count ++;
		//~ printf("%d", count);
		}
		else
		continue;
	}
	while (a != 0);
	printf("%d", count  - 1);
	
	return 0;
}

//~ #include <stdio.h>
 
//~ int main(void)
//~ {
//~ unsigned int a, count = 0;
    //~ do
    //~ {
        //~ scanf("%d", &a);
        //~ if (a%2 == 0)
            //~ count ++;
    //~ } 
    //~ while (a !=0);
    //~ printf("%d", count - 1);
    //~ return 0;
//~ }
