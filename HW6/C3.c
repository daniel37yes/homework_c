/*
 * C3.c
Написать функцию, которая возвращает среднее арифметическое 
двух переданных ей аргументов (параметров). int middle(int a, int b)
 */


#include <stdio.h>


 int middle(int a, int b)
{
    //~ int x=0 ;
    //~ x= (a+b)/2;
    return (a+b)/2;
}

int main()
{
    int a, b;
    scanf("%d %d",&a, &b);
    printf("%d",(a+b)/2);
    return 0;
}
