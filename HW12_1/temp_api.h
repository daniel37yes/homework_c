#ifndef TEMP_API_H
#define TEMP_API_H

#include "temp_data.h"
#include <stdint.h>

// Функция для настройки кодировки консоли (Windows)
void set_console_utf8_encoding();

// Функции для работы с данными
//1) Функция для обмена местами двух записей TemperatureDat
void changeIJ(TemperatureData* info, int i, int j);
// 2) Сортировка
void SortByT(TemperatureData* info, int n);
// 3) Возвращает целое число, представляющее дату (год << 16 | месяц << 8 | день)
unsigned int DateToInt(const TemperatureData* info);
// 4) Функция, упорядочивающая массив записей по дате
void SortByDate(TemperatureData* info, int n);
// 5) Функция для добавления одной записи в массив
void AddRecord(TemperatureData* info, uint32_t* number, uint16_t year, uint8_t month, uint8_t day, int8_t t);
// 6) Функция для удаления записи по индексу
int DeleteRecord(TemperatureData* info, uint32_t* number, int index);
// 7) Функция для парсинга данных из CSV-файла
int LoadFromCSV(SensorDataCollection* data, const char* filename);

// Функции вывода
void print_records(const SensorDataCollection* data);
void print_monthly_stats(const SensorDataCollection* data, int month);
void print_yearly_stats(const SensorDataCollection* data);
void print_all_monthly_stats(const SensorDataCollection* data);
void print_help();

#endif