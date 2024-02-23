CC = gcc -Wall -pedantic

build:
	mkdir -p build

student_list.o: build student_list.c 
	$(CC) student_list.c -c -o build/student_list.o
	$(CC) student.c -c -o build/student.o

main: build student_list.o main.c
	$(CC) main.c build/student_list.o build/student.o -o build/main

clean:
	rm -rf build
	rm -rf student_list.o

run: main
	./build/main