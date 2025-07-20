/*
 Составить функцию, возведение числа N в степень P.
  int power(n, p) и привести пример ее использования.
 */


#include <stdio.h>
#include <math.h>

int power(double n, double p)
{
    //~ pow (n,p);
    return pow(n, p);
}

int main()
{
    double n;
    double p;
    scanf("%lf %lf",&n, &p);
    printf("%d",power(n, p));
    return 0;
}

//~ #include <stdio.h>
//~ #include <math.h>

//~ int power(double n, double p)
//~ {
    //~ pow (n,p);
    //~ return pow(2, p);
//~ }

//~ int main()
//~ {
    //~ double n = 2;
    //~ double p;
    //~ scanf("%lf", &p);
    //~ printf("%d",power(2, p-1));
    //~ return 0;
//~ }
