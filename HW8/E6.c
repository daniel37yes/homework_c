/*
 * E6.c
 * 
Среднее арифметическое массива
Считать массив из 12 элементов и подсчитать среднее арифметическое элементов массива.

Данные на входе: 	12 целых чисел через пробел 
Данные на выходе: 	Среднее арифметическое в формате "%.2f" 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	1.08 

 * 
 */



#include <stdio.h>

#define ARR 12

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
	printf ("%.2f ", sum/ ARR);
}


int main(void)
{
	int arr [ARR] = {0};
    Massive_scan (arr,ARR);
    average (arr, ARR);
	return 0;
}
