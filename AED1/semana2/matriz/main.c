#include <stdio.h>
#include "matriz.h"

int main(void) {
    Matriz* A = matriz_create(2,2);
    matriz_set(A, 1, 0, 5);
    matriz_set(A, 0, 1, 5);
    bool s = matriz_is_symmetric(A);
    printf("A is synmetric = ");
    if (s == 1) printf("true\n");
    else printf("false\n");
    matriz_destroy(A);
    return 0;
}