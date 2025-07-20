/*
 * D9.c
 * 
 Сумма цифр числа
Дано натуральное число N. Вычислите сумму его цифр. 
Необходимо составить рекурсивную функцию.
int sum_digits(int n)
Данные на входе: 		Одно натуральное число. 
Данные на выходе: 	Целое число - сумма цифр введенного числа. 

Пример №1
Данные на входе: 	123 
Данные на выходе: 	6
 */


//~ #include <stdio.h>
 
//~ int get_sum(int n) 
//~ {
	//~ int res = n % 10;
    //~ if (n >= 1)
		//~ res += get_sum(n / 10);
	
    //~ return res;    	
//~ }
 
//~ int main()
//~ {
//~ int n;
    //~ scanf("%d", &n);
    //~ printf("%d", get_sum(n));
    //~ return 0;
//~ }


#include <stdio.h>

int get_sum(int n) 
{
    if (n == 0)  
        return 0;
    
    return (n % 10) + get_sum(n / 10);  // Текущая цифра + сумма остальных
}

int main() 
{
    int n;
    scanf("%d", &n);
    printf("%d", get_sum(n));
    return 0;
}
