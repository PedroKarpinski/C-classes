//Pedro Henrique Karpinski Silva
//RA 11202130643

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void ler_vetor(int v[], int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

typedef struct Conjunto {
    int lista[MAX];
    int tamanho_lista;
} Conjunto;

Conjunto* conjunto(int vet[], int n) {
    Conjunto* conjunto = (Conjunto*) malloc(sizeof(Conjunto));
    conjunto->tamanho_lista = n;
    for (int i = 0; i < n; i++)
        conjunto->lista[i] = vet[i];
    return conjunto;
}

Conjunto* conjunto_uniao(Conjunto* A, Conjunto* B) {
    Conjunto* uniao_AB = (Conjunto*) malloc(sizeof(Conjunto));
    int a = 0;
    int contador = 0;

    for (int i = 0; i < A->tamanho_lista; i++) {
        uniao_AB->lista[i] = A->lista[i];
        a++;
    }
    for (int j = a; j < A->tamanho_lista + B->tamanho_lista; j++)
        for (int k = 0; k < B->tamanho_lista; k++)
            if (k == j - A->tamanho_lista) {
                int valor = 0;
                for (int i = 0; i < A->tamanho_lista; i++)
                    if (B->lista[k] == A->lista[i]) {
                    contador++;
                    valor++;
                    }
                if (valor == 0)
                    uniao_AB->lista[j - contador] = B->lista[k];
            }
    uniao_AB->tamanho_lista = A->tamanho_lista + B->tamanho_lista - contador;
    return uniao_AB;
}

char conjunto_pertence(int a, Conjunto* A) {
    char retorno = '0';
    for (int i = 0; i < A->tamanho_lista; i++)
        if (A->lista[i] == a)
            retorno = '1';
    return retorno;
}

int main() {
    int v1[MAX];
    int v2[MAX];
    int n, m;
    int procurado;
    char procurado_pertence;
    printf("Digite o tamanho do conjunto A\n");
    scanf("%d", &n);
    printf("Digite os valores do conjunto A\n");
    ler_vetor(v1, n);
    printf("Digite o tamanho do conjunto B\n");
    scanf("%d", &m);
    printf("Digite os valores conjunto B\n");
    ler_vetor(v2, m);
    printf("Digite um valor para procurar em A uniao com B\n");
    scanf("%d", &procurado);
    Conjunto* A = conjunto(v1, n);
    Conjunto* B = conjunto(v2, m);
    Conjunto* C = conjunto_uniao(A, B);
    printf("\nA uniao com B:\n");
    for (int i = 0; i < C->tamanho_lista; i++)
        printf("%d ", C->lista[i]);
    procurado_pertence = conjunto_pertence(procurado, C);
    if (procurado_pertence == '1')
        printf("\n%d pertence a A uniao com B", procurado);
    else
        printf("\n%d nao pertence a A uniao com B", procurado);
    return 0;
}