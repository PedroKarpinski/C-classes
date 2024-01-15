// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void le_vetor(int vetor[], int n) {
    printf("Digite os %d valores\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);
}

void imprime_caracteristicas(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("entrada %d  ", i);
        printf("conteudo %d  ", vetor[i]);
        printf("endereco %llu\n", &vetor[i]);
    }
}

int main() {
    int n;
    int* vetor;
    printf("Digite o numero de elementos\n");
    scanf("%d", &n);
    vetor = malloc(n * sizeof(int));
    le_vetor(vetor, n);
    imprime_caracteristicas(vetor, n);
    free(vetor);
    return 0;
}