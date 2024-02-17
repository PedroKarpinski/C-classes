CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wvla -g
RM = rm -rf
EXECUTABLE = main

all: matriz.o
	$(CC) $(CFLAGS) matriz.o main.c -o $(EXECUTABLE)

matriz.o: matriz.h
	$(CC) $(CFLAGS) -c matriz.c

clean:
	$(RM) *.o $(EXECUTABLE)