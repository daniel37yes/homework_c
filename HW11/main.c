int main(void);

#ifdef _WIN32
#include <windows.h> // Для WinMain
// __attribute__((unused)) подавляет предупреждение о неиспользуемой функции,
// если компилятор не требует WinMain.
int __attribute__((unused)) WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    return main();
}
#endif

#include <stdio.h>
#include "temp_api.h" 
#include "temp_data.h" 



int main(void) {
    SensorDataCollection d; // Объявляем структуру для хранения данных

    // 1. Добавляем тестовые данные 
    d.number = AddInfo(&d);
    printf("Input records : %u\n", d.number);
    print_records(&d);

    // 2. Сохраняем данные в бинарный файл
    printf("\nSave data in sensor.bin\n");
    save_bin_d(&d);

    // 3. Сортировка по температуре и вывод
    SortByT(d.info, d.number);
    print_records(&d);

    // 4. Сортировка по дате и вывод
    SortByDate(d.info, d.number);
    print_records(&d);

    // 5. Загружаем данные из бинарного файла 
    // Сначала очистим данные в памяти, чтобы убедиться, что загрузка работает
    printf("\nRead from sensor.bin\n");
    d.number = 0; // Очищаем данные в памяти перед загрузкой
    load_bin_d(&d);
    printf("Overal data read: %u\n", d.number);
    print_records(&d);

    // 6. Вывод статистики по месяцам
    print_monthly_stats(&d, 1); // Статистика за январь
    print_monthly_stats(&d, 9); // Статистика за сентябрь
    print_monthly_stats(&d, 3); // Статистика за март
    print_monthly_stats(&d, 12); // Статистика за декабрь (нет данных)

    // 7. Вывод статистики за год
    print_yearly_stats(&d);

    return 0;
}
