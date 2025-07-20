
//~ Сумма цифр равна 10
//~ Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

#include <stdio.h>
int main(void)
{
int n, sum = 0;
scanf("%d", &n);
	while (n != 0)
	{
	sum+= n % 10;
	n = n / 10; // Отбросили одну цифру
	}
	if (sum == 10)
	printf("YES");
	else  
	printf("NO");
	
return 0;
}
