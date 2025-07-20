/*Две одинаковые цифры
Ввести целое число и определить, верно ли, что в его записи есть   две одинаковые цифры,
НЕ обязательно стоящие рядом.

Данные на входе:		Одно целое число 
Данные на выходе:	Одно слово: YES или NO
*/

#include <stdio.h>
int main(){
int a, other_nums, num;
	scanf("%d", &a);
	while (a > 0)
	{
		num = a % 10;
		//~ printf("%d\n", num);
    	other_nums = a / 10;
    	//~ printf("other_nums0 = %d\n", other_nums);
    	while (other_nums > 0)
		{
			if ((num == other_nums % 10)  )
        	{
             //~ printf("other_nums1 = %d\n", other_nums);
             printf("YES\n");
             return 0;
			}
        	  other_nums /= 10;
        	  //~ printf("other_nums2 = %d\n", other_nums );
    	}
    	    a /= 10;
    	    //~ printf("a = %d\n", a);
	}
	

	printf("NO\n");
	return 0;
}

