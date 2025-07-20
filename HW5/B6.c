//Ввести целое число и определить, верно ли, что в его записи есть   
 //две одинаковые цифры, стоящие рядом.

#include <stdio.h>
int main()
{
	long long int a, k;
	//~ printf("number:\n");
	scanf("%lld", &a);
	//~ printf("a= %lld \n", a);
		while (a>0) 
		{
			k = a%10;
			//~ printf("k= %lld \n", k);
			a = a/10;
			//~ printf("a= %lld \n", a);
		if (a%10 == k)
			{
			printf("YES\n");
			break;
			}   
		}
if (!a)
    printf("NO\n");   
}
