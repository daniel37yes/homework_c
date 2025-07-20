/*
 * C16.c
 * 
Проверка на простоту

Составить функцию логическую функцию, которая определяет, верно ли, 
что число простое. Используя функцию решить задачу.

int is_prime(int n)

Данные на входе: 	Одно целое не отрицательное число. 
Данные на выходе: 	YES или NO
 */


#include <stdio.h>

int is_prime(int a)
{
	int flag = 1;
	    if (a <= 1)
    {
     flag = 0;
     return flag; // 1 и меньше NO
    }
    for (int i = 2; i < a; i++)
    {
        if (a%i == 0)
        {
         flag = 0; // если есть делитель NO
         return flag;
        }
    }
    return flag;// делителя нет YES
}

int main()
{
    int a;
    scanf("%d", &a);
	is_prime(a);
	printf (is_prime(a) ? "YES\n" : "NO\n");
    return 0;
}



// через FLAG
//~ int is_prime(int n) 
//~ {
//~ int flag = 1;
    //~ for (int i = 2; i < n; i++) 
    //~ {
        //~ if (n % i == 0)
           //~ flag = 0;
    //~ }
    //~ if ((n==1) && (n==0))
        //~ flag=0;
    	
    //~ return flag;
//~ }
//~ int main()
//~ {
//~ int a;
 
    //~ scanf("%d", &a);
 
    //~ if (is_prime(a))
        //~ printf("YES");
    //~ else
        //~ printf("NO");
  
    //~ return 0;
//~ }

