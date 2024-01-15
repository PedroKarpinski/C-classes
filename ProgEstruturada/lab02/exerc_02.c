// Pedro Henrique Karpinski Silva
// RA - 11202130643

#include <stdio.h>

void ler_vetor(int lista[], int n) {
    int i;
    printf("Digite os %d valores\n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &lista[i]);
}

void imprime_nao_crescente(int lista[], int n) {
    int a, b, k;
    int auxiliar;

    for (a = 0; a < n-1; a++) {
        for (b = n-1; b > a; b--) {
            if (lista[a] < lista[b]) {
                auxiliar = lista[a];
                lista[a] = lista[b];
                lista[b] = auxiliar;
            }
        }
    }
    printf("Em ordem nao crescente\n");
    for (k = 0; k < n; k++)
        printf("%d ", lista[k]);
}

int main() {
    int sequencia[100];
    int n;
    printf("Digite o numero de valores da sequencia\n");
    scanf("%d", &n);
    ler_vetor(sequencia, n);
    imprime_nao_crescente(sequencia, n);
}