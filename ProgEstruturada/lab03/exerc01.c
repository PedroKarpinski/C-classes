//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#define MAX 100

void imprime_frase_recortada(char string[MAX], char c[1]) {
    int n = strlen(string);
    for (int i = 0; i < n; i++) {
        if (string[i] != c[0])
            printf("%c", string[i]);
        else 
            break;
    }
}

int main() {
    char c[1];
    char frase[MAX];
    printf("Digite o caractere\n");
    scanf("%s", c);
    getchar();
    printf("Digite a frase\n");
    fgets(frase, MAX, stdin);
    imprime_frase_recortada(frase, c);
    return 0;
}