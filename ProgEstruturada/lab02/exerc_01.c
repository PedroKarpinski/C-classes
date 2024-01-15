// Pedro Henrique Karpinski Silva
// RA - 11202130643

#include <stdio.h>

int busca(int valores[], int chave, int i) {
    if (valores[i] == chave)
        return i;
    else
        return -1;
}

void ler_vetor(int lista[], int n) {
    int i;
    printf("Digite os %d valores\n", n);
    for (i = 0; i < n; i++) 
        scanf("%d", &lista[i]);
}

int main() {
    int valores[100];
    int n, chave, i;
    int retorno[100];
    int contador = 0;
    printf("Digite o numero de valores\n");
    scanf("%d", &n);
    printf("Digite a chave\n");
    scanf("%d", &chave);
    ler_vetor(valores, n);
    printf("Retorno:\n");
    for (i = 0; i < n; i++) {
        retorno[i] = busca(valores, chave, i);
        if (retorno[i] != -1)
            printf("%d ", i);
        else
            contador += 1;
    }
    if (contador == n) {
        printf("-1");
    }
    return 0;
}