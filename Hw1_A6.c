#include <stdio.h>
#include <inttypes.h>

int main (void)
{
//    uint32_t x;
//    scanf ("%" SCNu32, &x );
//    uint32_t res = 0;
//    res = 0xFF000000u ^ x;
//    printf("%" PRIu32 "\n", res);
//    return 0;
// }
// более оптимальный способ, так как не нужно делать XOR для всех битов, а только для старших 8 битов, но болле длинный код, 
//так как нужно сначала вытащить старшие 8 битов, затем инвертировать их и потом уже вставить обратно в число.
   uint32_t x;
   scanf ("%" SCNu32, &x );
   uint32_t temp = 0;
   uint32_t res = 0;
   temp = x >> 24;
   temp = (~temp) & 0xFF; // так тоже работает, как 0xFF000000u ^ x. 
   res = (x & 0x00FFFFFFu) | (temp << 24);
   printf("%" PRIu32 "\n", res);
   return 0;
}