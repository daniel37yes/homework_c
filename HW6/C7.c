/*
 * C7.c
 * 
Перевести число N в систему счисления P
Составить функцию, которая переводит число N из десятичной системы 
счисления в P-ичную систему счисления.

Данные на входе: 		Два целых числа. N >= 0 и  2 <= P <= 9
Данные на выходе: 	Одно целое число

 */


#include <stdio.h>
 
int notation(int n, int p);
 
int main()
{
int n, p;
    scanf("%d%d", &n, &p);
    printf("%d\n", notation(n, p));
    return 0;
}
 
int notation(int n, int p)
{
int remainder;
int exponent = 1;
int res = 0;
    for(;n > 0;n /= p)
    {
        remainder = n % p;
        res += remainder * exponent;
        exponent *= 10;
    }
    return res;
}
