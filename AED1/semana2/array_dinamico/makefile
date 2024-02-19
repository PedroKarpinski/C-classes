CC = gcc -Wall -pedantic

build:
	mkdir -p build

array.o: build array_dinamico.c 
	$(CC) array_dinamico.c -c -o build/array.o
	$(CC) element.c -c -o build/element.o

main: build array.o main.c
	$(CC) main.c build/array.o build/element.o -o build/main

clean:
	rm -rf build
	rm -rf array_dinamico.o

run: main
	./build/main