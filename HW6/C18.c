/*
 * C18.c
 * 
 Количество цифр в тексте

Составить логическую функцию, которая определяет, что текущий символ 
это цифра. Написать программу считающую количество цифр в тексте.

int is_digit(char c)

Данные на входе: 	Текст из английских букв и знаков препинания. В конце текста символ точка. 
Данные на выходе: 	Одно целое число - количество цифр в тексте. 

Данные на входе: 	1Hello 36world. 
Данные на выходе: 	3 

 */


#include <stdio.h>

int is_digit();

int main( int argc, char **argv)
{
	printf("%d",is_digit());
	return 0;
}

int is_digit()
{
    char input;
    int count=0;
    while( (input = getchar())!='.') //dot
        if(input >= '0' && input <='9') 
            count++;
    return count;
}
