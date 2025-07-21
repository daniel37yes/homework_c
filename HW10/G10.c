/*
 * G10.c
 * 
Самое длинное слово
В файле .txt дана строка слов, разделенных пробелами. 
Найти самое длинное слово и вывести его в файл .txt. 
Случай, когда самых длинных слов может быть несколько, не обрабатывать. 

Данные на входе: 	Строка из английских букв и пробелов. Не более 1000 символов. 
Данные на выходе: 	Одно слово из английских букв. 

Пример
Данные на входе: 	Hello beautiful world 
Данные на выходе: 	beautiful 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1001

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char str[MAX_LENGTH];
    char longest_word[MAX_LENGTH] = "";
    int max_length = 0;
    int current_length = 0;
    char *word_start = str;

    // Читаем строку 
    if (fgets(str, MAX_LENGTH, input) == NULL) {
        fclose(input);
        fclose(output);
        return 1;
    }

    // Удаляем символ новой строки
    str[strcspn(str, "\n")] = '\0';

  
    for (char *p = str; *p != '\0'; p++) {
        if (isalpha(*p)) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                strncpy(longest_word, word_start, max_length);
                longest_word[max_length] = '\0';
            }
            current_length = 0;
            word_start = p + 1;
        }
    }
    
    // Проверяем последнее слово в строке
    if (current_length > max_length) {
        strncpy(longest_word, word_start, current_length);
        longest_word[current_length] = '\0';
        max_length = current_length;
    }

    // Если вся строка - одно слово
    if (max_length == 0 && strlen(str) > 0) {
        strcpy(longest_word, str);
    }

    if (strlen(longest_word) > 0) {
        fprintf(output, "%s", longest_word);
    }

    fclose(input);
    fclose(output);
    return 0;
}