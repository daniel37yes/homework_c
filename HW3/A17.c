#include <stdio.h>
int main(void)
{
int a;
	scanf ("%d", &a);
if((a<=2)||(a==12)) 
    printf("winter \n");  
else if((2<a) && (a<=5)) 
    printf("spring \n"); 
else if ((a>=6) && (a<9)) 
    printf("summer \n");
else if ((a>=9) && (a<=11)) 
    printf("autumn \n");  
return 0;
}


