#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {

    uint32_t x, k;
    scanf ("%" SCNu32 " %" SCNu32, &x, &k );
    uint32_t mask = (1u << k) - 1u;   // K единиц справа
    uint32_t max = 0;
    if (k > 31 || k == 0 )
    {
        printf("error k = 0...31  \n");
        return 1;
    }
    else 
    {
       for (uint32_t i = 0; i <= 32 - k; i++) 
        {
        uint32_t window = (x >> i) & mask; // вытащили K бит
        if (window > max) 
        max = window;
        }
    }
   
    printf("%" PRIu32 "\n", max);
    return 0;
}
