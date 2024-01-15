//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#define MAX 100

int encontrar_maximo(int lista[MAX]) {
    int i;
    int max = lista[0];
    for (i = 0; i < MAX; i++)
        if (lista[i] > max)
            max = lista[i];
    return max;
}

int main() {
    char sequencia[MAX];
    int tamanho_maior_cadeia;
    int cadeias[MAX];
    int contador = 0;
    printf("Digite a sequencia\n");
    scanf("%s", sequencia);
    for (int i = 0; i < MAX; i++) {
        cadeias[i] = 0;
        if (sequencia[i] == '0') {
            contador += 1;
            cadeias[i] = contador;
        }
        else
            contador = 0;
    }
    tamanho_maior_cadeia = encontrar_maximo(cadeias);
    printf("A maior cadeia eh %d", tamanho_maior_cadeia);
    return 0;
}