/*
 * C15.c
 * 
Цифры по возрастанию

Составить функцию логическую функцию, которая определяет, верно ли, 
что в заданном числе все цифры стоят по возрастанию. 
Используя данную функцию решить задачу.

int grow_up(int n)

Данные на входе: 	Одно целое не отрицательное число 
Данные на выходе: 	YES или NO 

 */


#include <stdio.h>

void ascending (int a)
{
//~ int prevDigit, currentDigit;
    //~ scanf("%d", &a);
    if (a < 10) 
    {
        printf("YES");  // Одиночное число всегда удовлетворяет условию
        return ;
    }
    int reversed = 0;
    while (a!= 0)
    {
		reversed = reversed *  10 + a%10;
		a /= 10;
	}
	
    int prevDigit = reversed % 10;  // Берём последнюю цифру
    reversed /= 10;
    while (reversed != 0) 
    {
       int currentDigit = reversed % 10;
        if (currentDigit <= prevDigit) // Если предыдущая цифра меньше или равна текущей → не по возрастанию
        {  
            printf("NO");
            return ;
        }
        prevDigit = currentDigit; // приравниваем текущую цифру и сравниваем со следующей
        reversed /= 10;
    }
    printf("YES");  // Если цикл прошёл без нарушения порядка
  
}

int main(void) 
{
    int a;
    scanf("%d", &a);
    ascending (a);
    return 0;
}
