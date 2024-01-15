//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

int soma(int v[], int n) {
    int i = n-1;
    if (i >= 0)
        return v[i] + soma(v, i); //retorno recursivo
    else
        return 0;
}

int main() {
    int n, x;
    int *v;
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &n);

    v = malloc(n * sizeof(int));
    printf("Digite os %d elementos do vetor: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    x = soma(v, n);
    printf("A soma dos elementos do vetor eh %d", x);

    free(v);
    return 0;
    }