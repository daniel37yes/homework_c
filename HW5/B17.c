/*
 Все счастливые числа
Ввести натуральное число и напечатать все числа от 10 до введенного 
числа - у которых сумма цифр равна произведению цифр 
Данные на входе:		Одно натуральное число большее 10 
Данные на выходе:	Числа у которых сумма цифр равна произведению цифр
 через пробел в порядке возрастания. Не превосходящие введенное число. 

 */


#include <stdio.h>

int main(void)
{
	int a; 
	int i = 0;
	scanf ("%d", &a);
	for (i = 10; i <= a && a >= 10; i++) 
	{	
		int current = i;
		int sum= 0; 
		int prod= 1;
		while (current !=0)
		{
			int digit = current %10;
			sum += digit;
			prod *= digit;
			current /= 10;
		}
	//~ printf ("i= %d \n", i);
	//~ printf ("prod*= %d \n", prod);
	//~ printf ("sum+= %d \n", sum);
			if (prod == sum)
			printf ("%d ", i);
	}	
	return 0;
}



