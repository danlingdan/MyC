CC = gcc
CFLAGS = -g -std=gnu23 -Wall -Wextra
TARGET = HuaC
SRCS = src/main.c src/codegen.c src/parse.c src/tokenize.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJS) $(TARGET).exe 2>NUL

.PHONY: all clean