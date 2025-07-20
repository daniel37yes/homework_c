//~ Ровно три цифры
//~ Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.


#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	if (n>99 && n<1000)
		printf("%s", "YES");
	else  
		printf("%s", "NO");
	return 0;
}
