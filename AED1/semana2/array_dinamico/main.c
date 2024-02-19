#include "array_dinamico.h"

#include <stdio.h>

int main() {
    ArrayDinamico* array = array_dinamico_create();

    for (int i = 0; i < 100; i++) 
        array_dinamico_add(array, i);

    array_dinamico_print(array);
    array_dinamico_destroy(array);
    return 0;
}