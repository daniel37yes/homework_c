#include <stdio.h>
 
int main() {
int a, b, c, d, max;
scanf("%d%d%d%d", &a, &b, &c, &d);
max = a > b ? a : b;
max = max> c ? max: c;
max = max> d ? max: d;
max = a + d;
printf("%d", max);
    return 0;
}
