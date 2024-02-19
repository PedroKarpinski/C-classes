#include "array_dinamico.h"

#include <stdlib.h>

#define INITIAL_CAPACITY 10

struct ArrayDinamico {
    Element* data;
    int size;
    int capacity;
};

ArrayDinamico* array_dinamico_create() {
    ArrayDinamico* array = malloc(sizeof(ArrayDinamico));

    array->capacity = INITIAL_CAPACITY;
    array->size = 0;
    array->data = malloc(sizeof(Element) * array->capacity);

    return array;
}

void array_dinamico_destroy(ArrayDinamico* array) {
    free(array->data);
    free(array);
}

void array_dinamico_resize(ArrayDinamico* array, int new_capacity) {
    Element* new_array = realloc(array->data, sizeof(Element) * new_capacity);

    if (new_array != NULL) {
        array->data = new_array;
        array->capacity = new_capacity;
    }
}

void array_dinamico_add(ArrayDinamico* array, Element element) {
    if (array->size == array->capacity) 
        array_dinamico_resize(array, array->capacity * 2);
    
    array->data[array->size] = element;
    array->size++;
}

void array_dinamico_print(ArrayDinamico* array) {
    for (int i = 0; i < array->size; i++)
        print_element(array->data[i]);
}

int array_dinamico_size(ArrayDinamico* array);
void array_dinamico_set(ArrayDinamico* array, int pos, Element element);

Element array_dinamico_get(ArrayDinamico* array, int pos) {
    if (pos < 0 || pos >= array->size)
        abort();
    
    return array->data[pos];
}