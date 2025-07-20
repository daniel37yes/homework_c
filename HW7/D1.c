/*
 * D1.c
 * 
 От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N 
Данные на входе: 		Одно натуральное число 
Данные на выходе: 	Последовательность чисел от 1 до введенного числа
 */


#include <stdio.h>

void sequence(int n )
{
	if (n > 1)   
	sequence(n - 1);
	printf ("%d ", n);
}

int main ()
{
	int n;
	scanf ("%d", &n);
	sequence (n);
	return 0;
}
