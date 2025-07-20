/*
 * D11.c
 * 
 Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 		Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	2 
 */


#include <stdio.h>

int counter(unsigned int n) 
{
    if (n == 0) 
    return 0;
    return (n % 2) + counter(n / 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", counter(n));
    return 0;
}

//~ int counter (int n)
//~ {
	//~ int count=0;
	//~ while (n>0)
	//~ {
	//~ count+= n % 2;
	//~ n = n / 2;
	//~ }
	//~ return count;
//~ }

//~ int main(int argc, char **argv)
//~ {
	 //~ int n;
    //~ scanf("%d", &n);
    //~ printf("%d", counter (n));
    //~ return 0;
//~ }

