//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inverte(char word[], int inicio, int fim) {
    char aux;
    if (fim > inicio) {
        aux = word[fim];        //troca dos elemento
        word[fim] = word[inicio];
        word[inicio] = aux;
        inverte(word, inicio + 1, fim - 1); //chamada recursiva
    }
    else //quando fim fica igual ou menor que inicio, todas letras já foram trocadas
        return;
}

int main() {
    char* w;
    printf("Digite uma palavra: ");
    scanf("%s", *&w);

    inverte(w, 0, strlen(w) - 1);
    printf("Palavra invertida: %s", w);

    free(w);
    return 0;
}