// #include <stdio.h>
// #include <inttypes.h>
// #include <stdint.h>

// int main(void) {
//     uint32_t N;
//     if (scanf("%" SCNu32, &N) != 1 || N == 0) return 1;

//     int32_t x;
//     if (scanf("%" SCNd32, &x) != 1) return 1;

//     int32_t mx = x;
//     uint32_t count = 1;

//     for (uint32_t i = 1; i < N; i++) {
//         if (scanf("%" SCNd32, &x) != 1) return 1;

//         if (x > mx) {
//             mx = x;
//             count = 1;
//         } else if (x == mx) {
//             count++;
//         }
//     }

//     printf("%" PRIu32 "\n", count);
//     return 0;
// }

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    uint32_t N;
    if (scanf("%" SCNu32, &N) != 1 || N == 0) return 0;

    int64_t mx = 0;          // значение не важно, пока has==0
    uint32_t count = 0;
    int has = 0;

    for (uint32_t i = 0; i < N; i++) {
        int64_t x;
        if (scanf("%" SCNd64, &x) != 1) break;   // на корректном вводе не сработает

        if (!has) {
            mx = x;
            count = 1;
            has = 1;
        } else if (x > mx) {
            mx = x;
            count = 1;
        } else if (x == mx) {
            count++;
        }
    }

    if (has) printf("%" PRIu32 "\n", count);
    return 0;
}


