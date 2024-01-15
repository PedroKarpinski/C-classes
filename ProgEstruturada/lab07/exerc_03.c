//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE *arq;
    char aux;
    int lenP = strlen(argv[1]);
    int contadorPalavra;
    int contadorLetras;
    int j;
    int linhaAtual;
    char *linha;
    int fazParte;
    int destaque;

    if (argc < 3) {
        printf("Nenhum arquivo fornecido\n");
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        arq = fopen(argv[i], "r");
        if (arq == NULL) {
            printf("Problema ao ler o arquivo %s\n", argv[i]);
            return 1;
        }
        contadorPalavra = 0;
        contadorLetras = 0;
        linhaAtual = 1;
        j = 0;
        fazParte = 0;
        linha = malloc(sizeof(char));
        while (fscanf(arq, "%c", &aux) != EOF) {
            contadorLetras++;
            linha = (char*) realloc(linha, (contadorLetras+1) * sizeof(char));
            linha[contadorLetras-1] = aux;
            if (aux == '\n') {
                if (fazParte == 1) {
                    printf("%s:%d:", argv[i], linhaAtual);
                    printf(" ");
                    for (int k = 0; k < contadorLetras-1; k++) {
                        if (k == destaque)
                            printf("\033[1;31m");
                        printf("%c", linha[k]);
                        if (k == destaque + lenP - 1)
                            printf("\033[1;m");
                    }
                    fazParte = 0;
                    printf("\n");
                }
                linhaAtual++;
                linha = malloc(sizeof(char));
                contadorLetras = 0;
            }

            if (aux == argv[1][j]) {
                contadorPalavra++;
                j++;
            }
            else {
                contadorPalavra = 0;
                j = 0;
            }

            if (contadorPalavra == lenP) {
                fazParte = 1;
                destaque = contadorLetras - lenP;
                contadorPalavra = 0;
                j = 0;
            } 
        }
        if (fscanf(arq, "%c", &aux) == EOF) {
            contadorLetras++;
            linha = (char*) realloc(linha, (contadorLetras+1) * sizeof(char));
            linha[contadorLetras-1] = aux;
            if (fazParte == 1) {
                    printf("%s:%d:", argv[i], linhaAtual);
                    printf(" ");
                    for (int k = 0; k < contadorLetras-1; k++) {
                        if (k == destaque)
                            printf("\033[1;31m");
                        printf("%c", linha[k]);
                        if (k == destaque + lenP - 1)
                            printf("\033[1;m");
                    }
                    fazParte = 0;
                    printf("\n");
                }
                linhaAtual++;
                linha = malloc(sizeof(char));
                contadorLetras = 0;
        }
        fclose(arq);
    }
    return 0;
}