/*
 * F19.c
 * 
Больше среднего
Написать функцию и программу, демонстрирующую работу данной функции.
Определить количество положительных элементов квадратной матрицы, 
превышающих по величине среднее арифметическое всех элементов главной диагонали.
 Реализовать функцию среднее арифметическое главной диагонали. 

Данные на входе: 	5 строк по 5 целых чисел через пробел 
Данные на выходе: 	Одно целое число 

Пример
Данные на входе: 	1 1 1 1 1 2 2 2 2 2 3 3 3 3 3 4 4 4 4 4 5 5 5 5 5 
Данные на выходе: 	10  
 */


#include <stdio.h>

#define SIZE 5  // Размер квадратной матрицы

// Функция вычисления среднего арифметического главной диагонали
float average_diagonal(int matrix[SIZE][SIZE]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += matrix[i][i];  // Суммируем элементы главной диагонали
    }
    return (float)sum / SIZE;  // Возвращаем среднее значение
}

// Функция подсчета элементов
int count_above_diag_avg(int matrix[SIZE][SIZE]) {
    float avg = average_diagonal(matrix);
    int count = 0;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Проверяем положительные элементы, превышающие среднее
            if (matrix[i][j] > 0 && matrix[i][j] > avg) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int matrix[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int result = count_above_diag_avg(matrix);
    printf("%d\n", result);
    
    return 0;
}
