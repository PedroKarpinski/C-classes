all: printy
 
printy: main.o string_lib.o
    gcc -o printy main.o string_lib.o
 
main.o: main.c string_lib.h
    gcc -o main.o main.c -c -W -Wall -ansi -pedantic
 
string_lib.o: string_lib.c string_lib.h
    gcc -o string_lib.o string_lib.c -c -W -Wall -ansi -pedantic
 
clean:
    rm -rf *.o *~ printy