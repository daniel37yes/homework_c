/*
 * E17.c
 * 
Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем 
встречаются только один раз, и вывести их на экран. 

Данные на входе: 	10 целых чисел через пробел 
Данные на выходе: 	Элементы которые встречаются только один раз через пробел 

Пример
Данные на входе: 	5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 -4 1 4 3 2 

 */



#include <stdio.h>
#define SIZE 10

void find_unique_elements(int arr[], int len) {
    
    
    for(int i = 0; i < len; i++) {
        int is_unique = 1; // Предполагаем, что элемент уникален
        
        // Проверяем, есть ли такой же элемент в массиве
        for(int j = 0; j < len; j++) {
            if(i != j && arr[i] == arr[j]) {
                is_unique = 0; // Нашли дубликат
                break;
            }
        }
        
        if(is_unique) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[SIZE];
    
    
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    find_unique_elements(arr, SIZE);
    
    return 0;
}
