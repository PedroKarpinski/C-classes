CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wvla -g

all: string_lib.o
	$(CC) $(CFLAGS) string_lib.o main.c -o $(EXECUTABLE)

string_lib.o: string_lib.h
	$(CC) $(CFLAGS) -c string_lib.c

clean:
	$(RM) *.o $(EXECUTABLE)