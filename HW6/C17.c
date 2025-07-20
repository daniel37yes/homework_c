/*
 * C17.c
 * 
Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в 
данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 		Целое не отрицательное число 
Данные на выходе: 	YES или NO 

 */


#include <stdio.h>

int is_happy_number(int a)

{
		int current = a;
		//~ int flag = 0; // вариант с флагом
		int sum= 0; 
		int prod= 1;
		while (current !=0)
		{
			int digit = current %10;
			sum += digit;
			prod *= digit;
			current /= 10;
		}
			//~ if (prod == sum) // вариант с if
			//~ flag = 1;
			//~ else
			//~ flag = 0;
		//~ flag = (prod == sum) ?  1 :  0 ; // вариант с тернарником
		
	//~ return flag;
	return (prod == sum) ?  1 :  0 ; // вариант с возвратом - укороченный
}

int main(void)
{
	int n; 
	scanf ("%d", &n);
	printf (is_happy_number(n) ? "YES\n" : "NO\n");
	return 0;
}
