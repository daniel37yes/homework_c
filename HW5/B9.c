//~ Ввести целое число и определить, верно ли, что все его цифры четные.

#include <stdio.h>

int main(void)
{
int a, k , count=0;
scanf("%d", &a);
while (a !=0)
	{
		k = a%10;
		//~ printf("k= %d \n", k);
		a/=10;
		//~ printf("a= %d \n", a);
		count+= k%2;
		//~ printf("count= %d \n", count);
	}
		if (count==0) 
		printf("YES");
		else
		printf("NO");
		return 0; 
}
