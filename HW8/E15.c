/*
 * E15.c
 * 
 Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: 
в одни помещать только положительные, во второй - только отрицательные. 
Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов. 

Данные на входе: 	10 целых чисел через пробел. 
Данные на выходе: 	Сперва положительные числа, потом отрицательыне числа, через пробел. 

Пример
Данные на входе: 	5 -4 0 1 4 -3 -3 3 0 2 
Данные на выходе: 	5 1 4 3 2 -4 -3 -3 

 * 
 */


#include <stdio.h>

#include <stdlib.h>

#define SIZE 10
#define MIN_VALUE -500
#define MAX_VALUE 500

int Massive_scan (int *arr, int n)
{
	//добавим счётчик и посчитаем элементы 
	int count = 0;
	for(int i = 0; i < n; i++){
    int num;
    if (scanf("%d", &num) != 1){
		return 1;
	}
	if (num < MIN_VALUE || num > MAX_VALUE){
		return 1;
	}
	arr[count++] = num;
}
	return count;
}

void SortPosNeg(const int *pos, int pos_count, const int *neg, int neg_count) {
    for(int i = 0; i < pos_count; i++) {
		    printf("%d ",pos[i]);
		}
    for(int i = 0; i < neg_count; i++) {
		    printf("%d ",neg[i]);
		}
    }
    

int main(void)
{
	int arr [SIZE];
	int positive[SIZE] = {0};
    int negative[SIZE] = {0};
    int pos_count = 0, neg_count = 0;
   
    
    int input_count = Massive_scan(arr, SIZE);
    // Разделение чисел на положительные и отрицательные
    // Добавим счётчик для того, чтобы отследить кол-во элементов
    for(int i = 0; i < input_count; i++) {
        if(arr[i] > 0) {
            positive[pos_count++] = arr[i];
        } 
        else if(arr[i] < 0) {
            negative[neg_count++] = arr[i];
        }
        // Нули игнорируем
	}
	SortPosNeg(positive, pos_count, negative, neg_count);
	return 0;
} 
