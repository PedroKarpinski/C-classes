//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void combinations(int elem[], int vprint[], int inicio, int fim, int indice) {
    for (int i = 0; i < indice; i++) { //impressão das combinações
        printf("%d", vprint[i]);
    }
    printf("\n");

    for (int i = inicio; i <= fim; i++) {
        vprint[indice] = elem[i];
        combinations(elem, vprint, i+1, fim, indice+1); //chamada recursiva para buscar combinações
    }
}

int main() {
    int n;
    int *elem, *vprint;
    printf("Digite um numero positivo: ");
    scanf("%d", &n);

    elem = malloc(n * sizeof(int)); //vetor com os elementos 1 até n
    vprint = malloc(n * sizeof(int)); //vetor para imprimir as combinações
    for (int i = 0; i < n; i++)
        elem[i] = i + 1;

    printf("Combinacoes:");
    combinations(elem, vprint, 0, n-1, 0);

    return 0;
}