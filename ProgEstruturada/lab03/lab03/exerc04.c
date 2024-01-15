//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#define MAX 100

int faz_parte(char palavra[MAX], char frase[MAX]) {
    int tam_palavra = strlen(palavra);
    int tam_frase = strlen(frase);
    int contador = 0;
    for (int i = 0; i < tam_frase; i++) {
        if (frase[i] == palavra[0]) {
            if (i == 0)
                for (int j = i; j < i + tam_palavra; j++) {
                if (frase[j] == palavra[j - i])
                    contador++;
                else if (frase[j] == 32 && palavra[j - i] == 10)
                    contador++;
                else {
                    contador = 0;
                    break;
                }
            }
            else
                if (frase[i-1] == ' ')
                for (int j = i; j < i + tam_palavra; j++) {
                    if (frase[j] == palavra[j - i])
                        contador++;
                    else if (frase[j] == 32 && palavra[j - i] == 10)
                        contador++;
                    else {
                        contador = 0;
                        break;
                    }
            }
        if (contador == tam_palavra)    
            break;
        }
    }
    if (contador == tam_palavra)
        return 1;
    else
        return 0;
}

int main() {
    char palavra[MAX], frase[MAX];
    char resposta;
    printf("Digite a palavra\n");
    fgets(palavra, MAX, stdin);
    printf("Digite a frase\n");
    fgets(frase, MAX, stdin);
    resposta = faz_parte(palavra, frase);
    if (resposta == 1)
        printf("sim");
    else if (resposta == 0)
        printf("nao");
}