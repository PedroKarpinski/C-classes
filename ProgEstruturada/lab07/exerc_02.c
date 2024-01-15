//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *arq;
    char aux;
    
    if (argc < 2) {
        printf("Nenhum arquivo fornecido\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        arq = fopen(argv[i], "r");
        if (arq == NULL) {
            printf("Problema ao ler o arquivo %s\n", argv[i]);
            return 1;
        }
        while (fscanf(arq, "%c", &aux) != EOF)
            printf("%c", aux);
        printf("\n");
        fclose(arq);
    }
    return 0;
}