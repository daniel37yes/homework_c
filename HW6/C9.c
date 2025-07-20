/*
 * C9.c
 * 
 Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 		Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

 */


#include <stdio.h>

unsigned long long factorial(int a)
{
	unsigned long long count = 1;
	for (int i = 1; i<=a; i++)
		count*=i;
	return count;
}

int main(void)
{
	int a;
	scanf("%d", &a);
	if (a > 20)
	{
		printf("Overflow!");
		return 2;
	}
	unsigned long long fact  = factorial(a);
	printf("%llu", fact);
	return 0;
}

