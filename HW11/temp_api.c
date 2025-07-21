// temp_api.c
// Реализации функций для работы с температурными данными.

#include "temp_api.h" // Включаем заголовочный файл с прототипами
#include <stdio.h>    // Для функций ввода/вывода
#include <string.h>   // Для memcpy 
#include <limits.h>   // Для INT_MAX, INT_MIN

// Функция для обмена местами двух записей TemperatureData
void changeIJ(TemperatureData* info, int i, int j) {
    TemperatureData temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

// Сортировка температуры
void SortByT(TemperatureData* info, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (info[i].temperature >= info[j].temperature) {
                changeIJ(info, i, j);
            }
        }
    }
}

// Функция для преобразования даты в целое число для сравнения
unsigned int DateToInt(const TemperatureData* info) {
    return (unsigned int)info->year << 16 | (unsigned int)info->month << 8 | (unsigned int)info->day;
}

// Сортировка по дате
void SortByDate(TemperatureData* info, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (DateToInt(info + i) >= DateToInt(info + j)) {
                changeIJ(info, i, j);
            }
        }
    }
}

// Добавляем записи в массив
void AddRecord(TemperatureData* info, int number,
               uint16_t year, uint8_t month, uint8_t day, int8_t t) {
    if (number < MAX_RECORDS) { // Проверка на выход за границы массива
        info[number].year = year;
        info[number].month = month;
        info[number].day = day;
        info[number].temperature = t;
    } else {
        fprintf(stderr, "Error upper MAX_RECORDS.\n");
    }
}

// Тестовые данные 
int AddInfo(SensorDataCollection* data) {
    data->number = 0; // Сбрасываем счетчик перед добавлением
    AddRecord(data->info, data->number++, 2021, 9, 16, 9);
    AddRecord(data->info, data->number++, 2022, 9, 2, -9);
    AddRecord(data->info, data->number++, 2021, 1, 7, 8);
    AddRecord(data->info, data->number++, 2021, 9, 5, 1);
    AddRecord(data->info, data->number++, 2021, 1, 15, -5); // Добавляем еще данные для января 2021
    AddRecord(data->info, data->number++, 2021, 1, 20, 0);  // И еще для января 2021
    AddRecord(data->info, data->number++, 2022, 3, 10, 12); // Данные для марта 2022
    AddRecord(data->info, data->number++, 2022, 3, 20, 18); // Еще для марта 2022
    return data->number;
}

// Функция для загрузки данных из бинарного файла
void load_bin_d(SensorDataCollection* data) {
    FILE* f = fopen("sensor.bin", "rb");
    if (f == NULL) {
        data->number = 0;
        return;
    }

    fread(&data->number, sizeof(data->number), 1, f);
    fread(data->info, data->number * sizeof(TemperatureData), 1, f);
    fclose(f);
}

void save_bin_d(SensorDataCollection* data) {
    FILE* f = fopen("sensor.bin", "wb");
    if (f == NULL) {
        return;
    }

    // Записываем количество записей
    fwrite(&data->number, sizeof(data->number), 1, f);
    
    // Записываем сами данные
    fwrite(data->info, data->number * sizeof(TemperatureData), 1, f);
    
    fclose(f);
}

// вывод 
void print_records(const SensorDataCollection* data) {
    printf("===================================\n");
    if (data->number == 0) {
        printf("No data.\n");
        return;
    }
    for (uint32_t i = 0; i < data->number; i++) {
        printf("%04d-%02d-%02d t=%3d\n",
               data->info[i].year,
               data->info[i].month,
               data->info[i].day,
               data->info[i].temperature);
    }
}

// Функция для вывода статистики по заданному месяцу
void print_monthly_stats(const SensorDataCollection* data, int month) {
    int sum_temp = 0;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;
    int count_in_month = 0;

    for (uint32_t i = 0; i < data->number; i++) {
        if (data->info[i].month == month) {
            sum_temp += data->info[i].temperature;
            if (data->info[i].temperature < min_temp) {
                min_temp = data->info[i].temperature;
            }
            if (data->info[i].temperature > max_temp) {
                max_temp = data->info[i].temperature;
            }
            count_in_month++;
        }
    }

    printf("\n--- Statistic per month %02d ---\n", month);
    if (count_in_month > 0) {
        printf("  Average temp: %.2f\n", (double)sum_temp / count_in_month);
        printf("  Min temp in this month: %d\n", min_temp);
        printf(" Max temp in this month: %d\n", max_temp);
    } else {
        printf("  No data for month %02d.\n", month);
    }
}

// Функция для вывода статистики за год
void print_yearly_stats(const SensorDataCollection* data) {
    int sum_temp = 0;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;
    int count_in_year = 0;

    if (data->number == 0) {
        printf("\n--- Statistics per year ---\n");
        printf("  No data .\n");
        return;
    }

    for (uint32_t i = 0; i < data->number; i++) {
        sum_temp += data->info[i].temperature;
        if (data->info[i].temperature < min_temp) {
            min_temp = data->info[i].temperature;
        }
        if (data->info[i].temperature > max_temp) {
            max_temp = data->info[i].temperature;
        }
        count_in_year++;
    }

    
    printf("  Average temp: %.2f\n", (double)sum_temp / count_in_year);
    printf("  Min temp per year: %d\n", min_temp);
    printf("  Max temp per year: %d\n", max_temp);
}