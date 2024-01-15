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

void calcula_transposta(double M[][MAX], int n, int m) {
    double MT[MAX][MAX];
    int i, j;
    printf("A matriz transposta eh\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            MT[i][j] = M[j][i];
            printf("%lf ", MT[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    double A[MAX][MAX];
    printf("Digite o numero de linhas da matriz\n");
    scanf("%d", &n);
    printf("Digite o numero de colunas da matriz\n");
    scanf("%d", &m);
    printf("Digite os valores da matriz\n");
    le_matriz(A, n, m);
    calcula_transposta(A, n, m);
    return 0;
}