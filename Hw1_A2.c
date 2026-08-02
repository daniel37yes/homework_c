#include <stdio.h>
#include <inttypes.h>

int main (void)
{
    uint32_t r, x;
    scanf ("%" SCNu32 " %" SCNu32, &x, &r);
    r %= 32;
    if (r == 0) { printf("%" PRIu32 "\n", x); return 0;}
    printf("%" PRIu32 "\n", (x >> r) | (x << (32 - r)));
    return 0;
}