/*
 * C5.c

Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

 */

#include <stdio.h>
int SUM(int a)
{
    int sum = 0, i =1;
    for ( i = 1; i <= a; i++)
    sum+= i;
    return sum ;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",SUM(n));
    return 0;
}
