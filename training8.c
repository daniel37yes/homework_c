#include <stdio.h>
 
int main() {
int a,b,c,d,e, max;
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
if ((a>b)&&(a>c)&&(a>d)&&(a>e))
max = a;
else if ((b>a)&&(b>c)&&(b>d)&&(b>e))
max = b;
else if ((c>a)&&(c>b)&&(c>d)&&(c>e))
max = c;
else if ((d>a)&&(d>c)&&(d>b)&&(d>e))
max = d;
else			
max = e;
printf("%d", max);
return 0;
}
