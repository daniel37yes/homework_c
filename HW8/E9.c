/*
 * E9.c
 * 
Циклический сдвиг массива вправо
Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически 

Пример №1
Данные на входе: 	4 -5 3 10 -4 -6 8 -10 1 0 
Данные на выходе: 	0 4 -5 3 10 -4 -6 8 -10 1 
 * 
 */


#include <stdio.h>
#define SIZE 10

int Input(int* arr, int n)
{
    int i;
    for(i=0; i < n ;i++)
        scanf("%d",&arr[i]);
    return i;
}

void shift_array_left(int a[], int size)
{
    int tmp = a[size - 1];
    for (size_t i = size -1; i > 0; i-- )
    {
        a[i] = a[i-1];
    }
    a[0] = tmp;
}

void Print(int *arr,int len)

{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
     int arr[SIZE];
     Input(arr, SIZE);
     shift_array_left(arr,SIZE);
     Print(arr,SIZE);
     return 0;
}
