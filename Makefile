CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SOURCES = my_mastermind.c my_functions.c
DEPS = my_headers.h
OBJFILES = $(SOURCES:.c=.o)
TARGET = my_game
all: $(TARGET)


$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) 

