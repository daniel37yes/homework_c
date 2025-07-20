/*
 * E18.c
 * 
В диапазоне натуральных чисел от 2 до N определить, сколько из них 
кратны любому из чисел в диапазоне от 2 до 9.
 */


#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    // Для делителя
    for (int d = 2; d <= 9; d++) {
        int count = 0;

        // Подсчет чисел, кратных d, в диапазоне [2, N]
        for (int num = 2; num <= N; num++) {
            if (num % d == 0) {
                count++;
            }
        }
        printf("%d %d\n", d, count);
    }

    return 0;
}