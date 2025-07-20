/*Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9». 
Данные на входе:		Одно целое число 
Данные на выходе:	Одно слово: YES или NO  
*/

#include <stdlib.h>
#include <stdio.h>
 int main (void)
 {
	long long int a;
	scanf("%lld", &a);
	int count = 0;
	while(a) 
	{ 
	  count += abs(a%10) == 9;
		//~ printf("count= %d \n", count);
	  a /= 10; 
	  //~ printf("a= %lld \n", a);
	} 
	  if (count == 1)	
	  printf("YES");
	  else 
	  printf("NO");
	  return 0;
}
