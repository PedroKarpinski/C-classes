//Pedro Henrique Karpinski Silva
//RA 11202130643
#include <stdio.h>
#include <string.h>
#define MAX 100

void inverte_tamanho(char s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] > 96 && s[i] < 123)
            s[i] = s[i] - 32;
        else if (s[i] > 64 && s[i] < 91)
            s[i] = s[i] + 32;
    }
}

int main() {
    char texto[MAX];
    int n;
    printf("Digite o texto\n");
    fgets(texto, MAX, stdin);
    n = strlen(texto);
    inverte_tamanho(texto, n);
    printf("\nTexto invertido:\n%s",texto);
}