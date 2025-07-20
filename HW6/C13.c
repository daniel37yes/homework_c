/*
 * C13.c
 * 
Вычислить cos
Составить функцию, которая вычисляет косинус как сумму ряда
 (с точностью 0.001)

cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... 
(x в радианах)
float cosinus(float x)

Данные на входе: 		Целое число от 0 до 90 
Данные на выходе: 	Вещественное число в формате "%.3f" 

 */


#include <stdio.h>
#include <math.h>
 
const float PI = 3.1415926535;
 
double cosx(double x)
{
double Xn = 1.0;
double sum = 0.0;
int i = 1;
    do
    {
        sum += Xn;
        Xn *= -1.0 * x * x / ((2 * i - 1) * (2 * i) );
        i++;
    }
    while (fabs(Xn) > 0.001);
        return sum;
    }
 
int main(void)
{
double x;
    scanf("%lf",&x);
    x = fmod (x * PI/180.0, 2 * PI);
    printf("%.3f",cosx(x));
    return 0;
}
