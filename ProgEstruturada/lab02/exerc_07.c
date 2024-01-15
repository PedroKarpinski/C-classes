// Pedro Henrique Karpinski Silva
// RA - 11202130643

#include <stdio.h>
#define MAX 100

void le_matriz(double M[][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%lf", &M[i][j]);
}

void inverte_linha(double M[][MAX], int m, int i, int j) {
    int a;
    int auxiliar[MAX];
    for (a = 0; a < m; a++) {
        auxiliar[a] = M[i][a];
        M[i][a] = M[j][a];
        M[j][a] = auxiliar[a];
    }
}

void imprime_matriz(double M[][MAX], int n, int m) {
    int i, j;
    printf("A matriz resultante eh\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%lf ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, i, j;
    double A[MAX][MAX];
    printf("Digite o numero de linhas da matriz\n");
    scanf("%d", &n);
    printf("Digite o numero de colunas da matriz\n");
    scanf("%d", &m);
    printf("Digite os valores da matriz\n");
    le_matriz(A, n, m);
    printf("Digite as linhas da matriz a serem trocadas (a primeira linha eh a linha 0)\n");
    scanf("%d %d", &i, &j);
    inverte_linha(A, m, i, j);
    imprime_matriz(A, n, m);
    return 0;
}