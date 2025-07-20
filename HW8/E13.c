/*
 * E13.c
 * 
Вторая с конца ноль 
Считать массив из 10 элементов и отобрать в другой массив все числа, 
у которых вторая с конца цифра (число десятков) – ноль. 

Данные на входе: 	10 целых чисел через пробел. 
Данные на выходе: 	Целые числа через пробел, у которых вторая с конца цифра - ноль 

Пример
Данные на входе: 	40 105 203 1 14 1000 22 33 44 55 
Данные на выходе: 	105 203 1 1000 
 */


#include <stdio.h>

#include <stdlib.h>

#define SIZE 10

int Massive_scan (int *arr, int len)
{
	int i;
	for(i = 0; i < SIZE; i++){
    scanf("%d", &arr[i]);
	}
	return i;
}

void ChooseSortByMiddleZero(int arr[], int n) {
    for(int i = 0; i < n; i++) {
		 if (((arr[i]/10)%10 == 0) || arr[i] < 10) {
		    printf("%d ",arr[i]);
		}
    }
}

int main(void)
{
	int arr [SIZE] ;
	
    Massive_scan (arr,SIZE);
    ChooseSortByMiddleZero(arr, SIZE);
	return 0;
} 
