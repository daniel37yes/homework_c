#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, c, d, max;
scanf("%d%d%d%d", &a, &b, &c, &d);
max = a > b ? a : b;
max = max> c ? max: c;
max = max> d ? max: d;
printf("%d", max);
	return 0;
}

