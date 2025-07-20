/*
 * D10.c
 * 
Проверка на простоту
Дано натуральное число n >= 1. Проверьте, является ли оно простым. 
Программа должна вывести слово YES, если число простое или NO в противном случае . 
Необходимо составить рекурсивную функцию и использовать ее.
int is_prime(int n, int delitel)

Данные на входе: 		Натуральное число
Данные на выходе: 	YES или NO

Пример №1
Данные на входе: 	11
Данные на выходе: 	YES
 */


#include <stdio.h>
 
int is_prime(int n, int divider)
{
    if (n == divider)
        return 1;
    if ((n > 1) && (n % divider != 0))
        return is_prime(n, divider + 1); 
    else 	
        return 0;    	
}
 
int main()
{
int n;
    scanf("%d", &n);


    is_prime(n, 2) ? printf("YES") : printf("NO");
    return 0;
}


