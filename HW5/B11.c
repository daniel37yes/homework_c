/*
 Перевернуть число
Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д. 

 */


#include <stdio.h>

int main(void)
{
	unsigned int a, reversed = 0;
	scanf("%d", &a);
	while (a != 0) 
    {
        reversed = reversed * 10 + a % 10;
        //~ printf("reversed= %d \n", reversed);
        a /= 10;
        //~ printf("a= %d \n", a);
    }
	printf("%d \n", reversed);
   
	return 0;
}

