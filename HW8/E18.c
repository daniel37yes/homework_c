/*
 * E18.c
 * 
 Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N. 

Данные на входе: 		Одно натуральное число N 
Данные на выходе: 	Цифры через пробел 

Пример
Данные на входе: 	54412 
Данные на выходе: 	5 4 4 1 2 
 */


#include <stdio.h>

#define MAX_DIGITS 20  

void print_digits_in_order(int n) {
    int digits[MAX_DIGITS];  // Статический массив для хранения цифр
    int digit_count = 0;
    
    // Сначала сохраняем цифры в обратном порядке
    while (n > 0) {
        digits[digit_count++] = n % 10;
        n /= 10;
    }
    
    for (int i = digit_count - 1; i >= 0; i--) {
        printf("%d ", digits[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    print_digits_in_order(n);
    
    return 0;
}
