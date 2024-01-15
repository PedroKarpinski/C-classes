//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void combinacoes(int vet[], int vprint[], int inicio, int fim, int indice, int tamanho) {
    if (indice == tamanho) { //quando indice for do tamanho k fornecido pelo usuario, imprime as combinações de tamanho k
        for (int i = 0; i < tamanho; i++) 
            printf("%d ", vprint[i]);
        printf("\n");
    }

    for (int i = inicio; i <= fim; i++) {
        vprint[indice] = vet[i];
        combinacoes(vet, vprint, i+1, fim, indice+1, tamanho); //chamada recursiva para buscar combinações
    }
}

int main() {
    int n, k;
    int *vet, *vprint;
    printf("Digite o numero de elementos e o tamanho das combinacoes: ");
    scanf("%d %d", &n, &k);

    vet = malloc(n * sizeof(int)); //vetor com os elementos fornecidos pelo usuario
    vprint = malloc(n * sizeof(int)); //vetor para imprimir as combinações
    for (int i = 0; i < n; i++) 
        scanf("%d", &vet[i]);

    printf("Combinacoes:\n");
    combinacoes(vet, vprint, 0, n-1, 0, k);

    free(vet);
    free(vprint);
    return 0;
}