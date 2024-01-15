// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* revert(char *c) {
    int lenC = strlen(c);
    char *reverso = malloc((lenC+1) * sizeof(char));
    for (int i = 0; i < lenC; i++)
        reverso[i] = c[lenC-i-1];
    reverso[lenC] = '\0';
    return reverso;
}

void imprime_string(char a[]) {
    printf("Conteudo de cReverso: %s", a);
}

int main() {
    char c[] = "ABCDE";
    char* cReverso = revert(c);
    imprime_string(cReverso);
    free(cReverso);
    return 0;
}