/*
 * G9.c
 * 
Удалить повторяющиеся символы
В файле .txt строка из меленьких и больших английских букв, 
знаков препинания и пробелов. Требуется удалить из нее повторяющиеся 
символы и все пробелы. Результат записать в файл .txt. 

Данные на входе: 	Строка из меленьких и больших английских букв, 
					знаков препинания и пробелов. Размер строки не 
					более 1000 сивмолов. 
Данные на выходе: 	Строка из меленьких и больших английских букв. 

Пример
Данные на входе: 	abc cde def 
Данные на выходе: 	abcdef 
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1001

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (!input || !output) {
        perror("Error opening files");
        if (input) fclose(input);
        if (output) fclose(output);
        return 1;
    }

    char str[MAX_LENGTH];
    char result[MAX_LENGTH] = {0};
    int result_index = 0;
    int char_exists[256] = {0}; // Для отслеживания уже встреченных символов

    // Читаем строку из файла
    if (fgets(str, MAX_LENGTH, input) == NULL) {
        fclose(input);
        fclose(output);
        return 1;
    }

    // Обрабатываем строку
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char c = str[i];
        
        // Пропускаем пробелы
        if (c == ' ') continue;
        
        // Если символ еще не встречался
        if (!char_exists[c]) {
            char_exists[c] = 1; // Помечаем как встреченный
            result[result_index++] = c; // Добавляем в результат
        }
    }

    // Записываем результат в файл
    fputs(result, output);

    fclose(input);
    fclose(output);
    return 0;
}
