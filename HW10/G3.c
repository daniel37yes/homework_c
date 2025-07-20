/*
 * G3.c
 * 
 Последний номер символа
В файле .txt дана строка из 1000 символов. Показать номера символов, 
совпадающих с последним символом строки. Результат записать в файл .txt 

Данные на входе: 	Строка не более 1000 символов 
Данные на выходе: 	Целые числа через пробел - номера символа, который 
					совпадает с последним символом строки. 

Пример
Данные на входе: 	aabbcdb 
Данные на выходе: 	2 3 

 */


#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    char str[1001];
    fgets(str, 1001, input); // Считываем строку целиком
    str[strcspn(str, "\n")] = '\0'; // Удаляем символ перевода строки

    int len = strlen(str);
    if (len == 0) {
        fclose(input);
        fclose(output);
        return 0;
    }

    
    char last_char = '\0';
    for (int i = len - 1; i >= 0; i--) {
        if (!isdigit(str[i])) {
            last_char = str[i];
            break;
        }
    }

    //~ // Если строка состоит только из цифр - выходим
    if (last_char == '\0') {
        fclose(input);
        fclose(output);
        return 0;
    }

    // Ищем совпадения (игнорируя цифры)
    for (int i = 0; i < len - 1; i++) {
        if (!isdigit(str[i]) && str[i] == last_char) {
            fprintf(output, "%d ", i ); // Нумерация с 1
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
