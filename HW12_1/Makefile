CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDFLAGS = -mconsole
TARGET = temperature_app.exe
SRCS = main.c temp_api.c
OBJS = $(SRCS:.c=.o)
HEADERS = temp_api.h temp_data.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJS) $(TARGET)
#не обращаем внимание на файлы del и clean если они есть в директории (как пример)
.PHONY: all clean