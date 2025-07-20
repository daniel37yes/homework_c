//~ Количество четных и нечетных цифр
//~ Подсчитать количество четных и нечетных цифр числа. 

#include <stdio.h>

int main(void)
//~ {
	//~ unsigned int a, count1 = 0,count2 = 0 ;
	//~ do 
	//~ {
		//~ scanf("%d", &a);
		//~ if (a%2 == 0)
		//~ {
		//~ printf("%d", a%2);
		//~ count1 ++;
		//~ }
		//~ else
		//~ count2 ++;
		//~ continue;
	//~ }
	//~ while (a%2 == 1);
	//~ count2 ++;

	//~ printf("%d %d", count1, count2);
	
	//~ return 0;
//~ }

{
unsigned int a,k, count1 = 0,count2 = 0 ;
scanf("%d", &a);
while (a !=0)
	{
		k = a%10;
		//~ printf("k= %d \n", k);
		a/=10;
		
		//~ printf("a= %d \n", a);
		if (k%2 == 0)
		count1++;
		else
		count2++;
		//~ printf("count= %d \n", count);
		
	}
	printf("%d %d \n", count1, count2);
return  0;
}
