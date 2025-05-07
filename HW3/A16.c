#include <stdio.h>

int main(int argc, char **argv)
{
int a, b, c;
	scanf("%d %d %d", &a,&b,&c);
if ((a<b)&& (b<c))
	printf("%s", "YES");
else 
	printf("%s", "NO");
return 0;
}

