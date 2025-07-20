/*
 * E1.c
 * 
Среднее арифметическое чисел
Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива. 

Данные на входе: 		5 целых ненулевых чисел через пробел 
Данные на выходе: 	Одно число в формате "%.3f" 

Пример №1
Данные на входе: 	4 15 3 10 14 
Данные на выходе: 	9.200
 * 
 */


#include <stdio.h>

#define ARR 5

int Massive_scan (int *arr, int len)
{
	int i;
	for(i = 0; i < ARR; i++){
    scanf("%d", &arr[i]);
	}
	return i;
}

void average (int *arr, int len )
{
	float sum= 0;
	for(int i = 0; i < len; i++){
    sum+= arr [i];
	}
	printf ("%.3f ", sum/ ARR);
}


int main(void)
{
	int arr [ARR] = {0};
    Massive_scan (arr,ARR);
    average (arr, ARR);
	return 0;
}
