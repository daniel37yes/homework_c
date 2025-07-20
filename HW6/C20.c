/*
 * C20.c
 * 
 Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность. 

Данные на входе: 	На вход подается строка состоящая из символов '(', ')' 
					и заканчивающаяся символом '.'. Размер строки не более 1000 символов. 
Данные на выходе: 	Необходимо напечатать слово YES если скобки расставлены верно и NO в противном случае. 

Пример №1
Данные на входе: 	(()()). 
Данные на выходе: 	YES 
 * 
 */


#include <stdio.h>


void correct_input()
{
    char input;
    int count = 0;
    while( (input = getchar())!= '.') //dot
        {
			if(input == '(' )
			{ 
				count++;
			}
			else if(input == ')' )
			{
				count--;
				if (count < 0)
				{
				printf("NO"); 
				return ;
				}
			}
		}
	printf(count == 0 ? "YES\n" : "NO\n");
}

int main(int argc, char **argv)
{
	correct_input();
	return 0;
}



//~ #include <stdio.h>

//~ void check_parentheses() 
//~ {
    //~ printf("Input until '.':\n");
    
    //~ char input;
    //~ int balance = 0;  // Баланс скобок: +1 для '(', -1 для ')'
    
    //~ while ((input = getchar()) != '.') 
    //~ {
        //~ if (input == '(') 
        //~ {
            //~ balance++;
        //~ } 
        //~ else if (input == ')') 
        //~ {
            //~ balance--;
            //~ // Если баланс ушёл в минус — скобки не сбалансированы
            //~ if (balance < 0) 
            //~ {
                //~ printf("NO\n");
                //~ return;
            //~ }
        //~ }
    //~ }
    
    //~ printf(balance == 0 ? "YES\n" : "NO\n");
//~ }

//~ int main() {
    //~ check_parentheses();
    //~ return 0;
//~ }
