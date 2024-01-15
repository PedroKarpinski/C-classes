// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void inc(int** a) {
    int b = **a + 1;
    int* aux = &b;
    *a = aux;
    free(aux);
}

int main() {
    int* a;
    a = malloc(sizeof(int));
    printf("Digite o valor inicial de a: ");
    scanf("%d", &*a);
    inc(&a);
    printf("a: %d\n", *(a));
    free(a);
    return 0;
}