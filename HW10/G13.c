/*
 * G13.c
 * 
 Изменить расширение
В файле .txt записан полный адрес файла (возможно, без расширения). 
Необходимо изменить его расширение на ".html" и записать результат в файл .txt. 

Данные на входе: 	Строка состоящая из символов: a-z, A-Z, 0-9, / 
Данные на выходе: 	Исходная строка с измененным расширением. 

Пример №1
Данные на входе: 	/DOC.TXT/qqq 
Данные на выходе: 	/DOC.TXT/qqq.html 

Пример №2
Данные на входе: 	/DOC.TXT/qqq.com 
Данные на выходе: 	/DOC.TXT/qqq.html 
 */


#include <stdio.h>
#include <string.h>

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    char path[1001];
    
    fgets(path, 1001, in);
    path[strcspn(path, "\n")] = '\0';
    
    // Находим последнюю точку и последний слэш
    char *last_dot = NULL;
    char *last_slash = NULL;
    for (char *p = path; *p; p++) {
        if (*p == '.') last_dot = p;
        if (*p == '/') last_slash = p;
    }
    
    // Если нужно удалить старое расширение
    if (last_dot && (!last_slash || last_dot > last_slash)) {
        *last_dot = '\0';
    }
    
    strcat(path, ".html");
    fprintf(out, "%s", path);
    
    fclose(in);
    fclose(out);
    return 0;
}
