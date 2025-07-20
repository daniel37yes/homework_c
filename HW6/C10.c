/*
 * C10.c
 * 
 * Простые множители

Составить функцию, печать всех простых множителей числа. 
Использовать ее для печати всех простых множителей числа.
void print_simple(int n)
Данные на входе: 		Целое положительное число. 
Данные на выходе: 	Последовательность всех простых множителей 
					данного числа в порядке возрастания. 

 * 
 */


#include <stdio.h>
void print_simple(int n);
int main(void)
{
int n;
    scanf("%d",&n);
    print_simple(n);
    return 0;
}
 
void print_simple(int n)
{
int div=2;
    while (n!=1)
    {
        if(n%div==0)
        {
            printf("%d ",div);
            n/=div;
        }
        else
            div+=1;
    }  
}

//~ #include <stdio.h>

//~ int main(void)
//~ {
	//~ int a; 
	//~ int i = 2;
	//~ scanf ("%d", &a);
	//~ while ( a!=1) 
	//~ {	
		//~ if (a%i ==0)
		//~ {	
			//~ printf ("i= %d \n", i);
			//~ a/=i;
		//~ }
		//~ else
			//~ i+=1;
	//~ }
	//~ return 0;
//~ }
