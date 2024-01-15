// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strcatt(char *a, char *b) {
    int lenA = strlen(a); 
    int lenB = strlen(b);
    char *c = malloc((lenA+lenB) * sizeof(char));

    for (int i = 0; i < lenA; i++)
        c[i] = a[i];
    for (int j = lenA; j < lenA+lenB+1; j++)
        c[j] = b[j-lenA];
    return c;
}

void imprime_string(char a[]) {
    int len = strlen(a);
    printf("Tamanho: %d\n Conteudo: ", len);
    for (int i = 0; i < len; i++)
        printf("%c", a[i]);
    printf("\n");
}

int main() {
    char *a = malloc(3 * sizeof(char));
    char *b = malloc(3 * sizeof(char));
    a = "ABC";
    b = "DEF";
    char *c = strcatt(a, b);
    imprime_string(a);
    imprime_string(b);
    imprime_string(c);
    free(a);
    free(b);
    free(c);
    return 0;
}