#include <stdio.h>
#include <inttypes.h>

int main (void)
{
   int count = 0;
//    int res = 0;
   uint32_t x;
   scanf ("%" SCNu32, &x );

   while (x!=0)
   {
    x &= (x-1);
    count++;
   }
   printf("%" PRIu32 "\n", count);
}