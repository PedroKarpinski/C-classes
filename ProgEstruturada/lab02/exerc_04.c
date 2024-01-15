// Pedro Henrique Karpinski Silva
// RA - 11202130643

#include <stdio.h>
#define MAX 200

void le_matriz(double M[][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%lf", &M[i][j]);
}

void imprime_soma_matrizes(double M1[][MAX], double M2[][MAX], int n, int m) {
    int i, j;
    double M3[MAX][MAX];
    printf("A matriz resultante eh\n");
    for (i = 0; i < n; i+=1) {
        for (j = 0; j < m; j++) {
            M3[i][j] = M1[i][j] + M2[i][j];
            printf("%lf ", M3[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    double A[MAX][MAX];
    double B[MAX][MAX];
    printf("Digite o numero de linhas das matrizes\n");
    scanf("%d", &n);
    printf("Digite o numero de colunas das matrizes\n");
    scanf("%d", &m);
    printf("Digite os valores da primeira matriz\n");
    le_matriz(A, n, m);
    printf("Digite os valores da segunda matriz\n");
    le_matriz(B, n, m);
    imprime_soma_matrizes(A, B, n, m);
    return 0;
}