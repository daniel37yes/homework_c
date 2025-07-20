/*
 * E2.c
 * 
 Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них. 

Данные на входе: 		5 целых чисел через пробел 
Данные на выходе: 	Одно единственное целое число 

Пример №1
Данные на входе: 	4 15 3 10 14 
Данные на выходе: 	3 

 */


#include <stdio.h>
#include <unistd.h>

#define ARR 5

int Massive_scan (int *arr, int len)
{
	int i;
	for(i = 0; i < ARR; i++){
    scanf("%d", &arr[i]);
	}
	return i;
}

int min_element (int *arr, int len )
{
	int min = arr[0], i;
	for(i = 0; i < len; i++){
		if ( min > arr[i])
	
		min = arr [i];
	
	}
	return min;
}


int main(void)
{
	int arr [ARR] = {0};
    Massive_scan (arr,ARR);
    min_element (arr, ARR);
    printf ("%d ", min_element (arr, ARR));
	return 0;
}
