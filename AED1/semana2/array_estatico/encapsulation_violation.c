#include <stdio.h>
#include "array.h"

// This will only be valid code if the Array struct is not an opaque type

int main() {
    Array* array = array_create(10);

    for (int i = 0; i < array_size(array); i++) {
        array_set(array, i, i);
    }

    array->size = 20; 

    array_print(array);
    array_destroy(array);

    return 0;
}