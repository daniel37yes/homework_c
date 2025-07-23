#ifdef _WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"
#include "temp_data.h"

int main(int argc, char* argv[]) {
    set_console_utf8_encoding();
    
    SensorDataCollection data = {0};
    int month_filter = 0;          // Фильтр по месяцу (0 - нет фильтра)
    const char* csv_filename = NULL; // Имя CSV файла
    int delete_index = -1;
    
    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        // Проверяем, начинается ли аргумент с '-' и имеет ли он хотя бы два символа
        if (argv[i][0] == '-' && strlen(argv[i]) == 2) {
            switch (argv[i][1]) { // Используем второй символ аргумента в switch
                case 'h':
                    print_help();
                    return 0; 
                case 'f':
                    if (i + 1 < argc) {
                        csv_filename = argv[++i]; // имя файла
                    } else {
                        fprintf(stderr, "Ошибка: Для ключа -f не указано имя файла.\n");
                        print_help();
                        return 1;
                    }
                    break; 
              /*   case 'm':
                    if (i + 1 < argc) {
                        month_filter = atoi(argv[++i]); // номер месяца 
                        // https://stackoverflow.com/questions/3420629/what-is-the-difference-between-sscanf-or-atoi-to-convert-a-string-to-an-integer
                        if (month_filter < 1 || month_filter > 12) {
                            fprintf(stderr, "Ошибка: Некорректный номер месяца для ключа -m. Месяц должен быть от 1 до 12.\n");
                            print_help();
                            return 1;
                        }
                    } else {
                        fprintf(stderr, "Ошибка: Для ключа -m не указан номер месяца.\n");
                        print_help();
                        return 1;
                    }
                    break; */
                    case 'm':
                    if (i + 1 < argc) {
                        int converted_month;
                        char trailing_char;
                        // считать инт и если нет, то чтото еще
                        if (sscanf(argv[++i], "%d%c", &converted_month, &trailing_char) == 1) {
                            if (converted_month < 1 || converted_month > 12) {
                                fprintf(stderr, "Ошибка: Некорректный номер месяца для ключа -m. Месяц должен быть от 1 до 12.\n");
                                print_help();
                                return 1;
                            }
                            month_filter = converted_month;
                        } else {
                            // если не прочитали инт
                            fprintf(stderr, "Ошибка: Некорректный формат номера месяца для ключа -m. Ожидается число.\n");
                            print_help();
                            return 1;
                        }
                    } else {
                        fprintf(stderr, "Ошибка: Для ключа -m не указан номер месяца.\n");
                        print_help();
                        return 1;
                    }
                    break;
                default:
                    fprintf(stderr, "Ошибка: Неизвестный аргумент '%s'.\n", argv[i]);
                    print_help();
                    return 1;
                case 'd':
                 if (i + 1 < argc) {
                    int converted_index;
                    char trailing_char; // Для обнаружения лишних символов

                     // Попытаемся прочитать целое число и, если что-то еще есть, сохранить в trailing_char
                      if (sscanf(argv[++i], "%d%c", &converted_index, &trailing_char) == 1) {
                            if (converted_index < 0) {
                                 fprintf(stderr, "Ошибка: Индекс для удаления должен быть неотрицательным.\n");
                                print_help();
                                return 1;
                            }
                            delete_index = converted_index;
                        } else {
                        // Если sscanf не смог прочитать ровно одно целое число (или вообще ничего не прочитал)
                            fprintf(stderr, "Ошибка: Некорректный формат индекса для ключа -d. Ожидается целое число.\n");
                            print_help();
                            return 1;
                            }
                } else {
                        fprintf(stderr, "Ошибка: Для ключа -d не указан индекс записи.\n");
                        print_help();
                        return 1;
                        }
                break;
            }
        } else {
            // если нет '-'
            fprintf(stderr, "Ошибка: Неизвестный или некорректно отформатированный аргумент '%s'.\n", argv[i]);
            print_help();
            return 1;
        }
    }

    // Загрузка данных
    if (csv_filename) {
        if (!LoadFromCSV(&data, csv_filename)) {
            fprintf(stderr, "Ошибка загрузки данных из CSV файла.\n");
            print_help();
        }
    } else {
        print_help();
    }

    // Удаление записи
    if (delete_index != -1) {
        if (DeleteRecord(data.info, &data.number, delete_index)) {
            printf("Запись с индексом %d успешно удалена.\n", delete_index);
        } else {
            fprintf(stderr, "Не удалось удалить запись с индексом %d. Возможно, индекс вне диапазона.\n", delete_index);
        }
    }
    // Вывод статистики
    if (month_filter > 0) {
        print_monthly_stats(&data, month_filter);
    } else {
        print_all_monthly_stats(&data);
        print_yearly_stats(&data);
    }

    return 0;
}