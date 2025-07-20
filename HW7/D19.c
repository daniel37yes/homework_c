/*
 * D19.c
 * 
Сколько раз встречается символ a
Дана строка из английских символов, пробелов и знаков препинания. 
В конце строки символ точка. Необходимо реализовать рекурсивную функцию, 
которая считывает данную строку со стандартного потока ввода и возвращает 
целое число - количество символов 'a' в данной строке.
int acounter(void)
Используя данную функцию решить задачу.

Данные на входе: 	Строка состоящая из английских букв, пробелов и знаков препинания. В коне строки символ '.' 
Данные на выходе: 	Одно целое число. 
 * 
 */


#include <stdio.h>

int acounter(void) 
{
    char input = getchar();
    if (input == '.') 
    return 0;
    return (input == 'a' ? 1 : 0) + acounter();
}

int main() 
{
    printf("%d", acounter());
    return 0;
}

//------------------------------------------------------
//~ #include <stdio.h>

//~ int acounter(int count);

//~ int main(int argc, char **argv) {
    //~ printf("%d", acounter(0));  // Начинаем с count = 0
    //~ return 0;
//~ }

//~ int acounter(int count) {
    //~ char input = getchar();
    
    //~ // Базовый случай: если встретили точку, возвращаем накопленный count
    //~ if (input == '.') {
        //~ return count;
    //~ }
    
    //~ // Если символ 'a', увеличиваем count
    //~ if (input == 'a') {
        //~ count++;
    //~ }
    
    //~ // Рекурсивный вызов для обработки следующего символа
    //~ return acounter(count);
//~ }
//---------------------------------------------
//~ #include <stdio.h>

//~ int acounter(void);

//~ int main( int argc, char **argv)
//~ {
	//~ printf("%d",acounter());
	//~ return 0;
//~ }

//~ int acounter(void)
//~ {
    //~ char input;
    //~ int count=0;
    //~ while( (input = getchar())!='.') //dot
        //~ if(input == 'a') 
            //~ count++;
    //~ return count;
//~ }


