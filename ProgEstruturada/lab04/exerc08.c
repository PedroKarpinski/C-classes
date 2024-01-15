// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

int** cartesiano(int v1[], int n1, int v2[], int n2) {
    int **a;
    int k = 0;
    a = malloc((n1*n2) * sizeof(int*));
    for (int i = 0; i < n1*n2; i++)
        a[i] = malloc(2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++) {
                *(*(a+k)+0) = v1[i];
                *(*(a+k)+1) = v2[j]; 
                k++;
            }
    return a;
}

void imprime_matriz(int **a, int n1, int n2) {
    for (int i = 0; i < n1*n2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", *(*(a+i)+j));
        printf("\n");
    }
}

int main() {
    int v1[3] = {1, 2, 3};
    int v2[4] = {4, 5, 6, 7};
    int n1 = 3;
    int n2 = 4;
    int **a;
    a = cartesiano(v1, n1, v2, n2);
    imprime_matriz(a, n1, n2);
    free(a);
    return 0;
}