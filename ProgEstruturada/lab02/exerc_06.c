// Pedro Henrique Karpinski Silva
// RA - 11202130643

#include <stdio.h>
#define MAX 100

void le_matriz(double M[][MAX], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &M[i][j]);
}

void eh_simetrica(double M[][MAX], int n) {
    int i, j;
    int contador = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (M[i][j] == M[j][i]) 
                contador += 1;
    }
    if (contador == n*n) 
        printf("Eh simetrica");
    else
        printf("Nao eh simetrica");
}

int main() {
    double A[MAX][MAX];
    int n;
    printf("Digite o numero de linhas e colunas da matriz\n");
    scanf("%d", &n);
    printf("Digite os valores da matriz\n");
    le_matriz(A, n);
    eh_simetrica(A, n);
    return 0;
}