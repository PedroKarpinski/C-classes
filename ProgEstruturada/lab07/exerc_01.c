//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *arq;
    char aux;

    if (argc < 2) {
        printf("Informe o nome do arquivo.\n");
        return 1;
    }
    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        printf("Problema ao ler o arquivo.\n");
        return 1;
    }
    int i = 0;
    char comp;
    while (fscanf(arq, "%c", &aux) != EOF) {
        if (aux == ' ' || aux == '\n')
            if (comp != ' ' && comp != '\n')
                i++;
        comp = aux;
    }
    if (comp != ' ' && comp != '\n')
        i++;

    fclose(arq);
    printf("O arquivo possui %d palavras", i);
    return 0;
}