// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void swap(int** a, int** b) {
    int* aux = *(a);
    *(a) = *b;
    *(b) = aux;
}

int main() {
    int *a, *b;
    a = malloc(sizeof(int));
    b = malloc(sizeof(int));
    printf("Digite o valor de a: ");
    scanf("%d", &*a);
    printf("Digite o valor de b: ");
    scanf("%d", &*b);
    swap(&a, &b);
    printf("a: %d\n", *(a));
    printf("b: %d\n", *(b)); 
    free(a);
    free(b);
    return 0;
}