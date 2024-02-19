#ifndef ARRAY_DINAMICO_H
#define ARRAY_DINAMICO_H

#include "element.h"

typedef struct ArrayDinamico ArrayDinamico;

ArrayDinamico* array_dinamico_create();
void array_dinamico_destroy(ArrayDinamico* array);                                                                                
void array_dinamico_add(ArrayDinamico* array, Element element);
void array_dinamico_print(ArrayDinamico* array);
int array_dinamico_size(ArrayDinamico* array);
void array_dinamico_set(ArrayDinamico* array, int pos, Element element);
Element array_dinamico_get(ArrayDinamico* array, int pos);

#endif