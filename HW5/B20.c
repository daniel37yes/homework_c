/*
Проверка на простоту
Проверить число на простоту.

 */

#include <stdio.h>

int main(void)
{
    int a, i;
    scanf("%d", &a);
    if (a <= 1)
    {
     printf("NO\n");  // 1 и меньше 
     return 0;
    }
    for (i = 2; i < a; i++)
    {
        if (a%i == 0)
        {
         printf("NO\n");  // если есть делитель
         return 0;
        }
    }
    printf("YES\n");  // делителя нет
    return 0;
}
