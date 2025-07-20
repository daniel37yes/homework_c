/*
 * E10.c
 * 
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента. 

Данные на входе: 	12 целых чисел через пробел 
Данные на выходе: 	12 целых чисел через пробел 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 5 7 
Данные на выходе: 	1 0 5 7 4 -5 3 10 -4 -6 8 -10 
 */



#include <stdio.h>
#define SIZE 12
#define SHIFT 4

int Input(int* arr, int n)
{
    int i;
    for(i=0; i < n ;i++)
        scanf("%d",&arr[i]);
    return i;
}

void shift_right_by_k(int arr[], int size, int k) {
    
    int temp[k];  // Временный массив для хранения последних k элементов
    
    // 1. Сохраняем последние k элементов в temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[size - k + i];
    }
    
    // 2. Сдвигаем остальные элементы вправо на k позиций
    for (int i = size - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }
    
    // 3. Вставляем сохранённые элементы в начало
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[SIZE];
    Input(arr, SIZE);
    
    shift_right_by_k(arr, SIZE, SHIFT);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
