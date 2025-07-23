#include "temp_api.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h> // Для SetConsoleOutputCP и SetConsoleCP
#endif

// UTF-8 (только для Windows) для русского.
void set_console_utf8_encoding() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Для вывода
    SetConsoleCP(CP_UTF8);       // Для ввода (если потребуется)
    #endif
}


void changeIJ(TemperatureData* info, int i, int j) {
    TemperatureData temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

void SortByT(TemperatureData* info, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (info[i].temperature >= info[j].temperature) {
                changeIJ(info, i, j);
            }
        }
    }
}

unsigned int DateToInt(const TemperatureData* info) {
    return (unsigned int)info->year << 16 | (unsigned int)info->month << 8 | (unsigned int)info->day;
}

void SortByDate(TemperatureData* info, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (DateToInt(info + i) >= DateToInt(info + j)) {
                changeIJ(info, i, j);
            }
        }
    }
}

void AddRecord(TemperatureData* info, uint32_t* number, uint16_t year, uint8_t month, uint8_t day, int8_t t) {
    if (*number < MAX_RECORDS) { // Проверка на выход за границы массива
        info[*number].year = year;
        info[*number].month = month;
        info[*number].day = day;
        info[*number].temperature = t;
        (*number)++;
    }  else {
        fprintf(stderr, "Ошибка: достигнут максимальный лимит записей.\n");
    }
}

int DeleteRecord(TemperatureData* info, uint32_t* number, int index) {
    if (index < 0 || (uint32_t)index >= *number) {
        fprintf(stderr, "Ошибка: неверный индекс для удаления.\n");
        return 0;
    }
    
    for (uint32_t i = (uint32_t)index; i < *number - 1; i++) {
        info[i] = info[i + 1];
    }
    (*number)--;
    return 1;
}


int LoadFromCSV(SensorDataCollection* data, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Ошибка: не удалось открыть файл %s\n", filename);
        return 0;
    }

    data->number = 0;
    char line[100];
    
    while (fgets(line, sizeof(line), file) != NULL && data->number < MAX_RECORDS) {
        // Пропускаем пустые строки 
        if (line[0] == '\n') {
            continue;
        }

        uint16_t year;
        uint8_t month, day;
        int8_t temp;
        char separator;
        
        // Проверяем корректность формата строки
        if (sscanf(line, "%hu%c%hhu%c%hhu%c%hhd", 
                  &year, &separator, 
                  &month, &separator, 
                  &day, &separator, 
                  &temp) == 7) {
            // Дополнительная проверка значений
            if (month < 1 || month > 12) {
                fprintf(stderr, "Ошибка: некорректный месяц в строке: %s \n", line);
                continue;
            }
            if (day < 1 || day > 31) {
                fprintf(stderr, "Ошибка: некорректный день в строке: %s \n", line);
                continue;
            }
            if (temp < -99 || temp > 99) {
                fprintf(stderr, "Ошибка: некорректная температура в строке: %s \n", line);
                continue;
            }
            if (year < 1900 || year > 2030){
                fprintf(stderr, "Ошибка: некорректный год в строке: %s \n", line);
                continue;
            }
            
            AddRecord(data->info, &data->number, year, month, day, temp);
        } else {
            fprintf(stderr, "Ошибка формата в строке: %s \n", line);
        }
    }
    
    fclose(file);
    return data->number;
}


void print_records(const SensorDataCollection* data) {
    printf("===================================\n");
    if (data->number == 0) {
        printf("Нет данных.\n");
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

void print_monthly_stats(const SensorDataCollection* data, int month) {
    int sum_temp = 0;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;
    int count = 0;

    for (uint32_t i = 0; i < data->number; i++) {
        if (data->info[i].month == month) {
            sum_temp += data->info[i].temperature;
            if (data->info[i].temperature < min_temp) {
                min_temp = data->info[i].temperature;
            }
            if (data->info[i].temperature > max_temp) {
                max_temp = data->info[i].temperature;
            }
            count++;
        }
    }

    printf("\nСтатистика за месяц %02d:\n", month);
    if (count > 0) {
        printf("  Средняя температура: %.2f\n", (double)sum_temp / count);
        printf("  Минимальная температура: %d\n", min_temp);
        printf("  Максимальная температура: %d\n", max_temp);
    } else {
        printf("  Нет данных за этот месяц.\n");
    }
}

void print_all_monthly_stats(const SensorDataCollection* data) {
    printf("\nСтатистика по месяцам:\n");
    for (int month = 1; month <= 12; month++) {
        print_monthly_stats(data, month);
    }
}

void print_yearly_stats(const SensorDataCollection* data) {
    if (data->number == 0) {
        printf("\nГодовая статистика:\nНет данных.\n");
        return;
    }

    int sum_temp = 0;
    int min_temp = INT_MAX;
    int max_temp = INT_MIN;

    for (uint32_t i = 0; i < data->number; i++) {
        sum_temp += data->info[i].temperature;
        if (data->info[i].temperature < min_temp) {
            min_temp = data->info[i].temperature;
        }
        if (data->info[i].temperature > max_temp) {
            max_temp = data->info[i].temperature;
        }
    }

    printf("\nГодовая статистика:\n");
    printf("  Средняя температура: %.2f\n", (double)sum_temp / data->number);
    printf("  Минимальная температура: %d\n", min_temp);
    printf("  Максимальная температура: %d\n", max_temp);
}

void print_help() {
    printf("\nОбработчик данных о температуре\n");
    printf("Использование: программа [опции]\n");
    printf("Опции:\n");
    printf("  -h          Показать эту справку\n");
    printf("  -f <файл>   Входной CSV файл для обработки\n");
    printf("  -m <месяц>  Показать статистику за указанный месяц (1-12)\n");
    printf("  -d <индекс> Удалить запись с указанным индексом\n");
    printf("\nБез опций программа выдаёт меню информации.\n");
}