// Определяет структуры для хранения данных о температуре.

#ifndef TEMP_DATA_H
#define TEMP_DATA_H

#include <stdint.h> // Для uint8_t, uint16_t, int8_t, uint32_t

#define MAX_RECORDS 100

// Структура для хранения данных о температуре
typedef struct {
    uint8_t day;         // День (2 цифры)
    uint8_t month;       // Месяц (2 цифры, 1-12)
    uint16_t year;       // Год (4 цифры)
    int8_t temperature;  // Температура (целое число от -99 до 99)
} TemperatureData;

// Структура для хранения коллекции данных о температуре 
typedef struct {
    uint32_t number; // Текущее количество записей
    TemperatureData info[MAX_RECORDS]; // Массив данных о температуре
} SensorDataCollection;

#endif // TEMP_DATA_H
