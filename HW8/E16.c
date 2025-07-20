/*
 * E16.c
 * 
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. 
Гарантируется, что такое число ровно 1. 

Данные на входе: 	10 целых числе через пробел 
Данные на выходе: 	Одно число, которое встречается чаще других. 

Пример
Данные на входе: 	4 1 2 1 11 2 34 11 0 11 
Данные на выходе: 	11 

 */




#include <stdio.h>
#define SIZE 10

void find_most_frequent(int arr[]) {
    int max_count = 0;
    int most_frequent = arr[0];
    
    for(int i = 0; i < SIZE; i++) {
        int current_count = 1;
        
        // Считаем, сколько раз встречается arr[i]
        for(int j = i + 1; j < SIZE; j++) {
            if(arr[i] == arr[j]) {
                current_count++;
            }
        }
        
        // Если текущее число встречается чаще, обновляем максимум
        if(current_count > max_count) {
            max_count = current_count;
            most_frequent = arr[i];
        }
    }
    
    printf("%d\n", most_frequent);
}

int main() {
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    find_most_frequent(arr);
    
    return 0;
}
