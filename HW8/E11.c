/*
 * E11.c
 * 
 Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре. 

Данные на входе: 		10 целых чисел через пробел 
Этот же массив отсортированный по последней цифре 

Пример №1
Данные на входе: 	14 25 13 30 76 58 32 11 41 97 
Данные на выходе: 	30 11 41 32 13 14 25 76 97 58 

 */


#include <stdio.h>
#include <inttypes.h>
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

void aPrint(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    printf("%d ",arr[i]);
    printf("\n");
}


void sortByLastDigit(int arr[], int n) {
    // Шаг 1: Создаем временный массив для последних цифр
    int last_digits[n];
    
    // Шаг 2: Заполняем временный массив
    for(int i = 0; i < n; i++) {
        last_digits[i] = arr[i] % 10;
    }
    
    // Шаг 3: Сортировка пузырьком с использованием временного массива
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            // Сравниваем последние цифры из временного массива
            if(last_digits[j] > last_digits[j+1]) {
                // Меняем местами в основном массиве
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Меняем местами во временном массиве
                int temp_digit = last_digits[j];
                last_digits[j] = last_digits[j+1];
                last_digits[j+1] = temp_digit;
            }
        }
    }
}


int main(void)
{
	int arr [SIZE] ;
	
    Massive_scan (arr,SIZE);
    sortByLastDigit(arr, SIZE);
   
    aPrint(arr, SIZE);
   
	return 0;
} 
