# Компилятор C
CC = gcc
MAKE = mingw32-make
# Флаги компиляции:
# -Wall: Включить все предупреждения
# -Wextra: Включить дополнительные предупреждения
# -std=c11: Использовать стандарт C11
# -I.: Добавить текущую директорию в пути поиска заголовочных файлов
CFLAGS = -Wall -Wextra -std=c11 -I.

# Флаги компоновки для консольного приложения
# -Wl,--subsystem,console явно указывает компоновщику использовать консольную подсистему.
# -lmingw32 явно связывает библиотеку mingw32, которая содержит правильную точку входа main.
# -Wl,--entry,mainCRTStartup явно указывает компоновщику, что точка входа - функция mainCRTStartup.
LDFLAGS = -mconsole

# Имя исполняемого файла
TARGET = temp_analyzer.exe


# Объектные файлы (автоматически генерируются из исходных файлов)
OBJS = main.o temp_api.o


# Правило по умолчанию: собрать все
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Компилируем main.c в main.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Компилируем temp_api.c в temp_api.o
temp_api.o: temp_api.c
	$(CC) $(CFLAGS) -c temp_api.c -o temp_api.o

# Очистка: удаляем скомпилированные файлы
clean:
	del $(OBJS) $(TARGET)