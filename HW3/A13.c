
#include <stdio.h>

int main(void)
{
int x, a, b, c, d;
	scanf ("%d", &x);
	a = x / 100;
	b = (x / 10)%10;
	c = x % 10;
	d = a*b*c;
    printf("%d",d);
return 0;
}

