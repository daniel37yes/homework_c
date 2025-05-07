#include <stdio.h>
int main(void)
{
int x, a, b, c;
scanf ("%d", &x);
a = x / 100;
b = (x / 10)%10;
c = x % 10;
if ((a>b)&& (a > c))
    printf("%d",a);
else if ((b>a)&&(b>c))
    printf("%d",b);
else
    printf("%d",c);
}
