//Pedro Henrique Karpinski Silva
//RA: 11202130643

#include <stdio.h>

int torre_de_hanoi(int ndiscos)
{
    if (ndiscos == 1) //caso base
        return 1; //retorna 1 pois aqui haveria a impressão de um movimento
    int contador = 0; //inicializa o contador de movimentos pros casos maiores que base
    
    contador += torre_de_hanoi(ndiscos - 1); //primeira chamada recursiva 
    contador++; //incremento no contador (aqui haveria a impressão de movimento)
    contador += torre_de_hanoi(ndiscos - 1); //segunda chamada recursiva
    
    return contador;
}

int main() {
    int ndiscos, movimentos;
    printf("Digite o numero de discos: ");
    scanf("%d", &ndiscos);

    movimentos = torre_de_hanoi(ndiscos);
    if (movimentos == 1)
        printf("Eh necessario 1 movimento");
    else
        printf("Sao necessarios %d movimentos", movimentos);

    return 0;
}