// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>

void swap(int **a, int **b) {
    int *aux;
    aux = *a;
    *a = *b;
    *b = aux;
    free(aux);
}

int main() {
    int a[3] = {5, 6, 7};
    int b[4] = {1, 2, 0, 8};

    int *ptrA = a;
    int *ptrB = b;

    printf("Antes da troca:\n");
    printf("vetor a: %d %d %d\n", ptrA[0], ptrA[1], ptrA[2]);
    printf("vetor b: %d %d %d %d\n", ptrB[0], ptrB[1], ptrB[2], ptrB[3]);

    swap(&ptrA, &ptrB);
    

    printf("\nDepois da troca:\n");
    printf("vetor a: %d %d %d %d\n", ptrA[0], ptrA[1], ptrA[2], ptrA[3]);
    printf("vetor b: %d %d %d\n", ptrB[0], ptrB[1], ptrB[2]);
    free(ptrA);
    free(ptrB);

    return 0;
}