// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

int** matriz_le(int n, int m) {
    int** M = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        M[i] = malloc(m * sizeof(int));
    printf("Digite os valores da matriz\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &*(*(M+i)+j));
    return M;
}

void matriz_print(int **M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            printf("%d ", *(*(M+i)+j));
        printf("\n");
    }
}

int main() {
    int n, m;
    int** M;
    printf("Digite o numero de linhas: ");
    scanf("%d", &n);
    printf("Digite o numero de colunas: ");
    scanf("%d", &m);
    M = matriz_le(n, m);
    matriz_print(M, n, m);
    free(M);
    free(*M);
    return 0;
}