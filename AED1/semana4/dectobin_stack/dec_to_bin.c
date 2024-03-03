#include "dec_to_bin.h"

#include <stdlib.h>
#include <stdio.h>

char* decToBin(unsigned int n) {
    Stack* stack = binaryStack(n);
    char* binaryStr = stackToString(stack);

    stack_destroy(stack);
    return binaryStr;
}

// new functions

Stack* binaryStack(unsigned int n) {
    int capacity = 1;
    int i = n;
    while (i != 1 && i != 0) {
        capacity++;
        i = i/2;
    }
    Stack* stack = stack_create(capacity);

    int j = n;
    while (j != 0) {
        stack_push(stack, (j%2)+'0');
        j = j/2;
    }

    return stack;
}

char* stackToString(Stack* s) {
    char* str = malloc(sizeof(char) * (s->capacity + 1));

    int i = 0;
    while (stack_isEmpty != true) {
        str[i] = stack_pop(s);
        i++;
    }
    str[i+1] = '\0';

    return str;
}