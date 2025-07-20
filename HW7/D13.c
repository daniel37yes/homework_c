/*
 * D13.c
 * 
 Печать простых множителей
Составить рекурсивную функцию, печать всех простых множителей числа. 
Данные на входе: 		Натуральное число 
Данные на выходе: 	Последовательность из всех простых делителей числа через пробел 

Пример №1
Данные на входе: 	12 
Данные на выходе: 	2 2 3
 */


#include <stdio.h>

void print_simple(int n, int div)
 {
    if (n == 1)
    return;
    for (;;)
    {
		if(n%div==0)
        {
            printf("%d ",div);
            print_simple(n/div, div );
			return; 
       }
    div++;
    }
}
int main(void)
{
int n;
    scanf("%d",&n);
    print_simple(n, 2);
    return 0;
}

