/*
 * G8.c
 * 
 Числа в массив
В файле .txt дана строка, не более 1000 символов, содержащая буквы, 
целые числа и иные символы. Требуется все числа, которые встречаются 
в строке, поместить в отдельный целочисленный массив. Например, если 
дана строка "data 48 call 9 read13 blank0a", то в массиве числа 
48, 9, 13 и 0. Вывести массив по возрастанию в файл .txt. 

Данные на входе: 	Строка из английских букв, цифр и знаков препинания 
Данные на выходе: 	Последовательность целых чисел отсортированная по возрастанию 

Пример
Данные на входе: 	data 48 call 9 read13 blank0a 
Данные на выходе: 	0 9 13 48 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUMBERS 1000  // Максимальное количество чисел в строке
#define MAX_STRING 1001  // Максимальная длина строки

// Функция сравнения для qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char str[MAX_STRING];
    int numbers[MAX_NUMBERS];
    int num_count = 0;
    int current_num = 0;
    int in_number = 0;  // Флаг: находимся ли внутри числа

    // Читаем всю строку из файла
    if (fgets(str, MAX_STRING, input) == NULL) {
        fclose(input);
        fclose(output);
        return 1;
    }

    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            // Если цифра, добавляем к текущему числу
            current_num = current_num * 10 + (str[i] - '0');
            in_number = 1;
        } else {
            // Если не цифра и мы были внутри числа, сохраняем число
            if (in_number) {
                if (num_count < MAX_NUMBERS) {
                    numbers[num_count++] = current_num;
                }
                current_num = 0;
                in_number = 0;
            }
        }
    }
    
    // Добавляем последнее число, если строка заканчивалась цифрой
    if (in_number && num_count < MAX_NUMBERS) {
        numbers[num_count++] = current_num;
    }

    // Сортируем массив чисел
    qsort(numbers, num_count, sizeof(int), compare);

    // Записываем результат в файл
    for (int i = 0; i < num_count; i++) {
        fprintf(output, "%d", numbers[i]);
        if (i < num_count - 1) {
            fprintf(output, " ");
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
