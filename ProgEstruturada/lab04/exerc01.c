// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void le_vetor(int vetor[], int n) {
    printf("Digite os %d valores\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
}

double calcula_media(int vetor[], int n) {
    double soma = 0;
    double media;
    for (int i = 0; i < n; i++)
        soma += vetor[i];
    media = soma/n;
    return media;
}

int main() {
    int n;
    double resultado;
    printf("Digite o numero de elementos\n");
    scanf("%d", &n);
    int* vetor = malloc(n * sizeof(int));
    le_vetor(vetor, n);
    resultado = calcula_media(vetor, n);
    free(vetor);
    printf("A media eh %.2lf\n", resultado);
    return 0;
}