#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 : 8;
};

void array2struct(int a[], struct pack_array *p) {
    uint32_t packed = 0;
    uint32_t c0 = 0, c1 = 0;

    for (uint32_t i = 0; i < 32; i++) {
        if (a[i] == 0) c0++;
        else {
            c1++;
            // packed |= (1u << i); если биты нумеровались с 0 справа, то так, но в условии сказано, что 0 - это старший бит, значит так:
            packed |= (1u << (31 - i));
        }
    }
    p->array = packed;
    p->count0 = c0;
    p->count1 = c1;
}

int main(void) {
    int a[32];
    for (int i = 0; i < 32; i++) {
        if (scanf("%d", &a[i]) != 1) return 1;
    }

    struct pack_array p;
    array2struct(a, &p);

    printf(" %" PRIu32 , p.array);
    printf(" %" PRIu32 , (uint32_t)p.count0);
    printf(" %" PRIu32 , (uint32_t)p.count1);

    return 0;
}
