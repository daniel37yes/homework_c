#include <stdio.h>
#include <inttypes.h>

int main (void)
{
    uint32_t x, k;
    scanf ("%" SCNu32 " %" SCNu32, &x, &k );
    if (1 > k > 31)
    {
        printf("error k = 0...31  \n");
        return 1;
    }
    else 
    {
       x = x & ((1u << k) - 1);
    }
    printf("%" PRIu32 "\n", x);
    return 0;
}
