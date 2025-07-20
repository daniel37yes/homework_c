/*
 Ввести целое число и определить, верно ли, что все его цифры 
 расположены в порядке возрастания.
 */

#include <stdio.h>

int main(void) {
    int a, prevDigit, currentDigit;
    scanf("%d", &a);
    if (a < 10) 
    {
        printf("YES");  // Однозначное число всегда удовлетворяет условию
        return 0;
    }
    prevDigit = a % 10;  // Берём последнюю цифру
    //~ printf("prevDigit= %d \n", prevDigit);
    a /= 10;
    //~ printf("a= %d \n", a);
    while (a != 0) 
    {
        currentDigit = a % 10;
        //~ printf("currentDigit= %d \n", currentDigit);
        if (currentDigit >= prevDigit) // Если предыдущая цифра меньше или равна текущей → не по возрастанию
        {  
            printf("NO");
            return 0;
        }
        prevDigit = currentDigit; // приравниваем текущую цифру и сравниваем со следующей
        a /= 10;
        //~ printf("a2= %d \n", a);
    }
    printf("YES");  // Если цикл прошёл без нарушения порядка
    return 0;
}
// Через флаг

//~ #include <stdio.h>
 
//~ int main(void)
//~ {
//~ unsigned int a, b = 0, flag = 0;
    //~ scanf("%d", &a);
    //~ b = a%10;
    //~ a /=10;
    //~ while (a != 0)
    //~ {
        //~ if (a%10 >= b)
    	  //~ {
            //~ flag =1;
        	//~ break;
    	  //~ }
    //~ b = a%10;
    //~ a/=10;  	
    //~ }
    //~ printf("%s", flag ? "NO" : "YES");
    //~ return 0;
//~ }
