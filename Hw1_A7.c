#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int main(void) {
    uint32_t N;
    if (scanf("%" SCNu32, &N) != 1) return 1;

    uint32_t res = 0;
    for (uint32_t i = 0; i < N; i++) {
        uint32_t x;
        if (scanf("%" SCNu32, &x) != 1) return 1;
        res ^= x;
    }

    printf("%" PRIu32 "\n", res);
    return 0;
}
