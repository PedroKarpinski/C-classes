// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void le_vetor(char vetor[], int n) {
    printf("Digite os %d caracteres\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &vetor[i]);
        getchar();
    }
}

void imprime_caracteristicas(char vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("entrada %d  ", i);
        printf("conteudo %c  ", vetor[i]);
        printf("endereco %llu\n", &vetor[i]);
    }
}

int main() {
    int n;
    char* vetor;
    printf("Digite o numero de elementos\n");
    scanf("%d", &n);
    getchar();
    vetor = malloc(n * sizeof(int));
    le_vetor(vetor, n);
    imprime_caracteristicas(vetor, n);
    free(vetor);
    return 0;
}