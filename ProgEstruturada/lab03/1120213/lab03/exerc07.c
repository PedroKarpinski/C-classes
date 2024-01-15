//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#define MAX 100

typedef struct M {
    int matriz[MAX][MAX];
    int tamanho_matriz;
} Matriz;

Matriz matriz_le(int n) {
    Matriz m;
    m.tamanho_matriz = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m.matriz[i][j]);
    return m;
}

Matriz matriz_multiplica(Matriz A, Matriz B) {
    Matriz m;
    int auxiliar = 0;
    if (A.tamanho_matriz > B.tamanho_matriz)
        m.tamanho_matriz = A.tamanho_matriz;
    else
        m.tamanho_matriz = B.tamanho_matriz;
    for (int i = 0; i < A.tamanho_matriz; i++) 
        for (int j = 0; j < B.tamanho_matriz; j++) {
            m.matriz[i][j] = 0;
            for (int k = 0; k < m.tamanho_matriz; k++)
                auxiliar += A.matriz[i][k] * B.matriz[k][j];
            m.matriz[i][j] = auxiliar;
            auxiliar = 0;
        }
    return m;
}

void imprime_matriz(Matriz m) {
    for (int i = 0; i < m.tamanho_matriz; i++) {
        for (int j = 0; j < m.tamanho_matriz; j++)
            printf("%d ", m.matriz[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o tamanho das dimensoes da matriz quadrada\n");
    scanf("%d", &n);
    printf("Digite os valores da matriz A\n");
    Matriz A = matriz_le(n);
    printf("Digite os valores da matriz B\n");
    Matriz B = matriz_le(n);
    Matriz C = matriz_multiplica(A, B);
    printf("\nA x B:\n");
    imprime_matriz(C);
}