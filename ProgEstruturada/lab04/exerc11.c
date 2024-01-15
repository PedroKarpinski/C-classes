// Pedro Henrique Karpinski Silva
// RA: 11202130643

#include <stdio.h>
#include <stdlib.h>

void swap(int **a, int **b) {
    int *aux = *a;
    *a = *b;
    *b = aux;
}

typedef struct {
    int* data;
    int capacity;
    int nelements;
}* VectorInt; 

VectorInt vectorint(void) {
    VectorInt v = malloc(sizeof(VectorInt));
    v->capacity = 1;
    v->data = malloc(sizeof(int));
    v->data[0] = -999;
    return v;
}

void vectorint_insert(VectorInt v, int a) {
    int contador = 0;
    int* newdata = malloc(2 * v->capacity * sizeof(int));
    int newcapacity = v->capacity * 2;
    for (int i = 0; i < v->capacity; i++)
        if (v->data[i] == -999) {
            v->data[i] = a;
            contador += 1;
            break;
        }
    if (contador == 0) {
        for (int i = 0; i <= v->capacity; i++) {
            if (i < v->capacity)
                *(newdata + i) = v->data[i]; 
            else
                *(newdata + v->capacity) = a;
        }
        for (int k = v->capacity+1; k < newcapacity; k++)
            *(newdata + k) = -999;

        v->capacity = newcapacity;
        swap(&v->data, &newdata);
    }
    free(newdata);
}

void vectorint_remove(VectorInt v, int a) {
    int contador = 0;
    int capacidade_inicial = v->capacity;
    int* newdata = malloc(v->capacity/2 * sizeof(int));
    for (int i = 0; i < v->capacity; i++)
        if (v->data[i] == a) {
            contador++;
            for (int j = i; j < v->capacity-1; j++)
                v->data[j] = v->data[j+1];
            v->capacity--;
            i--;
        }
    if (contador > capacidade_inicial/2) {
        for (int i = 0; i < v->capacity; i++)
            newdata[i] = v->data[i]; 
        v->data = newdata;
        v->capacity = capacidade_inicial / 2;
    }
    free(newdata);
}

int vectorint_at(VectorInt v, int i) {
    return v->data[i];
}

int vectorint_n(VectorInt v) {
    int tamanho = 0;
    for (int i = 0; i < v->capacity; i++)
        if (v->data[i] != -999)
            tamanho++;
    return tamanho;
}

void vectorint_pertence(VectorInt v, int x) {
    int contador = 0;
    for (int i = 0; i < v->capacity; i++)
        if (v->data[i] == x) {
            printf("\n%d pertence ao vetor\n", x);
            contador = 1;
            break;
        }
    if (contador == 0)
        printf("\n%d nao pertence ao vetor\n", x);
}

void vectorint_destroi(VectorInt v) {
    free(v->data);
}

void vectorint_imprime(VectorInt v) {
    printf("Vetor: ");
    for (int i = 0; i < v->nelements; i++)
        printf("%d ", v->data[i]);
    printf("\n");
}

int main() {
    VectorInt v = vectorint();
    vectorint_insert(v, 1);         //inserção de elementos no vetor
    vectorint_insert(v, 2);
    vectorint_insert(v, 3);
    vectorint_insert(v, 3);
    vectorint_insert(v, 4);
    v->nelements = vectorint_n(v);  //numero de elementos no vetor
    printf("\nAntes de remover as ocorrencias do elemento 3: \n");
    vectorint_imprime(v);
    vectorint_remove(v, 3);         //remoção das ocorrências do elemento 3 no vetor
    v->nelements = vectorint_n(v);
    printf("\nDepois de remover as ocorrencias do elemento 3: \n");
    vectorint_imprime(v);
    int i = vectorint_at(v, 2);     //busca pelo elemento na posição 2 do vetor
    printf("\nElemento na posicao 2 do vetor: %d", i);
    vectorint_pertence(v, 5);       //verificar se 5 é um elemento do vetor
    vectorint_destroi(v);           //liberar a memória do vetor
    return 0;
}