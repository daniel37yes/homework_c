#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, x;
	printf("input number: x=a+b+c \n");
	printf("input number: x=a*b*c \n");
	scanf("%d%d%d", &a, &b, &c);
	x=a+b+c;
	printf ("%d + %d + %d = %d \n", a, b, c, x );
	printf ("x = %d \n", x);
	x=a*b*c;
	printf ("%d * %d * %d = %d \n", a, b, c, x );
	printf ("x = %d \n", x);
	
	return 0;
}

