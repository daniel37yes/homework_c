/*
 * D20.c
 * 
 Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)
Используя данную функцию, решить задачу.

Данные на входе: 		Два целых положительных числа
Данные на выходе: 	Одно целое число n в степени p

Пример №1
Данные на входе: 	2 3
Данные на выходе: 	8
 * 
 */

#include <stdio.h>

int recurs_power(int n, int p) 
{
    if (p == 0)  // если степень 0
    return 1;      
    if (p == 1) // если степень 1 
    return n;
    if (p > 0) 
    {
        return n * recurs_power(n, p - 1); 
    } 
        return 0;
  
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d", recurs_power(n, p));
    return 0;
}

//------------------------------------------------
//~ #include <stdio.h>
//~ #include <math.h>

//~ int power(int n, int p)
//~ {
    //~ return pow(n, p);
//~ }

//~ int main()
//~ {
    //~ double n;
    //~ double p;
    //~ scanf("%lf %lf",&n, &p);
    //~ printf("%d",power(n, p));
    //~ return 0;
//~ }
