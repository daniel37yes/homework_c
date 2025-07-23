#ifndef TEMP_DATA_H
#define TEMP_DATA_H

#include <stdint.h>

#define MAX_RECORDS 100

typedef struct {
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t temperature;
} TemperatureData;

typedef struct {
    uint32_t number;
    TemperatureData info[MAX_RECORDS];
} SensorDataCollection;

#endif