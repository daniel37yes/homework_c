
#ifndef TEMP_API_H
#define TEMP_API_H

#include "temp_data.h" // Включаем определение структур TemperatureData и SensorDataCollection
#include <stdint.h>    // Для uint8_t, uint16_t, int8_t, uint32_t

// Функция для обмена местами двух записей TemperatureData

void changeIJ(TemperatureData* info, int i, int j);
void SortByT(TemperatureData* info, int n);
// Возвращает целое число, представляющее дату (год << 16 | месяц << 8 | день)
unsigned int DateToInt(const TemperatureData* info);
// Функция, упорядочивающая массив записей по дате
void SortByDate(TemperatureData* info, int n);

// Функция для добавления одной записи в массив
void AddRecord(TemperatureData* info, int number,
               uint16_t year, uint8_t month, uint8_t day, int8_t t);

// Функция для инициализации и добавления тестовых данных
int AddInfo(SensorDataCollection* data);

// Функция для загрузки данных из бинарного файла
void load_bin_d(SensorDataCollection* data);

// Функция для сохранения данных из коллекции в бинарный файл

void save_bin_d(SensorDataCollection* data);

// Функция для вывода всех записей в удобочитаемом формате
void print_records(const SensorDataCollection* data);

// Функция для вывода статистики по заданному месяцу

void print_monthly_stats(const SensorDataCollection* data, int month);

// Функция для вывода статистики за год

void print_yearly_stats(const SensorDataCollection* data);

#endif // TEMP_API_H
