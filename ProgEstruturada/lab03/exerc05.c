//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#define MAX 1000

void conserta_texto(char texto[]) {
    int i = 0;
    int len = strlen(texto);
    while (i < len) {
        if (i%80 == 0 && i != len-1) {
            if (texto[i] == ' ')
                texto[i] = '\n';
            else if (texto[i] != ' ') {
                int j = i;
                while (j > 0 && texto[j] != ' ')
                    j--;
                if (texto[j] == ' ')
                    texto[j] = '\n';
            }
            i++;
        }
    }
}

int main() {
    char texto[MAX];
    printf("Digite o texto\n");
    fgets(texto, MAX, stdin);
    conserta_texto(texto);
    printf("\n%s", texto);
    return 0;
}